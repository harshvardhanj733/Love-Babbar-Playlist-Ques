/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    if(head->next == NULL){
        return head;
    }
    // Write your code here.
    Node* slow = head; Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            break;
        }
    }
    if(fast == NULL){
        return head;
    }
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    if (fast != head) {
        fast->next = NULL;
    }
    else{
        while(fast->next != head){
            fast = fast->next;
        }
        fast->next = NULL;
    }

    return head;
}