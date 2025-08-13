#include <iostream>
#include <vector>
#include <algorithm>

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

    int totaltime = 0;
    for (auto &process : processes) {
        totaltime += process.btime;
        cout << "Process ID: " << process.pid
             << " Arrival Time: " << process.atime
             << " Burst Time: " << process.btime
             << " Waiting Time: " << totaltime - process.btime - process.atime
             << " Turnaround Time: " << totaltime - process.atime << endl;
    }
}

int main() {
    vector<Process> processes = {
        Process(1, 0, 5),
        Process(3, 2, 6),
        Process(2, 1, 7)
    };
    fcfs(processes);
    return 0;
}
