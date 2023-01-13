using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.DTO
{
    /// <summary>
    /// A player a 2 Game boards
    /// 1 for his ships
    /// 1 for his strike/miss shots
    /// </summary>
    public class Player
    {
        private static int _boardSize = 9;

        private string[,] _personalBoard = new string[_boardSize,_boardSize];
        private string[,] _shotsBoard = new string[_boardSize,_boardSize];


        public Player()
        {
            _personalBoard = Create2DBoard(_personalBoard);
            _shotsBoard= Create2DBoard(_shotsBoard);    
        }

        private string[,] Create2DBoard(string[,]  board)
        {
            //string[,] board = new string[_boardSize,_boardSize];
            for (int row = 0; row < _boardSize; row++)
            {
                for (int col = 0; col < _boardSize; col++)
                {
                    board[row,col] = " ";
                }
            }
            return board;

        }

        public string[,] GetPersonalBoard
        {
            get { return _personalBoard; }
        }
        public string[,] GetShotsBoard
        {
            get { return _shotsBoard; }
        }

        


    }
}
