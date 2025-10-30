#include <stdio.h>
#define MAX 5

int queue[MAX];
int front,rear=-1;

void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue overflow");
    }
        else{
            if(front==-1){
                front=0;
            }
            rear++;
            queue[rear]=x;
            printf("%d is inserted \n", queue[rear]);

        }
}

void dequeue(){
    if(front==-1||front>rear){
        printf("Queue underflow");

    }
        else{
            printf("%d is deleted \n   ", queue[front++]);
        }
}

void display(){
    if(front==-1){
        printf("Empty queue");

    }
        else{
            for(int i=front; i<=rear; i++){
                printf("%d ", queue[i]);
            }
        }
}

int main(){
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
    }

