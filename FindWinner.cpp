// file FindWinner.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinner.h"

#include <algorithm>

//---------------------------------------------------------------

// Define class static variables

//---------------------------------------------------------------

FindWinner* FindWinner::instance_m_p = 0;
Destroyer<FindWinner> FindWinner::destroyer_m;

//---------------------------------------------------------------

const int 
FindWinner::winning_moves_array_m[][winner_array_cols_m] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
        { 1, 4, 7 },
        { 2, 5, 8 },
        { 3, 6, 9 },
        { 1, 5, 9 },
        { 3, 5, 7 }  };

//---------------------------------------------------------------

const int 
FindWinner::winner_array_rows_m = sizeof(winning_moves_array_m)/
                                   (sizeof(int)*winner_array_cols_m);

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

  for ( int row = 0; row < winner_array_rows_m; row++ )
  {
    for ( int col = 0; col < winner_array_cols_m; col++ )
    {
      moves.insert(winning_moves_array_m[row][col]);
    }
   
    winningMoves_m.insert(moves);
    moves.clear();
  }

}

//---------------------------------------------------------------
