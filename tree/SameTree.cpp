/**
 * @file SameTree.cpp
 * @brief Solution to the LeetCode problem "Same Tree"
 * @link https://leetcode.com/problems/same-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * 
 * Intuition:
 * The idea is to use a recursive approach to compare each corresponding node of the two trees. If the current nodes of both trees have the same value, recursively check their left and right subtrees. If any pair of nodes differ, the trees are not the same. If both nodes are `nullptr`, they are considered the same.
 * 
 * Approach:
 * - If both nodes are `nullptr`, return true.
 * - If one node is `nullptr` and the other is not, return false.
 * - If the values of the current nodes are different, return false.
 * - Recursively check the left and right subtrees.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the smaller tree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the smaller tree. This is the space used by the system stack during the recursive calls.
 */

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * @brief Checks if two binary trees are the same.
     * 
     * @param p The root node of the first binary tree
     * @param q The root node of the second binary tree
     * @return bool True if the trees are the same, otherwise false
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        
        return !p && !q;
    }
};

