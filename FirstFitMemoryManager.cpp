#include "FirstFitMemoryManager.h"

/*
 * Developed by:
 * Name: Atah Habibi
 *   - Username: cssc4466
 * Name: Matthew Press
 *   - Username: cssc4443
 */

FirstFitMemoryManager::FirstFitMemoryManager(int total_size, int unit_size) : MemoryManager(total_size, unit_size) {}

int FirstFitMemoryManager::allocate_mem(int process_id, int num_units) {
    int nodes_traversed = 0;
    for (auto it = memory_list.begin(); it != memory_list.end(); ++it, ++nodes_traversed) {
        if (it->process_id == -1 && it->size >= num_units) {
            if (it->size > num_units) {
                memory_list.insert(it, MemoryBlock(it->start, num_units, process_id));
                it->start += num_units;
                it->size -= num_units;
            } else {
                it->process_id = process_id;
            }
            return nodes_traversed;
        }
    }
    return -1;
}
