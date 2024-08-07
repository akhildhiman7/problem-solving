/**
 * @file ValidateBinarySearchTree.cpp
 * @brief Solution to the LeetCode problem "Validate Binary Search Tree"
 * @link https://leetcode.com/problems/validate-binary-search-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 * 
 * Intuition:
 * To validate if a binary tree is a BST, we need to ensure that each node's value lies within a valid range. For the root node, the range is the whole integer range. For each subsequent node, the valid range is updated based on the node's parent's value. This can be achieved using a recursive approach.
 * 
 * Approach:
 * - Use a helper function that takes the current node, the lower bound, and the upper bound as parameters.
 * - For each node, check if its value is within the valid range.
 * - Recursively validate the left and right subtrees with updated ranges.
 * - The base case for the recursion is when the node is `nullptr`.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space used by the system stack during the recursive calls.
 */

#include <limits.h>
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
     * @brief Helper function to validate the binary search tree.
     * 
     * @param root The current node
     * @param lower The lower bound for the current node's value
     * @param upper The upper bound for the current node's value
     * @return bool True if the subtree rooted at the current node is a valid BST, otherwise false
     */
    bool isValidBSTHelper(TreeNode* root, long lower, long upper) {
        if (!root) {
            return true;
        }
        
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        
        return isValidBSTHelper(root->left, lower, root->val) && isValidBSTHelper(root->right, root->val, upper);
    }

    /**
     * @brief Determines if the binary tree is a valid binary search tree.
     * 
     * @param root The root node of the binary tree
     * @return bool True if the binary tree is a valid BST, otherwise false
     */
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};

