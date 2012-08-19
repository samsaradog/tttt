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

  // Returns whether a player has won or the game is a draw
  bool isLeaf() const;

  // Returns value of the game
  int getValue();

  // Returns number of possible moves in the game
  int getSize() const { return game_size_m; };

private:

  IntSet available_moves_m;

  Player human_m;
  Player computer_m;

  int game_value_m;

  // Throws an exception if the move is not available
  void checkAvailableMoves(int move) throw (invalid_argument);

  const static int game_size_m = 9;
};


#endif // GAME_H
