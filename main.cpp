#include <bits/stdc++.h>
using namespace std;

int random_val = rand();

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
    registers()
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

        int temp = random_val;
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

    bool is_segment_register(string &register_name)
    {
        return (register_name == "CS" || register_name == "DS" || register_name == "ES" || register_name == "SS");
    }

    bool is_register(string &register_name)
    {
        return reg.count(register_name);
    }

    int16_t get_data(string &register_name)
    {
        return *(reg[register_name]);
    }

    void set_value(string &register_name, int16_t val)
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
};

// gloabal objects
registers reg;

class memory
{
private:
    int8_t *memory_location;
    int32_t total_size;

public:
    memory()
    {
        total_size = 1048576;
        memory_location = new (nothrow) int8_t[1048576];

        srand(unsigned(time(NULL)));

        for (int i = 0; i < total_size; i += 1)
        {
            memory_location[i] = (rand() % 256);
        }
    }

    bool is_memory(string &operand)
    {
        for (auto &i : operand)
        {
            if (i == '[')
                return true;
        }
        return false;
    }

    uint16_t convert_string_to_memory_location(string &mem_loc)
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
    }
};

int main(void)
{
    string str = "AH";
    cout << reg.get_data(str) << '\n';
}