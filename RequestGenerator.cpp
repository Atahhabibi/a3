#include "RequestGenerator.h"

/*
 * Developed by:
 * Name: Atah Habibi
 *   - Username: cssc4466
 * Name: Matthew Press
 *   - Username: cssc4443
 */

RequestGenerator::RequestGenerator(int total_requests) : total_requests(total_requests) {
    srand(time(0));
}

std::pair<int, int> RequestGenerator::generate_allocation_request() {
    int process_id = rand() % total_requests;
    int num_units = 3 + rand() % 8;
    process_ids.push_back(process_id);
    return {process_id, num_units};
}

int RequestGenerator::generate_deallocation_request() {
    if (process_ids.empty()) return -1;
    int idx = rand() % process_ids.size();
    int process_id = process_ids[idx];
    process_ids.erase(process_ids.begin() + idx);
    return process_id;
}
