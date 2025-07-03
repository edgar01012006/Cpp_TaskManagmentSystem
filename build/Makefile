CXX = g++
CXXFLAGS = -std=c++17 -I../include -I../googletest/googletest/include -pthread
LDFLAGS = -L../googletest/build/lib -lgtest -lgtest_main

SRC_DIR = ../src
TEST_DIR = ../tests

SRC_FILES = $(SRC_DIR)/Task.cpp $(SRC_DIR)/User.cpp $(SRC_DIR)/TaskManager.cpp
TEST_FILES = $(TEST_DIR)/test_manager.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o) $(TEST_FILES:.cpp=.o)

TARGET = test_manager.exe

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)