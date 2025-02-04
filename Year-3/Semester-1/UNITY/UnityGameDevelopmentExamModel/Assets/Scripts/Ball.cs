using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class Ball : MonoBehaviour
    {
        #region Serialized Fields
        // Paharul ce ascunde mingea.
        [SerializeField] private GameObject _Cup;
        #endregion


        #region Methods
        // Metodă apelată la fiecare frame.
        // Folosită pentru a păstra mingea sub pahar.
        private void Update()
        {
            Vector3 cupPosition = _Cup.transform.position;
            transform.position = new Vector3(cupPosition.x, transform.position.y, cupPosition.z);
        }
        #endregion
    }
}
