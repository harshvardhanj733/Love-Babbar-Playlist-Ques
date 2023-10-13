#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> * current = head;

    if(current == NULL){
        return NULL;
    }

    LinkedListNode<int> * prev = NULL;
    while(current != NULL){
        LinkedListNode<int> * next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return prev;

}