#include <bits/stdc++.h>
#include "registers.h"
#include "memory.h"

#include "global_objects.h"

using namespace std;

// global object of memory
memory mem;

int random_val = rand();

// function prototypesWW

int main(void)
{
    string s1 = "AL", s2 = "BL";

    string s3 = "[AL][BL]2";
    cout << "here " << mem.string_to_effective_address(s3) << '\n';
    mem.set_memory_location(s3, 12);
    cout << mem.get_data(s3) << '\n';

    // string str = []
    // cout << mem.convert_string_to_memory_location()
    // fstream inputfile;
    // inputfile.open("input.txt", ios::in);

    // if (inputfile.is_open())
    // {
    //     string str;
    //     while (getline(inputfile, str))
    //     {
    //     }
    // }
}