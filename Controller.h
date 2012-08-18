#ifndef CONTROLLER_H
#define CONTROLLER_H

/* 
 * Class to receive input from the user, and return a string to 
 * display. Also returns whether to continue the game.
 *
 */

#include <stdexcept>
#include <string>
#include "Player.h"
#include "Game.h"
#include "View.h"
#include "Step.h"

using namespace std;

const string CT_MOVE_MESSAGE = "Please choose 1-9 to move,\nY for a new game,\nor Q to quit.\n";

const string CT_BYE_MESSAGE = "Thanks for playing!\n";

const string CT_BAD_ENTRY_MESSAGE = "Invalid input\n";

class Controller
{

public:
  Controller();
  ~Controller();

  // The second parameter is filled with a message to display
  // to the human playing the game.

  bool addResponse(char input, string& message);

private:

  Game 		game_m;

  const Player* human_m_p;
  const Player*	computer_m_p;

  View		view_m;

  bool 		continue_game_m;

  Step*		step_m_p;
};


#endif // CONTROLLER_H
