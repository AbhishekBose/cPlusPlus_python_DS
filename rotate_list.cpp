#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node
{
    int val;
    struct Node* next;
};


class Stack
{
    int top;
    public:
        int a[1000];
        Stack()
        {
            top=-1;
            cout<<"Value of top when initialized is"<<top<<endl;
        }
        int pop();
        bool push(int x);
        bool isEmpty();
};
        bool Stack::push(int x)
        {
            cout<<"Valueof top when about to push is:::"<<top<<endl;
            if(top>=999)
            {
                cout<<"Valueof top when about to push is:::"<<top<<endl;
                cout<<"Stack Overflow"<<endl;
                return false;
            }
            else
            {
                top+=1;
                a[top]=x;
                return true;
            }
        }
        int Stack::pop()
        {
            if(top<0)
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
            {
                int x=a[top];
                top-=1;
                return x;
            }
        }



void insert_at_end(struct Node** head,int dat)
{
    struct Node *to_be_inserted= NULL;
    struct Node *head_ptr= NULL;
    to_be_inserted = (struct Node*)malloc(sizeof(struct Node));
    to_be_inserted->val=dat;
    head_ptr = (struct Node*)malloc(sizeof(struct Node));
    head_ptr = *head;
    cout<<"The value in the head is::"<<head_ptr->val<<endl;
    while(head_ptr->next!=NULL){
        head_ptr=head_ptr->next;
    }
    head_ptr->next=to_be_inserted;
    
}

void traverse_list(struct Node* head)
{
    struct Node *traverse= NULL;
    traverse = head;
    while(traverse!=NULL)
    {
        cout<<traverse->val<<endl;
        traverse=traverse->next;
    }
}

bool check_if_palindrome(struct Node* head1)
{
    struct Node *temp = NULL;
    temp = head1;   
    Stack s1;
    while(temp!=NULL)
    {
        //cout<<"Temp val is::"<<temp->val<<endl;
        bool c=s1.push(temp->val);
        if (c==false)
        {
            break;
        }
        if(temp->next==NULL)
        {
            break;
        }
        else
        {
        temp=temp->next;
        }
    } 
   // cout<<temp->val<<endl;
    //cout<<head1->val;
    bool decision = false;
    struct Node *temp2 = head1;
    while(temp2!=NULL)
    {
        int val1=s1.pop();
        int val2 = temp2->val;
        if(val1==val2)
        {
            cout<<"val1 is::"<<val1<<endl;
            cout<<"val2 is::"<<val2<<endl;
            decision = true;
        }
        else
        {
            decision = false;
            break;
        }
        temp2=temp2->next;
    }
    cout<<"decision is::"<<decision<<endl;
    return decision;
}

struct Node* rotate_list(struct Node** head1,int k)
{
    
    // struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = NULL;
    struct Node *temp5 = NULL;
    temp=*head1;
    temp5=*head1;
    if(temp==NULL)
    {
        return temp;
    }
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            return temp5;
        }
        else
        {
            int temp2=temp->val;
            temp->val = temp->next->val;
            temp->next->val=temp2;
            temp=temp->next->next;
        }
    }
    cout<<"The value of temp is:::"<<temp5->val<<endl;
}

// 27 -> 67 -> 10 -> 64 -> 85 -> 4

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    // struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node*)malloc(sizeof(struct Node));
    head3=NULL;
    head->val=1;
    head->next=NULL;
    //insert_at_end(&head,1);
    insert_at_end(&head,2);
    insert_at_end(&head,3);
    insert_at_end(&head,4);
    insert_at_end(&head,5);
    insert_at_end(&head,6);
    cout<<endl;
    // head3=rotate_list(&head,2);
    // cout<<"The value of temp2 is:::"<<head3->val<<endl;
    traverse_list(head);
    // Stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // int x=s.pop();
    bool g= check_if_palindrome(head);
    cout<<"Is palindrome::"<<g;
    // cout<<"the popped element is:::"<<x<<endl;
}