#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <typeinfo>
#include <regex>
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
        // TODO: Check to to see if new file name doesn't exist already
        if (entry.is_regular_file())
        {
            // Debug mode
            cout << "Renaming: " << entry.path() << " --> " << entry.path().parent_path() / "new_path.mkv" << endl;

            // Logging

            // Actual implementation
            // fs::rename(entry, entry.path().parent_path() / "new_path.mkv");
        }
    }

    return EXIT_SUCCESS;
}

/* Replace all spaces with periods. */
fs::path replace_spaces(fs::path input_path)
{
    char target = ' ';
    std::string file = input_path.filename().string();

    for (int i = 0; i < file.length(); i++)
    {
        cout << file[i];
        if (file[i] == ' ')
        {
            file[i] = '.';
        }
    }
    printf("\n");

    for (char c : file)
    {
        cout << c;
    }
    printf("\n");

    return input_path.parent_path() / file;
}

/* Find patterns using regex and replace using defined rules. */
fs::path replace_regex(fs::path input_path)
{
    fs::path output_path = input_path;

    return output_path;
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

/* Initialize a file to log file renaming progress and any errors that occur. */
std::ofstream *init_logging(fs::path log_path)
{
    std::ofstream *ptr_log = new std::ofstream(log_path);

    return ptr_log;
}