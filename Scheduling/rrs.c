#include"sched.h"

int min(int a, int b)
{
    return a<b?a:b;
}

void rrs(process_t* ps, int n, int q)
{
    int current_time_index = 0, idx, temp = 0, total_time = 0;
    int prev_pid = 0, curr_pid = 0;
    int flag = 1;

    for(int l = 0; l<n; ++l)
        total_time+=ps[l].burst_time;
    for(int i=0 ;current_time_index < total_time; i++)
    {
        flag = 1;
        idx = i%n;
        
        //printf("current process time left %d\n", ps[idx].bt);
        if(ps[idx].bt != 0)
        {
            curr_pid = idx;
            if(prev_pid != curr_pid)
                ps[idx].wait_time += current_time_index - ps[(idx+1)%n].last_time_index;
            ps[idx].last_time_index = current_time_index;
            temp = min(ps[idx].bt, q);
            current_time_index += temp;
            ps[idx].bt -= temp;
            int t_idx = (idx+1)%n;
        }
        prev_pid = curr_pid;
        for(int j = 0;j<n; ++j)
        {
            if(ps[j].bt != 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int m = 0; m<n;++m)
        ps[m].turnar_time = ps[m].burst_time + ps[m].wait_time;
    print_result(ps, n, 3);
}