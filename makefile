# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Menu.o Queue.o
SRCS = main.cpp Menu.cpp Queue.cpp
HEADERS = Menu.hpp Queue.hpp

lab7: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o lab7

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o lab7
