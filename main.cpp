#include <bits/stdc++.h>

#include "registers.h"
#include "global_objects.h"

#include "memory.h"
#include "immediate.h"
#include "operation.h"
#include "alu.h"
#include "memory_global_object.h"

using namespace std;

// to correct the initialization of AL,AH,BL,BH and so on according to AX,BX and so on

// global object of memory
operation op;
alu al;
// immediate im;
// memory mem;

int random_val = rand();
// function prototypes
void process_instruction(string &);
void process_mov_instruction(vector<string> &);
void process_add_instruction(vector<string> &);
void split_instruction_into_operation_and_operand(string &, vector<string> &);
void upper_case(char &);

// spliting  instruction into operation & operands
void split_instruction_into_operation_and_operand(string &line, vector<string> &ans)
{
    int n = line.size();
    string curr = "";
    for (int i = 0; i < n; i += 1)
    {
        if (line[i] == ';')
            break;
        else if (line[i] == ' ' || line[i] == ',')
        {
            if (curr.size())
                ans.push_back(curr);
            curr = "";
        }
        else
        {
            curr.push_back(line[i]);
        }
    }

    if (curr.size())
        ans.push_back(curr);

    return;
}

// processing mov instruction
void process_mov_instruction(vector<string> &v)
{
    string operand1 = v[1];
    string operand2 = v[2];

    // memory <- memory (illegal)
    if (mem.is_memory(operand1) && mem.is_memory(operand2))
    {
        cout << "both opernads can not be memory location \n";
        return;
    }

    // imediate < -memory / register(illegal)
    else if (im.is_immediate(operand1))
    {
        cout << "the destination can not be imediate value";
    }
    else
    {
        // reg <- reg
        if (reg.is_register(operand1) && reg.is_register(operand2))
        {
            if (operand2[1] != operand1[1] && (operand1[1] == 'X' || operand2[1] == 'X'))
            {
                cout << "the registers in mov instruction should be of the same size --> error \n";
                return;
            }
            reg.set_value(operand1, reg.get_data(operand2));
        }
        // memory_location / register <- imediate
        else if (im.is_immediate(operand2))
        {
            if (reg.is_register(operand1))
                reg.set_value(operand1, im.get_data(operand2));
            else
                mem.set_memory_location(operand1, im.get_data(operand2));
        }
        else
        {
            // memory <- register
            if (mem.is_memory(operand1) && reg.is_register(operand2))
            {
                mem.set_memory_location(operand1, reg.get_data(operand2));
            }
            // register <- memory
            else if (reg.is_register(operand1) && mem.is_memory(operand2))
            {
                reg.set_value(operand1, mem.get_data(operand2));
            }

            // invalid
            else
            {
                cout << "illegal_instruction\n";
                return;
            }
        }
    }
}

// processing add instruction
void process_add_instruction(vector<string> &v)
{
    string operand1 = v[1];
    string operand2 = v[2];

    al.perform_addition(v[1], v[2]);
}

// processing instruction
void process_instruction(string &instruction)
{
    for (auto &i : instruction)
    {
        upper_case(i);
    }

    vector<string> v;
    split_instruction_into_operation_and_operand(instruction, v);

    int n = v.size();

    if (n == 0)
        return;

    string opration = v[0];

    int no_of_operands = op.get_number_of_operands(opration);

    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << '\n';

    if (no_of_operands != (n - 1) || no_of_operands == -1)
    {
        cout << "illegal instruction\n";
        return;
    }

    if (opration == "MOV")
    {
        process_mov_instruction(v);
    }
    else if (opration == "ADD")
    {
        process_add_instruction(v);
    }
}

void upper_case(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main(void)
{
    fstream inputfile;
    inputfile.open("input.txt", ios::in);

    ofstream output;
    output.open("output.txt");

    if (inputfile.is_open())
    {
        string str;
        while (getline(inputfile, str))
        {
            process_instruction(str);
            reg.print_register_map(output);
            cout << "\n\n";
        }
    }
}