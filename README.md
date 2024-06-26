# Memory Allocation/Deallocation Simulation

## Developed by:
- Name: Atah Habibi
  - Username: cssc4466
- Name: Matthew Press
  - Username: cssc4443

## Class Information:
- Class: CS 480, Summer 2024

## File Manifest
- main.cpp: Contains the implementation of the main simulation.
- MemoryManager.h: Header file for the MemoryManager class.
- MemoryManager.cpp: Implementation file for the MemoryManager class.
- FirstFitMemoryManager.h: Header file for the First Fit Memory Manager class.
- FirstFitMemoryManager.cpp: Implementation file for the First Fit Memory Manager class.
- BestFitMemoryManager.h: Header file for the Best Fit Memory Manager class.
- BestFitMemoryManager.cpp: Implementation file for the Best Fit Memory Manager class.
- RequestGenerator.h: Header file for the Request Generator class.
- RequestGenerator.cpp: Implementation file for the Request Generator class.
- Statistics.h: Header file for the Statistics class.
- Statistics.cpp: Implementation file for the Statistics class.
- Makefile: File to compile and link the project.
- README.txt: This README file.

## Compile Instructions
1. Navigate to the project directory.
2. Run `make` to compile the project. This will generate an executable named `sim`.

## Operating Instructions
1. Ensure the executable `sim` is in the current directory.
2. Run `./sim` to execute the simulation.
3. The program will generate 10,000 memory allocation and deallocation requests and calculate performance statistics for both the first fit and best fit memory allocation techniques.

## Design Decisions
- Used a linked list to keep track of memory blocks, allowing dynamic memory management.
- Implemented both first fit and best fit memory allocation strategies to compare their performance.
- Memory is divided into units of 2 KB each, simulating realistic memory allocation scenarios.
- Allocated memory requests between 3 and 10 units to simulate various process memory requirements.

## Extra Features
- Implemented a fragment count function to track memory fragmentation.
- Randomized request generation to simulate real-world scenarios.

## Known Deficiencies or Bugs
- The simulation assumes that memory is requested only once per process, and the entire memory is deallocated on a deallocation request. This simplification may not fully represent complex real-world memory management.
- Random request generation might not cover all edge cases for allocation and deallocation.

## Lessons Learned
- Implementing different memory allocation techniques provides insight into their performance and efficiency.
- Managing dynamic memory with linked lists requires careful handling of pointers and memory blocks.
- Simulating large-scale memory operations helps understand the impact of fragmentation and allocation strategies on system performance.
