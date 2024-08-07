/**
 * @file KthSmallestElementInBST.cpp
 * @brief Solution to the LeetCode problem "Kth Smallest Element in a BST"
 * @link https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the root of a binary search tree and an integer `k`, return the `k`-th smallest element in the tree.
 * 
 * Intuition:
 * In a binary search tree (BST), an in-order traversal visits the nodes in ascending order. Therefore, by performing an in-order traversal, we can visit the nodes in the sorted order and keep a count of the visited nodes until we reach the `k`-th smallest element.
 * 
 * Approach:
 * - Perform an in-order traversal of the BST.
 * - Keep a counter to count the nodes visited.
 * - When the counter reaches `k`, store the value of the current node.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree, in the worst case if `k` is `n`.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space used by the system stack during the recursive calls.
 */

#include <iostream>
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
    int currCount = 0;
    int result = 0;
    
    /**
     * @brief Helper function to perform in-order traversal and find the k-th smallest element.
     * 
     * @param root The current node
     * @param k The k-th position to find
     */
    void helper(TreeNode *root, int &k) {
        if (!root || currCount >= k) {
            return;
        }
        
        helper(root->left, k);
        
        currCount++;
        if (currCount == k) {
            result = root->val;
            return;
        }
        
        helper(root->right, k);
    }
    
    /**
     * @brief Finds the k-th smallest element in the BST.
     * 
     * @param root The root node of the binary search tree
     * @param k The k-th position to find
     * @return int The k-th smallest element in the BST
     */
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return result;
    }
};

