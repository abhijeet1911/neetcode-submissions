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
private:
    unordered_map<int, int> inorder_map;
    int preorder_idx;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);

        int inorder_root_idx = inorder_map[root_val];

        root->left = arrayToTree(preorder, left, inorder_root_idx - 1);
        root->right = arrayToTree(preorder, inorder_root_idx + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_idx = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};
