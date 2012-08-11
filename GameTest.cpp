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

  for ( int i = 0; i < 8; i++ )
    game_m.addHumanMove(i);

  CPPUNIT_ASSERT(game_m.moveAvailable());
  CPPUNIT_ASSERT(game_m.moveAvailable(8));

  game_m.addComputerMove(8);

  CPPUNIT_ASSERT(!game_m.moveAvailable());

}

//---------------------------------------------------------------

void GameTest::availableMoves(void)
{
  for ( int i = 0; i < 9; i += 2 )
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
