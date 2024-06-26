#include "Statistics.h"

Statistics::Statistics() : total_requests(0), allocation_denied(0), total_nodes_traversed(0), total_fragments(0) {}

void Statistics::print_statistics(const std::string& technique) {
    double avg_fragments = static_cast<double>(total_fragments) / total_requests;
    double avg_nodes_traversed = static_cast<double>(total_nodes_traversed) / (total_requests - allocation_denied);
    double denial_percentage = static_cast<double>(allocation_denied) / total_requests * 100;

    std::cout << "End of " << technique << " Allocation" << std::endl;
    std::cout << "Average External Fragments Each Request: " << avg_fragments << std::endl;
    std::cout << "Average Nodes Traversed Each Allocation: " << avg_nodes_traversed << std::endl;
    std::cout << "Percentage Allocation Requests Denied Overall: " << denial_percentage << "%" << std::endl;
}
