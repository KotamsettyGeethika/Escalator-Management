 #include <stdio.h>
 #include <stdlib.h>

#define MAX_PEOPLE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int count;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(Queue *q, int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    q->count++;
}

void dequeue(Queue *q) {
    if (q->front == NULL)
        return;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->count--;
}

int main() {
    Queue *q = createQueue();

    printf("Welcome to the escalator!\n");
    printf("Enter 0 to exit\n");
    while (1) {
        printf("Enter the number of people getting on the escalator: ");
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        if (q->count + num > MAX_PEOPLE) {
            printf("Sorry, the escalator is full. Please wait for the next one.\n");
            continue;
        }
        for (int i = 0; i < num; i++)
            enqueue(q, i);
        printf("%d people are on the escalator.\n", q->count);
        dequeue(q);
        printf("%d people are on the escalator.\n", q->count);
    }
    printf("Exiting the escalator program.\n");
    return 0;
}
