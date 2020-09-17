#include "deadlock_utils.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

std::vector<int> find_index(std::vector<bool>& finish, std::vector<std::vector<int>>& request, std::vector<int>& work)
{
    std::set<int> s1, s2;
    for(int i=0; i<request.size(); ++i)
    {
        if(compare_vec(request[i], work))
            s1.insert(i);
    }
    for(int i=0; i<finish.size(); ++i)
    {
        if(finish[i] == false)
           s2.insert(i);
    }
    std::vector<int> result(5);
    std::vector<int>::iterator it = std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
    result.resize(it - result.begin());
    return result;
}

void detect_deadlock(std::vector<bool>& finish)
{
    bool flag = true;
    for(int i=0;i<finish.size(); ++i)
    {
        if(finish[i]==false)
        {
            flag = false;
            std::cout<<"Deadlock detected in process "<<i<<"\n";
        }
    }
    if(flag)
        std::cout<<"No deadlocks detected!\n";
}
 
int main()
{
    int m = 3; //Number of resource classes
    int n = 5;  //Number of processes
    std::vector<int> available;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> request;
    int temp;
    read_vec(available, m);
    read_2D(allocation, n, m);
    read_2D(request, n, m);
    std::vector<int> work = available;
    std::vector<bool> finish;
    for(int i=0; i<n; ++i)
    {
        finish.push_back(iszero(allocation[i]));
    }
    int ctr = 1;
    while(true)
    {
        std::cout<<"Iteration "<<ctr<<"\n";
        ctr++;
        std::vector<int> indices = find_index(finish, request, work);
        if(indices.size() == 0)
            break;
        else
        {
            int ind = indices[0];
            add_vecs(work, allocation[ind]);
            finish[ind] = true;
        }
    }
    detect_deadlock(finish);
    return 0;
}