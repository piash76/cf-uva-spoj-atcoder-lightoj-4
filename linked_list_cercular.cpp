#include<bits/stdc++.h>
using namespace std;


int n;
struct node    ///self referential structure
{
    int data;
    struct node *next;  ///pointing to next node
};

struct node *head=NULL,*last;

void creation()
{
    int i,val;
    struct node *t;

    head=new node;

    cin>>val;
    head->data=val;
    head->next=head;

    last=new node;
    last=head;  ///saving head in last

    for(i=1;i<n;i++)
    {
        cin>>val;
        t=new node;

       t->data=val;
        t->next=last->next;

        last->next=t;

        last=t;


    }


}


void display()
{

    struct node *p=new node;
    p=head;


    /*do
    {
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=head);*/
    while(1)
    {
         printf("%d\n",p->data);
         if(p->next==head) break;
        p=p->next;
    }


}










int main()
{
    cin>>n;

    creation();
    display();



}
