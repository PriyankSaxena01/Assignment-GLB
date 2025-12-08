#include <bits/stdc++.h>
using namespace std;

class DeleteString {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
    };

    TrieNode* root;

    TrieNode* deleteKey(TrieNode* root, string key) {
        if(root == nullptr || key.empty()) return root;
        deleteHelper(root, key, 0);
        return root;
    }

private:
    bool deleteHelper(TrieNode* node, string key, int depth) {
        if(node == nullptr) return false;

        if(depth == key.length()) {
            if(node->isEndOfWord) {
                node->isEndOfWord = false;
            }
            return isEmpty(node);
        }

        int index = key[depth] - 'a';
        TrieNode* child = node->children[index];

        if(child == nullptr) {
            return false;
        }

        bool shouldDeleteChild = deleteHelper(child, key, depth + 1);

        if(shouldDeleteChild) {
            node->children[index] = nullptr;
        }

        return !node->isEndOfWord && isEmpty(node);
    }

    bool isEmpty(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != nullptr) return false;
        }
        return true;
    }
};

int main() {

}
