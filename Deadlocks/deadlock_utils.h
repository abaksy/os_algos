#ifndef DEADLOCK_H
#define DEADLOCK_H

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

//Read a vector of integers of size n from STDIN
void read_vec(std::vector<int>& v, int n);

//Read a matrix of integers from STDIN of r rows and n columns
void read_2D(std::vector<std::vector<int>>& v, int r, int c);

//Add vectors in place (v1 = v1+v2)
void add_vecs(std::vector<int>& v1, std::vector<int>& v2); 

//Subtract vectors in place (v1 = v1-v2)
void subt_vecs(std::vector<int>& v1, std::vector<int>& v2); 

//Return true if v[i]==0 for all i, else return false
bool iszero(std::vector<int>& v);

//Return true if v1[i] <= v2[i] for all i, else return false
bool compare_vec(std::vector<int>& v1, std::vector<int>& v2);

//Returns an index i such that finish[i]==false and vect[i] <= work
std::vector<int> find_index(std::vector<bool>& finish, std::vector<std::vector<int>>& vect, std::vector<int>& work);
#endif