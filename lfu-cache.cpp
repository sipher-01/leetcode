class LFUCache
{
public:
    struct Node{
        int val;
        int key;
        int cnt;
        Node* prev;
        Node* next;
        Node(int KEY, int VAL){
            key = KEY;
            val = VAL;
            cnt = 1;
        }
    };
    private:
    struct list{
        int size;
        Node* head;
        Node* tail;
     list(){
         head = new Node(0,0);
         tail = new Node(0,0);
         head->next = tail;
         tail->prev = head;
         size = 0;
     }
     void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        node->prev = head;
        size++;
    }
     void deleteNode(Node* node){
         Node* nextNode = node->next;
         Node* prevNode = node->prev;
         prevNode->next = nextNode;
         nextNode->prev = prevNode;
         size--;
     }

    };
public:
    unordered_map<int,list*>freqList;
    unordered_map<int,Node*>keyNode;
    int maxcap;
    int minFreq;
    int curcap;
    LFUCache(int capacity)
    {
        // Write your code here.
        maxcap = capacity;
        minFreq = 0;
        curcap = 0;
    }

    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqList[node->cnt]->size==0){
            minFreq++;
        }
        list* nextHigherList = new list();
        if(freqList.find(node->cnt+1) != freqList.end()){
            nextHigherList = freqList[node->cnt+1];
        }
        node->cnt += 1;
        nextHigherList->addNode(node);
        freqList[node->cnt] = nextHigherList;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key) != keyNode.end()){
            Node* temp = keyNode[key];
            int res = temp->val;
            updateFreqList(temp);
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxcap == 0)return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }
        else {
            if(curcap==maxcap){
                list* l = freqList[minFreq];
                keyNode.erase(l->tail->prev->key);
                freqList[minFreq]->deleteNode(l->tail->prev);
                curcap--;
            }
            curcap++;
            minFreq = 1;
            list* newList = new list();
            if(freqList.find(minFreq) != freqList.end()){
                newList = freqList[minFreq];
            }
            Node* node = new Node(key,value);
            newList->addNode(node);
            keyNode[key] = node;
            freqList[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */