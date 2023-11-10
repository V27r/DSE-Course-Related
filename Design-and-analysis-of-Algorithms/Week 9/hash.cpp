#include <iostream>
#include <vector>
using namespace std;

const int tableSize = 100; // size of hash table

// Open hash table class
class OpenHashTable {
private:
    vector<int> table[tableSize]; // hash table
    int hash(int key); // hash function
public:
    void insert(int key); // insert key into hash table
    bool search(int key, int& numComparisons); // search for key in hash table
};

// Hash function using modulo operation
int OpenHashTable::hash(int key) {
    return key % tableSize;
}

// Insert key into hash table
void OpenHashTable::insert(int key) {
    int index = hash(key);
    table[index].push_back(key);
}

// Search for key in hash table
bool OpenHashTable::search(int key, int& numComparisons) {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        numComparisons++;
        if (table[index][i] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    OpenHashTable hashTable;
    int numKeys, key, numComparisons;
    cout << "Enter number of keys to insert: ";
    cin >> numKeys;
    cout << "Enter keys to insert: ";
    for (int i = 0; i < numKeys; i++) {
        cin >> key;
        hashTable.insert(key);
    }
    cout << "Enter key to search: ";
    cin >> key;
    numComparisons = 0;
    if (hashTable.search(key, numComparisons))
        cout << "Key found after " << numComparisons << " comparisons.\n";
    else 
        cout << "Key not found after " << numComparisons << " comparisons.\n";
    cout << "Enter key that is not in table: ";
    cin >> key;
    numComparisons = 0;
    if (hashTable.search(key, numComparisons)) 
        cout << "Key found after " << numComparisons << " comparisons.\n";
    else 
        cout << "Key not found after " << numComparisons << " comparisons.\n";
    return 0;
}
