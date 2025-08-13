#include <iostream>
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

void fcfs(Process processes[], int size) {
    // Sort by arrival time (using bubble sort for simplicity)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (processes[j].atime > processes[j + 1].atime) {
                swap(processes[j], processes[j + 1]);
            }
        }
    }

    int totaltime = 0;
    for (int i = 0; i < size; i++) {
        totaltime += processes[i].btime;
        cout << "Process ID: " << processes[i].pid
             << " Arrival Time: " << processes[i].atime
             << " Burst Time: " << processes[i].btime
             << " Waiting Time: " << totaltime - processes[i].btime - processes[i].atime
             << " Turnaround Time: " << totaltime - processes[i].atime << endl;
    }
}

int main() {
    Process processes[] = {
        Process(1, 0, 5),
        Process(3, 2, 6),
        Process(2, 1, 7)
    };
    int size = sizeof(processes) / sizeof(processes[0]);
    fcfs(processes, size);
    return 0;
}
