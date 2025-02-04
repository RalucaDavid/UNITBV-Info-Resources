using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class DeathSaver : Saver
    {
        public override void Save()
        {
            int currentDeaths = PlayerPrefs.GetInt(SaveLoadConstants.DEATH_COUNT_KEY);
            currentDeaths++;
            PlayerPrefs.SetInt(SaveLoadConstants.DEATH_COUNT_KEY, currentDeaths);
        }
    }
}
