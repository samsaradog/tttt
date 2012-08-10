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


const int BLOCKED_MOVE_COMBINATION_SIZE = 2;

int blockedMoveCombinations[][BLOCKED_MOVE_COMBINATION_SIZE] = {
  { 0, 1 },
  { 0, 2 },
  { 0, 8 },
  { 0, 4 },
  { 0, 7 },
  { 0, 6 },
  { 1, 2 },
  { 1, 8 },
  { 1, 5 },
  { 2, 3 },
  { 2, 4 },
  { 2, 8 },
  { 2, 6 },
  { 3, 8 },
  { 3, 7 },
  { 3, 4 },
  { 4, 5 },
  { 4, 6 },
  { 4, 8 },
  { 5, 8 },
  { 5, 6 },
  { 6, 7 },
  { 6, 8 },
  { 7, 8 },
};

const int BLOCKED_MOVE_COUNT = sizeof(blockedMoveCombinations)/
                              (sizeof(int)*BLOCKED_MOVE_COMBINATION_SIZE);

int notBlockedMoveCombinations[][BLOCKED_MOVE_COMBINATION_SIZE] = {
  { 0, 3 },
  { 0, 5 },
  { 1, 3 },
  { 1, 4 },
  { 1, 6 },
  { 1, 7 },
  { 2, 5 },
  { 2, 7 },
  { 3, 5 },
  { 3, 6 },
  { 4, 7 },
  { 5, 7 },
};

const int NOT_BLOCKED_MOVE_COUNT = sizeof(notBlockedMoveCombinations)/
                                  (sizeof(int)*BLOCKED_MOVE_COMBINATION_SIZE);


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

void FindWinnerTest::makeWinner(void)
{
  game_m.addHumanMove(0);
  game_m.addHumanMove(3);

  int winningMove = finder_m_p->winningMove(&game_m, game_m.getHuman());

  CPPUNIT_ASSERT( 0 > winningMove );

  game_m.addHumanMove(1);
  game_m.addComputerMove(2);

  // 3 would be a winning move for the human, but
  // since the computer is there, it should not be
  // available

  winningMove = finder_m_p->winningMove(&game_m, game_m.getHuman());

  CPPUNIT_ASSERT( 0 > winningMove );

  game_m.addHumanMove(8);
  winningMove = finder_m_p->winningMove(&game_m, game_m.getHuman());

  CPPUNIT_ASSERT( 0 <= winningMove );

  game_m.addHumanMove(winningMove);
  CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getHuman()));
}

//---------------------------------------------------------------

void FindWinnerTest::checkBlockedMoves()
{
  int winningMove = 0;

  for ( int i = 0; i < BLOCKED_MOVE_COUNT; i++ )
  {
    game_m.addHumanMove(blockedMoveCombinations[i][0]);
    game_m.addHumanMove(blockedMoveCombinations[i][1]);

    winningMove = finder_m_p->winningMove(&game_m, game_m.getHuman());

    CPPUNIT_ASSERT( 0 <= winningMove );

    game_m.addHumanMove(winningMove);
    CPPUNIT_ASSERT(finder_m_p->hasWinner(game_m.getHuman()));

    game_m.reset();
  }
}

//---------------------------------------------------------------

void FindWinnerTest::checkNotBlockedMoves()
{
  int winningMove = 0;

  for ( int i = 0; i < NOT_BLOCKED_MOVE_COUNT; i++ )
  {
    game_m.addHumanMove(notBlockedMoveCombinations[i][0]);
    game_m.addHumanMove(notBlockedMoveCombinations[i][1]);

    winningMove = finder_m_p->winningMove(&game_m, game_m.getHuman());

    CPPUNIT_ASSERT( 0 > winningMove );

    game_m.reset();
  }
}

//---------------------------------------------------------------
