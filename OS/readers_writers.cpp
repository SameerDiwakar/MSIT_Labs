
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t rw_mutex;
sem_t mutex;
int read_count = 0;
int shared_data = 0;

const int NUM_READERS = 5;
const int NUM_WRITERS = 2;
const int READ_ITERATIONS = 3;
const int WRITE_ITERATIONS = 3;

void* reader(void* arg) {
    int reader_id = *((int*)arg);
    for (int i = 0; i < READ_ITERATIONS; i++) {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1)
            sem_wait(&rw_mutex);
        sem_post(&mutex);

        cout << "Reader " << reader_id << " is reading shared data = " << shared_data << endl;
        sleep(1);

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0)
            sem_post(&rw_mutex);
        sem_post(&mutex);

        sleep(1);
    }
    cout << "Reader " << reader_id << " has finished reading." << endl;
    return nullptr;
}

void* writer(void* arg) {
    int writer_id = *((int*)arg);
    for (int i = 0; i < WRITE_ITERATIONS; i++) {
        sem_wait(&rw_mutex);
        shared_data++;
        cout << "\tWriter " << writer_id << " is writing shared_data = " << shared_data << endl;
        sleep(1);
        sem_post(&rw_mutex);
        sleep(1);
    }
    cout << "\tWriter " << writer_id << " has finished writing." << endl;
    return nullptr;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], nullptr, reader, &reader_ids[i]);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], nullptr, writer, &writer_ids[i]);
    }

    for (int i = 0; i < NUM_READERS; i++)
        pthread_join(readers[i], nullptr);
    for (int i = 0; i < NUM_WRITERS; i++)
        pthread_join(writers[i], nullptr);

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    cout << "\nend.\n";
    return 0;
}


 


// Reader 1 is reading shared data = 0Reader 
// 2 is reading shared data = 0
// Reader 3 is reading shared data = 0
// Reader 4 is reading shared data = 0
// Reader 5 is reading shared data = 0
// 	Writer 1 is writing shared_data = 1
// 	Writer 2 is writing shared_data = 2
// Reader 1 is reading shared data = 2
// Reader 4 is reading shared data = 2
// Reader 3 is reading shared data = 2
// Reader 5 is reading shared data = 2
// Reader 2 is reading shared data = 2
// 	Writer 1 is writing shared_data = 3
// 	Writer 2 is writing shared_data = 4
// Reader 3 is reading shared data = 4
// Reader 4 is reading shared data = 4
// Reader 5 is reading shared data = 4
// Reader 2 is reading shared data = 4
// Reader 1 is reading shared data = 4
// 	Writer 1 is writing shared_data = 5
// Reader 3 has finished reading.
// Reader 4 has finished reading.
// Reader Reader Reader 1 has finished reading.
// 5	Writer 2 is writing shared_data =  has finished reading.6
// 2
//  has finished reading.
// 	Writer 1 has finished writing.
// 	Writer 2 has finished writing.

// end.



/*
------------------------------------------------
EXPERIMENT-6: Readers-Writers Problem
------------------------------------------------

Definition:
The Readers-Writers Problem is a classical synchronization problem in operating systems. 
It deals with scenarios where **multiple processes** want to access **shared data** simultaneously. 
The challenge is to allow **concurrent reading** by multiple readers, while ensuring that **writing is exclusive**, 
to prevent data inconsistency or corruption.

- Readers: Processes that only read the shared data. Multiple readers can access the data at the same time since 
  they do not modify it, which ensures no conflicts occur between them.
- Writers: Processes that modify or update the shared data. Only **one writer** is allowed to access the shared data 
  at any time. During writing, no readers can access the data to prevent **race conditions** or data corruption.

Key Points and Rules:
1. **Concurrent Reading**: Multiple readers can read the data simultaneously without any issues.
2. **Exclusive Writing**: Writers must have exclusive access; no other readers or writers can access the data during writing.
3. **Synchronization**: Mechanisms like **mutexes, semaphores, or monitors** are used to coordinate access and prevent conflicts.
4. **Priority Schemes**: Readers-first, writers-first, or fair access policies can be implemented depending on system requirements.
5. **Race Conditions Prevention**: Proper synchronization ensures that the data remains consistent and no updates are lost.
6. **Deadlock Avoidance**: Care must be taken to avoid deadlock situations when both readers and writers are waiting for each other.

------------------------------------------------
Example Execution:
------------------------------------------------

// Initial shared data = 0

Reader 1 is reading shared data = 0
Reader 2 is reading shared data = 0
Reader 3 is reading shared data = 0
Reader 4 is reading shared data = 0
Reader 5 is reading shared data = 0

Writer 1 is writing shared_data = 1
Writer 2 is writing shared_data = 2

Reader 1 is reading shared data = 2
Reader 4 is reading shared data = 2
Reader 3 is reading shared data = 2
Reader 5 is reading shared data = 2
Reader 2 is reading shared data = 2

Writer 1 is writing shared_data = 3
Writer 2 is writing shared_data = 4

Reader 3 is reading shared data = 4
Reader 4 is reading shared data = 4
Reader 5 is reading shared data = 4
Reader 2 is reading shared data = 4
Reader 1 is reading shared data = 4

Writer 1 is writing shared_data = 5

Reader 3 has finished reading.
Reader 4 has finished reading.
Reader 1 has finished reading.
Reader 5 has finished reading.
Reader 2 has finished reading.

Writer 1 has finished writing.
Writer 2 has finished writing.

// end

------------------------------------------------
Explanation:
1. Initially, all readers (R1-R5) read shared data simultaneously since no writers are active.
2. Writer 1 and Writer 2 write sequentially to shared_data. During writing, **no readers are allowed**.
3. After writers finish writing, readers read the updated data again.
4. Each reader prints its reading, and then signals completion.
5. Each writer prints its writing, and then signals completion.
6. The program ensures **data consistency** by synchronizing access: 
   - Multiple readers can read together.
   - Only one writer can write at a time with **no concurrent readers**.

------------------------------------------------
Observations:
- Demonstrates the classical **Readers-Writers synchronization problem**.
- Prevents **race conditions** and **data inconsistency**.
- Shows alternating access between readers and writers, respecting their constraints.
*/

