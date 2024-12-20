# Operating Systems Algorithms

C/C++ implementation of some algorithms used in Operating Systems. This repository covers algorithms from the Dinosaur Book (OS Concepts by Silberschatz, Galvin, Gagne et. al.)

## Scheduling

The output is a table with rows in the order in which the processes in the queue will be submitted to the CPU.

1) Shortest Job First scheduling:
The job with the shortest burst time is sent in first

2) Round Robin Scheduling:
All jobs get an equal slice (quantum) of CPU time, and this repeats until all jobs are complete.

3) Priority Scheduling:
Jobs are submitted to the CPU in order of their user-defined priorities.

## Deadlocks

Deadlock detection algorithm is implemented as presented in the textbook Operating Systems Concepts (9e.) by Galvin, Silberschatz and
Gagne.
