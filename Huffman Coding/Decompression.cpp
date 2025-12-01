#include <bits/stdc++.h>
using namespace std;

class Decompression {
public:
    unordered_map<char, string> encoder;
    unordered_map<string, char> decoder;

private:
    class Node {
    public:
        char data;
        int cost;
        Node* left;
        Node* right;

        Node(char data, int cost) {
            this->data = data;
            this->cost = cost;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

public:
    Decompression(string feeder, string check) {
        unordered_map<char, int> fmap;

        for(char c : feeder) {
            if(fmap.find(c) == fmap.end()) {
                fmap[c] = 0;
            }
            fmap[c] = fmap[c] + 1;
        }

        auto cmp = [](Node* a, Node* b) {
            return a->cost > b->cost;
        };

        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

        for(auto &it : fmap) {
            Node* node = new Node(it.first, it.second);
            pq.push(node);
        }

        while(pq.size() > 1) {
            Node* first = pq.top(); pq.pop();
            Node* second = pq.top(); pq.pop();

            Node* newNode = new Node('\0', first->cost + second->cost);
            newNode->left = first;
            newNode->right = second;

            pq.push(newNode);
        }

        Node* ft = pq.top();
        pq.pop();

        initEncoderDecoder(ft, "");

        // replicate Java behavior exactly
        string lowerCheck = check;
        for(char &c : lowerCheck) c = tolower(c);

        if(lowerCheck == "encode") {
            cout << Encoder(feeder);
        } else {
            cout << Decoder(Encoder(feeder));
        }
    }

private:
    void initEncoderDecoder(Node* node, string osf) {
        if(node == nullptr) {
            return;
        }

        if(node->left == nullptr && node->right == nullptr) {
            encoder[node->data] = osf;
            decoder[osf] = node->data;
        }

        initEncoderDecoder(node->left, osf + "0");
        initEncoderDecoder(node->right, osf + "1");
    }

public:
    string Encoder(string word) {
        string sb = "";
        for(char c : word) {
            sb += encoder[c];
        }
        return sb;
    }

    string Decoder(string code) {
        string key = "";
        string ans = "";
        for(char c : code) {
            key += c;
            if(decoder.find(key) != decoder.end()) {
                ans += decoder[key];
                key = "";
            }
        }
        return ans;
    }
};

int main() {
    string word = "abcd";
    Decompression dp(word, "decode");
}
