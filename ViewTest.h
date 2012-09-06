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

#define VT_ZERO_POS     1
#define VT_ONE_POS      5
#define VT_TWO_POS      9
#define VT_THREE_POS    13
#define VT_FOUR_POS     33
#define VT_FIVE_POS     37
#define VT_SIX_POS      41
#define VT_SEVEN_POS    45
#define VT_EIGHT_POS    65
#define VT_NINE_POS     69
#define VT_A_POS        73
#define VT_B_POS        77
#define VT_C_POS        97
#define VT_D_POS        101
#define VT_E_POS        105
#define VT_F_POS        109


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

  static string makeResult();

protected:
  void showEmpty();
  void showOneMove();

private:
  Game game_m;

  View view_m;

  string result_m;
};

#endif // VIEWTEST_H
