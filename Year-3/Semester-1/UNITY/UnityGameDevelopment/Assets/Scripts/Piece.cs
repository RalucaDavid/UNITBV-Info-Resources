using UnityEngine;

public class Piece : MonoBehaviour
{
    [SerializeField] private MeshRenderer _MeshRenderer;

    public MeshRenderer MeshRenderer => _MeshRenderer;
    
}
