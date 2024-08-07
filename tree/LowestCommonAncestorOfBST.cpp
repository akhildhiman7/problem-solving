/**
 * @file LowestCommonAncestorOfBST.cpp
 * @brief Solution to the LeetCode problem "Lowest Common Ancestor of a Binary Search Tree"
 * @link https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. The LCA of two nodes `p` and `q` in a BST is the lowest node that has both `p` and `q` as descendants.
 * 
 * Intuition:
 * In a BST, the left subtree of a node contains only nodes with keys less than the node's key, and the right subtree contains only nodes with keys greater than the node's key. This property allows us to determine the LCA by comparing the values of `p` and `q` with the current node's value.
 * 
 * Approach:
 * - Start from the root node and compare the values of `p` and `q` with the current node's value.
 * - If both `p` and `q` are smaller than the current node, move to the left subtree.
 * - If both `p` and `q` are greater than the current node, move to the right subtree.
 * - If one is smaller and the other is greater, the current node is the LCA.
 * 
 * Time Complexity:
 * - O(h), where h is the height of the BST.
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @brief Finds the lowest common ancestor (LCA) of two given nodes in a BST.
     * 
     * @param root The root node of the BST
     * @param p The first given node
     * @param q The second given node
     * @return TreeNode* The LCA of the two given nodes
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

