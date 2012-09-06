// file StepTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "StepTest.h"
#include "StepFactory.h"

//CPPUNIT_TEST_SUITE_REGISTRATION( StepTest );

//---------------------------------------------------------------

void StepTest::setUp()
{
  StepFactory the_factory;

  step_m_p = the_factory.getSteps();

  game_m.reset();
}

//---------------------------------------------------------------

void StepTest::tearDown()
{
  if ( NULL != step_m_p )
  {
    delete step_m_p;
    step_m_p = NULL;
  }
}

//---------------------------------------------------------------

// This step checks for a valid user move

void StepTest::testStep1()
{
  game_m.addHumanMove(1);

  string message("");

  bool keep_playing = step_m_p->makeMove(1, message, &game_m);

  CPPUNIT_ASSERT( message == 
                 "Square 1 not available. Please choose another.\n" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

// This step says that if adding the human move means the
// human wins, announce the win and end the game.

void StepTest::testStep2()
{
  game_m.addHumanMove(1);
  game_m.addHumanMove(2);

  string message("");

  bool keep_playing = step_m_p->makeMove(3, message, &game_m);

  CPPUNIT_ASSERT( message == "The Human has won. Congratulations!\n");

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This step says that if there is no move left after the human
// moves, declare a draw and end the game.

void StepTest::testStep3()
{
  for ( int i = 1; i < game_m.getSize(); i++ )
    game_m.addComputerMove(i);

  string message("");

  bool keep_playing = step_m_p->makeMove(game_m.getSize(), message, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n");

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This step checks whether the computer can make a winning move.
// If so, make the move and announce the win.

void StepTest::testStep4()
{
  game_m.addComputerMove(3);
  game_m.addComputerMove(8);

  game_m.addHumanMove(4);

  string message("");

  step_m_p->makeMove(1, message, &game_m);

  bool message_ok = ( ( message == "Computer Wins!\n" ) ||
                      ( message == "Computer is going to win.\n" ) );

  CPPUNIT_ASSERT( message_ok );
}

//---------------------------------------------------------------

// This step is for the computer making a blocking move. This first
// version is when the blocking move is the last available, creating
// a draw

void StepTest::testStep5a()
{
  game_m.addComputerMove(1);
  game_m.addComputerMove(2);
  game_m.addHumanMove(3);

  game_m.addHumanMove(4);
  game_m.addComputerMove(5);
  game_m.addComputerMove(6);

  game_m.addHumanMove(9);

  string message("");

  bool keep_playing = step_m_p->makeMove(8, message, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n" );

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This next case is as above, but the game can continue

void StepTest::testStep5b()
{
  game_m.addComputerMove(3);
  game_m.addComputerMove(8);

  game_m.addHumanMove(2);
  game_m.addHumanMove(7);

  string message("");

  bool keep_playing = step_m_p->makeMove(6, message, &game_m);

  CPPUNIT_ASSERT( message == "" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

// This step is the last in the chain. It has the computer pick
// a square based on its rules. The first case creates a draw.

void StepTest::testLastStepA()
{
  game_m.addComputerMove(2);
  game_m.addHumanMove(3);

  game_m.addComputerMove(4);
  game_m.addComputerMove(5);
  game_m.addHumanMove(6);

  game_m.addHumanMove(8);
  game_m.addComputerMove(9);

  string message("");

  bool keep_playing = step_m_p->makeMove(1, message, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n" );

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This case does not create a draw

void StepTest::testLastStepB()
{
  game_m.addComputerMove(1);

  game_m.addHumanMove(3);

  string message("");

  bool keep_playing = step_m_p->makeMove(6, message, &game_m);

  CPPUNIT_ASSERT( message == "" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------
