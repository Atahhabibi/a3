#include <iostream>
#include <tuple>  // Include <tuple> for std::tuple
#include "MemoryManager.h"
#include "FirstFitMemoryManager.h"
#include "BestFitMemoryManager.h"
#include "RequestGenerator.h"
#include "Statistics.h"

int main() {
    const int total_memory = 256; // in KB
    const int unit_size = 2; // in KB
    const int total_requests = 10000;

    FirstFitMemoryManager first_fit_manager(total_memory, unit_size);
    BestFitMemoryManager best_fit_manager(total_memory, unit_size);
    RequestGenerator request_generator(total_requests);

    Statistics first_fit_stats;
    Statistics best_fit_stats;

    for (int i = 0; i < total_requests; ++i) {
        bool is_allocation = rand() % 2;
        if (is_allocation) {
            std::tuple<int, int> allocation_request = request_generator.generate_allocation_request();  // Use std::tuple to store the return value
            int process_id = std::get<0>(allocation_request);  // Use std::get to access elements
            int num_units = std::get<1>(allocation_request);

            int first_fit_nodes = first_fit_manager.allocate_mem(process_id, num_units);
            int best_fit_nodes = best_fit_manager.allocate_mem(process_id, num_units);

            first_fit_stats.total_requests++;
            best_fit_stats.total_requests++;

            if (first_fit_nodes == -1) {
                first_fit_stats.allocation_denied++;
            } else {
                first_fit_stats.total_nodes_traversed += first_fit_nodes;
            }

            if (best_fit_nodes == -1) {
                best_fit_stats.allocation_denied++;
            } else {
                best_fit_stats.total_nodes_traversed += best_fit_nodes;
            }
        } else {
            int process_id = request_generator.generate_deallocation_request();
            if (process_id != -1) {
                first_fit_manager.deallocate_mem(process_id);
                best_fit_manager.deallocate_mem(process_id);
            }
        }

        first_fit_stats.total_fragments += first_fit_manager.fragment_count();
        best_fit_stats.total_fragments += best_fit_manager.fragment_count();
    }

    first_fit_stats.print_statistics("First Fit");
    best_fit_stats.print_statistics("Best Fit");

    return 0;
}
