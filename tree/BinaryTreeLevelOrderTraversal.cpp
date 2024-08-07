/**
 * @file BinaryTreeLevelOrderTraversal.cpp
 * @brief Solution to the LeetCode problem "Binary Tree Level Order Traversal"
 * @link https://leetcode.com/problems/binary-tree-level-order-traversal/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 * 
 * Intuition:
 * The idea is to use a queue to traverse the binary tree level by level. We enqueue the root node and a `nullptr` marker to indicate the end of a level. For each node, we process its value and enqueue its children. When we encounter a `nullptr` marker, we know we have finished processing a level, so we store the values of that level and add another `nullptr` marker if there are more nodes to process.
 * 
 * Approach:
 * - Use a queue to keep track of the nodes at the current level.
 * - Enqueue the root node and a `nullptr` marker.
 * - Process each node in the queue, enqueueing its children and adding the node's value to a temporary list.
 * - When encountering a `nullptr` marker, store the temporary list of values and reset the list for the next level.
 * - Repeat until all levels are processed.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(n), where n is the number of nodes in the binary tree. This is the space used by the queue.
 */

#include <vector>
#include <queue>
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
     * @brief Performs level order traversal of a binary tree.
     * 
     * @param root The root node of the binary tree
     * @return vector<vector<int>> The level order traversal of the binary tree's nodes' values
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        vector<int> temp;
        
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(nullptr);
        
        while (!qu.empty()) {
            TreeNode *curr = qu.front();
            qu.pop();
            
            if (!curr) {
                res.push_back(temp);
                temp.clear();
                
                if (qu.empty()) {
                    break;
                }
                qu.push(nullptr);
                continue;
            }
            
            temp.push_back(curr->val);
            
            if (curr->left) {
                qu.push(curr->left);
            }
            if (curr->right) {
                qu.push(curr->right);
            }
        }
        
        return res;
    }
};

