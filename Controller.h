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

class Controller
{

public:
  Controller();
  ~Controller();

  // The second parameter is filled with a message to display
  // to the human playing the game.

  bool addResponse(char input, string& message);

  const string& getMoveMessage() const { return move_message_m; };
  const string& getByeMessage()  const { return bye_message_m; };

  const string& getBadEntryMessage() const { return bad_entry_message_m; };

private:

  Game 		game_m;

  const Player* human_m_p;
  const Player*	computer_m_p;

  View		view_m;

  bool 		continue_game_m;

  Step*		step_m_p;

  const static string move_message_m;
  const static string bye_message_m;
  const static string bad_entry_message_m;
};


#endif // CONTROLLER_H
