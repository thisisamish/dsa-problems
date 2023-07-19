// Written By - Amish Verma
// Both get and put operations take O(1) time
// We are using a DLL and a hashmap so SC is O(capacity)

class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };

    LRUCache(int _capacity) {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNodeAfterHead (Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* toRemove) {
        toRemove->prev->next = toRemove->next;
        toRemove->next->prev = toRemove->prev;
    }
    
    int get(int key_) {
        if (mapping.find(key_) == mapping.end()) {
            return -1;
        }
        Node* resNode = mapping[key_];
        int res = resNode->val;
        mapping.erase(key_);
        deleteNode(resNode);
        addNodeAfterHead(resNode);
        mapping[key_] = head->next;
        return res;
    }
    
    void put(int key_, int value) {
        if (mapping.find(key_) != mapping.end()) {
            Node* existingNode = mapping[key_];
            mapping.erase(key_);
            deleteNode(existingNode);
        }
        if (mapping.size() == capacity) {
            mapping.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNodeAfterHead(new Node(key_, value));
        mapping[key_] = head->next;
    }

private:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*> mapping;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */