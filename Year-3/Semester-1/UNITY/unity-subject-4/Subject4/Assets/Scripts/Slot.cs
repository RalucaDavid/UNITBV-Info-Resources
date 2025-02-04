using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class Slot : MonoBehaviour
    {
        #region Private Fields
        // Piesa de puzzle aflată pe slot.
        private PuzzlePiece _puzzlePiece;
        #endregion


        #region Serialized Fields
        // Vecinii slotului.
        [SerializeField] private List<Slot> _Neighbours;
        #endregion


        #region Properties
        // Proprietate ce returnează _puzzlePiece.
        public PuzzlePiece PuzzlePiece => _puzzlePiece;
        #endregion


        #region Methods
        // Setează piesa aflată pe slot.
        public void SetPiece(PuzzlePiece puzzlePiece)
        {
            _puzzlePiece = puzzlePiece;
        }

        // Returnează câmpul liber aflat în lista vecinilor,
        // sau null dacă niciul vecin nu este liber.
        public Slot GetFreeNeighbour()
        {
            // Exercitiul 1B
            foreach (var neighbor in _Neighbours)
            {
                if (neighbor.PuzzlePiece == null)
                {
                    return neighbor;
                }
            }
            return null;
        }
        #endregion
    }
}
