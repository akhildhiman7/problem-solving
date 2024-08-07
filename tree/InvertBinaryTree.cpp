/**
 * @file InvertBinaryTree.cpp
 * @brief Solution to the LeetCode problem "Invert Binary Tree"
 * @link https://leetcode.com/problems/invert-binary-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the root of a binary tree, invert the tree, and return its root.
 * 
 * Intuition:
 * The idea is to recursively swap the left and right children of each node in the tree. Starting from the root, we swap its left and right children and then recursively invert the left and right subtrees. This way, we achieve the inverted binary tree.
 * 
 * Approach:
 * - If the current node is `nullptr`, return `nullptr`.
 * - Recursively invert the left subtree.
 * - Recursively invert the right subtree.
 * - Swap the left and right children of the current node.
 * - Return the current node.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space used by the system stack during the recursive calls.
 */

#include <algorithm> // For std::swap
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
     * @brief Inverts a binary tree.
     * 
     * @param root The root node of the binary tree
     * @return TreeNode* The root node of the inverted binary tree
     */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
};

