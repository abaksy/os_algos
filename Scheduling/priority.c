#include "sched.h"

void priority(process_t* ps, int n)
{
    process_t temp;
    for(int i=0; i<n-1; ++i)
    {
        for(int j=0; j<n-i-1; ++j)
        {
            if(ps[j].pty > ps[j+1].pty)
            {
                temp = ps[j];
                ps[j] = ps[j+1];
                ps[j+1] = temp;
            }
        }
    }
    ps[0].wait_time = 0;
    ps[0].turnar_time = ps[0].burst_time;
    for(int i=1; i<n; ++i)
    {
        ps[i].wait_time = ps[i-1].wait_time + ps[i-1].burst_time;
        ps[i].turnar_time = ps[i-1].turnar_time + ps[i].burst_time;
    }
    print_result(ps, n, 2);
}