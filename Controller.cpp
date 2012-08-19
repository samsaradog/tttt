// file View.cpp

#include <cctype>
#include <cstdlib>

#include "Controller.h"
#include "StepFactory.h"
#include "TreeNode.h"

//---------------------------------------------------------------

// Initialize static constants

//---------------------------------------------------------------

const string Controller::move_message_m =         
	"Please choose 1-9 to move,\nY for a new game,\nor Q to quit.\n";

const string Controller::bye_message_m = "Thanks for playing!\n";

const string Controller::bad_entry_message_m = "Invalid input\n";

//---------------------------------------------------------------

Controller::Controller() : game_m(),
                           human_m_p(game_m.getHuman()), 
                           computer_m_p(game_m.getComputer()), 
                           view_m(), continue_game_m(true),
                           step_m_p(NULL)
{
  StepFactory the_factory;

  step_m_p = the_factory.getSteps();

  // seed the random number generators

  srand(time(0));
}

//---------------------------------------------------------------

Controller::
~Controller()
{
  if ( NULL != step_m_p )
  {
    delete step_m_p;
    step_m_p = NULL;
  }
}

//---------------------------------------------------------------

bool Controller::addResponse(char input, string& message)
{
  bool return_value = true;

  switch (toupper(input))
  {
    case 'Y':
    {
      game_m.reset();

      message.clear();

      bool computer_first = ( 1 == (rand() % 2) );

      if ( computer_first )
      {
        message += "Computer moves first.\n";

        TreeNode* node_p = new MaxNode(game_m);

        game_m.addComputerMove( node_p->getMove() );

        delete node_p;
      }
      else
      {
        message += "Human moves first.\n";
      }

      message += view_m.show(human_m_p, computer_m_p, &game_m);
      message += getMoveMessage();
    }
    break;

    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
       int move = input - '0';

       message.clear();

       bool more_moves = step_m_p->makeMove(move,
                                            message,
                                            &game_m);

       message += view_m.show(human_m_p, computer_m_p, &game_m);

       if ( more_moves )
         message += getMoveMessage();
       else
         message += "Play again? (Y/N)\n";
    }
    break;

    case 'Q':
    case 'N':
    {
      message = getByeMessage();
      return_value = false;
    }
    break;

    default:
    {
      message = getBadEntryMessage();
      message += getMoveMessage();
      return_value = true;
    }
    break;
  }

  return return_value;
}


//---------------------------------------------------------------
