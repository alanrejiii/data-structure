
#include <stdio.h>

int deque[100]; 
int front = -1, rear = -1;
int size = 0;

void insertFront(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[front] = value;
        printf("%d inserted at front\n", value);
    } else if (front == 0) {
        front = size - 1;
        deque[front] = value;
        printf("%d inserted at front\n", value);
    } else {
        deque[--front] = value;
        printf("%d inserted at front\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    } else if (rear == size - 1) {
        rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    } else {
        deque[++rear] = value;
        printf("%d inserted at rear\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from front\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("%d deleted from rear\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        int i = front;
        printf("Deque: ");
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        } else {
            while (i < size) {
                printf("%d ", deque[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("Enter the size of the deque: \n");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("\nDeque Operations:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-6): \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: \n");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: \n");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}