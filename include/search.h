#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include <filesystem>

void dfs_postorder();
int rename_recursive(std::filesystem::path path);
std::filesystem::path replace_spaces(std::filesystem::path input_path);
std::filesystem::path replace_regex(std::filesystem::path input_path);

std::vector<std::string> collect_files();
std::ofstream *init_logging(std::filesystem::path log_path);

#endif