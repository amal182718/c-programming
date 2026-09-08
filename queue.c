#include <stdio.h>

int front = -1;
int rear = -1;
int MAX;

void display(int queue[]) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) { // Fixing the loop to include the 'rear' element
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void enqueue(int queue[], int value) {
    if (rear == MAX - 1) {
        printf("Queue is full (Overflow)\n");
    } else {
        if (front == -1) { // If it's the first element being added
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue\n", value);
    }
    display(queue);
}

void dequeue(int queue[]) {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    display(queue);
}

int main() {
    int choice, value;

    // Ask for the size of the queue
    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);

    // Declare the queue with the specified size
    int queue[MAX];

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
