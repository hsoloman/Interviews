// Write a method to merge two sorted linked lists and return the sorted, merged linked list.
// Write the code for any classes/structs that you will need and state any assumptions.
// Please talk out loud your thought process with me.

typename T
class Node {
    T val;
    Node * next;
};

Node * merge(Node* a, node* b){
    Node * ret(nullptr);
    Node * current(nullptr);
    
    if (a && !b){return a;}
    else if (!a && b){return b;}
    else if (!a && !b){return nullptr;}
    
    if (a->val < b->val) {
        ret = a;
        a = a->next;
    } else {
        ret = b;
        b = b->next;
    }
    current = ret;
    
    while (a && b){
        if (a->val < b->val){
            current->next = a;
            current = a;    
            a = a->next;
        } else {
            current-> next = b;
            current = b;
            b = b->next;
        }
    }

    if (a) {current->next = a;}
    else if (b) {current->next = b;}
    else {current->next = nullptr;}
    
    return ret;
}
