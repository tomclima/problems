#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26]; // Supports only lowercase English letters
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) 
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    void getAllWords(TrieNode* node, string prefix) {
        if (node->isEndOfWord)
            cout << prefix << endl; // Print the complete word
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                getAllWords(node->children[i], prefix + char(i + 'a'));
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    void printWordsWithPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) {
                cout << "No words found with prefix \"" << prefix << "\"\n";
                return;
            }
            node = node->children[index];
        }
        getAllWords(node, prefix);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("bat");
    trie.insert("ball");
    trie.insert("banana");

    string prefix;
    cout << "Enter prefix to search: ";
    cin >> prefix;

    cout << "Words with prefix \"" << prefix << "\":\n";
    trie.printWordsWithPrefix(prefix);

    return 0;
}
