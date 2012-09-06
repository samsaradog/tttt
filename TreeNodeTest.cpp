// file TreeNodeTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "TreeNodeTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION( TreeNodeTest );

//---------------------------------------------------------------

TreeNodeTest::~TreeNodeTest()
{
  tearDown();
}

//---------------------------------------------------------------

void TreeNodeTest::setUp()
{
  game_m.reset();
}

//---------------------------------------------------------------

void TreeNodeTest::tearDown()
{
}

//---------------------------------------------------------------

void TreeNodeTest::minWinLeaf()
{
  for ( int i = 1; i <= 3; i++ )
    game_m.addHumanMove(i);
    
  MinNode current(game_m);

  CPPUNIT_ASSERT( -1 == current.getMove() );
  CPPUNIT_ASSERT( -1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinLeaf()
{
  for ( int i = 1; i <= 3; i++ )
    game_m.addComputerMove(i);
    
  MaxNode current(game_m);

  CPPUNIT_ASSERT( -1 == current.getMove() );
  CPPUNIT_ASSERT(  1 == current.getValue() );

  game_m.reset();

  game_m.addComputerMove(4);
  game_m.addComputerMove(5);
  game_m.addComputerMove(6);

  MaxNode current2(game_m);

  CPPUNIT_ASSERT( -1 == current2.getMove() ); 
  CPPUNIT_ASSERT(  1 == current2.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minDrawLeaf()
{

//  O | X | O
// ----------
//  O | X | X
// ----------
//  X | O | X

  game_m.addComputerMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(3);

  game_m.addComputerMove(4);
  game_m.addHumanMove(5);
  game_m.addHumanMove(6);

  game_m.addHumanMove(7);
  game_m.addComputerMove(8);
  game_m.addHumanMove(9);

  MinNode current(game_m);

  CPPUNIT_ASSERT( -1 == current.getMove() );
  CPPUNIT_ASSERT(  0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawLeaf()
{

//  O | X | O
// ----------
//  O | X | X
// ----------
//  X | O | X

  game_m.addComputerMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(3);

  game_m.addComputerMove(4);
  game_m.addHumanMove(5);
  game_m.addHumanMove(6);

  game_m.addHumanMove(7);
  game_m.addComputerMove(8);
  game_m.addHumanMove(9);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( -1 == current.getMove() );
  CPPUNIT_ASSERT(  0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minWinDepth1()
{

//  X | O | X
// ----------
//  X | O | O
// ----------
//    | X | O

  game_m.addHumanMove(1);
  game_m.addComputerMove(2);
  game_m.addHumanMove(3);

  game_m.addHumanMove(4);
  game_m.addComputerMove(5);
  game_m.addComputerMove(6);

  game_m.addHumanMove(8);
  game_m.addComputerMove(9);

  MinNode current(game_m);

  CPPUNIT_ASSERT(  7 == current.getMove() );
  CPPUNIT_ASSERT( -1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinDepth1()
{

//  O | X | O
// ----------
//  0 | X | X
// ----------
//    | 0 | X

  game_m.addComputerMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(3);

  game_m.addComputerMove(4);
  game_m.addHumanMove(5);
  game_m.addHumanMove(6);

  game_m.addComputerMove(8);
  game_m.addHumanMove(9);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 7 == current.getMove() );
  CPPUNIT_ASSERT( 1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minDrawDepth1()
{

//  O | X | O
// ----------
//  0 | X | X
// ----------
//    | 0 | X

  game_m.addComputerMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(3);

  game_m.addComputerMove(4);
  game_m.addHumanMove(5);
  game_m.addHumanMove(6);

  game_m.addComputerMove(8);
  game_m.addHumanMove(9);

  MinNode current(game_m);

  CPPUNIT_ASSERT( 7 == current.getMove() );
  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth1()
{

//  X | O | X
// ----------
//  X | O | O
// ----------
//    | X | O

  game_m.addHumanMove(1);
  game_m.addComputerMove(2);
  game_m.addHumanMove(3);

  game_m.addHumanMove(4);
  game_m.addComputerMove(5);
  game_m.addComputerMove(6);

  game_m.addHumanMove(8);
  game_m.addComputerMove(9);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 7 == current.getMove() );
  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minLoseDepth2()
{

//    | X |  
// ----------
//  O | O | X
// ----------
//  O | X | O

  game_m.addHumanMove(2);

  game_m.addComputerMove(4);
  game_m.addComputerMove(5);
  game_m.addHumanMove(6);

  game_m.addComputerMove(7);
  game_m.addHumanMove(8);
  game_m.addComputerMove(9);

  MinNode current(game_m);

  int new_move  = current.getMove();

  bool move_result = ( ( 1 == new_move ) || ( 3 == new_move) );

  CPPUNIT_ASSERT( move_result );
  CPPUNIT_ASSERT( 1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxLoseDepth2()
{

//    | O |  
// ----------
//  X | X | O
// ----------
//  X | O | X

  game_m.addComputerMove(2);

  game_m.addHumanMove(4);
  game_m.addHumanMove(5);
  game_m.addComputerMove(6);

  game_m.addHumanMove(7);
  game_m.addComputerMove(8);
  game_m.addHumanMove(9);

  MaxNode current(game_m);

  int new_move  = current.getMove();

  bool move_result = ( ( 1 == new_move ) || ( 3 == new_move) );

  CPPUNIT_ASSERT( move_result );
  CPPUNIT_ASSERT( -1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth5()
{

//    |   |  
// ----------
//  X | X |  
// ----------
//  O |   |  

  game_m.addHumanMove(4);
  game_m.addHumanMove(5);

  game_m.addComputerMove(7);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 6 == current.getMove() );
  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinDepth5()
{

//    | X |  
// ----------
//    | O | O
// ----------
//    |   | X

  // Since the algorithm is only about winning, not winning
  // quickly, the computer could pick several squares and
  // still win. Since the square it picks is random, we
  // can't look for it specifically

  game_m.addHumanMove(2);
  game_m.addHumanMove(9);
  game_m.addComputerMove(5);
  game_m.addComputerMove(6);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinDepth7()
{

//    |   |  
// ----------
//  X | O |  
// ----------
//    |   |  

  game_m.addHumanMove(4);
  game_m.addComputerMove(5);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 1 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth6()
{

//  O | X |  
// ----------
//    | X |  
// ----------
//    |   |  

  game_m.addHumanMove(2);
  game_m.addHumanMove(5);
  game_m.addComputerMove(1);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 0 == current.getValue() );
  CPPUNIT_ASSERT( 8 == current.getMove() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth7()
{

//    | O |  
// ----------
//    | X |  
// ----------
//    |   |  

  game_m.addHumanMove(5);
  game_m.addComputerMove(2);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth8()
{

//    |   |  
// ----------
//    | X |  
// ----------
//    |   |  

  game_m.addHumanMove(5);

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth9()
{

//    |   |  
// ----------
//    |   |  
// ----------
//    |   |  

  MaxNode current(game_m);

  CPPUNIT_ASSERT( 0 == current.getValue() );
}

//---------------------------------------------------------------
