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
// class Solution {
// public:
//     int lehtheight=1;
//     int rightheight=1;
//     bool isBalanced(TreeNode* root)
//      {
       
//     }
//     void heightcheck( int lehtheight,int rightheigh)
// };
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        return height!=-1;
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if (lh == -1 || rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 +max(lh, rh);
    }
};