/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build_tree(vector<int> pre, vector<int> vin) {
        if(pre.size()==0) {return NULL;}
        TreeNode *root = new TreeNode(pre[0]);
        if(pre.size()==1) {return root;}
        int pos = 0;
        for(int i=0;i<vin.size();i++) {
            if(vin[i] == pre[0]) {pos = i; break;}
        }
        vector<int> left_pre(pre.begin()+1, pre.begin()+1+pos), left_vin(vin.begin(), vin.begin()+pos);
        root->left = build_tree(left_pre, left_vin);
        vector<int> right_pre(pre.begin()+pos+1, pre.end()), right_vin(vin.begin()+pos+1, vin.end());
        root->right = build_tree(right_pre, right_vin);
        
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *root;
        vector<int> ans;
        root = build_tree(pre, vin);
        
        return root;
    }
};