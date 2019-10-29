#include <stdio.h>

#define MAX 5

struct lqueue
{
    int front , rear ;
    int data[MAX];
};

void initialize(struct lqueue *q)
{
    q->front = -1;
    q->rear = -1;
}
void insert(struct lqueue *q,int element);
void delet(struct lqueue *q);
void displayall(struct lqueue *q);


int main ()
{
    struct lqueue q;
    int choice,element;
    char exit='n';
    initialize(&q);

    do
    {
        printf("Choices\n");
        printf("1. Insert Element \n");
        printf("2. delete Element \n");
        printf("3. Display all Elements \n");
        printf("4. exit \n");
        printf("Your Choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter Elements to insert :");
                         scanf("%d",&element);

                         insert(&q , element);
                         break;

            case 2 : delet(&q);
                          break;

            case 3: printf("\n All Elements :\n");
                         displayall(&q);
                         break;

            case 4: exit ='y';
        }
    }while(exit!='y');


}

void insert(struct lqueue *q , int element)
{
    if (q->front == (q->rear +1)%MAX ) printf("Queue Full\n");

    else
    {
        if (q->front == -1) q->front =0;

        q->rear = (q->rear+1)%MAX;

        q->data[q->rear] = element;
    }
}

void delet(struct lqueue *q)
{
    if (q->rear == -1) printf("Queue Empty\n");
    else
    {
        printf(" Element : %d Deleted\n",q->data[q->front]);

        if (q->front == q->rear)
            { q->front = q->rear = -1; }

        else
            q->front = (q->front+1)%MAX;

        printf("Queue After Deletion :\n");
        displayall(q);
    }
}

void displayall(struct lqueue *q)
{

    if (q->rear == -1) printf("Queue Empty\n");
    else
    {
        int counter;
        counter = q->front;

        while (1)
        {
            if (counter == q->rear)
            {
                printf("%d ",q->data[counter]);
                break;
            }


           /*if (counter != MAX ) printf("%d ",q->data[counter]);

           else  if (counter == MAX) counter = counter%MAX;
            else*/
            printf("%d ",q->data[counter]);
            counter = (counter+1)%MAX;

        }
        printf("\n");
    }
}

