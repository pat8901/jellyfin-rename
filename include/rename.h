#ifndef RENAME_H
#define RENAME_H

#include <filesystem>
#include <vector>
#include <string>

std::vector<std::string> tokenize(std::filesystem::path input_path);

std::filesystem::path replace_spaces(std::filesystem::path input_path);
std::filesystem::path replace_regex(std::filesystem::path input_path);

#endif