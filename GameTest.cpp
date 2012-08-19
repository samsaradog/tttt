// file GameTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "GameTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( GameTest );

//---------------------------------------------------------------

void GameTest::setUp()
{
  game_m.reset();
}

//---------------------------------------------------------------

void GameTest::tearDown()
{
}

//---------------------------------------------------------------

void GameTest::addMoves()
{
  CPPUNIT_ASSERT_NO_THROW(game_m.addHumanMove(1));

  CPPUNIT_ASSERT_THROW(game_m.addHumanMove(1), invalid_argument);
  CPPUNIT_ASSERT_THROW(game_m.addComputerMove(1), invalid_argument);

  CPPUNIT_ASSERT_NO_THROW(game_m.addComputerMove(2));

  // Try some moves not on the grid
  CPPUNIT_ASSERT_THROW(game_m.addComputerMove(-1), invalid_argument);
  CPPUNIT_ASSERT_THROW(game_m.addComputerMove(10), invalid_argument);

  // Reset the game and try adding the same move as above
  CPPUNIT_ASSERT_NO_THROW(game_m.reset());
  CPPUNIT_ASSERT_NO_THROW(game_m.addHumanMove(1));
}

//---------------------------------------------------------------

void GameTest::isMoveAvailable(void)
{
  CPPUNIT_ASSERT(game_m.moveAvailable());

  const int game_size = game_m.getSize();

  for ( int i = 1; i < game_size; i++ )
    game_m.addHumanMove(i);

  CPPUNIT_ASSERT(game_m.moveAvailable());
  CPPUNIT_ASSERT(game_m.moveAvailable(game_size));

  game_m.addComputerMove(game_size);

  CPPUNIT_ASSERT(!game_m.moveAvailable());

}

//---------------------------------------------------------------

void GameTest::availableMoves(void)
{
  for ( int i = 2; i < game_m.getSize(); i += 2 )
    game_m.addHumanMove(i);

  IntSet a_set = game_m.getAvailable();

  IntSet::const_iterator it = a_set.begin();

  int move = 1;

  while ( a_set.end() != it )
  {
    CPPUNIT_ASSERT( move == *it );
    move += 2;
    it++;
  }
}

//---------------------------------------------------------------

void GameTest::equalityTestA(void)
{
  game_m.addHumanMove(1);

  Game another_game(game_m);  

  CPPUNIT_ASSERT( game_m == another_game );

  CPPUNIT_ASSERT( !game_m.moveAvailable(1) );
}

//---------------------------------------------------------------

void GameTest::equalityTestB(void)
{
  game_m.addComputerMove(3);

  Game another_game = game_m;

  CPPUNIT_ASSERT( game_m == another_game );

  CPPUNIT_ASSERT( !game_m.moveAvailable(3) );
}

//---------------------------------------------------------------

void GameTest::isLeafTest(void)
{
  // build a draw game
  buildDrawGame();

  CPPUNIT_ASSERT( game_m.isLeaf() );

  game_m.reset();

  // Now a computer win

  for ( int i = 1; i < 4; i++ )
    game_m.addComputerMove(i);

  CPPUNIT_ASSERT( game_m.isLeaf() );

  game_m.reset();

  // Now a human win

  for ( int i = 1; i < 4; i++ )
    game_m.addHumanMove(i);

  CPPUNIT_ASSERT( game_m.isLeaf() );
}

//---------------------------------------------------------------

void GameTest::isNotLeafTest()
{
  // start with an empty game

  CPPUNIT_ASSERT( !game_m.isLeaf() );

  // add a few, but not enough to make a winner or draw
  
  game_m.addHumanMove(1);
  game_m.addHumanMove(3);

  game_m.addComputerMove(2);
  game_m.addComputerMove(5);

  CPPUNIT_ASSERT( !game_m.isLeaf() );
}

//---------------------------------------------------------------

void GameTest::nodeValueWin()
{
  for ( int i = 1; i < 4; i++ )
    game_m.addComputerMove(i);

  CPPUNIT_ASSERT( 1 == game_m.getValue() );
}

//---------------------------------------------------------------

void GameTest::nodeValueLose()
{
  for ( int i = 1; i < 4; i++ )
    game_m.addHumanMove(i);

  CPPUNIT_ASSERT( -1 == game_m.getValue() );
}

//---------------------------------------------------------------

void GameTest::nodeValueDraw()
{
  // Empty game or game with no winner should also show up as a draw value

  CPPUNIT_ASSERT( 0 == game_m.getValue() );

  buildDrawGame();

  CPPUNIT_ASSERT( 0 == game_m.getValue() );
}

//---------------------------------------------------------------

void GameTest::buildDrawGame()
{
  game_m.addHumanMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(3);

  game_m.addComputerMove(4);
  game_m.addComputerMove(5);
  game_m.addHumanMove(6);

  game_m.addHumanMove(7);
  game_m.addHumanMove(8);
  game_m.addComputerMove(9);
}

//---------------------------------------------------------------
