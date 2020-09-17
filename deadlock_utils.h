#ifndef DEADLOCK_H
#define DEADLOCK_H

#include<vector>

void read_vec(std::vector<int>& v, int n);

void read_2D(std::vector<std::vector<int>>& v, int r, int c);

void add_vecs(std::vector<int>& v1, std::vector<int>& v2); 

bool iszero(std::vector<int>& v);

int compare_vec(std::vector<int>& v1, std::vector<int>& v2);
#endif