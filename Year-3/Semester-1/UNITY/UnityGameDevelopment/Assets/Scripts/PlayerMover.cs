using UnityEngine;

public class PlayerMover : MonoBehaviour
{
    [SerializeField]
    float _MovementSpeed;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(horizontalInput, 0.0f, verticalInput) * _MovementSpeed * Time.deltaTime;
        transform.Translate(movement);

        if (Input.GetKey(KeyCode.Q))
        {
            transform.Translate(Vector3.up * _MovementSpeed * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.E))
        {
            transform.Translate(Vector3.down * _MovementSpeed * Time.deltaTime);
        }
    }
}
