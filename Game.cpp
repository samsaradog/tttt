// file Game.cpp

#include <cppunit/config/SourcePrefix.h>
#include "Game.h"

#include <algorithm>

//---------------------------------------------------------------

Game::Game()
{
  reset();
}

//---------------------------------------------------------------

Game::Game(const Game& other)
{
  human_m           = other.human_m;
  computer_m        = other.computer_m;
  available_moves_m = other.available_moves_m;
}

//---------------------------------------------------------------

Game::~Game()
{
}

//---------------------------------------------------------------

Game& Game::operator=(Game other)
{
  std::swap(human_m, other.human_m);
  std::swap(computer_m, other.computer_m);
  std::swap(available_moves_m, other.available_moves_m);

  return *this;
}

//---------------------------------------------------------------

bool Game::operator==(const Game& other)
{
  return(
          ( human_m           == other.human_m )    &&
          ( computer_m        == other.computer_m ) &&
          ( available_moves_m == other.available_moves_m )
        );
}

//---------------------------------------------------------------

void Game::reset() throw()
{
  human_m.clear();
  computer_m.clear();

  available_moves_m.clear();

  for ( int i = 0; i <= 8; i++ )
    available_moves_m.insert(i);
}

//---------------------------------------------------------------

void Game::addHumanMove(int move) throw (invalid_argument)
{
  checkAvailableMoves(move);

  human_m.insert(move);
}

//---------------------------------------------------------------

void Game::addComputerMove(int move) throw (invalid_argument)
{
  checkAvailableMoves(move);

  computer_m.insert(move);
}

//---------------------------------------------------------------

void Game::checkAvailableMoves(int move) throw (invalid_argument)
{
  IntSet::iterator it = available_moves_m.find(move);

  if ( available_moves_m.end() == it )
    throw invalid_argument("move not valid");

  available_moves_m.erase(it);
}

//---------------------------------------------------------------

bool Game::moveAvailable() const
{
  return !available_moves_m.empty();
}

//---------------------------------------------------------------

bool Game::moveAvailable(int move) const
{
  bool returnValue = false;
  IntSet::const_iterator it = available_moves_m.find(move);

  if ( available_moves_m.end() != it )
    returnValue = true;

  return returnValue;
}

//---------------------------------------------------------------

const IntSet& Game::getAvailable() const
{
  return available_moves_m;
}

//---------------------------------------------------------------



