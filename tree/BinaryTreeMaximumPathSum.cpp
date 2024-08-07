/**
 * @file BinaryTreeMaximumPathSum.cpp
 * @brief Solution to the LeetCode problem "Binary Tree Maximum Path Sum"
 * @link https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a non-empty binary tree, find the maximum path sum. The path may start and end at any node in the tree.
 * 
 * Intuition:
 * To find the maximum path sum, we need to consider paths that may pass through the root of each subtree. For each node, we calculate the maximum path sum including that node and update the global maximum path sum if necessary. The recursive function will return the maximum path sum starting from the current node and moving downward to its children.
 * 
 * Approach:
 * - Define a recursive helper function that calculates the maximum path sum starting from the current node.
 * - For each node, calculate the maximum path sum of its left and right subtrees.
 * - Update the global maximum path sum if the sum of the current node's value and the maximum path sums of its left and right subtrees is greater.
 * - Return the maximum path sum starting from the current node and moving downward to its children.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space used by the system stack during the recursive calls.
 */

#include <climits> // For INT_MIN
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
    int maxSum = INT_MIN;
    
    /**
     * @brief Helper function to calculate the maximum path sum starting from the current node.
     * 
     * @param root The current node
     * @return int The maximum path sum starting from the current node
     */
    int helper(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        // Calculate the maximum path sum including the current node and update the global maximum
        maxSum = max(maxSum, root->val + max(leftSum, 0) + max(rightSum, 0));
        
        // Return the maximum path sum starting from the current node and moving downward
        return max(0, root->val + max(leftSum, rightSum));
    }
    
    /**
     * @brief Finds the maximum path sum in the binary tree.
     * 
     * @param root The root node of the binary tree
     * @return int The maximum path sum in the binary tree
     */
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

