#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt;
    int ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT BT for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
    }

    vector<bool> done(n, false);
    int completed = 0, time = 0;
    double totalTAT = 0, totalWT = 0;

    while (completed < n) {
        int idx = -1;
        int bestBT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time) {
                if (p[i].bt < bestBT) {
                    bestBT = p[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        totalTAT += p[idx].tat;
        totalWT += p[idx].wt;
        done[idx] = true;
        completed++;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << "P" << x.pid << "\t"
             << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }

    cout << "\nAverage TAT = " << totalTAT / n;
    cout << "\nAverage WT = " << totalWT / n << "\n";

    return 0;
}

// Enter number of processes: 3
// Enter AT BT for P1: 0 4 
// Enter AT BT for P2: 1 3
// Enter AT BT for P3: 2 1

// PID	AT	BT	CT	TAT	WT
// P1	0	4	4	4	0
// P2	1	3	8	7	4
// P3	2	1	5	3	2

// Average TAT = 4.66667
// Average WT = 2

/*
------------------------------------------------
SJF (Shortest Job First) Scheduling Algorithm
------------------------------------------------

Definition:
SJF is a CPU scheduling algorithm that selects the process with the shortest burst time (CPU execution time) among the available processes. 
It aims to minimize the average waiting time and turnaround time. 
In non-preemptive SJF, once a process starts execution, it runs to completion.

------------------------------------------------
Example:
------------------------------------------------

Processes:
Process   AT   BT
P1        0    4
P2        1    3
P3        2    1

Step-by-step execution (Non-preemptive SJF):

1. At time 0: Only P1 has arrived. Execute P1 (BT=4) 
   - Completion Time (CT) = 0 + 4 = 4
   - Turnaround Time (TAT) = CT - AT = 4 - 0 = 4
   - Waiting Time (WT) = TAT - BT = 4 - 4 = 0

2. At time 4: P2 and P3 have arrived. Choose the process with shortest BT, which is P3 (BT=1)
   - CT = 4 + 1 = 5
   - TAT = 5 - 2 = 3
   - WT = 3 - 1 = 2

3. At time 5: Only P2 remains
   - CT = 5 + 3 = 8
   - TAT = 8 - 1 = 7
   - WT = 7 - 3 = 4

------------------------------------------------
Gantt Chart (SJF Non-preemptive):
| P1 | P3 | P2 |
0    4    5    8

Explanation:
- P1 executes from 0 to 4
- P3 executes from 4 to 5
- P2 executes from 5 to 8

------------------------------------------------
Waiting Time (WT):
P1 = 0
P2 = 4
P3 = 2

------------------------------------------------
Turnaround Time (TAT):
P1 = 4
P2 = 7
P3 = 3

------------------------------------------------
Average Waiting Time  = (0 + 4 + 2) / 3 = 2
Average Turnaround Time = (4 + 7 + 3) / 3 = 4.66667
*/
