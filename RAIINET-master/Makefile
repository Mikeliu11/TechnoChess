CXX= g++
CXXFLAGS= -std=c++14 -Wall -MMD -Werror=vla
LDFLAGS =  -L/usr/X11/lib -I/usr/X11/include
EXEC= RAIInet
OBJECTS= subject.o player.o board.o square.o ability.o abDownload.o abFirewall.o abStrengthBoost.o abLinkedBoost.o abPolarize.o abScan.o Display.o TextDisplay.o link.o main.o state.o observer.o

DEPENDS= ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}
.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
