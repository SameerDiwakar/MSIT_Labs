#include <bits/stdc++.h>
using namespace std;

void fifo(vector<int> pages, int n, int frames) {
    queue<int> q;
    unordered_set<int> s;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(pages[i]) == s.end()) {
            faults++;
            if (s.size() == frames) {
                int val_to_remove = q.front();
                q.pop();
                s.erase(val_to_remove);
            }
            s.insert(pages[i]);
            q.push(pages[i]);
        }
    }
    cout << "FIFO Page Faults: " << faults << endl;
}

void lru(vector<int> pages, int n, int frames) {
    list<int> l;
    unordered_map<int, list<int>::iterator> pos;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        
        if (pos.find(currentPage) != pos.end()) {
            l.erase(pos[currentPage]); 
        } else {
            faults++;
            if (l.size() == frames) {
                int lru_val = l.back();
                l.pop_back();
                pos.erase(lru_val);
            }
        } 
        
        l.push_front(currentPage);
        pos[currentPage] = l.begin();
    }
    cout << "LRU Page Faults: " << faults << endl;
}

int findOptimalReplacement(const vector<int>& f, const vector<int>& pages, int current_index, int n) {
    int farthest = current_index;
    int index_to_replace = -1;

    for (int j = 0; j < f.size(); j++) {
        int page_in_frame = f[j];
        int next_use = n;
        
        for (int k = current_index + 1; k < n; k++) {
            if (pages[k] == page_in_frame) {
                next_use = k;
                break;
            }
        }

        if (next_use > farthest) {
            farthest = next_use;
            index_to_replace = j;
        }
    }
    return index_to_replace;
}

void optimal(vector<int> pages, int n, int frames) {
    vector<int> f;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        
        if (find(f.begin(), f.end(), currentPage) == f.end()) {
            faults++;
            
            if (f.size() < frames) {
                f.push_back(currentPage);
            } else {
                int index_to_replace = findOptimalReplacement(f, pages, i, n);
                f[index_to_replace] = currentPage;
            }
        }
    }

    cout << "Optimal Page Faults: " << faults << endl;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int n = pages.size();
    int frames = 4;
    
    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);
    
    return 0;
}

// FIFO Page Faults: 7
// LRU Page Faults: 6
// Optimal Page Faults: 6
/*
------------------------------------------------
Page Replacement Policies and Page Faults
------------------------------------------------

Definition:
- **Page**: A fixed-size block of virtual memory.
- **Page Fault**: Occurs when a process requests a page that is **not in main memory**.
  - The OS must load the page from secondary storage (like disk) into memory.
  - Causes **slight delay**, as disk access is slower than RAM.
  
- **Page Replacement Algorithms** are used when:
  - Memory frames are full
  - A new page must be loaded
  - Some existing page must be replaced to minimize page faults

------------------------------------------------
Common Algorithms:
------------------------------------------------

1. FIFO (First-In-First-Out):
   - Replaces the **oldest loaded page** in memory.
   - Uses a queue structure.
   - Advantage: Simple to implement.
   - Disadvantage: May replace frequently used pages → higher page faults.

2. LRU (Least Recently Used):
   - Replaces the page that has **not been used for the longest time**.
   - Advantage: Considers actual usage, often better than FIFO.
   - Uses a stack or counter to track usage.

3. Optimal (OPT):
   - Replaces the page that **will not be used for the longest time in the future**.
   - Minimizes page faults theoretically.
   - Cannot be implemented in practice, used as a benchmark.

------------------------------------------------
Example:
------------------------------------------------

Memory Frames: limited
Page Reference String: (example execution)
Output:

FIFO Page Faults: 7
LRU Page Faults: 6
Optimal Page Faults: 6

Step-by-step Explanation:

1. FIFO:
   - Pages replaced in **order of arrival**.
   - 7 page faults occurred because some pages were replaced even if needed soon.

2. LRU:
   - Pages replaced were those **least recently used**.
   - 6 page faults occurred, slightly better than FIFO.

3. Optimal:
   - Pages replaced were those **not needed for the longest future time**.
   - 6 page faults occurred, same as LRU in this example.
   - Represents **minimum possible page faults**.

------------------------------------------------
Summary:
- **Page Fault**: Triggered when requested page is absent in memory.
- Page replacement algorithms decide **which page to remove** when memory is full.
- FIFO → simple but can be inefficient.
- LRU → practical and efficient.
- Optimal → theoretical minimum page faults.
- Goal: Reduce page faults to improve system performance.

*/
