using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assets.Scripts
{
    // Stările jocului.
    public enum GameState
    {
        // Default.
        Undefined = 0,
        // Când are loc amestecul.
        Shuffle,
        // Când jucătorul trebuie să aleagă un pahar.
        Choice
    }
}
