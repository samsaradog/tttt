
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

private:
  Game game_m;

};


#endif // GAMETEST_H
