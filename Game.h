#ifndef GAME_H
#define GAME_H

/* 
 * Class to model the game. Holds sets of human moves, computer
 * moves and free spaces.
 *
 */

#include <stdexcept>
#include <set>
#include "Player.h"

using namespace std;

typedef set<int> IntSet;

class Game
{

public:
  Game();
  Game(const Game& other);

  ~Game();

  Game& operator=(Game other);

  bool operator==(const Game& other);

  void reset() throw();

  void addHumanMove(int move)    throw (invalid_argument);
  void addComputerMove(int move) throw (invalid_argument);

  const Player* getHuman()    { return &human_m; };
  const Player* getComputer() { return &computer_m; };

  // Returns whether any move is available
  bool moveAvailable() const;

  // Returns whether the given move is available
  bool moveAvailable(int) const;

  // Returns a copy of the set of available moves
  const IntSet& getAvailable() const;

private:

  IntSet available_moves_m;

  Player human_m;
  Player computer_m;

  // Throws an exception if the move is not available
  void checkAvailableMoves(int move) throw (invalid_argument);
};


#endif // GAME_H
