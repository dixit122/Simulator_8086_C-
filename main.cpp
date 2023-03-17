#include <bits/stdc++.h>
#include "registers.h"
#include "memory.h"

#include "global_objects.h"

using namespace std;

int random_val = rand();

int main(void)
{
    string str = "AH";
    cout << reg.get_data(str) << '\n';
}