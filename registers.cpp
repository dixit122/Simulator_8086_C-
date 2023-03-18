#include "registers.h"

registers::registers()
{
    regi["AX"] = &AX;
    regi["BX"] = &BX;
    regi["CX"] = &CX;
    regi["DX"] = &DX;
    regi["BP"] = &BP;
    regi["SP"] = &SP;
    regi["DI"] = &DI;
    regi["SI"] = &SI;
    regi["FLAG"] = &flag;

    regi["AL"] = &AL;
    regi["BL"] = &BL;
    regi["CL"] = &CL;
    regi["DL"] = &DL;

    regi["AH"] = &AH;
    regi["BH"] = &BH;
    regi["CH"] = &CH;
    regi["DH"] = &DH;

    regi["CS"] = &CS;
    regi["DS"] = &DS;
    regi["ES"] = &ES;
    regi["SS"] = &SS;

    int temp = rand();
    for (auto &i : regi)
    {
        *(i.second) = temp;
        temp++;
    }

    AH = ((AX & (0xFF00)) >> 8);
    AL = (AX & (0x00FF));
    BH = ((BX & (0xFF00)) >> 8);
    BL = (BX & (0x00FF));
    CH = ((CX & (0xFF00)) >> 8);
    CL = (CX & (0x00FF));
    DH = ((DX & (0xFF00)) >> 8);
    DL = (DX & (0x00FF));

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
    return regi.count(register_name);
}

int32_t registers::get_data(string &register_name)
{
    if (regi.count(register_name) == 0)
    {
        cout << register_name << "\n\n";
        print_register_map();
        cout << "the given register name does not exist\n\n";
        return -1;
    }
    return *(regi[register_name]);
}

void registers::set_value(string &register_name, int32_t val)
{
    if (regi.count(register_name) == 0)
    {
        cout << register_name << "\n\n";
        print_register_map();
        cout << "the given register name does not exist\n\n";
        return;
    }
    *regi[register_name] = val;

    int n = register_name.size();
    char last_character = register_name[n - 1];

    if (last_character == 'H')
    {
        *regi[register_name.substr(0, 1) + "X"] &= (0x00FF);
        *regi[register_name.substr(0, 1) + "X"] |= (val << 8);
    }
    else if (last_character == 'L')
    {
        *regi[register_name.substr(0, 1) + "X"] &= (0xFF00);
        *regi[register_name.substr(0, 1) + "X"] |= (val);
    }
}

void registers::print_register_map()
{
    cout << regi.size() << '\n';
    for (auto &i : regi)
    {
        cout << i.first << " " << *(i.second) << "\n";
    }
}

void registers::print_reg_data_hex_format(string &register_name)
{
    int32_t data = get_data(register_name);
    stringstream ss;
    ss << hex << data;
    string ans = ss.str();

    cout << ans << '\n';

    return;
}
