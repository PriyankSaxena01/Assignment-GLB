
class Solution {
public:
bool isBST(TreeNode* root,long min, long max)
{
    if(root==NULL)
    return true;
    if(root->val>min && root->val<max)
    {
        bool left=isBST(root->left,min,root->val);
        bool right=isBST(root->right,root->val,max);
        return left && right;
    }
    return false;
}
    bool isValidBST(TreeNode* root) {
        long x=LONG_MIN;
        long y=LONG_MAX;
        return isBST(root,x,y);
    }
};
