using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

namespace Assets.Scripts
{
    public class PreviousTimeSaver : Saver
    {
        [SerializeField] private Timer _CurrentTimer;

        public override void Save()
        {
            string dataPath = $"{Application.persistentDataPath}/{SaveLoadConstants.PREVIOUS_TIMER_FILE_NAME}"; 
            if(!File.Exists(dataPath))
            {
                File.Create(dataPath).Dispose();
            }

            using (FileStream fileStream = new FileStream(dataPath, FileMode.Open))
            {
                using (BinaryWriter binaryWriter = new BinaryWriter(fileStream))
                {
                    TimerDTO timerDTO = _CurrentTimer.TimerDTO;
                    string timerDTOjson = JsonUtility.ToJson(timerDTO);
                    binaryWriter.Write(timerDTOjson);
                }
            }
        }
    }
}
