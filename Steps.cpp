// file Steps.cpp

#include <iostream>

#include "Steps.h"
#include "RuleFactory.h"

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

// This step checks whether the computer can make a move and win.

bool Step4::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{
  bool return_value = false;

  int computer_move = finder_m_p->winningMove(game_p, 
                                              game_p->getComputer());

  if ( 0 <= computer_move )
  {
    game_p->addComputerMove(computer_move);
    message += "Computer Wins!\n";
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->makeMove(human_move, message, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This step blocks the human from winning. It also checks whether
// the game has any moves left. If not. declares a draw.

bool Step5::makeMove(int human_move,
                     string& message,
                     Game*   game_p)
{
  bool return_value = false;

  int computer_move = finder_m_p->winningMove(game_p, 
                                              game_p->getHuman());

  if ( 0 <= computer_move )
  {
    game_p->addComputerMove(computer_move);

    if ( game_p->moveAvailable() )
      return_value = true;
    
    else
      message += "Draw Game.\n";
    
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->makeMove(human_move, message, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

LastStep::
LastStep() : Step(NULL), rule_m_p(NULL)
{
  RuleFactory factory;

  rule_m_p = factory.getRules();
}

//---------------------------------------------------------------

LastStep::
~LastStep()
{
  if ( NULL != rule_m_p )
  {
    delete rule_m_p;
    rule_m_p = NULL;
  }
}

//---------------------------------------------------------------

bool LastStep::makeMove(int human_move,
                        string& message,
                        Game*   game_p)
{

  const Player* human_p    = game_p->getHuman();
  const Player* computer_p = game_p->getComputer();

  int computer_move = rule_m_p->getMove(human_p, computer_p, game_p);

  bool return_value = false;

  if ( 0 <= computer_move )
  {
    game_p->addComputerMove(computer_move);

    if ( game_p->moveAvailable() )
      return_value = true;
    
    else
      message += "Draw Game.\n";
  }

  return return_value;
}

//---------------------------------------------------------------
