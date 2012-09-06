// file ViewTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "ViewTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ViewTest );

//---------------------------------------------------------------

void ViewTest::setUp()
{
  result_m  = makeResult();

  game_m.reset();
}

//---------------------------------------------------------------

void ViewTest::tearDown()
{
}

//---------------------------------------------------------------

void ViewTest::showEmpty()
{
  string result = view_m.show(game_m.getHuman(), 
                              game_m.getComputer(), 
                              &game_m);

  CPPUNIT_ASSERT( result_m == result );
}

//---------------------------------------------------------------

void ViewTest::showOneMove()
{
  game_m.addHumanMove(6);
  game_m.addComputerMove(8);
  game_m.addComputerMove(15);

  result_m.replace(VT_SIX_POS,   1, 1, 'X');
  result_m.replace(VT_EIGHT_POS, 1, 1, 'O');
  result_m.replace(VT_F_POS,     1, 1, 'O');

  string result = view_m.show(game_m.getHuman(), 
                              game_m.getComputer(), 
                              &game_m);

  CPPUNIT_ASSERT( result_m == result );
}

//---------------------------------------------------------------

string ViewTest::makeResult()
{
  string return_value;

  return_value  = " 0 | 1 | 2 | 3 \n";
  return_value += "---------------\n";
  return_value += " 4 | 5 | 6 | 7 \n";
  return_value += "---------------\n";
  return_value += " 8 | 9 | A | B \n";
  return_value += "---------------\n";
  return_value += " C | D | E | F \n";

  return return_value;
}

//---------------------------------------------------------------
