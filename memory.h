#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class memory
{
private:
    int8_t *memory_location;
    int32_t total_size;

public:
    memory();
    bool is_memory(string &);
    uint16_t convert_string_to_memory_location(string &mem_loc);
};

#endif