using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DTO.Area
{
    public class GameArea
    {

        
        List<Player> _players= new List<Player>();

        public List<Player> Players
        {
            get { return _players; }
        }

        public bool isGameFull()
        {
            return _players.Count == 2;
        }

        public void AddPLayer()
        {
            if(isGameFull())
            {
                throw new Exception("Game is full (Max 2 players");
            }
            _players.Add(new Player());
        }



    }
}
