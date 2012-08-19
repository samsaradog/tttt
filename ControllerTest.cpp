// file ControllerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "ControllerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ControllerTest );

#define VT_ONE_POS 	1
#define VT_TWO_POS 	5
#define VT_THREE_POS	9
#define VT_FOUR_POS	25
#define VT_FIVE_POS	29
#define VT_SIX_POS 	33
#define VT_SEVEN_POS 	49
#define VT_EIGHT_POS 	53
#define VT_NINE_POS	57

//---------------------------------------------------------------

void ControllerTest::setUp()
{
  result_m.clear();

  result_m  = " 1 | 2 | 3 \n";
  result_m += "-----------\n";
  result_m += " 4 | 5 | 6 \n";
  result_m += "-----------\n";
  result_m += " 7 | 8 | 9 \n";
}

//---------------------------------------------------------------

void ControllerTest::tearDown()
{
}

//---------------------------------------------------------------

void ControllerTest::initialGame()
{
  string result;

  bool keep_playing = controller_m.addResponse('y', result);

  result_m += controller_m.getMoveMessage();

  CPPUNIT_ASSERT( result_m == result );
  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

void ControllerTest::quitGame()
{
  string result;

  bool keep_playing = controller_m.addResponse('q', result);

  CPPUNIT_ASSERT( controller_m.getByeMessage() == result );
  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

void ControllerTest::badEntry()
{
  string result;

  bool keep_playing = controller_m.addResponse('%', result);

  string expected_result = controller_m.getBadEntryMessage() +
                           controller_m.getMoveMessage();

  CPPUNIT_ASSERT( expected_result == result );
  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------
