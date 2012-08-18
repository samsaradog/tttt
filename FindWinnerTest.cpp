// file FindWinnerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinnerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( FindWinnerTest );

const int WINNING_MOVE_SIZE = 3;

int winningMoveCombinations[][WINNING_MOVE_SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
        { 1, 4, 7 },
        { 2, 5, 8 },
        { 3, 6, 9 },
        { 1, 5, 9 },
        { 3, 5, 7 }  };

const int WINNING_MOVE_COUNT = sizeof(winningMoveCombinations)/
                              (sizeof(int)*WINNING_MOVE_SIZE);

//---------------------------------------------------------------

void FindWinnerTest::setUp()
{
  game_m.reset();
}

//---------------------------------------------------------------

void FindWinnerTest::tearDown()
{
}

//---------------------------------------------------------------

void FindWinnerTest::humanWinner()
{
  game_m.addHumanMove(1);
  game_m.addHumanMove(2);
  game_m.addComputerMove(6);
  game_m.addComputerMove(7);
  game_m.addComputerMove(9);

  CPPUNIT_ASSERT(!finder_m_p->hasWinner(game_m.getHuman()));

  game_m.addHumanMove(3);

  CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getHuman()));
}

//---------------------------------------------------------------

void FindWinnerTest::allHumanWinners()
{
  for (int i = 0; i < WINNING_MOVE_COUNT; i++)
  {
    game_m.reset();

    for ( int j = 0; j < WINNING_MOVE_SIZE; j++ )
      game_m.addHumanMove(winningMoveCombinations[i][j]);

    CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getHuman()));
  }
}

//---------------------------------------------------------------

void FindWinnerTest::computerWinner()
{
  game_m.addComputerMove(1);
  game_m.addComputerMove(2);
  game_m.addHumanMove(6);
  game_m.addHumanMove(7);
  game_m.addHumanMove(9);

  CPPUNIT_ASSERT(!finder_m_p->hasWinner(game_m.getComputer()));

  game_m.addComputerMove(3);

  CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getComputer()));
}

//---------------------------------------------------------------

void FindWinnerTest::allComputerWinners()
{
  for (int i = 0; i < WINNING_MOVE_COUNT; i++)
  {
    game_m.reset();

    for ( int j = 0; j < WINNING_MOVE_SIZE; j++ )
      game_m.addComputerMove(winningMoveCombinations[i][j]);

    CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getComputer()));
  }
}

//---------------------------------------------------------------
