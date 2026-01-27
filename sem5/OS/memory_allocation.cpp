#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void firstFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++) { // For each process
        for (int j = 0; j < m; j++) // For each block
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
    }
    cout << "\nFirst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

void bestFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nBest Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

void worstFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

int main() {
    int m, n;
    cout << "Enter number of memory blocks: ";
    cin >> m;
    vector<int> blockSize(m);
    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> processSize(n);
    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }
    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);
    return 0;
}
// Enter number of memory blocks: 5
// Enter sizes of memory blocks:
// 100 500 200 300 600
// Enter number of processes: 4
// Enter sizes of processes:
// 212 417 112 307

// First Fit Allocation:
// Process No.	Process Size	Block No.
//  1		212		2
//  2		417		5
//  3		112		2
//  4		307		Not Allocated

// Best Fit Allocation:
// Process No.	Process Size	Block No.
//  1		212		4
//  2		417		2
//  3		112		3
//  4		307		5

// Worst Fit Allocation:
// Process No.	Process Size	Block No.
//  1		212		5
//  2		417		2
//  3		112		5
//  4		307		Not Allocated



/*
------------------------------------------------
Memory Allocation in Operating Systems
------------------------------------------------

Definition:
Memory Allocation is the process of assigning blocks of memory to processes in a system. 
- The goal is to efficiently use available memory while minimizing fragmentation. 
- Dynamic memory allocation assigns memory to processes **at runtime** as they arrive.

Three common allocation strategies are:

1. First Fit:
   - Allocate the process to the **first block** that is large enough.
   - Simple and fast, but can cause external fragmentation if small blocks are left scattered.

2. Best Fit:
   - Allocate the process to the **smallest block** that is large enough.
   - Minimizes wasted memory, but may take longer to find the suitable block.

3. Worst Fit:
   - Allocate the process to the **largest available block**.
   - Leaves large blocks free for future processes, but may fail for medium-sized processes if largest blocks are used inefficiently.

------------------------------------------------
Example:
------------------------------------------------

Memory Blocks: 100, 500, 200, 300, 600
Processes: 212, 417, 112, 307

1. First Fit Allocation
-----------------------
Step-by-step:
- Process 1 (212) → First block ≥ 212 is block 2 (500) → allocate → remaining 288
- Process 2 (417) → First block ≥ 417 is block 5 (600) → allocate → remaining 183
- Process 3 (112) → First block ≥ 112 is block 2 (remaining 288) → allocate → remaining 176
- Process 4 (307) → No block ≥ 307 left → Not Allocated

Result:

Process No.  Process Size  Block No.
1           212           2
2           417           5
3           112           2
4           307           Not Allocated

2. Best Fit Allocation
----------------------
Step-by-step:
- Process 1 (212) → Smallest block ≥ 212 is block 4 (300) → allocate → remaining 88
- Process 2 (417) → Smallest block ≥ 417 is block 2 (500) → allocate → remaining 83
- Process 3 (112) → Smallest block ≥ 112 is block 3 (200) → allocate → remaining 88
- Process 4 (307) → Smallest block ≥ 307 is block 5 (600) → allocate → remaining 293

Result:

Process No.  Process Size  Block No.
1           212           4
2           417           2
3           112           3
4           307           5

3. Worst Fit Allocation
-----------------------
Step-by-step:
- Process 1 (212) → Largest block is 5 (600) → allocate → remaining 388
- Process 2 (417) → Largest block ≥ 417 is 2 (500) → allocate → remaining 83
- Process 3 (112) → Largest block ≥ 112 is 5 (remaining 388) → allocate → remaining 276
- Process 4 (307) → Largest block ≥ 307 is 5 (remaining 276 < 307) → cannot allocate → Not Allocated

Result:

Process No.  Process Size  Block No.
1           212           5
2           417           2
3           112           5
4           307           Not Allocated

------------------------------------------------
Observations:
- First Fit: Fast, may leave scattered unused small blocks.
- Best Fit: Minimizes wasted memory, usually allocates more processes successfully.
- Worst Fit: Leaves small blocks free, may fail to allocate large processes efficiently.
*/

 
