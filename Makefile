CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla 
EXEC = tetris
OBJECTS = board.o level.o level0.o level1.o level2.o i_block.o o_block.o l_block.o s_block.o t_block.o z_block.o j_block.o block.o main.o score.o game.o interpreter.o subject.o graphical_display.o window.o -lX11
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}f

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
	