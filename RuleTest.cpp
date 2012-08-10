// file RuleTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "RuleTest.h"
#include "RuleFactory.h"

CPPUNIT_TEST_SUITE_REGISTRATION( RuleTest );

//---------------------------------------------------------------

void RuleTest::setUp()
{
  RuleFactory the_factory;

  rule_m_p = the_factory.getRules();

  game_m.reset();
}

//---------------------------------------------------------------

void RuleTest::tearDown()
{
  if ( NULL != rule_m_p )
  {
    delete rule_m_p;
    rule_m_p = NULL;
  }
}

//---------------------------------------------------------------

// This rule says if there is one square left, pick it.

void RuleTest::testRule1()
{
  for ( int i = 0; i < 3; i++ )
    game_m.addHumanMove(i);

  for ( int i = 4; i < 9; i++ )
    game_m.addComputerMove(i);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 3 == move );
}

//---------------------------------------------------------------

// This rule says that if the center square is not picked, pick it

void RuleTest::testRule2()
{
  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 8 == move );
}

//---------------------------------------------------------------

// This rule says that if the center square is the only one taken
// by the human, pick an even square.

void RuleTest::testRule3()
{
  game_m.addHumanMove(8);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);
  
  CPPUNIT_ASSERT( 0 == (move % 2) );
}

//---------------------------------------------------------------

// This rule says if the if computer has the center square and human 
// has one other square, move in square ((human + 3) mod 8).
// This test has the human making a move to an even square

void RuleTest::testRule4Odd()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(6);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);
  
  CPPUNIT_ASSERT( 1 == move );
}

//---------------------------------------------------------------

// This test is as above but has the human making a move to an odd square

void RuleTest::testRule4Even()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(5);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);
  
  CPPUNIT_ASSERT( 0 == move );
}
//---------------------------------------------------------------

// This test is for when the computer has picked the center square, and
// the human has picked two even squares, but not created a blocking
// situation. This first case is when the human has squares 0 and 4

void RuleTest::testRule5a()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(0);
  game_m.addHumanMove(4);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 1 == (move % 2)  );
}

//---------------------------------------------------------------

// This next case is as above, but the human has 2 and 6

void RuleTest::testRule5b()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(2);
  game_m.addHumanMove(6);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 1 == (move % 2)  );
}

//---------------------------------------------------------------

// This test is where the computer has the center, and the human 
// has an odd and an even. The computer has to pick the right odd square

void RuleTest::testRule6a()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(2);
  game_m.addHumanMove(5);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 7 == move );
}

//---------------------------------------------------------------

// Same as above but rotated around the grid

void RuleTest::testRule6b()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(6);
  game_m.addHumanMove(1);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 3 == move );
}

//---------------------------------------------------------------

// These next two are mirror images of the first two

void RuleTest::testRule6c()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(2);
  game_m.addHumanMove(7);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 5 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule6d()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(6);
  game_m.addHumanMove(3);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 1 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule6e()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(0);
  game_m.addHumanMove(5);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 3 == move );
}

//---------------------------------------------------------------

// Human has 9 and a corner. Computer has the opposite corner.
// Computer should pick two more than the computer's move

void RuleTest::testRule7a()
{
  game_m.addHumanMove(8);
  game_m.addHumanMove(0);
  game_m.addComputerMove(4);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 6 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule7b()
{
  game_m.addHumanMove(8);
  game_m.addHumanMove(2);
  game_m.addComputerMove(6);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 0 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule7c()
{
  game_m.addHumanMove(8);
  game_m.addHumanMove(4);
  game_m.addComputerMove(0);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 2 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule7d()
{
  game_m.addHumanMove(8);
  game_m.addHumanMove(6);
  game_m.addComputerMove(2);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 4 == move );
}

//---------------------------------------------------------------

// If the computer has 8, and the human has two odd squares,
// the computer needs to pick the right square, otherwise the 
// human can set up a win.

void RuleTest::testRule8a()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(1);
  game_m.addHumanMove(3);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 4 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule8b()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(1);
  game_m.addHumanMove(7);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 0 == move );
}

//---------------------------------------------------------------

// In this and the next case, the human moves are on the opposite
// sides of the center

void RuleTest::testRule8c()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(1);
  game_m.addHumanMove(5);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 6 == move );
}

//---------------------------------------------------------------

void RuleTest::testRule8d()
{
  game_m.addComputerMove(8);
  game_m.addHumanMove(3);
  game_m.addHumanMove(7);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);

  CPPUNIT_ASSERT( 0 == move );
}

//---------------------------------------------------------------

// This rule is the last in the chain. It just says pick any open
// square.

void RuleTest::testLastRule()
{
  int a_moves[] = {3, 4, 5, 6, 7};

  IntSet some_moves(a_moves, a_moves+5);

  game_m.addComputerMove(0);
  game_m.addHumanMove(1);
  game_m.addComputerMove(2);
  game_m.addHumanMove(8);

  int move = rule_m_p->getMove(game_m.getHuman(), 
                               game_m.getComputer(), 
                               &game_m);
  
  CPPUNIT_ASSERT( some_moves.count(move) );
}

//---------------------------------------------------------------
