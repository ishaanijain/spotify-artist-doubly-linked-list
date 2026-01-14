
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I../include
SOURCES = artist.cpp artistList.cpp parse_csv.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = hw04

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean