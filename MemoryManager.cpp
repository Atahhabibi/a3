#include "MemoryManager.h"

MemoryBlock::MemoryBlock(int start, int size, int process_id) :
    start(start), size(size), process_id(process_id) {}

MemoryManager::MemoryManager(int total_size, int unit_size) : total_size(total_size), unit_size(unit_size) {
    memory_list.push_back(MemoryBlock(0, total_size / unit_size));
}

int MemoryManager::deallocate_mem(int process_id) {
    for (auto it = memory_list.begin(); it != memory_list.end(); ++it) {
        if (it->process_id == process_id) {
            it->process_id = -1;
            return 1;
        }
    }
    return -1;
}

int MemoryManager::fragment_count() {
    int count = 0;
    for (const auto& block : memory_list) {
        if (block.process_id == -1 && block.size <= 2) {
            count++;
        }
    }
    return count;
}
