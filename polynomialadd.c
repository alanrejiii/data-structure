#include <stdio.h>
#include <stdlib.h>

#define MAX 5  


typedef struct {
    int arr[MAX];
    int front;
    int rear;
} CircularQueue;


void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}


void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {  
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Enqueued %d\n", value);
    }
}


int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {  
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return value;
    }
}


void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int i = q->front;
        printf("Queue elements: ");
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    
    display(&queue);

    
    printf("Dequeued: %d\n", dequeue(&queue));

    
    enqueue(&queue, 60);

    
    display(&queue);

    return 0;
}