using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DTO.WebDTO
{
    public class PlayerDTO
    {
       

        public List<List<string>> ShipBoard { get; set; }
        public List<List<string>> ShotBoard { get; set; }

    }
}
