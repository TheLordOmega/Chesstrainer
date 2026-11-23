CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

src/chess: src/*.cpp src/*.h
	$(CXX) $(CXXFLAGS) src/*.cpp -o src/chess

tests/rulest: tests/rulest.cpp src/*.cpp src/*.h
	$(CXX) $(CXXFLAGS) tests/rulest.cpp $(filter-out src/main.cpp,$(wildcard src/*.cpp)) -o tests/rulest

test: tests/rulest
	./tests/rulest

run: src/chess
	cd src && ./chess

clean:
	rm -f src/chess tests/rulest

.PHONY: test run clean