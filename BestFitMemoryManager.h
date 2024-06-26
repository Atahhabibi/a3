#ifndef BEST_FIT_MEMORY_MANAGER_H
#define BEST_FIT_MEMORY_MANAGER_H

#include "MemoryManager.h"

/*
 * Developed by:
 * Name: Atah Habibi
 *   - Username: cssc4466
 * Name: Matthew Press
 *   - Username: cssc4443
 */

class BestFitMemoryManager : public MemoryManager {
public:
    BestFitMemoryManager(int total_size, int unit_size);
    int allocate_mem(int process_id, int num_units) override;
};

#endif
