#ifndef TREE_NODE_H
#define TREE_NODE_H

/* 
 * Virtual base class and inherited node classes for decision tree nodes.
 *
 */

#include <vector>
#include "Game.h"

using namespace std;

typedef vector<int> IntVector;

//---------------------------------------------------------------------

class TreeNode
{
public:
  TreeNode(const Game& currentGame) : game_m(currentGame), 
                                      value_m(0),
                                      next_move_m(-1) {};
  virtual ~TreeNode() {}; 

  int getMove() const { return next_move_m; };

  int getValue() const { return value_m; };

protected:

  Game game_m;

  int value_m;
  int next_move_m;

  virtual void minimax(int min, int max) = 0;

  IntVector getMoves();
};

//---------------------------------------------------------------------

class MaxNode : public TreeNode
{
public:
  MaxNode(const Game& current_game, int min=-1, int max=1);
  virtual ~MaxNode() {};

protected:
  virtual void minimax(int min, int max);
};

//---------------------------------------------------------------------

class MinNode : public TreeNode
{
public:
  MinNode(const Game& current_game, int min=-1, int max=1);
  virtual ~MinNode() {};

protected:
  virtual void minimax(int min, int max);
};

//---------------------------------------------------------------------

#endif // TREE_NODE_H
