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