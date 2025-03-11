class Solution {
public:
    bool solve(TreeNode* leftPtr, TreeNode* rightPtr) {
        if (leftPtr == NULL && rightPtr == NULL)
            return true;
        if (leftPtr == NULL || rightPtr == NULL) 
            return false;
        if (leftPtr->val != rightPtr->val) {
            return false;
        }
            return solve(leftPtr->left, rightPtr->right) &&  solve(leftPtr->right, rightPtr->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};