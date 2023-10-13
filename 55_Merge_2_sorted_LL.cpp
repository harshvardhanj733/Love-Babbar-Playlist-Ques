#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.

    if(first == NULL && second == NULL){
        return NULL;
    }
    else if(first == NULL){
        return second;
    }
    else if(second == NULL){
        return first;
    }

    Node<int>* firstTraverse = first;
    Node<int>* secondTraverse = second;

    Node<int>* result = NULL;
    Node<int>* resultTraverse = NULL;

    if(first->data <= second->data){
        result = first;
        resultTraverse = first;

        firstTraverse = firstTraverse->next;
    }
    else{
        result = second;
        resultTraverse = second;

        secondTraverse = secondTraverse->next;
    }

    while(firstTraverse != NULL && secondTraverse != NULL){
        if(firstTraverse->data <= secondTraverse->data){
            resultTraverse->next = firstTraverse;
            firstTraverse = firstTraverse->next;
            resultTraverse = resultTraverse->next;
        }
        else{
            resultTraverse->next = secondTraverse;
            secondTraverse = secondTraverse->next;
            resultTraverse = resultTraverse->next;
        }
    }
    while(firstTraverse != NULL){
        resultTraverse->next = firstTraverse;
        firstTraverse = firstTraverse->next;
        resultTraverse = resultTraverse->next;
    }
    while(secondTraverse != NULL){
        resultTraverse->next = secondTraverse;
        secondTraverse = secondTraverse->next;
        resultTraverse = resultTraverse->next;
    }

    return result;
    
}
