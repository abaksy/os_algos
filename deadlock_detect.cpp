#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

bool iszero(std::vector<int> av)       //Return true if av[i] == 0 for all i else false
{
    for(int i=0; i<av.size(); ++i)
    {
        if(av[i] != 0)
            return false;
    }
    return true;
}

int compare_vec(std::vector<int> v1, std::vector<int> v2)  //Return true if v1<= v2 else false
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

void add_vecs(std::vector<int>& v1, std::vector<int>& v2)
{
    for(int i=0; i<v1.size(); ++i)
        v1[i] += v2[i];
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
    for(int i=0; i<m; ++i)
    {
        std::cin>>temp;
        available.push_back(temp);
    }
    std::vector<int> temp1;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            std::cin>>temp;
            temp1.push_back(temp);
        }
        allocation.push_back(temp1);
        temp1.clear();
    }
    std::vector<int> temp2;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            std::cin>>temp;
            temp2.push_back(temp);
        }
        request.push_back(temp2);
        temp2.clear();
    }
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