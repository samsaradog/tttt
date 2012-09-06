// ControllerTest.h

#ifndef CONTROLLER_TEST_H
#define CONTROLLER_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Controller.h"

/* 
 * A test case to exercise
 * features of the Controller Class
 *
 */

class ControllerTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ControllerTest );
//  CPPUNIT_TEST( initialGame );
//  CPPUNIT_TEST( oneMove );
  CPPUNIT_TEST( quitGame );
  CPPUNIT_TEST( badEntry );
  CPPUNIT_TEST_SUITE_END();

public:

  ControllerTest() : controller_m() {};

  ~ControllerTest() {}

  void setUp();
  void tearDown();

protected:
  void initialGame();
  void oneMove();
  void quitGame();
  void badEntry();

private:
  Controller controller_m;
};

#endif // CONTROLLER_TEST_H
