// file View.cpp

#include "View.h"

#define HUMAN_MARKER 'X'
#define COMPUTER_MARKER 'O'

//---------------------------------------------------------------

string View::show(const Player* human_p, 
                  const Player* computer_p,
                  const Game*   game_p) throw()
{
  string return_value = " ";
  return_value += getRepresentation(0, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(1, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(2, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(3, human_p, computer_p, game_p);
  return_value += " \n";
  return_value += "---------------\n ";
  return_value += getRepresentation(4, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(5, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(6, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(7, human_p, computer_p, game_p);
  return_value += " \n";
  return_value += "---------------\n ";
  return_value += getRepresentation(8, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(9, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(10, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(11, human_p, computer_p, game_p);
  return_value += " \n";
  return_value += "---------------\n ";
  return_value += getRepresentation(12, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(13, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(14, human_p, computer_p, game_p);
  return_value += " | ";
  return_value += getRepresentation(15, human_p, computer_p, game_p);
  return_value += " \n";

  return return_value;
}


//---------------------------------------------------------------

char View::getRepresentation(const int move,
                             const Player* human_p, 
                             const Player* computer_p,
                             const Game*   game_p)
{
  if ( ( 0 > move ) || ( game_p->getSize() <= move ) )
    throw runtime_error("Move out of range");

  // yes, this is coupled to ASCII being contiguous, but it's
  // fast and cheap

  char return_value;

  if ( 9 >= move )
  {
     return_value = '0' + move;
  }
  else
  {
     int high_move = move - 10;
     return_value = 'A' + high_move;
  }

  if ( human_p->hasMoved(move))
    return_value = HUMAN_MARKER;
  else if ( computer_p->hasMoved(move) )
    return_value = COMPUTER_MARKER;

  return return_value;
}

//---------------------------------------------------------------
