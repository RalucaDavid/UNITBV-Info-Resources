using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class DeathCounter : MonoBehaviour
    {
        [SerializeField] private DeathLoader _DeathLoader;

        private void Start()
        {
            _DeathLoader.Load();
        }
    }
}
