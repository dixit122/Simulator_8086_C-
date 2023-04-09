#ifndef ALH_H
#define ALU_H

#include <bits/stdc++.h>
#include "memory_global_object.h"
using namespace std;

class alu
{
public:
    int32_t decode_operand(string &);
    void perform_addition(string &, string &);
    void perform_subtraction(string &, string &);
    void perform_multiplication(string &);
    void transfer_data(string &, int32_t &);
};

#endif