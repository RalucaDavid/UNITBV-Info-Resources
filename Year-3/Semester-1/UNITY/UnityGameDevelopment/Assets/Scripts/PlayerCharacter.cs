using UnityEngine;

public class PlayerCharacter : MonoBehaviour
{
    private EnemyCharacter _enemy = null;

    void Start() 
    {
    }

    void Update()
    {

        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(horizontalInput, 0, verticalInput) * 3.0f * Time.deltaTime;
        transform.Translate(movement);

        if (Input.GetKeyDown(KeyCode.Space) && _enemy != null)
            _enemy.TakeDamage();

    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Enemy"))
          _enemy = collision.gameObject.GetComponent<EnemyCharacter>();
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.gameObject.CompareTag("Enemy"))
        _enemy = null;
    }
}