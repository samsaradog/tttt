// file TreeNodeTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "TreeNodeTest.h"

#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION( TreeNodeTest );

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
  if ( NULL != current_m_p )
  {
    delete current_m_p;
    current_m_p = NULL;
  }
}

//---------------------------------------------------------------

void TreeNodeTest::minWinLeaf()
{
  for ( int i = 0; i < 9; i++ )
    game_m.addHumanMove(i);
    
  current_m_p = new MinNode(game_m);

  CPPUNIT_ASSERT( -1 == current_m_p->getMove() );
  CPPUNIT_ASSERT( -1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinLeaf()
{
  for ( int i = 0; i < 9; i++ )
    game_m.addComputerMove(i);
    
  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( -1 == current_m_p->getMove() );
  CPPUNIT_ASSERT(  1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minDrawLeaf()
{

//  O | X | O
// ----------
//  O | X | X
// ----------
//  X | O | X

  game_m.addComputerMove(0);
  game_m.addComputerMove(2);
  game_m.addComputerMove(5);
  game_m.addComputerMove(7);

  game_m.addHumanMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(4);
  game_m.addHumanMove(6);
  game_m.addHumanMove(8);

  current_m_p = new MinNode(game_m);

  CPPUNIT_ASSERT( -1 == current_m_p->getMove() );
  CPPUNIT_ASSERT(  0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawLeaf()
{

//  O | X | O
// ----------
//  O | X | X
// ----------
//  X | O | X

  game_m.addComputerMove(0);
  game_m.addComputerMove(2);
  game_m.addComputerMove(5);
  game_m.addComputerMove(7);

  game_m.addHumanMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(4);
  game_m.addHumanMove(6);
  game_m.addHumanMove(8);

  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( -1 == current_m_p->getMove() );
  CPPUNIT_ASSERT(  0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minWinDepth1()
{

//  X | O | X
// ----------
//  X | O | O
// ----------
//    | X | O

  game_m.addHumanMove(0);
  game_m.addHumanMove(2);
  game_m.addHumanMove(5);
  game_m.addHumanMove(7);

  game_m.addComputerMove(1);
  game_m.addComputerMove(3);
  game_m.addComputerMove(4);
  game_m.addComputerMove(8);

  current_m_p = new MinNode(game_m);

  CPPUNIT_ASSERT(  6 == current_m_p->getMove() );
  CPPUNIT_ASSERT( -1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinDepth1()
{

//  O | X | O
// ----------
//  0 | X | X
// ----------
//    | 0 | X

  game_m.addComputerMove(0);
  game_m.addComputerMove(2);
  game_m.addComputerMove(5);
  game_m.addComputerMove(7);

  game_m.addHumanMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(4);
  game_m.addHumanMove(8);

  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( 6 == current_m_p->getMove() );
  CPPUNIT_ASSERT( 1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minDrawDepth1()
{

//  O | X | O
// ----------
//  0 | X | X
// ----------
//    | 0 | X

  game_m.addComputerMove(0);
  game_m.addComputerMove(2);
  game_m.addComputerMove(5);
  game_m.addComputerMove(7);

  game_m.addHumanMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(4);
  game_m.addHumanMove(8);

  current_m_p = new MinNode(game_m);

  CPPUNIT_ASSERT( 6 == current_m_p->getMove() );
  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth1()
{

//  X | O | X
// ----------
//  X | O | O
// ----------
//    | X | O

  game_m.addHumanMove(0);
  game_m.addHumanMove(2);
  game_m.addHumanMove(5);
  game_m.addHumanMove(7);

  game_m.addComputerMove(1);
  game_m.addComputerMove(3);
  game_m.addComputerMove(4);
  game_m.addComputerMove(8);

  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( 6 == current_m_p->getMove() );
  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::minLoseDepth2()
{

//    | X |  
// ----------
//  O | O | X
// ----------
//  O | X | O

  game_m.addHumanMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(5);

  game_m.addComputerMove(4);
  game_m.addComputerMove(6);
  game_m.addComputerMove(7);
  game_m.addComputerMove(8);

  current_m_p = new MinNode(game_m);

  int new_move  = current_m_p->getMove();

  bool move_result = ( ( 0 == new_move ) || ( 2 == new_move) );

  CPPUNIT_ASSERT( move_result );
  CPPUNIT_ASSERT( 1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxLoseDepth2()
{

//    | O |  
// ----------
//  X | X | O
// ----------
//  X | O | X

  game_m.addComputerMove(1);
  game_m.addComputerMove(3);
  game_m.addComputerMove(5);

  game_m.addHumanMove(4);
  game_m.addHumanMove(6);
  game_m.addHumanMove(7);
  game_m.addHumanMove(8);

  current_m_p = new MaxNode(game_m);

  int new_move  = current_m_p->getMove();

  bool move_result = ( ( 0 == new_move ) || ( 2 == new_move) );

  CPPUNIT_ASSERT( move_result );
  CPPUNIT_ASSERT( -1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth5()
{

//    |   |  
// ----------
//  X | X |  
// ----------
//  O |   |  

  game_m.addHumanMove(7);
  game_m.addHumanMove(8);

  game_m.addComputerMove(6);

  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( 3 == current_m_p->getMove() );
  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxWinDepth7()
{

//    |   |  
// ----------
//  X | O |  
// ----------
//    |   |  

  game_m.addHumanMove(7);
  game_m.addComputerMove(8);

  current_m_p = new MaxNode(game_m);

  CPPUNIT_ASSERT( 1 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth7()
{

//    | O |  
// ----------
//    | X |  
// ----------
//    |   |  

  game_m.addHumanMove(8);
  game_m.addComputerMove(1);

  current_m_p = new MaxNode(game_m);

cout << endl << "next move is " << current_m_p->getMove() << endl;
cout << endl << "value is     " << current_m_p->getValue() << endl;

  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth8()
{

//    |   |  
// ----------
//    | X |  
// ----------
//    |   |  

  game_m.addHumanMove(8);

  current_m_p = new MaxNode(game_m);

cout << endl << "next move is " << current_m_p->getMove() << endl;
cout << endl << "value is     " << current_m_p->getValue() << endl;

  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------

void TreeNodeTest::maxDrawDepth9()
{

//    |   |  
// ----------
//    |   |  
// ----------
//    |   |  

  current_m_p = new MaxNode(game_m);

cout << endl << "next move is " << current_m_p->getMove() << endl;
cout << endl << "value is     " << current_m_p->getValue() << endl;

  CPPUNIT_ASSERT( 0 == current_m_p->getValue() );
}

//---------------------------------------------------------------
