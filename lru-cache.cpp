class LRUCache {
public:
    class Node{
     public: 
        int key, val;
        Node *next, *prev;
        Node(int KEY, int VAL){key = KEY; val = VAL;}
    };
// initialisation
    int cap;
    unordered_map<int,Node*>mp;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

// ADD Node and Delete Node
    void addNode(Node *newNode) {
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode) {
        Node *delPrev=delNode->prev;
        Node *delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node *resNode=mp[key];
            int res=resNode->val;

            mp.erase(key);
            deleteNode(resNode);

            addNode(resNode);
            mp[resNode->key]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key) != mp.end()){
            Node *exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */