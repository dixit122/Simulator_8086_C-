#ifndef REGISTERS_H
#define REGISTERS_H

#include <bits/stdc++.h>
using namespace std;

class registers
{
private:
    int16_t AX, BX, CX, DX;
    int16_t CS, DS, SS, ES;
    int16_t SP, BP, SI, DI;
    int16_t AL, BL, CL, DL;
    int16_t AH, BH, CH, DH;
    int16_t flag;
    map<string, int16_t *> reg;

public:
    registers();

    bool is_segment_register(string &);

    bool is_register(string &);

    int16_t get_data(string &);

    void set_value(string &, int16_t);
};

#endif