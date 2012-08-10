
#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Player.h"
#include "Game.h"

/* 
 * A test case to exercise
 * features of the Player Class
 *
 */

class PlayerTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( PlayerTest );
  CPPUNIT_TEST( checkMoves );
  CPPUNIT_TEST( checkMove );
  CPPUNIT_TEST_SUITE_END();

public:
  PlayerTest() : game_m(),
                 human_m_p(game_m.getHuman()), 
                 computer_m_p(game_m.getComputer())  {};

  ~PlayerTest() {};

  void setUp();
  void tearDown();

protected:
  void checkMoves();
  void checkMove();

private:
  Game   game_m;

  const Player* human_m_p;
  const Player* computer_m_p;
};


#endif // PLAYERTEST_H
