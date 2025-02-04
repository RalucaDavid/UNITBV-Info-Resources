using UnityEngine;

public class EnemyCharacter : MonoBehaviour
{
    [SerializeField] private int _Health;

    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {

    }

    public void TakeDamage()
    {
        _Health--;
        if (_Health <= 0)
        {
            Destroy(gameObject);
        }
    }
}