#ifndef REQUEST_GENERATOR_H
#define REQUEST_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>

class RequestGenerator {
    int total_requests;
    std::vector<int> process_ids;
    
public:
    RequestGenerator(int total_requests);
    std::pair<int, int> generate_allocation_request();
    int generate_deallocation_request();
};

#endif
