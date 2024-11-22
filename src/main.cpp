#include <stdio.h>
#include <iostream>
#include "search.h"
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    cout << "C++ Version:" << __cplusplus << endl;

    vector<string> files = collect_files();

    cout << "Vector size (1): " << files.size() << endl;

    string name = "jeff";
    files.push_back(name);
    cout << "Vector size (2): " << files.size() << endl;

    return 0;
}