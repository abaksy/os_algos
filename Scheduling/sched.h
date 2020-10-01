#ifndef _SCHED_H
#define _SCHED_H

#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int pid;
    int pty;
    int burst_time;
    int bt;
    int wait_time;
    int turnar_time;
    int last_time_index;
}process_t;

process_t* build_process_q(int n, int type);
void print_result(process_t* ps, int n, int type);
void rrs(process_t* ps, int n, int q);
void sjf(process_t* ps, int n);
void priority(process_t* ps, int n);

#endif