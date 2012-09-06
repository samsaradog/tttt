
#ifndef FIND_WINNER_H
#define FIND_WINNER_H

/* 
 * Class to test whether either the human or computer has won the game.
 * Also finds whether a single move will win the game for either the
 * computer or the human.
 *
 */

#include "Game.h"
#include "Player.h"
#include "Destroyer.h"

#include <set>
#include <vector>

typedef set<IntSet> IntSetSet;
typedef vector<IntSetSet> IntSetSetVector;

// We want this class to be a singleton, since
// we'll need it a lot in the tree.

class FindWinner
{
public:
  static FindWinner* Instance();

  bool hasWinner(const Player* player_p) const;

private:
  FindWinner();
  ~FindWinner();

  IntSetSet winningMoves_m;
  void buildWinningMovesSet();

  friend class Destroyer<FindWinner>;

  static FindWinner* instance_m_p;
  static Destroyer<FindWinner> destroyer_m;

  // Give this a value here so we can use it for the array

  static const int winner_array_cols_m = 4;

  static const int winning_moves_array_m[][winner_array_cols_m];

  static const int winner_array_rows_m;

};

#endif // FIND_WINNER_H
