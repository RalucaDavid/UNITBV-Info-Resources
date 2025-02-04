using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class PreviousTime : MonoBehaviour
    {
        [SerializeField] private PreviousTimeLoader _PreviousTimerLoader;

        private void Start ()
        {
            _PreviousTimerLoader.Load();
        }
    }
}
