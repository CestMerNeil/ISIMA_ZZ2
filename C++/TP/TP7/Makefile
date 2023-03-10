SRC=ListeMotsTries.cpp tests.cpp main.cpp
EXE=tp7
CXX=g++
CXXFLAGS+=-Wall -Wextra -MMD -g -Wfatal-errors -std=c++14
LDFLAGS= 

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)