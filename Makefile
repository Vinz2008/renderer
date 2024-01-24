CXX = g++

CXXFLAGS = -c -g -Wall
LDFLAGS = -lSDL2 -lm

SRCDIR = src

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all: renderer

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

renderer: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f renderer src/*.o

run:
	./renderer