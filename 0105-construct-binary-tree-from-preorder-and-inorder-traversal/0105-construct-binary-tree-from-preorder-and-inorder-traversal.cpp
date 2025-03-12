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
    TreeNode* Solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int&index, map<int,int>&mp){
        if(start>end)
        return NULL;
        int rootval=preorder[index];
        int inindex=mp[rootval];
        index++;
        TreeNode*root=new TreeNode(rootval);
        root->left=Solve(preorder,inorder,start,inindex-1,index,mp);
        root->right=Solve(preorder,inorder,inindex+1,end,index,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
     {
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
    }
    int index=0, n=inorder.size();
  return   Solve(preorder,inorder,0,n-1,index,mp);
    }
};
// class Solution {
// public:
//     TreeNode* build(vector<int>& preorder, int pstart, int pend,
//                     vector<int>& inorder, int istart, int iend,
//                     const unordered_map<int, int>& mp)
//     {
//         if (pend < pstart || iend < istart) {
//             return nullptr;
//         }
        
//         TreeNode* root = new TreeNode(preorder[pstart]);
//         int proot = mp.at(root->val);
//         int left = proot - istart;
//         root->left = build(preorder, pstart + 1, pstart + left,
//                            inorder, istart, proot - 1, mp);
//         root->right = build(preorder, pstart + left + 1, pend,
//                             inorder, proot + 1, iend, mp);
//         return root;
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int, int> mp;
//         for (int i = 0; i < inorder.size(); i++) {
//             mp[inorder[i]] = i;
//         }
//         return build(preorder, 0, preorder.size() - 1,
//                      inorder, 0, inorder.size() - 1, mp);
//     }
// };
