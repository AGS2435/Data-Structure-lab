#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if((rear+1)%MAX==front){
        printf("Queue overflow");
        }
        else{
            if(front==-1){
                front=0;
                }
            rear=(rear+1)%MAX;
            queue[rear]=x;
            printf("%d is inserted \n", queue[rear]);
            }
        }

void dequeue(){
    if(front==-1){
        printf("Queue underflow");

    }
        else{
            printf("%d is deleted \n   ", queue[front]);
            if(front==rear){
                front=rear=-1;
                }
                else{
                    front=(front+1)%MAX;
                    }
        }
}

void display(){
    if(front==-1){
        printf("Empty queue");

    }
        else{
            printf("Queue elements: \n");
            int i=front;
            while(1){
                printf("%d ", queue[i]);
                if(i==rear){
                    break;
                    }
                i=(i+1)%MAX;
                }
            }
        }


int main(){
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();

    enqueue(2);
    display();
    return 0;
    }

