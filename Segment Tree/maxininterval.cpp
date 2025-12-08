#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int startInterval;
    int endInterval;
    Node* left;
    Node* right;
    Node(int s,int e){
        startInterval=s;
        endInterval=e;
        left=NULL;
        right=NULL;
        data=0;
    }
};

class MaxInInterval{
public:
    static Node* root;

    static void populate(vector<int>& arr){
        root=build(arr,0,arr.size()-1);
    }

    static Node* build(vector<int>& arr,int s,int e){
        if(s==e){
            Node* node=new Node(s,e);
            node->data=arr[s];
            return node;
        }
        Node* node=new Node(s,e);
        int mid=(s+e)/2;
        node->left=build(arr,s,mid);
        node->right=build(arr,mid+1,e);
        node->data=max(node->left->data,node->right->data);
        return node;
    }

    static void inorder(){
        callInorder(root);
    }

    static void callInorder(Node* node){
        if(node==NULL) return;
        cout<<node->data<<" ";
        callInorder(node->left);
        callInorder(node->right);
    }

    static int maxQuery(int start,int end){
        return findMaxQuery(root,start,end);
    }

    static int findMaxQuery(Node* node,int start,int end){
        if(node->startInterval>=start && node->endInterval<=end){
            return node->data;
        }else if(node->startInterval>end || node->endInterval<start){
            return INT_MIN;
        }else{
            return max(findMaxQuery(node->left,start,end),findMaxQuery(node->right,start,end));
        }
    }
};

Node* MaxInInterval::root=NULL;

int main(){
    vector<int> arr={1,2,3,4};
    MaxInInterval::populate(arr);
    MaxInInterval::inorder();
    cout<<endl;
    cout<<MaxInInterval::maxQuery(1,2);
}
