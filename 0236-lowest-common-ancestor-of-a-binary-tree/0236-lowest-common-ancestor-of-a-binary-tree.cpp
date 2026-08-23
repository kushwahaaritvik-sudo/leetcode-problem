/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL){
            return NULL;
        }
        
        if(root->val==p->val||root->val==q->val){
            return root;
        }

       TreeNode* leftLCD =lowestCommonAncestor(root->left,p,q);
       TreeNode* rightLCD= lowestCommonAncestor(root->right,p,q);

       if(leftLCD && rightLCD){
        return root;
       }
       else if(leftLCD!=NULL){
        return leftLCD;
       }
       else{
         return rightLCD;
       }
    }
};