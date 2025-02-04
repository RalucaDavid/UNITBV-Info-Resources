using Assets.Scripts;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NavMeshPlayer : MonoBehaviour
{
    [SerializeField] private GameObject _WinCondition;
    private WinSaver _winSaver;
    private PreviousTimeSaver _previousTimeSaver;

    private void Start()
    {
        _winSaver = FindAnyObjectByType<WinSaver>();
        _previousTimeSaver = FindAnyObjectByType<PreviousTimeSaver>();
    }
    private void Update()
    {
        float distance = Vector3.Distance(transform.position, _WinCondition.transform.position);
        if(distance<1)
        {
            _previousTimeSaver?.Save();
            _winSaver?.Save();
            SceneManager.LoadScene("VictoryScreen");
        }
    }
}
