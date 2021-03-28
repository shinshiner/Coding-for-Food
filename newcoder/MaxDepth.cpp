/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int getDepth(TreeNode* node){
        if(node == NULL) {return 0;}
        else{return 1 + max(getDepth(node->left), getDepth(node->right));}
    }
    int maxDepth(TreeNode* root) {
        int ans=getDepth(root);
        return ans;
    }
};