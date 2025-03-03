#include "iostream"

using namespace std;

class LRU_Cache {
    public:
        class Node {
            public:
                int key, value;
                Node *prev, *next;

                Node(const int k, const int v) {
                    key = k;
                    value = v;
                    prev = nullptr;
                    next = nullptr;
                }
        };
    //Creating dummy nodes.
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> map;

    // Helper Functions
    void add_node(Node *new_node) const {
        Node *old_next = head->next;

        head->next = new_node;
        new_node->prev = head;

        new_node->next = old_next;
        old_next->prev = new_node;
    }

    void delete_node(Node *old_node) {
        Node *old_prev = old_node->prev;
        Node *old_next = old_node->next;

        old_prev->next = old_next;
        old_next->prev = old_prev;

        delete old_node;

    }

    void bring_node_to_front(Node *node) const {
        // Detach connection
        Node *old_prev = node->prev;
        Node *old_next = node->next;

        old_prev->next = old_next;
        old_next->prev = old_prev;

        //Create new connection
        old_next = head->next;

        head->next = node;
        node->prev = head;

        node->next = old_next;
        old_next->prev = node;
    }

    explicit LRU_Cache(const int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        bring_node_to_front(map[key]);
        return map[key]->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map.erase(key);
            delete_node(map[key]);
        }
        if (map.size() == capacity) {
            cout<<"Capacity exceeded\n"<<"Deleting least recently used...."<<endl;
            map.erase(tail->prev->key);
            delete_node(tail->prev);
        }

        Node *new_node = new Node(key, value);
        add_node(new_node);
        map[key] = new_node;
    }
};

int main() {
    LRU_Cache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
}