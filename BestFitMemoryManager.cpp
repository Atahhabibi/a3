#include "BestFitMemoryManager.h"

BestFitMemoryManager::BestFitMemoryManager(int total_size, int unit_size) : MemoryManager(total_size, unit_size) {}

int BestFitMemoryManager::allocate_mem(int process_id, int num_units) {
    auto best_fit_it = memory_list.end();
    int best_fit_size = total_size + 1;
    int nodes_traversed = 0;

    for (auto it = memory_list.begin(); it != memory_list.end(); ++it, ++nodes_traversed) {
        if (it->process_id == -1 && it->size >= num_units && it->size < best_fit_size) {
            best_fit_it = it;
            best_fit_size = it->size;
        }
    }

    if (best_fit_it != memory_list.end()) {
        if (best_fit_it->size > num_units) {
            memory_list.insert(best_fit_it, MemoryBlock(best_fit_it->start, num_units, process_id));
            best_fit_it->start += num_units;
            best_fit_it->size -= num_units;
        } else {
            best_fit_it->process_id = process_id;
        }
        return nodes_traversed;
    }
    return -1;
}
