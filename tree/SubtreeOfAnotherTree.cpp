/**
 * @file SubtreeOfAnotherTree.cpp
 * @brief Solution to the LeetCode problem "Subtree of Another Tree"
 * @link https://leetcode.com/problems/subtree-of-another-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the roots of two binary trees `root` and `subRoot`, return true if there is a subtree of `root` with the same structure and node values of `subRoot` and false otherwise. A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.
 * 
 * Intuition:
 * To determine if one tree is a subtree of another, we need to compare each node in the main tree (`root`) with the root node of the subtree (`subRoot`). If we find a node in the main tree that matches the root of the subtree, we then check if the subtree rooted at this node is identical to `subRoot` using a helper function.
 * 
 * Approach:
 * - Define a helper function `areEqual` that checks if two trees are identical.
 * - Use a recursive function `isSubtree` to traverse the main tree.
 * - For each node in the main tree, use the helper function to check if the subtree rooted at this node is identical to `subRoot`.
 * 
 * Time Complexity:
 * - O(n * m), where n is the number of nodes in the main tree and m is the number of nodes in the subtree.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the main tree. This is the space used by the system stack during the recursive calls.
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
    /**
     * @brief Checks if two binary trees are identical.
     * 
     * @param p The root node of the first binary tree
     * @param q The root node of the second binary tree
     * @return bool True if the trees are identical, otherwise false
     */
    bool areEqual(TreeNode *p, TreeNode *q) {
        if (p && q) {
            return p->val == q->val && areEqual(p->left, q->left) && areEqual(p->right, q->right);
        }
        return !p && !q;
    }
    
    /**
     * @brief Determines if there is a subtree of `root` with the same structure and node values of `subRoot`.
     * 
     * @param root The root node of the main binary tree
     * @param subRoot The root node of the subtree
     * @return bool True if `subRoot` is a subtree of `root`, otherwise false
     */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return subRoot == nullptr;
        }
        
        return areEqual(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

