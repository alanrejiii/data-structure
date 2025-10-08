#include <stdio.h>
int queue[100]; 
int front = -1, rear = -1;
int size = 0; 

void enqueue(int value) {
    if (rear == size - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void Exit()
{
    printf("Exit from the program.");
}
int main() {
    int operations, choice, value;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5.Exit\n");
    for (int i = 0; i < operations; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                Exit();
                return 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

