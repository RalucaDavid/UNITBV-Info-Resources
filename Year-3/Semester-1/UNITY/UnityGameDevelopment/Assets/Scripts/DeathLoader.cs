using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

namespace Assets.Scripts
{
    public class DeathLoader : Loader
    {
        [SerializeField] private TextMeshProUGUI _DeathsText;
        public override void Load()
        {
            int currentDeaths = PlayerPrefs.GetInt(SaveLoadConstants.DEATH_COUNT_KEY);
            _DeathsText.text += currentDeaths;
        }
    }
}
