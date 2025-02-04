using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

namespace Assets.Scripts
{
    public class WinLoader : Loader
    {
        [SerializeField] private TextMeshProUGUI _WinsText;

        public override void Load()
        {
            if(File.Exists(SaveLoadConstants.WIN_COUNT_PATH))
            {
                string data = File.ReadAllText(SaveLoadConstants.WIN_COUNT_PATH);
                int.TryParse(data, out int currentWins);
                _WinsText.text += currentWins;
            }
            else
            {
                _WinsText.text += 0;
            }
        }
    }
}
