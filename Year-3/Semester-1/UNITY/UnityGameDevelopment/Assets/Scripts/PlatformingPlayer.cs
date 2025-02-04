using NUnit.Framework;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlatformingPlayer : MonoBehaviour
{
    private Rigidbody _rigidbody;
    private List<Collision> _groundCollisions;

    [SerializeField] private float _MovementSpeed;
    [SerializeField] private float _RotationSpeed;
    [SerializeField] private float _JumpSpeed;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        _rigidbody = GetComponent<Rigidbody>();
        _groundCollisions = new List<Collision>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.UpArrow))
        {
            transform.position += transform.forward * _MovementSpeed * Time.deltaTime;
        }
        if(Input.GetKey(KeyCode.DownArrow))
        {
            transform.position += -transform.forward * _MovementSpeed * Time.deltaTime;
        }
        if(Input.GetKey(KeyCode.LeftArrow))
        {
            transform.eulerAngles += Vector3.down * _RotationSpeed * Time.deltaTime;
        }
        if(Input.GetKey(KeyCode.RightArrow))
        {
            transform.eulerAngles += Vector3.up * _RotationSpeed * Time.deltaTime;
        }

        if(Input.GetKeyDown(KeyCode.Z) && _groundCollisions.Count  > 0)
        {
            _rigidbody.AddForce(new Vector3(0, _JumpSpeed, 0), ForceMode.Impulse);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Platform"))
            _groundCollisions.Add(collision);
        if (collision.gameObject.tag == "Water")
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
        if(collision.gameObject.transform.parent?.tag == "WinCondition")
        {
            SceneManager.LoadScene("VictoryScreen");
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.gameObject.CompareTag("Platform"))
            _groundCollisions.Remove(collision);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("Destination"))
        {
            Chest chest = GameObject.FindAnyObjectByType<Chest>();
            chest.OpenChest();
        }
    }
}
