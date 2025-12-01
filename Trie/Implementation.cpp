#include <bits/stdc++.h>
using namespace std;

class Implementation {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEndOfWord = false;

        TrieNode() {
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    Implementation() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->children[c - 'a'] == nullptr){
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

int main() {

}
