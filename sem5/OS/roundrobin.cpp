#include <iostream>
using namespace std;

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;

    int burstTime[100], remainingTime[100], waitingTime[100] = {0}, turnaroundTime[100];

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    int time = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = false;
                if (remainingTime[i] > timeQuantum) {
                    time += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }

    float totalWT = 0, totalTAT = 0;
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << burstTime[i] << "\t"
             << waitingTime[i] << "\t" << turnaroundTime[i] << "\n";
        totalWT += waitingTime[i];
        totalTAT += turnaroundTime[i];
    }

    cout << "\nAverage Waiting Time: " << totalWT/n;
    cout << "\nAverage Turnaround Time: " << totalTAT/n << endl;

    return 0;
}

// Enter number of processes: 3
// Enter burst time for each process:
// P1: 6
// P2: 4
// P3: 8
// Enter Time Quantum: 2

// Process	BT	WT	TAT
// P1		6	8	14
// P2		4	6	10
// P3		8	10	18

// Average Waiting Time: 8
// Average Turnaround Time: 14

/*
------------------------------------------------
Round Robin (RR) CPU Scheduling
------------------------------------------------

Definition:
- Round Robin is a CPU scheduling algorithm where each process is assigned a **fixed time quantum**.
- Processes are executed in **cyclic order** for a time slice equal to the quantum.
- If a process does not finish during its time slice, it is put at the **end of the ready queue**.
- Aims to provide **fair CPU allocation** and reduce waiting time for all processes.

Key Points:
1. Each process gets CPU for a maximum of **time quantum** units.
2. If a process completes before the quantum, it releases the CPU.
3. Processes are executed in **circular order** until all are completed.
4. Calculates **Waiting Time (WT)** and **Turnaround Time (TAT)** for all processes.

------------------------------------------------
Example:
------------------------------------------------

Input:
Number of processes = 3
Burst Times (BT):
P1 = 6, P2 = 4, P3 = 8
Time Quantum = 2

Step-by-step execution:

1. Ready Queue initially: P1, P2, P3
2. P1 executes 2 units → remaining BT = 4
3. P2 executes 2 units → remaining BT = 2
4. P3 executes 2 units → remaining BT = 6
5. P1 executes 2 units → remaining BT = 2
6. P2 executes 2 units → completes (BT=0)
7. P3 executes 2 units → remaining BT = 4
8. P1 executes 2 units → completes
9. P3 executes 2 units → remaining BT = 2
10. P3 executes 2 units → completes

Gantt Chart (Time units):
| P1 | P2 | P3 | P1 | P2 | P3 | P1 | P3 | P3 |
0    2    4    6    8   10   12   14  16  18

------------------------------------------------
Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT):

Process   BT   WT   TAT
P1        6    8    14   (TAT = CT-BT_start=14-0=14, WT = TAT-BT=14-6=8)
P2        4    6    10   (TAT=10, WT=6)
P3        8    10   18   (TAT=18, WT=10)

------------------------------------------------
Average Times:
Average WT = (8 + 6 + 10)/3 = 8
Average TAT = (14 + 10 + 18)/3 = 14

------------------------------------------------
Observations:
1. Round Robin ensures **fair CPU sharing** among processes.
2. The **time quantum** affects performance:
   - Too small → more context switching overhead
   - Too large → behaves like FCFS
3. Suitable for **time-sharing systems** where responsiveness is important.
*/
