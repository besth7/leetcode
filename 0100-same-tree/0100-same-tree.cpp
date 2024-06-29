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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> p1, q1;
        p1.push(p);
        q1.push(q);

        while(!p1.empty() || !q1.empty()) {
            TreeNode* t1 = p1.front();
            TreeNode* t2 = q1.front();
            if (!t1 && !t2) {
                p1.pop(); q1.pop();
                continue;
            }
            if (!t1 && t2 || t1 && !t2) return false;
            if (t1->val != t2->val) return false;
            p1.pop(); q1.pop();

            p1.push(t1->left);
            p1.push(t1->right);
            q1.push(t2->left);
            q1.push(t2->right);
        }
        return true;
    }
};