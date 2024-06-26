#ifndef FIRST_FIT_MEMORY_MANAGER_H
#define FIRST_FIT_MEMORY_MANAGER_H

#include "MemoryManager.h"

class FirstFitMemoryManager : public MemoryManager {
public:
    FirstFitMemoryManager(int total_size, int unit_size);
    int allocate_mem(int process_id, int num_units) override;
};

#endif
