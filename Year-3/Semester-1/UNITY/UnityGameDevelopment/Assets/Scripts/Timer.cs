using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

namespace Assets.Scripts
{
    public class Timer : MonoBehaviour
    {
        private TextMeshProUGUI _timerText;
        private TimerDTO _timerDTO;
        private string _defaultTimerText;

        public TimerDTO TimerDTO => _timerDTO;

        private void Start()
        {
            _timerText = GetComponent<TextMeshProUGUI>();
            _timerDTO = new TimerDTO();
            _defaultTimerText = _timerText.text;

            InvokeRepeating("UpdateTimer", 0f, 1f);
        }

        private void UpdateTimer()
        {
            if (_timerDTO.seconds < 59)
            {
                _timerDTO.seconds += 1;
            }
            else
            {
                _timerDTO.seconds = 0;
                _timerDTO.minutes = +1;
            }

            string minutesText = _timerDTO.minutes < 10 ? $"0{_timerDTO.minutes}" : _timerDTO.minutes.ToString();
            string secondsText = _timerDTO.seconds < 10 ? $"0{_timerDTO.seconds}" : _timerDTO.seconds.ToString();
            _timerText.text = $"{_defaultTimerText}{minutesText}:{secondsText}";
        }
    }
}
