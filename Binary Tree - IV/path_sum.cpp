/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void checksum(TreeNode* root,int& sum ,int target,bool& ans)
    {
        if(root==NULL)
        return;
        int k=root->val;
        if(root->left==NULL && root->right==NULL && sum+k==target)
        {
            ans=true;
        }
        int add=sum+k;
        checksum(root->left,add,target,ans);
        checksum(root->right,add,target,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
    bool ans=false;
    int add=0;
    checksum(root,add,targetSum,ans);
    return ans;
    }
};
