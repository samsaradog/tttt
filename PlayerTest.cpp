// file PlayerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "PlayerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( PlayerTest );

//---------------------------------------------------------------

void PlayerTest::setUp()
{
  game_m.reset();
}

//---------------------------------------------------------------

void PlayerTest::tearDown()
{
}

//---------------------------------------------------------------

void PlayerTest::checkMoves()
{
  // For this test, we want to make some moves for the human
  // and computer and then send a set of moves to the players
  // to find if they are present

  for ( int i = 0; i < 4; i++ )
    game_m.addHumanMove(i);

  IntSet moves;
  moves.insert(1);
  moves.insert(3);
  moves.insert(6);

  CPPUNIT_ASSERT(!human_m_p->hasMoved(moves));

  game_m.addHumanMove(6);

  CPPUNIT_ASSERT(human_m_p->hasMoved(moves));

  CPPUNIT_ASSERT(!computer_m_p->hasMoved(moves));

  // Reset the game and add some computer moves

  game_m.reset();

  for ( int i = 3; i < 7; i++ )
    game_m.addComputerMove(i);

  CPPUNIT_ASSERT(!computer_m_p->hasMoved(moves));

  game_m.addComputerMove(1);

  CPPUNIT_ASSERT(computer_m_p->hasMoved(moves));
}

//---------------------------------------------------------------

void PlayerTest::checkMove()
{
  for ( int move = 0; move < 9; move++ )
  {

    game_m.addHumanMove(move);
    CPPUNIT_ASSERT( human_m_p->hasMoved(move) );

    game_m.reset();
  }
}

//---------------------------------------------------------------
