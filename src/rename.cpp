#include <filesystem>
#include <vector>
#include <string>
#include <iostream>

namespace fs = std::filesystem;
using namespace std;

/* Tokenizes a file and places the tokens in a vector to be processed further. */
vector<string> tokenize(fs::path input_path)
{
    vector<string> file_tokens(10);

    string file_name = input_path.filename().string();

    int i = 0;
    int left = 0;
    int count = 0;
    for (char c : file_name)
    {
        if (c == ' ' || c == '.')
        {
            string token = file_name.substr(left, count);
            file_tokens.push_back(token);
            left = i + 1;
            count = 0;
        }
        count++;
        i++;
    }

    i = 0;
    for (string s : file_tokens)
    {
        cout << i << ": " << s << endl;
        i++;
    }

    // cout << "filename=" << file_name << endl;

    return file_tokens;
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