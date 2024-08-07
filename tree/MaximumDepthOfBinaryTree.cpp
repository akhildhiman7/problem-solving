/**
 * @file MaximumDepthOfBinaryTree.cpp
 * @brief Solution to the LeetCode problem "Maximum Depth of Binary Tree"
 * @link https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * Intuition:
 * The maximum depth of a binary tree can be found using a depth-first search (DFS) approach. Starting from the root, we recursively calculate the maximum depth of the left and right subtrees and add 1 (for the current node) to get the depth of the current subtree. The base case for the recursion is when the node is `nullptr`, in which case the depth is 0.
 * 
 * Approach:
 * - If the root is `nullptr`, return 0.
 * - Recursively calculate the maximum depth of the left and right subtrees.
 * - The maximum depth of the tree is the greater of the depths of the left and right subtrees plus 1 (for the current node).
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space used by the system stack during the recursive calls.
 */

#include <algorithm> // For std::max
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
     * @brief Finds the maximum depth of the binary tree.
     * 
     * @param root The root node of the binary tree
     * @return int The maximum depth of the binary tree
     */
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

