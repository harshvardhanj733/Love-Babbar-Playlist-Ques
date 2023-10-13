#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    int arr[100001] = {0};

    Node* ptr = head;
    arr[ptr->data]++;

    while(ptr->next != NULL){
        if(arr[ptr->next->data] == 0){
            arr[ptr->next->data]++;
            ptr = ptr->next;
        }
        else{
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
    }
    return head;
}