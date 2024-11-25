#include <stdio.h>
#include <iostream>
#include "search.h"
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main(void)
{
    cout << "C++ Version:" << __cplusplus << endl;
    fs::path test_path = "/home/jeff/Desktop/projects/c++/jellyfin-rename/test";

    build_test_files();
    rename_recursive(test_path);

    return 0;
}