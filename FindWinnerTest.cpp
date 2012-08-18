// file FindWinnerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinnerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( FindWinnerTest );

const int WINNING_MOVE_SIZE = 3;

int winningMoveCombinations[][WINNING_MOVE_SIZE] = {
  { 0, 1, 2 },
  { 7, 8, 3 },
  { 6, 5, 4 },
  { 0, 7, 6 },
  { 1, 8, 5 },
  { 2, 3, 4 },
  { 0, 8, 4 },
  { 2, 8, 6 },
};

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
  game_m.addHumanMove(0);
  game_m.addHumanMove(1);
  game_m.addComputerMove(6);
  game_m.addComputerMove(8);
  game_m.addComputerMove(3);

  CPPUNIT_ASSERT(!finder_m_p->hasWinner(game_m.getHuman()));

  game_m.addHumanMove(2);

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
  game_m.addComputerMove(0);
  game_m.addComputerMove(1);
  game_m.addHumanMove(3);
  game_m.addHumanMove(8);
  game_m.addHumanMove(4);

  CPPUNIT_ASSERT(!finder_m_p->hasWinner(game_m.getComputer()));

  game_m.addComputerMove(2);

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
