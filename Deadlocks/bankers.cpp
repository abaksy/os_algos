#include "deadlock_utils.h"

bool is_safe_state(std::vector<bool>& , std::vector<std::vector<int>>&, std::vector<int>&, std::vector<std::vector<int>>&);

bool safe_request_grant(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&, std::vector<int>&, std::vector<int>&);

int main()
{
    int m = 3;  //Number of resource classes
    int n = 5;  //Number of processes
    std::vector<int> available;
    std::vector<std::vector<int>> max;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> need;

    read_vec(available, m);
    read_2D(max, n, m);
    read_2D(allocation, n, m);
    read_2D(need, n, m);

    std::vector<int> work = available;
    std::vector<bool> finish(n, false);

    return 0;
}

bool is_safe_state(std::vector<bool>& finish, std::vector<std::vector<int>>& need, 
    std::vector<int>& work, std::vector<std::vector<int>>& allocation)
{
    int ctr = 1;
    while(true)
    {
        std::cout<<"Iteration "<<ctr<<"\n";
        ctr++;
        std::vector<int> indices = find_index(finish, need, work);
        if(indices.size()==0)
            break;
        int ind = indices[0];
        add_vecs(work, allocation[ind]);
        finish[ind] = true;
    }
    bool flag = true;
    for(int i=0;i<finish.size(); ++i)
    {
        if(finish[i]==false)
        {
            return false;
        }
    }
    return true;
}

bool safe_request_grant(std::vector<std::vector<int>>& allocation, std::vector<std::vector<int>>& need, 
    std::vector<int>& available, std::vector<int>& request)
{
    return true;
}