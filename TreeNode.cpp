// file TreeNode.cpp

#include <algorithm>

#include "TreeNode.h"

/*
 * Implementation of a min/max decision tree node with alpha/beta
 * pruning found at:
 * http://www.cs.cornell.edu/courses/cs312/2002sp/lectures/rec21.htm
 *
 */

//---------------------------------------------------------------

IntVector TreeNode::getMoves()
{
  IntVector return_value;

  IntSet available_moves = game_m.getAvailable();

  return_value.resize( available_moves.size() );

  copy ( available_moves.begin(), 
         available_moves.end(), 
         return_value.begin() );

  random_shuffle( return_value.begin(), return_value.end() );

  return return_value;
}

//---------------------------------------------------------------

MinNode::MinNode(const Game& current_game, int min, int max) :
	TreeNode(current_game)
{
  if ( game_m.isLeaf() )
    value_m = game_m.getValue();
  else
    minimax(min, max);
}

//---------------------------------------------------------------

void MinNode::minimax(int min, int max)
{
  IntVector available_moves = getMoves();

  // isLeaf() call in constructor checks whether any more moves are available

  IntVector::const_iterator it = available_moves.begin();

  value_m     = max;
  next_move_m = *it;

  bool keep_looking = true;

  while ( keep_looking && ( available_moves.end() != it ) )
  {
    Game new_game(game_m);

    new_game.addHumanMove(*it);

    MaxNode tree_node(new_game, min, value_m);

    int node_value = tree_node.getValue();

    if ( node_value < value_m )
    {
      value_m     = node_value;
      next_move_m = *it;
    }

    if ( value_m <= min )
    {
      value_m      = min;
      keep_looking = false;
    }

    it++;

  } // end while iterating over available moves

}

//---------------------------------------------------------------

MaxNode::MaxNode(const Game& current_game, int min, int max) :
	TreeNode(current_game)
{
  if ( game_m.isLeaf() )
    value_m = game_m.getValue();
  else
    minimax(min, max);
}

//---------------------------------------------------------------

void MaxNode::minimax(int min, int max)
{
  IntVector available_moves = getMoves();

  // isLeaf() call in constructor checks whether any more moves are available

  IntVector::const_iterator it = available_moves.begin();

  value_m     = min;
  next_move_m = *it;

  bool keep_looking = true;

  while ( keep_looking && ( available_moves.end() != it ) )
  {
    Game new_game(game_m);

    new_game.addComputerMove(*it);

    MinNode new_node(new_game, value_m, max);

    int node_value = new_node.getValue();

    if ( node_value > value_m )
    {
      value_m     = node_value;
      next_move_m = *it;
    }

    if ( value_m >= max )
    {
      value_m      = max;
      keep_looking = false;
    }

    it++;

  } // end while iterating over available moves

}

//---------------------------------------------------------------
