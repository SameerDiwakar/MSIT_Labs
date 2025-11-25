 #include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, pr;
    int ct, tat, wt;
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
    }

    vector<bool> done(n, false);
    int completed = 0, time = 0;
    double totalTAT = 0, totalWT = 0;

    while (completed < n) {
        int idx = -1;
        int bestPr = INT_MAX;

        // Find highest priority available process
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].pr < bestPr) {
                bestPr = p[i].pr;
                idx = i;
            }
        }

        if (idx == -1) {
            time++; // No process has arrived yet
            continue;
        }

        // Run the selected process to completion
        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        totalTAT += p[idx].tat;
        totalWT += p[idx].wt;

        done[idx] = true;
        completed++;
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


// Enter number of processes: 3
// Enter AT BT PR for P1: 0 5 2
// Enter AT BT PR for P2: 1 3 1
// Enter AT BT PR for P3: 2 4 3

// PID	AT	BT	PR	CT	TAT	WT
// P1	0	5	2	5	5	0
// P2	1	3	1	8	7	4
// P3	2	4	3	12	10	6

// Average TAT = 7.33333
// Average WT = 3.33333


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
*/
