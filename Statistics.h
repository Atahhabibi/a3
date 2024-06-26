#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <string>

/*
 * Developed by:
 * Name: Atah Habibi
 *   - Username: cssc4466
 * Name: Matthew Press
 *   - Username: cssc4443
 */

struct Statistics {
    int total_requests;
    int allocation_denied;
    int total_nodes_traversed;
    int total_fragments;

    Statistics();
    void print_statistics(const std::string& technique);
};

#endif
