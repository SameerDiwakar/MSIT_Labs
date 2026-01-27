#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes and resources: ";
    cin >> n >> m;

    int alloc[n][m], maxNeed[n][m], avail[m];

    cout << "Enter Allocation matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Max matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxNeed[i][j];

    cout << "Enter Available resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    int need[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxNeed[i][j] - alloc[i][j];

    bool finish[n] = {false};
    int safe[n], count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safe[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is NOT in safe state\n";
            return 0;
        }
    }

    cout << "Safe sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safe[i] << " ";
    cout << endl;

    return 0;
}


// Enter number of processes and resources: 3 2 
// Enter Allocation matrix:
// 0 1
// 2 0
// 3 0
// Enter Max matrix:
// 7 5
// 3 2
// 9 0
// Enter Available resources:
// 3 3
// System is NOT in safe state

/*
------------------------------------------------
Banker's Algorithm for Deadlock Avoidance
------------------------------------------------

Definition:
- Banker's Algorithm is a **deadlock avoidance algorithm** used in operating systems.
- It checks whether allocating resources to a process will leave the system in a **safe state**.
- A **safe state** is one in which all processes can eventually get the resources they need and complete without causing deadlock.

Key Points:
1. System knows:
   - Number of processes (n) and resources (m)
   - Allocation matrix: how many resources each process is currently holding
   - Max matrix: maximum resources each process may need
   - Available resources vector: currently available resources
2. Algorithm simulates resource allocation:
   - Checks if system can allocate requested resources without entering an unsafe state.
   - If yes → safe, else → not safe.
3. Prevents deadlock **before it occurs**.

------------------------------------------------
Example:
------------------------------------------------

Input:

Enter number of processes and resources: 3 2

Allocation matrix:
P1: 0 1
P2: 2 0
P3: 3 0

Max matrix:
P1: 7 5
P2: 3 2
P3: 9 0

Available resources:
3 3

Step-by-step Execution:

1. Calculate the Need matrix = Max - Allocation

   Need:
   P1: 7-0=7, 5-1=4 → 7 4
   P2: 3-2=1, 2-0=2 → 1 2
   P3: 9-3=6, 0-0=0 → 6 0

2. Check if processes can finish with Available resources (3 3):

   - P1: Needs 7 4 → Not ≤ Available (3 3) → Cannot finish
   - P2: Needs 1 2 → ≤ Available (3 3) → Can finish
     → Allocate P2 → Release its resources: Available = Available + Allocation(P2) = (3+2, 3+0) = (5,3)
   - P1: Needs 7 4 → Not ≤ Available (5 3) → Cannot finish
   - P3: Needs 6 0 → Not ≤ Available (5 3) → Cannot finish

3. Since not all processes can finish → System is **NOT in safe state**.

------------------------------------------------
Output:
System is NOT in safe state.

------------------------------------------------
Observations:
- Banker's Algorithm **avoids deadlock** by ensuring only safe allocations.
- Safe state → sequence of process execution exists without deadlock.
- Unsafe state → system may enter deadlock if resources are allocated.
- This example shows an **unsafe state**, so some processes cannot finish safely.

*/

