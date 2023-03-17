#include "memory.h"
#include "registers.h"
#include "global_objects.h"

registers reg;

memory::memory()
{
    total_size = 1048576;
    memory_location = new (nothrow) int8_t[1048576];

    srand(unsigned(time(NULL)));

    for (int i = 0; i < total_size; i += 1)
    {
        memory_location[i] = (rand() % 256);
    }
}

bool memory::is_memory(string &operand)
{
    for (auto &i : operand)
    {
        if (i == '[')
            return true;
    }
    return false;
}

uint16_t memory::convert_string_to_memory_location(string &mem_loc)
{
    uint16_t location = 0;

    string curr = "";
    vector<string> elements;
    for (auto &i : mem_loc)
    {
        if (i == '[' || i == ']' || i == ' ' || i == '+' || i == '-')
        {
            if (curr.size())
            {
                elements.push_back(curr);
            }
            curr = "";
            if (i == '-')
            {
                curr.push_back('-');
            }
        }
        else
        {
            curr.push_back(i);
        }
    }

    for (auto &i : elements)
    {
        if (reg.is_register(i))
        {
        }
    }
}