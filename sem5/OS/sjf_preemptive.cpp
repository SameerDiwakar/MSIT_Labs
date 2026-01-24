#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt;
    int ct, tat, wt, rt;
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
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    double totalTAT = 0, totalWT = 0;

    while (completed < n) {
        int idx = -1;
        int bestRT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].rt < bestRT) {
                    bestRT = p[i].rt;
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
// Enter AT BT for P2: 1 2
// Enter AT BT for P3: 4 1

// PID	AT	BT	CT	TAT	WT
// P1	0	4	7	7	3
// P2	1	2	3	2	0
// P3	4	1	5	1	0

// Average TAT = 3.33333
// Average WT = 1

/*
------------------------------------------------
SJF Preemptive (Shortest Remaining Time First)
------------------------------------------------

Definition:
SJF Preemptive (also called Shortest Remaining Time First - SRTF) is a CPU scheduling algorithm that always executes the process with the shortest remaining burst time. 
- If a new process arrives with a burst time smaller than the remaining time of the currently running process, the CPU preempts the running process.
- It minimizes average waiting time and turnaround time.

------------------------------------------------
Example:
------------------------------------------------

Processes:
Process   AT   BT
P1        0    4
P2        1    2
P3        4    1

Step-by-step execution (SJF Preemptive):

1. At time 0: Only P1 has arrived. Start P1 (remaining BT=4)

2. At time 1: P2 arrives (BT=2). Compare with P1 remaining (3). 
   - P2 has smaller remaining time → preempt P1. Execute P2 (remaining BT=2)

3. At time 3: P2 finishes. Choose the next process with shortest remaining time. P1 (remaining BT=3) has arrived, execute P1.

4. At time 4: P3 arrives (BT=1). Compare with P1 remaining (2). 
   - P3 has smaller remaining time → preempt P1. Execute P3.

5. At time 5: P3 finishes. Resume P1 (remaining BT=2) and execute till completion (time 7)

------------------------------------------------
Gantt Chart (SJF Preemptive):
| P1 | P2 | P1 | P3 | P1 |
0    1    3    4    5    7

------------------------------------------------
Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT):

PID   AT  BT  CT  TAT  WT
P1    0   4   7   7    3   (TAT = 7-0=7, WT = 7-4=3)
P2    1   2   3   2    0   (TAT = 3-1=2, WT = 2-2=0)
P3    4   1   5   1    0   (TAT = 5-4=1, WT = 1-1=0)

------------------------------------------------
Average Waiting Time  = (3 + 0 + 0)/3 = 1
Average Turnaround Time = (7 + 2 + 1)/3 = 3.33333
*/




