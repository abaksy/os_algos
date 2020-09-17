#include "deadlock_utils.h"
#include<iostream>

void read_vec(std::vector<int>& v, int n)
{
    int temp;
    for(int i=0; i<n; ++i)
    {
        std::cin>>temp;
        v.push_back(temp);
    }
}

void read_2D(std::vector<std::vector<int>>& v, int r, int c)
{
    std::vector<int> temp1;
    int temp;
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            std::cin>>temp;
            temp1.push_back(temp);
        }
        v.push_back(temp1);
        temp1.clear();
    }
}

void add_vecs(std::vector<int>& v1, std::vector<int>& v2)
{
    for(int i=0; i<v1.size(); ++i)
        v1[i] += v2[i];
}

bool iszero(std::vector<int>& v)       //Return true if av[i] == 0 for all i else false
{
    for(int i=0; i<v.size(); ++i)
    {
        if(v[i] != 0)
            return false;
    }
    return true;
}

int compare_vec(std::vector<int>& v1, std::vector<int>& v2)  //Return true if v1<= v2 else false
{
    int n = v1.size();
    //int flag = 0;
    for(int i=0; i<n; ++i)
    {
        if(v1[i] > v2[i])
            return false;
    }
    return true;
}

