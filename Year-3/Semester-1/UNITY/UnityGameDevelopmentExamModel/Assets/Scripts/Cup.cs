using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class Cup : MonoBehaviour
    {
        #region Private Fields
        // Destinația paharului atunci când se află în mișcare.
        private Vector3 _destination;

        // Referință la GameManager.
        private GameManager _gameManager;

        // Componenta BoxCollider a paharului.
        private BoxCollider _boxCollider;
        #endregion


        #region Serialized Fields
        // Determină daca paharul are mingea ascunsă sub el.
        // Trebuie să fie true pentru un singur pahar.
        [SerializeField] private bool _IsCorrectCup;

        // Sistemul de particule aflat sub pahar.
        [SerializeField] private ParticleSystem _ParticleSystem;
        #endregion


        #region Properties
        // Determină dacă se mișcă sau nu.
        public bool IsMoving { get; private set; }

        // Returnează variabila _IsCorrectCup.
        public bool IsCorrectCup => _IsCorrectCup;
        #endregion


        #region
        // Inițializeză membrii clasei.
        private void Start()
        {
            _gameManager = FindAnyObjectByType<GameManager>();
            _boxCollider = GetComponent<BoxCollider>();
        }

        // Metodă apelată la fiecare frame.
        // Folosită pentru realizarea mișcării paharului.
        private void Update()
        {
            if (IsMoving)
            {
                transform.position = Vector3.MoveTowards(transform.position, _destination, Time.deltaTime);
                if (transform.position == _destination)
                {
                    IsMoving = false;
                    _gameManager.ContinueToNextAction();
                }
            }
        }

        // Setează o destinație pentru pahar și îl pune în mișcare.
        public void SetCupDestination(Vector3 destination)
        {
            _destination = destination;
            IsMoving = true;
        }

        // Dezactivează colliderul paharului.
        public void DisableCollider()
        {
            _boxCollider.enabled = false;
        }

        // Activează sistemul de particule aflat sub pahar.
        public void ActivateParticleSystem()
        {
            // Pentru Exercițul 3.
            if (_ParticleSystem != null)
            {
                _ParticleSystem.Play();
            }
        }
        #endregion
    }
}
