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
   public class PreviousTimeLoader : Loader
    {
        [SerializeField] private TextMeshProUGUI _PreviousTimeText;

        public override void Load()
        {
            string dataPath = $"{Application.persistentDataPath}/{SaveLoadConstants.PREVIOUS_TIMER_FILE_NAME}";
            if(File.Exists(dataPath))
            {
                using (FileStream fileStream = new FileStream(dataPath, FileMode.Open))
                {
                    using (BinaryReader binaryReader = new BinaryReader(fileStream))
                    {
                        string timerDTOjson = binaryReader.ReadString();
                        TimerDTO timerDTO = JsonUtility.FromJson<TimerDTO>(timerDTOjson);

                        string minutesText = timerDTO.minutes < 10 ? $"0{timerDTO.minutes}" : timerDTO.minutes.ToString();
                        string secondsText = timerDTO.seconds < 10 ? $"0{timerDTO.seconds}" : timerDTO.seconds.ToString();
                        _PreviousTimeText.text += $"{minutesText}:{secondsText}";
                    }
                }
            }
            else
            {
                _PreviousTimeText.text += $"00:00";
            }
        }
    }
}
