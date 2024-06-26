#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <string>

struct Statistics {
    int total_requests;
    int allocation_denied;
    int total_nodes_traversed;
    int total_fragments;

    Statistics();
    void print_statistics(const std::string& technique);
};

#endif
