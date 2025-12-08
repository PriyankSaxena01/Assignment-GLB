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

class LazyPropagation{
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
        node->data=node->left->data+node->right->data;
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

    static void update(int index,int value){
        root->data=callUpdate(root,index,value);
    }

    static int callUpdate(Node* node,int index,int value){
        if(index>=node->startInterval && index<=node->endInterval){
            if(index==node->startInterval && index==node->endInterval){
                node->data=value;
                return node->data;
            }else{
                int leftAnswer=callUpdate(node->left,index,value);
                int rightAnswer=callUpdate(node->right,index,value);
                node->data=leftAnswer+rightAnswer;
                return node->data;
            }
        }
        return node->data;
    }
};

Node* LazyPropagation::root=NULL;

int main(){
    vector<int> arr={1,2,3,4};
    LazyPropagation::populate(arr);
    LazyPropagation::inorder();
    cout<<endl;
    LazyPropagation::update(2,2);
    LazyPropagation::inorder();
}
