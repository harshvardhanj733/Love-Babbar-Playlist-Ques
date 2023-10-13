/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

void reverse(Node* & s, Node* & head){
    Node* current = s;
    Node* prev = NULL;
    while(current!=NULL){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if(s == head){
        head = prev;
    }
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    int count = 1;
    Node* s = head; Node* e = head;
    Node* prev = NULL;
    while(e != NULL){
        if(count == k){
            Node* next = e->next;
            e->next = NULL;
            reverse(s, head);
            s->next = next;
            if(prev!=NULL){
                prev->next = e;
            }
            count = 1;
            prev = s;
            s = next;
            e = next;
        }
        else{
            count++;
            e = e->next;
        }
    }

    return head;
}