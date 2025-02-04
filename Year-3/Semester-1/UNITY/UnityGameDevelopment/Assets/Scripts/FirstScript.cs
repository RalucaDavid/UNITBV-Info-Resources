using UnityEngine;

public class FirstScript : MonoBehaviour
{
    float _xScaleFactor;
    [SerializeField]
    float _yScaleFactor;
    [SerializeField]

    void Start()
    {
        _xScaleFactor = 2.0f;
        Debug.Log("xScaleFactor: " + _xScaleFactor);
        Debug.Log("yScaleFactor: " + _yScaleFactor);

        transform.localScale = new Vector3(2.0f, 1.0f, 1.0f);
        transform.position = new Vector3(2.3f, 1.0f, 1.0f);
        transform.eulerAngles = new Vector3(12.0f, 50.0f, 35.0f);

    }

    void Update()
    {
        if (Input.GetMouseButton(0))
        {
            Vector3 mousePos = Input.mousePosition;
            Vector3 worldPos = Camera.main.ScreenToWorldPoint(new Vector3(mousePos.x, mousePos.y, transform.position.z - Camera.main.transform.position.z));
            transform.position = new Vector3(worldPos.x, worldPos.y, transform.position.z);
        }
    }
}
