// code to implement a linked list
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void traverse_list(struct Node* head)
{
    struct Node *traverse= NULL;
    traverse = head;
    while(traverse!=NULL)
    {
        cout<<traverse->data<<endl;
        traverse=traverse->next;
    }
}

void insert_into_list(struct Node** head,int data)
{
    struct Node *to_be_inserted= NULL;
    to_be_inserted = (struct Node*)malloc(sizeof(struct Node));
    to_be_inserted->data=data;
    // while(head->next!=NULL){
    //     head=head->next;
    // }
    to_be_inserted->next = *head;
    // head->next=to_be_inserted;
    // to_be_inserted->next=NULL;
    *head=to_be_inserted;
}

// 1-2-3-4-5-6-7-8-9

void insert_at_end(struct Node** head,int dat)
{
    struct Node *to_be_inserted= NULL;
    struct Node *head_ptr= NULL;
    to_be_inserted = (struct Node*)malloc(sizeof(struct Node));
    to_be_inserted->data=dat;
    head_ptr = (struct Node*)malloc(sizeof(struct Node));
    head_ptr = *head;
    while(head_ptr->next!=NULL){
        head_ptr=head_ptr->next;
    }
    head_ptr->next=to_be_inserted;
    // while(*head->next!=NULL){
    //     *head=*head->next;
    // }
    // *head->next=to_be_inserted;
}
void insert_after_node(struct Node** head,int dat)
{
    
}
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
int get_count(struct Node **head_ref)
{
     struct Node* temp = *head_ref;

     if (temp->next!=NULL)
     {
         temp=temp->next;
         return 1+get_count(&temp);
     }
     else
     {
         return 1;
     }


}

// void reverse_list(struct Node** head)
// {

// }


void reverse_list_1(struct Node** head)
{
    struct Node *prev=NULL;
    struct Node *curr=NULL;
    struct Node *next=NULL;
    curr=*head;
    cout<<"Current data is:::"<<curr->data<<"\n";
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
    struct Node *temp = NULL;
    temp=*head;
    cout<<"reversed list is as follows\n";
    traverse_list(temp);
}

struct Node* reverse_list_2(struct Node** head,struct Node** prev)
{   
    if(*head==NULL)
    {
        cout<<"New traverse list is:::"<<endl;
        return *prev;
        // traverse_list(*prev);
    }
    else
    {
        struct Node *next= NULL;
        struct Node *cur = *head;
        next=cur->next;
        cur->next = *prev;
        *prev=cur;
        reverse_list_2(&next,&*prev);
    }

}

struct Node* reverse_list_3(struct Node* head,int k)
{   
    struct Node *prev=NULL;
    struct Node *curr=NULL;
    struct Node *next=NULL;
    curr=head;
    cout<<"Current data is:::"<<curr->data<<"\n";
    int count=0;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count+=1;
    }
    // head=prev;

    if(next!=NULL)
    {
        head->next=reverse_list_3(next,k);
    }
    return prev;
}

void delete_from_list(struct Node** head,int dat)
{
    struct Node *prev= NULL;
    struct Node *tmp= NULL;
    prev=*head;
    tmp=*head;
    while(tmp!=NULL&&tmp->data!=dat){
        prev=tmp;
        tmp=tmp->next;
    }
    prev->next=tmp->next;
    free(tmp);

}
struct Node* merge_sorted2(struct Node* head1, struct Node* head2)
{
    struct Node *start1 = NULL;
    struct Node *start2 = NULL;
    struct Node *tmp = NULL;
    start1 = head1;
    start2 = head2;
    if(start1==NULL)
    {
        return start2;
    }
    if(start2 ==NULL)
    {
        return start1;
    }
    if(start1->data<start2->data)
    {
        start1->next=merge_sorted2(start1->next,start2);
    }
    else
    {
        tmp = start2;
        start2 = start2->next;
        tmp->next = start1;
        start1 = tmp;
        start1->next = merge_sorted2(start1->next,start2);
    }
    return start1;

}
void merge_sorted(struct Node** head1, struct Node** head2)
{
    struct Node *tmp1= NULL;
    struct Node *tmp2= NULL;
    struct Node *curr= NULL;
    struct Node *next= NULL;
    struct Node *start= NULL;
    tmp1=*head1;
    tmp2=*head2;

    if(tmp1->data<tmp2->data)
    {
        tmp1=*head1;
        tmp2=*head2;
        start=*head1;
    }
    else
    {
        tmp1=*head2;
        tmp2=*head1;
        start=*head2;
    }
    while(1)
    {
        cout<<"tmp1 data is::: "<<tmp1->data<<endl;
        cout<<"tmp2 data is::: "<<tmp2->data<<endl;
        if(tmp1->next==NULL)
        {
            tmp1->next=tmp2;
            cout<<"about to break"<<endl;
            break;
        }

        else if(tmp1->next->data>=tmp2->data)
        {
           curr=tmp1->next;
           next=tmp2->next;
           if(curr->data<next->data)
           {
           tmp2->next=tmp1->next;
           tmp1->next=tmp2;
           tmp1=curr;
           tmp2=next;}
           else{
               tmp1->next=tmp2;
               tmp2=curr;
               tmp1=next;
           }
        }
        else{
        tmp1=tmp1->next;    }
    }
    cout<<"The joined list is as follows"<<endl;
    traverse_list(start);
}


int main()
{
    struct Node *head = NULL;
    struct Node *head2 = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *temp = NULL;
    struct Node *temp2 = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head2 = (struct Node*)malloc(sizeof(struct Node));
    // first = (struct Node*)malloc(sizeof(struct Node));
    // second = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    insert_at_end(&head,2);
    insert_at_end(&head,3);
    insert_at_end(&head,5);
    // insert_at_end(&head,4);
    // insert_at_end(&head,5);
    // insert_at_end(&head,6);
    head2->data = 2;
    insert_at_end(&head2,4);
    insert_at_end(&head2,6);
    insert_at_end(&head2,10);
    // insert_at_end(&head2,10);
    // insert_at_end(&head2,11);
    // insert_at_end(&head2,12);

    // head->next=first;
    // first->data=6;
    // first->next=second;
    // second->data=9;
    // second->next=NULL;
    // traverse_list(head);
    // insert_into_list(&head,89);
    // insert_at_end(&head,90);
    // insert_at_end(&head,190);
    // insert_at_end(&head,290);
    // insert_at_end(&head,390);
    // cout<<endl<<"After insetion:::"<<endl;
    // traverse_list(head);
    // delete_from_list(&head,5);
    // // deleteNode(&head,5);
    // cout<<endl<<"After deletion:::"<<endl;
    traverse_list(head);
    cout<<endl;
    traverse_list(head2);
    // int count=get_count(&head);
    // cout<<"The count is:::"<<count<<"\n";
    // //reverse_list_1(&head);
    // temp2=reverse_list_3(head,3);
    // traverse_list(temp2);
    // merge_sorted(&head2,&head);
    struct Node *head3 = NULL;
    head3 = merge_sorted2(head,head2);
    cout<<"\n";
    traverse_list(head3);
    return 0;
}