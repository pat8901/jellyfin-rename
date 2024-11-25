#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <typeinfo>
#include "search.h"

namespace fs = std::filesystem;
using namespace std;

void dfs_postorder()
{
    fs::path CWD = fs::current_path();
    cout << "Current path stem " << fs::current_path().stem() << endl;

    for (fs::directory_entry const &entry : fs::recursive_directory_iterator(CWD))
    {
        if (entry.is_directory())
        {
            cout << "\n==== " << entry.path().relative_path() << " ====" << endl;
        }
        if (entry.is_regular_file())
        {
            cout << "file: " << entry.path() << endl;
        }
    }
}

int rename_recursive(std::filesystem::path path)
{
    cout << "Media Location=" << path << endl;

    for (fs::directory_entry const &entry : fs::recursive_directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            cout << "before=" << entry.path() << endl;
            fs::rename(entry, entry.path().parent_path() / "what.mkv");
            cout << "after=" << entry.path() << endl;
        }
    }

    return EXIT_SUCCESS;
}

void build_test_files()
{
    fs::path test_path = "/home/jeff/Desktop/projects/c++/jellyfin-rename/test";
    cout << "test exist: " << fs::directory_entry(test_path).exists() << endl;

    // Adding media type directories
    fs::create_directory(test_path / "movies");
    fs::create_directory(test_path / "tv");

    // Adding movies and shows parent directories
    fs::create_directory(test_path / "movies/Star Wars");
    fs::create_directory(test_path / "movies/Jurassic Park");
    fs::create_directory(test_path / "tv/Futurama");
    fs::create_directory(test_path / "tv/Curb Your Enthusiasm");

    // Adding movies and tv shows
    std::ofstream file(test_path / "movies/Star Wars/star wars 1.mp4");
    file.close();
    std::ofstream file2(test_path / "tv/Futurama/Space Pilot 3000.mp4");
    file.close();
}

std::vector<std::string> collect_files()
{
    std::vector<std::string> files;

    size_t size = files.size();
    return files;
}