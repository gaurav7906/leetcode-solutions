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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
        return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            int level=q.size();
            double sum=0.0;
            for(int i=0;i<level;i++){
                 TreeNode*temp=q.front();
                 double node=temp->val;
                 q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
                
                sum+=node;
            }
            sum=sum/level;
            ans.push_back(sum);
        }
        return ans;
    }
};