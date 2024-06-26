#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <list>


/*
 * Developed by:
 * Name: Atah Habibi
 *   - Username: cssc4466
 * Name: Matthew Press
 *   - Username: cssc4443
 */

class MemoryBlock {
public:
    int start;
    int size;
    int process_id;

    MemoryBlock(int start, int size, int process_id = -1);
};

class MemoryManager {
protected:
    std::list<MemoryBlock> memory_list;
    int total_size;
    int unit_size;
    
public:
    MemoryManager(int total_size, int unit_size);
    virtual int allocate_mem(int process_id, int num_units) = 0;
    int deallocate_mem(int process_id);
    int fragment_count();
};

#endif
