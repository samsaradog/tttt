// file FindWinner.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinner.h"

#include <algorithm>

//---------------------------------------------------------------

// Define class static variables

FindWinner* FindWinner::instance_m_p = 0;
Destroyer<FindWinner> FindWinner::destroyer_m;

//---------------------------------------------------------------

// Array to define what sets of moves win a game

const int WINNER_ARRAY_COLS = 3;

//---------------------------------------------------------------

int winningMovesArray_m[][WINNER_ARRAY_COLS] = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 3, 6, 9 },
	{ 1, 5, 9 },
	{ 3, 5, 7 }  };

const int WINNER_ARRAY_ROWS = sizeof(winningMovesArray_m)/
                              (sizeof(int)*WINNER_ARRAY_COLS);

//---------------------------------------------------------------

// This will come in handy for building the vector
#define FW_POSSIBLE_MOVES 9

//---------------------------------------------------------------

FindWinner::FindWinner()
{
  buildWinningMovesSet();
}

//---------------------------------------------------------------

FindWinner::~FindWinner()
{
}

//---------------------------------------------------------------

FindWinner* FindWinner::Instance()
{
  if ( NULL == instance_m_p )
  {
    instance_m_p = new FindWinner();
    destroyer_m.SetDoomed(instance_m_p);
  }

  return instance_m_p;
}

//---------------------------------------------------------------

bool FindWinner::hasWinner(const Player* player_p) const
{
  IntSetSet::const_iterator moves_it = winningMoves_m.begin();
  bool found = false;

  while ( ( false == found ) && ( winningMoves_m.end() != moves_it ) )
  {
    found = player_p->hasMoved(*moves_it);
    moves_it++;
  }

  return found;
}

//---------------------------------------------------------------

void FindWinner::buildWinningMovesSet()
{
  winningMoves_m.clear();
  IntSet moves;

  moves.clear();

  for ( int row = 0; row < WINNER_ARRAY_ROWS; row++ )
  {
    for ( int col = 0; col < WINNER_ARRAY_COLS; col++ )
    {
      moves.insert(winningMovesArray_m[row][col]);
    }
   
    winningMoves_m.insert(moves);
    moves.clear();
  }

}

//---------------------------------------------------------------
