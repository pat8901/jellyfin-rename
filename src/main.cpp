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
    fs::path test_path_movie = "/home/jeff/Desktop/projects/c++/jellyfin-rename/test/movies/Star Wars/star wars 1.mp4";

    build_test_files();
    rename_recursive(test_path);

    replace_spaces(test_path_movie);
    replace_regex(test_path_movie);

    return EXIT_SUCCESS;
}