# Creates test program for the TicTacToe game
# file:Makefile

# When running this test, be sure to include ${BASE_PATH}/lib in the
# environment variable LD_LIBRARY_PATH

#CPPUNIT_PATH=${BASE_PATH} 

CFLAGS?= -Wall 
LFLAGS?= 

TESTAPP = tttttest
APP = tttt
MAINOBJ = tttt.o
OBJS =  Game.o FindWinner.o Player.o View.o Controller.o StepFactory.o Steps.o TreeNode.o
TESTOBJS = Main.o GameTest.o FindWinnerTest.o ViewTest.o PlayerTest.o ControllerTest.o StepTest.o TreeNodeTest.o

LIBS = -lstdc++ -ldl 

# don't want to include cppunit in the finished application
TESTLIBS = -lcppunit

all: check $(APP)

$(TESTAPP): $(OBJS) $(TESTOBJS)
	g++ -o $(TESTAPP) $(OBJS) $(TESTOBJS) $(LFLAGS) $(LIBS) $(TESTLIBS)

$(APP): $(OBJS) $(MAINOBJ)
	g++ -o $(APP) $(OBJS) $(MAINOBJ) $(LFLAGS) $(LIBS)

.cpp.o:
	g++ -c $(CFLAGS) $<

tttt.o: tttt.cpp $(OBJS)
Game.o: Game.cpp Game.h Player.h
FindWinner.o: FindWinner.cpp FindWinner.h Game.o Destroyer.h
Player.o: Player.cpp Player.h
View.o: View.cpp View.h Game.o 
Controller.o: Controller.cpp Controller.h Game.o 
StepFactory.o: StepFactory.cpp StepFactory.h Steps.h
Steps.o: Steps.cpp Steps.h Step.h
TreeNode.o: TreeNode.cpp TreeNode.h

GameTest.o: GameTest.cpp GameTest.h Game.o
FindWinnerTest.o: FindWinnerTest.cpp FindWinnerTest.h FindWinner.o
PlayerTest.o: PlayerTest.cpp PlayerTest.h Player.o
ViewTest.o: ViewTest.cpp ViewTest.h View.o Game.o
ControllerTest.o: ControllerTest.cpp ControllerTest.h Controller.o Game.o
StepTest.o: StepTest.cpp StepTest.h Steps.o Game.o
TreeNodeTest.o: TreeNodeTest.cpp TreeNodeTest.h TreeNode.o Game.o

main.o: main.cpp

check: $(TESTAPP)
	@./$(TESTAPP)

clean:
	rm -f *.o $(TESTAPP) $(APP)
