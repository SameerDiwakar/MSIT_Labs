#include <iostream>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t mutexS;
sem_t emptyS;
sem_t fullS;
int x = 0;

void producer() {
    sem_wait(&emptyS);
    sem_wait(&mutexS);
    cout << "\nProducer produced item " << x++;
    sem_post(&mutexS);
    sem_post(&fullS);
}

void consumer() {
    sem_wait(&fullS);
    sem_wait(&mutexS);
    cout << "\nConsumer consumed item " << --x;
    sem_post(&mutexS);
    sem_post(&emptyS);
}

int main() {
    int choice;
    sem_init(&mutexS, 0, 1);
    sem_init(&emptyS, 0, 10);
    sem_init(&fullS, 0, 0);

    cout << "\n1. Producer\n2. Consumer\n3. Exit";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                return 0;
            default:
                cout << "\nInvalid choice!";
        }
    }
}




// 1. Producer
// 2. Consumer
// 3. Exit
// Enter your choice: 1

// Producer produced item 0
// Enter your choice: 1

// Producer produced item 1
// Enter your choice: 2

// Consumer consumed item 1
// Enter your choice: 2

// Consumer consumed item 0
// Enter your choice: 2


/*
------------------------------------------------
Producer-Consumer Problem
------------------------------------------------

Definition:
- The Producer-Consumer problem is a classical **synchronization problem** in operating systems.
- It involves two types of processes sharing a common **buffer**:
  1. **Producer**: Produces items and adds them to the buffer.
  2. **Consumer**: Consumes items from the buffer.
- The buffer has **limited size**, so producers must wait if it is full, and consumers must wait if it is empty.
- Synchronization ensures **data consistency** and prevents **race conditions**.

Key Points:
1. **Shared buffer**: Where produced items are stored temporarily.
2. **Mutual exclusion**: Only one process can modify the buffer at a time.
3. **Synchronization**: Producers wait if the buffer is full; consumers wait if the buffer is empty.

------------------------------------------------
Example Execution:
------------------------------------------------

Menu:
1. Producer
2. Consumer
3. Exit

User Interaction:

Enter your choice: 1
- Producer produced item 0
Buffer: [0]

Enter your choice: 1
- Producer produced item 1
Buffer: [0, 1]

Enter your choice: 2
- Consumer consumed item 1
Buffer: [0]

Enter your choice: 2
- Consumer consumed item 0
Buffer: []

Enter your choice: 2
- Buffer is empty, consumer cannot consume

------------------------------------------------
Explanation:

1. **Producer 1** produces item 0 → adds to buffer.
2. **Producer 2** produces item 1 → adds to buffer.
3. **Consumer 1** consumes item 1 → removes it from buffer.
4. **Consumer 2** consumes item 0 → removes it from buffer.
5. When the buffer is empty, consumer cannot consume until a producer adds a new item.

------------------------------------------------
Observations:
- Demonstrates the **classic producer-consumer synchronization problem**.
- Ensures no **buffer underflow** or **overflow**.
- Multiple producers and consumers can work simultaneously if synchronized.
- Requires semaphores or mutexes in actual OS implementations to prevent race conditions.

*/
