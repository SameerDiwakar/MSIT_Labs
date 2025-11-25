#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

bool compareArrival(Process a, Process b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time of process " << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter burst time of process " << p[i].pid << ": ";
        cin >> p[i].burst;
    }

    sort(p.begin(), p.end(), compareArrival);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival;
        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        currentTime = p[i].completion;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].turnaround << "\t"
             << p[i].waiting << "\n";
    }

    return 0;
}


// Enter number of processes: 3
// Enter arrival time of process 1: 0
// Enter burst time of process 1: 4
// Enter arrival time of process 2: 1
// Enter burst time of process 2: 3
// Enter arrival time of process 3: 2
// Enter burst time of process 3: 1

// PID	AT	BT	CT	TAT	WT
// 1	0	4	4	4	0
// 2	1	3	7	6	3
// 3	2	1	8	6	5

// Average Turnaround Time: 5.33333
// Average Waiting Time:    2.66667


// FCFS (First Come First Serve) is one of the simplest CPU scheduling algorithms in operating
// systems. It schedules processes in the order of their arrival—the process that arrives first
// gets executed first. It’s a non-preemptive scheduling algorithm, meaning once a process
// starts executing, it runs to completion.
/*
------------------------------------------------
Example (FCFS)
------------------------------------------------

Processes:
Process   AT   BT
P1        0    4
P2        1    3
P3        2    1

Gantt Chart (FCFS):
P1 |----| P2 |---| P3 |-| 
0     4     7     8

Explanation:
- P1 arrives at time 0 and starts immediately.
- P2 arrives at time 1 but waits until P1 finishes at time 4.
- P3 arrives at time 2 but waits until P2 finishes at time 7.

------------------------------------------------
Waiting Time
------------------------------------------------
P1 = 0  
P2 = 4 – 1 = 3  
P3 = 7 – 2 = 5  

------------------------------------------------
Turnaround Time
------------------------------------------------
P1 = 4 – 0 = 4  
P2 = 7 – 1 = 6  
P3 = 8 – 2 = 6  

------------------------------------------------
Average Waiting Time  = (0 + 3 + 5) / 3 = 2.66667
Average Turnaround Time = (4 + 6 + 6) / 3 = 5.33333
*/
