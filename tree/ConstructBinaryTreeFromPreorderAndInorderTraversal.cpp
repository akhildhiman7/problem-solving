/**
 * @file ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
 * @brief Solution to the LeetCode problem "Construct Binary Tree from Preorder and Inorder Traversal"
 * @link https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 * Intuition:
 * The first element of the `preorder` traversal is the root of the tree. By locating this root in the `inorder` traversal, we can determine the left and right subtrees. Recursively apply this logic to build the entire tree.
 * 
 * Approach:
 * - Use a hash map to store the index of each value in the `inorder` traversal for quick lookup.
 * - Define a recursive helper function that constructs the tree using the current segment of `preorder` and `inorder` traversals.
 * - The base case for recursion is when the segment is empty.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(n), where n is the number of nodes in the binary tree. This includes the space used by the hash map and the recursion stack.
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
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
    unordered_map<int, int> inoIndexes; // Map to store inorder indexes for quick lookup
    vector<int> pre, ino;
    
    /**
     * @brief Initializes the hash map for inorder indexes.
     */
    void initialize() {
        for (int i = 0; i < ino.size(); i++) {
            inoIndexes[ino[i]] = i;
        }
    }

    /**
     * @brief Helper function to construct the binary tree from preorder and inorder traversals.
     * 
     * @param preStart The start index of the current preorder segment
     * @param preEnd The end index of the current preorder segment
     * @param inStart The start index of the current inorder segment
     * @param inEnd The end index of the current inorder segment
     * @return TreeNode* The root node of the constructed binary tree
     */
    TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(pre[preStart]);
        int inRootIndex = inoIndexes[root->val];
        int leftTreeSize = inRootIndex - inStart;

        root->left = helper(preStart + 1, preStart + leftTreeSize, inStart, inRootIndex - 1);
        root->right = helper(preStart + leftTreeSize + 1, preEnd, inRootIndex + 1, inEnd);

        return root;
    }

    /**
     * @brief Builds the binary tree from preorder and inorder traversals.
     * 
     * @param preorder The preorder traversal of the binary tree
     * @param inorder The inorder traversal of the binary tree
     * @return TreeNode* The root node of the constructed binary tree
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        ino = inorder;
        
        initialize();
        
        return helper(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

