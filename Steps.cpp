// file Steps.cpp

#include "Steps.h"
#include "TreeNode.h"

//---------------------------------------------------------------

// Declare the static members of Step

Mapper Step::mapper_m;
FindWinner* Step::finder_m_p = FindWinner::Instance();

//---------------------------------------------------------------

// This step checks whether the human move is available

bool Step1::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{

  bool return_value = false;

  if ( false == game_p->moveAvailable(human_move) )
  {
    return_value = true;

    int translated_move = mapper_m.computerToHuman(human_move);
    char move_char = '0' + translated_move;

    message += "Square ";
    message += move_char;
    message += " not available. Please choose another.\n";
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->makeMove(human_move, message, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This step adds the human move and checks whether they won

bool Step2::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{
  bool return_value = false;

  game_p->addHumanMove(human_move);

  if ( finder_m_p->hasWinner(game_p->getHuman()) )
  {
    message += "The Human has won. Congratulations!\n";
    return_value = false;
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->makeMove(human_move, message, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This step checks whether another move is possible. If not
// declares a draw and ends the game.

bool Step3::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{
  bool return_value = false;

  if ( !game_p->moveAvailable() )
  {
    message += "Draw Game.\n";
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->makeMove(human_move, message, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This step gets the computer move and adds it to the game.

bool Step4::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{
  bool return_value = false;

  TreeNode* node_p = new MaxNode(*game_p);

  int computer_move = node_p->getMove();
  int game_value    = node_p->getValue();

  delete node_p;

  if ( 0 <= computer_move )
  {
    game_p->addComputerMove(computer_move);

    if ( finder_m_p->hasWinner(game_p->getComputer()) )
    {
      message += "Computer Wins!\n";
    }
    else if ( !game_p->moveAvailable() )
    {
      message += "Draw Game.\n";
    }
    else
    {
      return_value = true;
    }

  } // end after checking for valid computer move

  if ( ( true == return_value ) && ( 1 == game_value ) )
  {
    message += "Computer is going to win.\n";
  }

  return return_value;
}

//---------------------------------------------------------------
