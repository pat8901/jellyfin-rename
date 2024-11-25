#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include <filesystem>

void dfs_postorder();
int rename_recursive(std::filesystem::path path);
void build_test_files();
std::vector<std::string> collect_files();

#endif