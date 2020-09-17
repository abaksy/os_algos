/*
Implementation of the Deadlock Detection Algorithm
for multiple resource classes, each having more than one instance

Algorithm is as presented by the textbook 
Operating Systems Concepts (9e.), by Silberschatz, Galvin and Gagne 
*/
#include "deadlock_utils.h"

//Detect deadlock using the finish vector. No deadlocks if finish[i] is true for all i
void detect_deadlock(std::vector<bool>& finish);

 
int main()
{
    int m = 3;  //Number of resource classes
    int n = 5;  //Number of processes
    std::vector<int> available;                 //Number of instances available per resource class (size: n)
    std::vector<std::vector<int>> allocation;   //Matrix of currently allocated instances per process per resource class (size: n x m)
    std::vector<std::vector<int>> request;      //Matrix of requested instances per process per resource class (size: n x m)
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
        if(indices.size() == 0) //No indices found
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
