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
Non-Preemptive Priority Scheduling
-----------------------------------------------

In Non-Preemptive Priority Scheduling, once the CPU has been assigned to a 
process, it cannot be taken away until the process completes its execution.
Even if a new process arrives with a higher priority, the currently running 
process continues until it finishes. After the CPU becomes free, the process 
with the highest priority from the ready queue is selected next.

Example:

Processes:
Process   AT   BT   Priority
P1        0    5        2
P2        1    3        1
P3        2    4        3

Gantt Chart (Non-Preemptive):
P1 |-------| P2 |---| P3 |----|
0         5     8     12

Explanation:
Since P1 arrives first, it starts running at time 0. P2 arrives later with 
higher priority, but non-preemptive scheduling does not allow interruption, 
so P1 completes first.

Waiting Time:
P1 = 0
P2 = 5 – 1 = 4
P3 = 8 – 2 = 6

Turnaround Time:
P1 = 5
P2 = 7
P3 = 10

-----------------------------------------------
Preemptive Priority Scheduling
-----------------------------------------------

In Preemptive Priority Scheduling, the CPU can be taken away from the currently 
running process if a new process arrives with a higher priority. The interrupted 
process is placed back into the ready queue and resumes later when it again 
becomes the highest-priority available process. This method gives faster response 
to high-priority tasks.

Example:

Processes:
Process   AT   BT   Priority
P1        0    5        2
P2        1    3        1
P3        2    4        3

Gantt Chart (Preemptive):
P1 |--| P2 |---| P1 |--| P3 |----|
0    1    4     7     9     13

Explanation:
P1 starts first, but at time 1, P2 arrives with a higher priority, so it 
preempts P1. After P2 completes, P1 resumes, and after P1 finishes, P3 executes.

Waiting Time:
P1 = (1 – 0) + (7 – 4) = 4
P2 = 0
P3 = 9 – 2 = 7

Turnaround Time:
P1 = 9
P2 = 3
P3 = 11
*/
