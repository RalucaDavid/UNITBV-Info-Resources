using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class WinCounter : MonoBehaviour
    {
        [SerializeField] private WinLoader _WinLoader;

        private void Start()
        {
            _WinLoader.Load();
        }
    }
}
