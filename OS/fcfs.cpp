#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Process {
public:
    int pid;
    int atime;
    int btime;

    Process(int pid, int atime, int btime) {
        this->pid = pid;
        this->atime = atime;
        this->btime = btime;
    }
};

void fcfs(vector<Process> &processes) {
    // Sort by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.atime < b.atime;
    });

    cout << "Process ID  Arrival Time   Burst Time     Waiting Time   Turnaround Time" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    int totaltime = 0;
    int total_wait = 0;
    int total_turn = 0;

    for (auto &process : processes) {
        int waiting_time = totaltime - process.atime;
        if (waiting_time < 0) waiting_time = 0;

        totaltime += process.btime;
        int turnaround_time = totaltime - process.atime;

        total_wait += waiting_time;
        total_turn += turnaround_time;

        cout << setw(8) << process.pid << "   "
             << setw(10) << process.atime << "   "
             << setw(10) << process.btime << "   "
             << setw(12) << waiting_time << "   "
             << setw(12) << turnaround_time << endl;
    }

    int n = processes.size();
    cout << "\nAverage Waiting Time:    " << fixed << setprecision(2) << (double)total_wait / n << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (double)total_turn / n << endl;
}

int main() {
    vector<Process> processes = {
        Process(1, 0, 5),
        Process(2, 1, 7),
        Process(3, 2, 6),
        Process(4, 3, 9)
    };
    fcfs(processes);
    return 0;
}

// Process ID  Arrival Time   Burst Time     Waiting Time   Turnaround Time
// ----------------------------------------------------------------------
//        1            0            5              0              5
//        2            1            7              4             11
//        3            2            6             10             16
//        4            3            9             15             24

// Average Waiting Time:    7.25
// Average Turnaround Time: 14.00


// FCFS (First Come First Serve) is one of the simplest CPU scheduling algorithms in operating
// systems. It schedules processes in the order of their arrival—the process that arrives first
// gets executed first. It’s a non-preemptive scheduling algorithm, meaning once a process
// starts executing, it runs to completion.

/*
FCFS (First Come First Serve) Scheduling

FCFS is one of the simplest CPU scheduling algorithms. It schedules processes 
strictly in the order of their arrival time. The process that arrives first is 
executed first. This is a non-preemptive scheduling algorithm, which means that 
once a process starts executing, it continues until it finishes without any 
interruption.

------------------------------------------------
Example
------------------------------------------------

Processes:
Process   AT   BT
P1        0    5
P2        1    7
P3        2    6
P4        3    9

Gantt Chart (FCFS):
P1 |-----| P2 |-------| P3 |------| P4 |---------|
0        5            12          18            27

Explanation:
- P1 arrives at time 0 and starts immediately.
- P2 arrives at time 1 but waits until P1 finishes at time 5.
- P3 arrives at time 2 and waits until P2 completes at time 12.
- P4 arrives at time 3 and waits until P3 completes at time 18.

------------------------------------------------
Waiting Time
------------------------------------------------
P1 = 0  
P2 = 5  – 1 = 4  
P3 = 12 – 2 = 10  
P4 = 18 – 3 = 15  

------------------------------------------------
Turnaround Time
------------------------------------------------
P1 = 5  – 0 = 5  
P2 = 12 – 1 = 11  
P3 = 18 – 2 = 16  
P4 = 27 – 3 = 24  
*/
