/* Given a sequence of pairs of characters, one-per-line:

B C
A B
A D

Where each sequence corresponds to a parent-child relationship

Construct a tree from the sequence of inputs, and return the root of the tree (in this case, it would be A)

      A
     / \
    D   B
     \ / \    
      C   Q

*/

// vector<pair<char, char> > input; 

struct Node {
        Node(char _val): val(_val), parent(0){}
        char val;
        node* parent;
        set<Node*> children;
};


Node * create_tree(const vector<pair<char, char> >& input) {
    map<char, Node*> nodes;
    
    for (vector::iterator it = input.begin() ; it != input.end() ; ++it){
        Node * parent(0);
        parent = nodes.find(it->first);
        if (!parent) {
            parent = new Node(it->first);
            nodes.insert(parent);
        } 
        
        Node * child(0);
        child = nodes.find(it->second);
        if (!child){
            child = new Node(it->second);
            nodes.insert(child);
        }

        parent->children.insert(child);        
        child->parent = parent;    
    }
    
    Node * current = nodes.first();
    if (!current) return 0;
    
    while(current->parent){current = current->parent);
    return current;
}
