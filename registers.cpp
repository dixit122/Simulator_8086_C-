#include "registers.h"

registers::registers()
{
    reg["AX"] = &AX;
    reg["BX"] = &BX;
    reg["CX"] = &CX;
    reg["DX"] = &DX;
    reg["BP"] = &BP;
    reg["SP"] = &SP;
    reg["DI"] = &DI;
    reg["SI"] = &SI;
    reg["FLAG"] = &flag;

    reg["AL"] = &AL;
    reg["BL"] = &BL;
    reg["CL"] = &CL;
    reg["DL"] = &DL;

    reg["AH"] = &AH;
    reg["BH"] = &BH;
    reg["CH"] = &CH;
    reg["DH"] = &DH;

    reg["CS"] = &CS;
    reg["DS"] = &DS;
    reg["ES"] = &ES;
    reg["SS"] = &SS;

    int temp = rand();
    for (auto &i : reg)
    {
        *(i.second) = temp;
        temp++;
    }

    flag = 0;

    CS = 0;
    DS = 16384;
    ES = 2 * DS;
    SS = 3 * DS;
}

bool registers::is_segment_register(string &register_name)
{
    return (register_name == "CS" || register_name == "DS" || register_name == "ES" || register_name == "SS");
}

bool registers::is_register(string &register_name)
{
    return reg.count(register_name);
}

int16_t registers::get_data(string &register_name)
{
    return *(reg[register_name]);
}

void registers::set_value(string &register_name, int16_t val)
{
    *reg["register_name"] = val;

    int n = register_name.size();
    char last_character = register_name[n - 1];

    if (last_character == 'H')
    {
        *reg[register_name.substr(0, 1) + "X"] |= (val << 8);
    }
    else if (last_character == 'L')
    {
        *reg[register_name.substr(0, 1) + "X"] |= (val);
    }
}