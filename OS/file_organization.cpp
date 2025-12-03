#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Record {
    int id;
    string name;
};

void sequentialFile() {
    ofstream fout("sequential.txt", ios::out);
    int n;
    cout << "Enter number of records: ";
    cin >> n;
    Record r;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Name: ";
        cin >> r.id >> r.name;
        fout << r.id << " " << r.name << endl;
    }
    fout.close();
    cout << "\nStored Sequentially in 'sequential.txt'\n";

    ifstream fin("sequential.txt", ios::in);
    cout << "\nReading Sequentially:\n";
    while (fin >> r.id >> r.name) {
        cout << r.id << " " << r.name << endl;
    }
    fin.close();
}

void directFile() {
    fstream file("direct.dat", ios::in | ios::out | ios::binary | ios::trunc);
    int n;
    cout << "Enter number of records: ";
    cin >> n;
    Record r;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Name: ";
        cin >> r.id >> r.name;
        file.write((char*)&r, sizeof(r));
    }

    cout << "\nEnter record number to read (0-based index): ";
    int index;
    cin >> index;
    file.seekg(index * sizeof(r));
    file.read((char*)&r, sizeof(r));
    cout << "\nRecord at index " << index << ": " << r.id << " " << r.name << endl;
    file.close();
}

void indexedSequentialFile() {
    ofstream dataFile("data.txt");
    ofstream indexFile("index.txt");
    int n;
    cout << "Enter number of records: ";
    cin >> n;
    Record r;
    int indexStep = 2;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Name: ";
        cin >> r.id >> r.name;
        streampos pos = dataFile.tellp();
        dataFile << r.id << " " << r.name << endl;
        if (i % indexStep == 0)
            indexFile << r.id << " " << pos << endl;
    }
    dataFile.close();
    indexFile.close();
    cout << "\nIndexed data stored in 'data.txt' and 'index.txt'\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- FILE ORGANIZATION TECHNIQUES ---\n";
        cout << "1. Sequential File\n";
        cout << "2. Direct (Random Access) File\n";
        cout << "3. Indexed Sequential File\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sequentialFile(); break;
            case 2: directFile(); break;
            case 3: indexedSequentialFile(); break;
            case 4: cout << "Exiting\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}


// --- FILE ORGANIZATION TECHNIQUES ---
// 1. Sequential File
// 2. Direct (Random Access) File
// 3. Indexed Sequential File
// 4. Exit
// Enter choice: 1
// Enter number of records: 2
// Enter ID and Name: 101 Rohit
// Enter ID and Name: 102 Sameer

// Stored Sequentially in 'sequential.txt'

// Reading Sequentially:

// --- FILE ORGANIZATION TECHNIQUES ---
// 1. Sequential File
// 2. Direct (Random Access) File
// 3. Indexed Sequential File
// 4. Exit
// Enter choice: 2
// Enter number of records: 2
// Enter ID and Name: 101 Jatin
// Enter ID and Name: 102 Sarthak

// Enter record number to read (0-based index): 1

// Record at index 1: 102 Sarthak

// --- FILE ORGANIZATION TECHNIQUES ---
// 1. Sequential File
// 2. Direct (Random Access) File
// 3. Indexed Sequential File
// 4. Exit
// Enter choice: 3
// Enter number of records: 2
// Enter ID and Name: 101 Rohit
// Enter ID and Name: 102 Sameer

// Indexed data stored in 'data.txt' and 'index.txt'

// --- FILE ORGANIZATION TECHNIQUES ---
// 1. Sequential File
// 2. Direct (Random Access) File
// 3. Indexed Sequential File
// 4. Exit
// Enter choice: 4
// Exiting


/*
------------------------------------------------
FILE ORGANIZATION TECHNIQUES
------------------------------------------------

Definition:
File organization refers to the way records are stored in a file so that they can be efficiently accessed, read, and updated. 
It affects the performance of searching, inserting, updating, and deleting records in a file.

Common Techniques:

1. Sequential File Organization:
   - Records are stored **one after another** in order of entry or key value.
   - Easy to implement and read **sequentially**.
   - Efficient for batch processing or printing all records.
   - Searching for a specific record may be slow since we may need to scan all preceding records.

2. Direct (Random Access) File Organization:
   - Records can be **accessed directly** using a record number or offset.
   - Uses **binary files** with `seekg`/`seekp` to move to a specific position.
   - Faster than sequential files for retrieval of individual records.
   - Insertions or deletions can be more complex because of fixed-size record positions.

3. Indexed Sequential File Organization:
   - Combines **sequential and direct access**.
   - An **index file** stores key values and pointers to actual records in the data file.
   - Sequential processing is possible while still enabling fast search through the index.
   - Supports **efficient insertion, deletion, and update** without scanning the whole file.

------------------------------------------------
Summary:
- **Sequential Files** → simple, good for sequential access and batch operations.
- **Direct Files** → fast random access, ideal for frequent searches or updates.
- **Indexed Sequential Files** → hybrid approach, supports both sequential and direct access efficiently.
*/
