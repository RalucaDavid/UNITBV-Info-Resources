using Assets.Scripts;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.SceneManagement;

public class EnemyWalker : MonoBehaviour
{
    private NavMeshAgent _navMeshAgent;
    private Animator _animator;
    private DeathSaver _deathSaver;
    private PreviousTimeSaver _previousTimeSaver;

    [SerializeField] private GameObject _ObjectToFollow;

    private void Start()
    {
        _previousTimeSaver = FindAnyObjectByType<PreviousTimeSaver>();
        _deathSaver = FindAnyObjectByType<DeathSaver>();
        _navMeshAgent = GetComponent<NavMeshAgent>();
        _animator = GetComponent<Animator>();
    }

    private void Update()
    {
        _navMeshAgent.SetDestination(_ObjectToFollow.transform.position);
        float distance = Vector3.Distance(transform.position, _ObjectToFollow.transform.position);

        if(distance >5)
        {
            _animator.SetInteger("WalkStyle", 1);
        }

        if(distance <5)
        {
            _animator.SetInteger("WalkStyle", 2);
        }

        if (distance <1)
        {
            _previousTimeSaver?.Save();
            _deathSaver?.Save();
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
