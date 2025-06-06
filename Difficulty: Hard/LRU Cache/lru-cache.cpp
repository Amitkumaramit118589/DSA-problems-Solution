//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  int capacity;
    std::list<std::pair<int, int>> cacheList; // Stores key-value pairs in order of use
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap; // Maps keys to iterators in the list

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1; // Key not found
        }

        // Move the accessed key-value pair to the front of the list
        cacheList.splice(cacheList.begin(), cacheList, it->second);

        return it->second->second; // Return the value
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // Key already exists, update its value and move it to the front
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            it->second->second = value;
            return;
        }

        // If cache is full, remove the least recently used item
        if (cacheMap.size() == capacity) {
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        // Add the new key-value pair to the front of the list and update the map
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends