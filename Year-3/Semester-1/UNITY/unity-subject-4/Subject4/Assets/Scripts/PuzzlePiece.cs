using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class PuzzlePiece : MonoBehaviour
    {
        #region Private Fields
        // Câmpul peste care se află piesa.
        private Slot _slot;

        // Variabilă ce reține dacă piesa se află sau nu în mișcare.
        private bool _isMoving;

        // Reține destinația piesei la mutarea treptată.
        // Folosită pentru Exercițiul 3A.
        private Vector3 _targetPosition;
        #endregion


        #region Properties
        // Returnează câmpul _slot.
        public Slot Slot => _slot;
        #endregion


        #region Methods
        // Setează slotul peste care se află piesa, și o poziționează pe acesta.
        public void SetSlot(Slot slot)
        {
            _slot = slot;
            transform.position = new Vector3(slot.transform.position.x, transform.position.y, slot.transform.position.z);
            slot.SetPiece(this);
        }

        // Setează slotul peste care se află piesă, și pornește repoziționarea treptată, ce are loc în Update.
        public void SetSlotGradually(Slot slot)
        {
            // Exercițiul 3A
            _slot = slot;
            _targetPosition = new Vector3(slot.transform.position.x, transform.position.y, slot.transform.position.z);
            _isMoving = true;
            slot.SetPiece(this);
        }

        // Mută piesa pe câmpul liber, doar dacă aceasta este adiacentă câmpului liber. 
        public bool TryMove()
        {
            // Exercitiul 1C
            Slot freeNeighbor = _slot.GetFreeNeighbour();
            if (freeNeighbor != null)
            {
                _slot.SetPiece(null);
                SetSlot(freeNeighbor);
                return true;
            }
            return false;
        }

        // Metodă apelată la fiecare frame.
        // Dacă piesa este în mișcare, actualizează treptat poziția acesteia către destinație.
        private void Update()
        {
            // Exercițiul 3A
            if (_isMoving)
            {
                transform.position = Vector3.MoveTowards(transform.position, _targetPosition, Time.deltaTime);
                if (transform.position == _targetPosition)
                {
                    _isMoving = false;
                }
            }
        }
        #endregion
    }
}
