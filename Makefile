//souldaher210@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
TARGET = main
TEST_TARGET = test

SRC = Graph.cpp Algorithms.cpp
HEADERS = Graph.h Algorithms.h
MAIN = Main.cpp
TEST = Test.cpp

all: $(TARGET)

$(TARGET): $(MAIN) $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN) $(SRC) -o $(TARGET)

test: $(TEST) $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST) $(SRC) -o $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

run_test: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
