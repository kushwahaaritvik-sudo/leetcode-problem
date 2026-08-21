class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        // Both subtrees are empty
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Only one subtree is empty
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Values and both child subtrees must match
        return p->val == q->val &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // An empty tree is considered a subtree
        if (subRoot == nullptr) {
            return true;
        }

        // root is empty, but subRoot is not
        if (root == nullptr) {
            return false;
        }

        // Check at the current node, then search both children
        return isIdentical(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};