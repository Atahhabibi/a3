CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = sim

all: $(TARGET)

$(TARGET): main.o MemoryManager.o FirstFitMemoryManager.o BestFitMemoryManager.o RequestGenerator.o Statistics.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o MemoryManager.o FirstFitMemoryManager.o BestFitMemoryManager.o RequestGenerator.o Statistics.o

main.o: main.cpp MemoryManager.h FirstFitMemoryManager.h BestFitMemoryManager.h RequestGenerator.h Statistics.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MemoryManager.o: MemoryManager.cpp MemoryManager.h
	$(CXX) $(CXXFLAGS) -c MemoryManager.cpp

FirstFitMemoryManager.o: FirstFitMemoryManager.cpp FirstFitMemoryManager.h MemoryManager.h
	$(CXX) $(CXXFLAGS) -c FirstFitMemoryManager.cpp

BestFitMemoryManager.o: BestFitMemoryManager.cpp BestFitMemoryManager.h MemoryManager.h
	$(CXX) $(CXXFLAGS) -c BestFitMemoryManager.cpp

RequestGenerator.o: RequestGenerator.cpp RequestGenerator.h
	$(CXX) $(CXXFLAGS) -c RequestGenerator.cpp

Statistics.o: Statistics.cpp Statistics.h
	$(CXX) $(CXXFLAGS) -c Statistics.cpp

clean:
	rm -f *.o $(TARGET)