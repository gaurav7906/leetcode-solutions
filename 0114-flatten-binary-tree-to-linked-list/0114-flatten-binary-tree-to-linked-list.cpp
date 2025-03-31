class Solution {
public:
    void getlist(TreeNode* root1, TreeNode*& root2) {
        if (root1 == NULL)
            return;
        root2->right = root1;
        root2->left = NULL; 
        root2 = root2->right;
        TreeNode* leftChild = root1->left;
        TreeNode* rightChild = root1->right;
        getlist(leftChild, root2);
        getlist(rightChild, root2);
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* temp = dummy;
        getlist(root, temp);
        root = dummy->right;
    }
};
