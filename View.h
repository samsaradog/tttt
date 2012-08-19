#ifndef VIEW_H
#define VIEW_H

/* 
 * Class to display the game. Holds a Mapper object to translate
 * between what the computer uses to represent the game and what
 * the human sees.
 *
 */

#include <stdexcept>
#include <string>
#include "Player.h"
#include "Game.h"

using namespace std;

class View
{

public:
  View()  {};
  ~View() {};

  string show(const Player* human_p, 
              const Player* computer_p,
              const Game*   game_p) throw();

private:

  char getRepresentation(const int move,
                         const Player* human_p,
                         const Player* computer_p,
                         const Game*   game_p);

};


#endif // VIEW_H
