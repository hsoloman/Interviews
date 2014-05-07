// reverse a singly linked list
// needs to be tested


struct Node{
    Node * next; 
    int value;
}


// return pointer to new head
Node * reverse(Node * head){
    // return null if null, return head if size == 1
    if (head == null || head->next== null) return head;

    Node * last = head;
    Node * current = head.next;

    while (current != null){
        Node * next = current.next; // could be null
        current.next = last;
        last = current;
        current = next;
    }

    return last;
}
