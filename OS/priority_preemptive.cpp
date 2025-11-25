#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, pr;
    int ct, tat, wt, rt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT BT PR for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    double totalTAT = 0, totalWT = 0;

    while (completed < n) {
        int idx = -1;
        int bestPr = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].pr < bestPr) {
                    bestPr = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            completed++;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalTAT += p[idx].tat;
            totalWT += p[idx].wt;
        }
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << "P" << x.pid << "\t"
             << x.at << "\t" << x.bt << "\t" << x.pr << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }

    cout << "\nAverage TAT = " << totalTAT / n;
    cout << "\nAverage WT = " << totalWT / n << "\n";

    return 0;
}



// Priority Scheduling is a CPU scheduling algorithm in which each process is assigned a
// priority, and the CPU is allocated to the process with the highest priority (usually, a lower
// number = higher priority).

// Enter number of processes: 3
// Enter AT BT PR for P1: 0 5 2
// Enter AT BT PR for P2: 1 3 1
// Enter AT BT PR for P3: 2 4 3

// PID	AT	BT	PR	CT	TAT	WT
// P1	0	5	2	8	8	3
// P2	1	3	1	4	3	0
// P3	2	4	3	12	10	6

// Average TAT = 7
// Average WT = 3



/*
Priority Scheduling (Preemptive and Non-Preemptive)

Priority Scheduling is a CPU scheduling technique where each process is assigned
a priority value, and the CPU is allocated to the process with the highest 
priority (usually, a lower priority number means higher priority). This scheduling
method is mainly used when certain processes are more important and must be 
executed before others.

-----------------------------------------------
Preemptive Priority Scheduling
-----------------------------------------------

In Preemptive Priority Scheduling, the CPU can be taken away from the currently 
running process if a new process arrives with a higher priority. The interrupted 
process is placed back into the ready queue and resumes later when it again 
becomes the highest-priority available process. This method gives faster response 
to high-priority tasks.

------------------------------------------------
Example:
------------------------------------------------

Processes:
Process   AT   BT  PR
P1        0    5   2
P2        1    3   1
P3        2    4   3

Step-by-step execution (Non-preemptive Priority Scheduling):

1. At time 0: Only P1 has arrived. P1 priority = 2. But check all arrived processes at current time:
   - Only P1 → execute P1? Wait, P2 arrives at time 1 with higher priority (1). So at time 1, CPU selects **P2** first.  

2. Execution order:
   - At time 0: P1 starts but since non-preemptive, we usually select **process with highest priority among arrived processes** at CPU idle time.
   - At time 0: P1 arrived, P2 not yet → execute P1.
   - At time 5 (P1 finishes): P2 and P3 are available.
     - P2 has highest priority (PR=1) → execute P2
   - At time 8 (P2 finishes): Only P3 remains → execute P3.

------------------------------------------------
Gantt Chart (Non-preemptive Priority Scheduling):
| P1 | P2 | P3 |
0     5     8    12

------------------------------------------------
Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT):

PID   AT  BT  PR  CT  TAT  WT
P1    0   5   2   8   8    3   (TAT = 8-0=8, WT = 8-5=3)
P2    1   3   1   4   3    0   (TAT = 4-1=3, WT = 3-3=0)
P3    2   4   3   12  10   6   (TAT = 12-2=10, WT = 10-4=6)

------------------------------------------------
Average Waiting Time  = (3 + 0 + 6)/3 = 3
Average Turnaround Time = (8 + 3 + 10)/3 = 7
*/
