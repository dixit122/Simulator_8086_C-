#include "alu.h"

memory mem;
immediate im;

int32_t alu::decode_operand(string &operand)
{
    if (reg.is_register(operand))
    {
        return reg.get_data(operand);
    }

    else if (mem.is_memory(operand))
    {
        return mem.get_data(operand);
    }

    else if (im.is_immediate(operand))
    {
        return int32_t(im.get_data(operand));
    }
}

void alu::perform_addition(string &operand1, string &operand2)
{
    int32_t val2 = decode_operand(operand2);
    int32_t val1 = decode_operand(operand1);

    int32_t ans = val1 + val2;

    if (reg.is_register(operand1))
    {
        reg.set_value(operand1, ans);
    }
    else if (mem.is_memory(operand1))
    {
        mem.set_memory_location(operand1, ans);
    }
    else
    {
        cout << "invalid operand in alu instruction";
    }
    return;
}

void alu::perform_subtraction(string &operand1, string &operand2)
{
    int32_t val2 = decode_operand(operand2);
    int32_t val1 = decode_operand(operand1);

    int32_t ans = val1 - val2;

    if (reg.is_register(operand1))
    {
        reg.set_value(operand1, ans);
    }
    else if (mem.is_memory(operand1))
    {
        mem.set_memory_location(operand1, ans);
    }
    else
    {
        cout << "invalid operand in alu instruction";
    }
    return;
}

void alu::perform_multiplication(string &operand1)
{
    long long ans = decode_operand(operand1);
    if (reg.is_register(operand1))
    {
        if (operand1[operand1.size() - 1] == 'X')
        {
            string operand2 = "AX";
            ans = reg.get_data(operand2) * reg.get_data(operand1);
            reg.set_value(operand1, ans & 0x0000FFFF);

            string upper_word = "DX";
            reg.set_value(upper_word, ans & 0xFFFF0000);
        }
        else
        {
            string operand2 = "AL";
            ans = reg.get_data(operand2) * reg.get_data(operand1);

            string destination = "AX";
            reg.set_value(destination, ans);
        }
    }
    else
    {
        cout << "invalid operand for multiplication";
    }
}