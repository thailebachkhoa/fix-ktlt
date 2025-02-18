#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 class Solution {
    public:
        bool IsInRange (int val, int a, int b) {
            int min = a < b ? a : b;
            int max = a > b ? a : b;
            return val >= min && val <= max;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* result = root;
            while (true) {
                if (IsInRange(result->val, p->val, q->val)) {
                    return result;
                }
                if (result->val > p->val && result->val > q->val) {
                    result = result->left;
                } else if (result->val < p->val && result->val < q->val) {
                    result = result->right;
                } else {
                    return result;
                }
            }
            return result;

        }
    };

int main() {
    
}
