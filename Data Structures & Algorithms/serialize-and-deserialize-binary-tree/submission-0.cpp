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

#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N,";
        }
        
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string token;
        stringstream ss(data);
        
        while (getline(ss, token, ',')) {
            q.push(token);
        }
        
        return buildTree(q);
    }


    TreeNode* buildTree(queue<string>& q) {
        string val = q.front();
        q.pop();
        
        if (val == "N") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(val));
        
        node->left = buildTree(q);
        node->right = buildTree(q);
        
        return node;
    }
};
