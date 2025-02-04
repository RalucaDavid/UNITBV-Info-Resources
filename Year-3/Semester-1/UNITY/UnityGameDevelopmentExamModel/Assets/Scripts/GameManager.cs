using Assets.Scripts;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    #region Private Fields
    // Lista amestecurilor. Fiecare amestec este salvat ca
    // pereche de pahare pentru amestecul respectiv. 
    private List<Tuple<Cup, Cup>> _shuffles;

    // Indexul amestecului curent din listă.
    private int _shuffleIndex;

    // Starea jocului.
    // La început este Undefined.
    // Dupa apăsarea butonului Start, devine Shuffle.
    // Cand jucătorul trebuie să aleaga un pahar, va deveni Choice.
    private GameState _gameState;

    // Paharul ales de jucator.
    private Cup _chosenCup;

    // Componenta AudioSource pentru redarea sunetelor.
    private AudioSource _audioSource;
    #endregion


    #region Serialized Fields
    // Lista de pahare din joc.
    [SerializeField] private List<Cup> _Cups;

    // Numărul minim de amestecuri.
    // Numărul de amestecuri va fi MAI MARE SAU EGAL cu această valoare.
    [SerializeField] private int _MinimumNumberOfShuffles;

    // Numărul maxim de amestecuri.
    // Numărul de amestecuri va fi MAI MIC decât această valoare.
    [SerializeField] private int _MaximumNumberOfShuffles;

    // Butonul de start.
    [SerializeField] private Button _StartButton;

    // Căsuța de text pentru afișarea mesajelor.
    [SerializeField] private TextMeshProUGUI _TextBox;

    // Sunetul folosit la apăsarea butonului de start.
    [SerializeField] private AudioClip _ButtonClickSound;

    // Sunetul folosit la amestecul dintre 2 pahare.
    [SerializeField] private AudioClip _CupMoveSound;

    // Sunetul folosit la ridicarea unui pahar.
    [SerializeField] private AudioClip _CupLiftSound;
    #endregion


    #region Methods
    // Inițializeză membrii clasei.
    private void Start()
    {
        _shuffleIndex = 0;
        _gameState = GameState.Undefined;
        _audioSource = GetComponent<AudioSource>();
    }

    // Metodă apelată când se apasă butonul Start.
    public void PrepareGame()
    {
        DisableStartButton();
        PrepareShuffles();
        LayCups();
        PlayAudio(_ButtonClickSound);
    }

    // Butonul Start devine neinteractiv.
    private void DisableStartButton()
    {
        _StartButton.interactable = false;
    }

    // Generează lista de amestecuri de pahare din cadrul jocului.
    private void PrepareShuffles()
    {
        // Parametrul Max este Max Exclusiv, deci limita maximă este adunată cu 1.
        int numberOfShuffles = UnityEngine.Random.Range(_MinimumNumberOfShuffles, _MaximumNumberOfShuffles + 1);
        _shuffles = new List<Tuple<Cup, Cup>>();
        for (int index = 0; index < numberOfShuffles; ++index)
        {
            Cup firstCup = _Cups[UnityEngine.Random.Range(0, _Cups.Count)];
            Cup secondCup;
            do
            {
              secondCup = _Cups[UnityEngine.Random.Range(0, _Cups.Count)];
            } while (secondCup == firstCup);
            _shuffles.Add(new Tuple<Cup, Cup>(firstCup, secondCup));
        }
    }

    // Așează paharele pe masă.
    private void LayCups()
    {
        _gameState = GameState.Shuffle;
        foreach (Cup cup in _Cups)
        {
            Vector3 position = new Vector3(cup.transform.position.x, 0.44f, cup.transform.position.z);
            cup.SetCupDestination(position);
        }
    }

    // Metodă apelată după ce un pahar și-a terminat o acțiune de mișcare.
    public void ContinueToNextAction()
    {
        if (AllCupsFinishedMoving())
        {
            // În funcție de stagiul în care se află jocul, se execută cod diferit.
            switch (_gameState)
            {
                // Pentru stagiul de amestec.
                case GameState.Shuffle:
                    DoNextShuffle();
                    break;

                // Pentru stagiul alegerii unui pahar.
                case GameState.Choice:
                    FinishGame();
                    break;
            }
        }
    }

    // Realizează următorul amestec din lista de amestecuri,
    // sau pune jocul în stagiul de alegere dacă nu mai există amestecuri de făcut.
    private void DoNextShuffle()
    {
        if (_shuffles != null)
        {
            if (_shuffleIndex < _shuffles.Count)
            {
                var currentShuffle = _shuffles[_shuffleIndex];
                var firstCup = currentShuffle.Item1;
                var secondCup = currentShuffle.Item2;

                Vector3 tempPosition = firstCup.transform.position;
                firstCup.SetCupDestination(secondCup.transform.position);
                secondCup.SetCupDestination(tempPosition);
                _shuffleIndex++;

                PlayAudio(_CupMoveSound);
            }
            else
            {
                _gameState = GameState.Choice;
                _TextBox.text = "Make your choice";
            }
        }
    }

    // Afișează mesajul de final.
    private void FinishGame()
    {
        if (_chosenCup.IsCorrectCup)
        {
            _TextBox.text = "Well done!";
            _chosenCup.ActivateParticleSystem();
        }
        else
        {
            _TextBox.text = "Try again";
        }
    }

    // Returnează true numai dacă toate paharele și-au terminat acțiunile de mișcare.
    private bool AllCupsFinishedMoving()
    {
        foreach (Cup cup in _Cups)
        {
            if (cup.IsMoving)
            {
                return false;
            }
        }
        return true;
    }

    // Dezactivează componentele collider pentru toate paharele.
    private void DisableCupColliders()
    {
        foreach (Cup cup in _Cups)
        {
            cup.DisableCollider();
        }
    }

    // Metodă apelată la fiecare frame.
    private void Update()
    {
        FindCup();
    }

    // Metodă folosită pentru identificarea paharului selectat în faza de alegere.
    private void FindCup()
    {
        if (_gameState == GameState.Choice && Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            Physics.Raycast(ray, out RaycastHit hit);
            if (hit.collider != null)
            {
                Cup cup = hit.collider.gameObject.GetComponent<Cup>();
                if (cup != null)
                {
                    _chosenCup = cup;
                    DisableCupColliders();
                    Vector3 destination = _chosenCup.transform.position;
                    destination = new Vector3(destination.x, 0.65f, destination.z);
                    _chosenCup.SetCupDestination(destination);
                    PlayAudio(_CupLiftSound);
                }
            }
        }
    }

    // Redă un sunet audio.
    private void PlayAudio(AudioClip audioClip)
    {
        if (audioClip != null && _audioSource != null)
        {
            _audioSource.PlayOneShot(audioClip);
        }
    }

    // Resetează scena.
    public void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
    #endregion
}
