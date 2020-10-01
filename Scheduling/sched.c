#include"sched.h"
#include<stdio.h>

void print_result(process_t* ps, int n, int type)
{
    if(type!=2)
    {
        printf("Job   Burst Time   Wait Time   Turnaround Time\n");
        for(int i=0; i<n; ++i)
        {
            printf("%-6d", ps[i].pid);
            printf("%-13d", ps[i].burst_time);
            printf("%-12d", ps[i].wait_time);
            printf("%-14d", ps[i].turnar_time);
            printf("\n");
        }
    }
    else
    {
        printf("Job   Priority   Burst Time   Wait Time   Turnaround Time\n");
        for(int i=0; i<n; ++i)
        {
            printf("%-6d", ps[i].pid);
            printf("%-11d", ps[i].pty);
            printf("%-13d", ps[i].burst_time);
            printf("%-12d", ps[i].wait_time);
            printf("%-14d", ps[i].turnar_time);
            printf("\n");
        }
    }
    
    int avg_wait = 0, avg_turnar = 0;
    for(int i=0; i<n; ++i)
    {
        avg_wait+= ps[i].wait_time;
        avg_turnar += ps[i].turnar_time;
    }
    printf("Average Wait time: %.4f\nAverage Turnaround time: %.4f\n", (float)avg_wait/(float)n, (float)avg_turnar/(float)n);
}

process_t* build_process_q(int n, int type)
{
    int q;
    process_t* ps = (process_t*)malloc(sizeof(process_t)*n);

    for(int i=0; i<n; ++i)
    {
        ps[i].pid = i;
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &ps[i].burst_time);
        ps[i].bt = ps[i].burst_time;
        ps[i].wait_time = 0;
        ps[i].turnar_time = 0;
        ps[i].last_time_index = 0;
        ps[i].pty = 0;
        if(type==2)
        {
            printf("Enter priority of process %d: ", i+1);
            scanf("%d", &ps[i].pty);
        }
        printf("\n");
    }
    return ps;
}


int main()
{
    int opt, q, n;
    printf("1)Shortest Job First Scheduling\n2)Priority Scheduling\n3)Round Robin Scheduling");
    printf("\nEnter the algorithm to demonstrate: ");
    scanf("%d", &opt);
    printf("Enter number of processes: ");
    scanf("%d", &n); 
    process_t* ps = build_process_q(n, opt);
    switch(opt)
    {
        case 1:
            sjf(ps, n);
            break;
        case 2:
            priority(ps, n);
            break;
        case 3:
            printf("Enter time quantium for Round Robin Scheduling: ");
            scanf("%d", &q);
            rrs(ps, n, q);
            break;
        default:
            printf("Invalid option!");
    }
    return 0;
}