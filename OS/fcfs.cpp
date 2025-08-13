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
    for (auto &process : processes) {
        int waiting_time = totaltime - process.atime;
        if (waiting_time < 0) waiting_time = 0;
        totaltime += process.btime;
        int turnaround_time = totaltime - process.atime;

        cout << setw(8) << process.pid << "   "
             << setw(10) << process.atime << "   "
             << setw(10) << process.btime << "   "
             << setw(12) << waiting_time << "   "
             << setw(12) << turnaround_time << endl;
    }
}

int main() {
    vector<Process> processes = {
        Process(1, 0, 4),
        Process(2, 1, 3),
        Process(3, 2, 2),
        Process(4, 3, 1)
    };
    fcfs(processes);
    return 0;
}
