// file ControllerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "ControllerTest.h"
#include "ViewTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ControllerTest );

//---------------------------------------------------------------

void ControllerTest::setUp()
{
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

  string expected_result = ViewTest::makeResult();

  expected_result += controller_m.getMoveMessage();

  CPPUNIT_ASSERT( expected_result == result );
  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

void ControllerTest::oneMove()
{
  string result;

  bool keep_playing = controller_m.addResponse('f', result);

  string expected_result = ViewTest::makeResult();
  expected_result.replace(VT_F_POS, 1, 1, 'O');

  expected_result += controller_m.getMoveMessage();

  CPPUNIT_ASSERT( expected_result == result );
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
