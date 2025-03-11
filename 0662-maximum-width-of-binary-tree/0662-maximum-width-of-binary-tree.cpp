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

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
      queue<pair<TreeNode*,int>>q;
       int ans=0;
    q.push({root,0});
    while(!q.empty()){
        TreeNode*node=q.front().first;
        int minindex=q.front().second;
        int first,last;
        int n=q.size();
        for(int i=0;i<n;i++){
            int current_index=q.front().second-minindex;
            TreeNode*node=q.front().first;
            if(i==0) first=current_index;
            if(i==n-1) last=current_index;
                q.pop();
            if(node->left){
                q.push({node->left,(long long)current_index*2+1});
            }
            if(node->right){
                q.push({node->right,(long long)current_index*2+2});
            }
        }
       ans=max(ans,last-first+1);
    }
    return ans;
    }
};