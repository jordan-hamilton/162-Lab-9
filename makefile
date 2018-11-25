# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Menu.o stackSim.o queueSim.o
SRCS = main.cpp Menu.cpp stackSim.cpp queueSim.cpp
HEADERS = Menu.hpp stackSim.hpp queueSim.hpp

lab9: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o lab9

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o lab9
