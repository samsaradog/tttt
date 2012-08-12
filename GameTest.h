
#ifndef GAMETEST_H
#define GAMETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Game.h"

/* 
 * A test case to exercise
 * features of the Game Class
 *
 */

class GameTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( GameTest );
  CPPUNIT_TEST( addMoves );
//  CPPUNIT_TEST( checkMoves );
  CPPUNIT_TEST( isMoveAvailable );
  CPPUNIT_TEST( availableMoves );
  CPPUNIT_TEST( equalityTestA );
  CPPUNIT_TEST( equalityTestB );
  CPPUNIT_TEST( isLeafTest );
  CPPUNIT_TEST( isNotLeafTest );
  CPPUNIT_TEST( nodeValueWin );
  CPPUNIT_TEST( nodeValueLose );
  CPPUNIT_TEST( nodeValueDraw );
  CPPUNIT_TEST_SUITE_END();

public:

  GameTest() : game_m()  {};

  ~GameTest()
  {
  }

  void setUp();
  void tearDown();

protected:
  void addMoves();
//  void checkMoves();
  void isMoveAvailable();
  void availableMoves();
  void equalityTestA();
  void equalityTestB();
  void isLeafTest();
  void isNotLeafTest();
  void nodeValueWin();
  void nodeValueLose();
  void nodeValueDraw();

private:
  Game game_m;

  void buildDrawGame();

};


#endif // GAMETEST_H
