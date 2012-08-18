// ViewTest.h

#ifndef VIEWTEST_H
#define VIEWTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "View.h"

/* 
 * A test case to exercise
 * features of the View Class
 *
 */

class ViewTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ViewTest );
  CPPUNIT_TEST( showEmpty );
  CPPUNIT_TEST( showOneMove );
  CPPUNIT_TEST_SUITE_END();

public:

  ViewTest() : game_m(),
               view_m(),
               result_m("") {};

  ~ViewTest()
  {
    tearDown();
  }

  void setUp();
  void tearDown();

protected:
  void showEmpty();
  void showOneMove();

private:
  Game game_m;

  View view_m;

  string result_m;
};

#endif // VIEWTEST_H
