#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int, Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    public:
    LRUCache(int capacity) {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }

    void set(int key, int value) {
        Node* new_node = new Node(key, value);
        // first element?
        if(head == nullptr) {
            head = tail = new_node;
        } else {
            if(mp.size() == cp) {
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                temp->prev = nullptr;
                mp.erase(temp->key);
                temp = nullptr;
                delete temp;
            }
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        mp[key] = new_node;
    }

    int get(int key) {
        int result = -1;
        //if data is in map
        if(mp.count(key) == 1) {
            result = mp[key]->value;
            Node* temp = head;
            while(temp->key != key && temp != nullptr) {
                temp = temp->next;
            }

            if(temp == head) {
                // do nothing
            } else if(temp == tail) {
                tail = tail->prev;
                tail->next = nullptr;
                temp->prev = nullptr;
                // set temp to be new head;
                temp->next = head;
                head->prev = temp;
                head = temp;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = nullptr;
                // set temp to be new head;
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        return result;
    }

    // Method for testing and debugging
    void show_cache() const {
      //  map<int, Node*>::iterator it = mp.cbegin();
      cout << "Printing map contents" << endl;
        for( auto it = mp.begin(); it != mp.cend(); ++it) {
            cout << it->first << ": " << it->second->value << endl;
          //  ++it;
        }

        cout << "Printing linked list contents" << endl;
        Node * temp = head;
        while(temp != nullptr) {
            cout << temp->key << ": " << temp->value << endl;
            temp = temp->next;
        }
    }
};


/**
 * Main method for testing the cache
 * input format:
 * First line of input will contain the number of lines containing or commands followed by the capacity of the cache.
 * The following lines can either contain or commands.
 * An input line starting with will be followed by a to be found in the cache.
 * An input line starting with will be followed by the and respectively to be inserted/replaced in the cache.
 */
int main() {
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0; i < n; i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
         l.show_cache();
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key, value);

         l.show_cache();
      }
   }
   return 0;
}
