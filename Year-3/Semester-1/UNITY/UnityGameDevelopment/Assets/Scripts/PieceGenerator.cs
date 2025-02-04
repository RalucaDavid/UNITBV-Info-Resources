using UnityEngine;

public class PieceGenerator : MonoBehaviour
{
    [SerializeField] private Piece _BlackPiece;
    [SerializeField] private Piece _WhitePiece;
    [SerializeField] private MeshRenderer _Board;

    void Start()
    {
        PlaceWhitePieces();
        PlaceBlackPieces();
    }

    void PlaceWhitePieces()
    {
        Piece whitePiece = Instantiate(_WhitePiece);

        Bounds bounds = _Board.bounds;

        float whitePieceX = _Board.transform.position.x - bounds.size.x / 2 + bounds.size.x / 8 / 2;
        float whitePieceY = _Board.transform.position.y + _WhitePiece.MeshRenderer.bounds.size.y / 2;
        float whitePieceZ = _Board.transform.position.z + bounds.size.z / 2 - bounds.size.z / 8 / 2;

        whitePiece.transform.position = new Vector3(
            whitePieceX,
            whitePieceY,
            whitePieceZ
        );

        Vector3 basePosition = whitePiece.transform.position;
        Destroy(whitePiece);

        const int verticalPiecesCount = 3;
        const int horizontalPiecesCount = 4;

        Vector3 horizontalDistance = new Vector3(bounds.size.x / 8 * 2, 0, 0);
        Vector3 verticalDistance = new Vector3(0, 0, bounds.size.z / 8);
        Vector3 currentPosition = basePosition;

        for (int verticalPieceIndex = 0; verticalPieceIndex != verticalPiecesCount; ++verticalPieceIndex)
        {
            for (int horizontalPieceIndex = 0; horizontalPieceIndex != horizontalPiecesCount; ++horizontalPieceIndex)
            {
                Piece piece = Instantiate(_WhitePiece);
                piece.transform.position = currentPosition;
                currentPosition += horizontalDistance;
            }

            if (verticalPieceIndex % 2 == 1)
            {
                currentPosition = new Vector3(basePosition.x, currentPosition.y, currentPosition.z);
            }
            else
            {
                currentPosition = new Vector3(basePosition.x + bounds.size.x / 8, currentPosition.y, currentPosition.z);
            }

            currentPosition -= verticalDistance;
        }
    }

    private void PlaceBlackPieces()
    {
        Bounds bounds = _Board.bounds;

        Vector3 basePosition = _Board.transform.position;
        basePosition.x -= bounds.size.x / 2 - bounds.size.x / 8 / 2;
        basePosition.z -= bounds.size.z / 2 - bounds.size.z / 8 / 2 - (bounds.size.z / 8 / 2 * 4);

        int verticalPiecesCount = 3;
        int horizontalPiecesCount = 4;
        Vector3 horizontalDistance = new Vector3(bounds.size.x / 8 * 2, 0, 0);
        Vector3 verticalDistance = new Vector3(0, 0, bounds.size.z / 8);
        Vector3 currentPosition = basePosition;

        for (int verticalPieceIndex = 0; verticalPieceIndex < verticalPiecesCount; ++verticalPieceIndex)
        {
            if (verticalPieceIndex % 2 == 1)
            {
                currentPosition.x = basePosition.x;
            }
            else
            {
                currentPosition.x = basePosition.x + bounds.size.x / 8; 
            }

            for (int horizontalPieceIndex = 0; horizontalPieceIndex < horizontalPiecesCount; ++horizontalPieceIndex)
            {
                Piece piece = Instantiate(_BlackPiece);
                piece.transform.position = currentPosition;
                currentPosition += horizontalDistance;
            }

            currentPosition -= verticalDistance;
        }
    }
}
