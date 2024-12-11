#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

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