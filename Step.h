#ifndef STEP_H
#define STEP_H

/* 
 * Virtual base class for steps to take processing a user move. Based
 * on Chain of Responsibility pattern.
 *
 */

#include "Player.h"
#include "Game.h"
#include "FindWinner.h"

using namespace std;

class Step
{

public:
  Step(Step* next_p) : next_m_p(next_p) {};
  virtual ~Step() 
  { 
    if ( NULL != next_m_p )
      delete next_m_p;
  };

  virtual bool makeMove(int human_move,
                        string& message, 
                        Game*   game_p) = 0;

protected:

  static FindWinner*	finder_m_p;
  Step* next_m_p;
};


#endif // STEP_H
