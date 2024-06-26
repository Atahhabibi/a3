#ifndef BEST_FIT_MEMORY_MANAGER_H
#define BEST_FIT_MEMORY_MANAGER_H

#include "MemoryManager.h"

class BestFitMemoryManager : public MemoryManager {
public:
    BestFitMemoryManager(int total_size, int unit_size);
    int allocate_mem(int process_id, int num_units) override;
};

#endif
