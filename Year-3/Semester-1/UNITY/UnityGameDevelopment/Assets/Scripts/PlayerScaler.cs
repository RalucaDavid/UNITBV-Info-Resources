using UnityEngine;

public class PlayerScaler : MonoBehaviour
{

    [SerializeField]
    float _ScaleFactor;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.P))
        {
            transform.localScale += new Vector3(_ScaleFactor, _ScaleFactor, _ScaleFactor);
        }
        else if (Input.GetKeyDown(KeyCode.O))
        {
            transform.localScale -= new Vector3(_ScaleFactor, _ScaleFactor, _ScaleFactor);
        }
    }
}
