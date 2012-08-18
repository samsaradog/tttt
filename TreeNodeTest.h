#ifndef TREE_NODE_TEST_H
#define TREE_NODE_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "TreeNode.h"

/* 
 * A test case to exercise
 * features of the TreeNode Class
 *
 */

class TreeNodeTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( TreeNodeTest );
  CPPUNIT_TEST( minWinLeaf );
  CPPUNIT_TEST( maxWinLeaf );
  CPPUNIT_TEST( minDrawLeaf );
  CPPUNIT_TEST( maxDrawLeaf );
  CPPUNIT_TEST( minWinDepth1 );
  CPPUNIT_TEST( maxWinDepth1 );
  CPPUNIT_TEST( maxWinDepth5 );
  CPPUNIT_TEST( maxWinDepth7 );
  CPPUNIT_TEST( minDrawDepth1 );
  CPPUNIT_TEST( maxDrawDepth1 );
  CPPUNIT_TEST( maxDrawDepth5 );
  CPPUNIT_TEST( maxDrawDepth6 );
  CPPUNIT_TEST( maxDrawDepth7 );
  CPPUNIT_TEST( maxDrawDepth8 );
  CPPUNIT_TEST( maxDrawDepth9 );
  CPPUNIT_TEST( minLoseDepth2 );
  CPPUNIT_TEST( maxLoseDepth2 );
  CPPUNIT_TEST_SUITE_END();

public:
  TreeNodeTest() : game_m() {};

  ~TreeNodeTest();

  void setUp();
  void tearDown();

protected:
  void minWinLeaf();
  void maxWinLeaf();
  void minDrawLeaf();
  void maxDrawLeaf();

  void minWinDepth1();
  void maxWinDepth1();
  void maxWinDepth5();
  void maxWinDepth7();
  void minDrawDepth1();
  void maxDrawDepth1();
  void maxDrawDepth5();
  void maxDrawDepth6();
  void maxDrawDepth7();
  void maxDrawDepth8();
  void maxDrawDepth9();
  void minLoseDepth2();
  void maxLoseDepth2();

private:
  Game      game_m;
};


#endif // TREE_NODE_TEST_H
