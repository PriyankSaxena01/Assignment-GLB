#include <bits/stdc++.h>
using namespace std;

class CountWords {
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

    int wordCount(TrieNode* root) {
        if(root == nullptr) return 0;

        int count = 0;
        if(root->isEndOfWord){
            count++;
        }

        for(int i = 0; i < 26; i++){
            if(root->children[i] != nullptr){
                count += wordCount(root->children[i]);
            }
        }

        return count;
    }
};

int main() {

}
