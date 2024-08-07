/**
 * @file SerializeAndDeserializeBinaryTree.cpp
 * @brief Solution to the LeetCode problem "Serialize and Deserialize Binary Tree"
 * @link https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
 * You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * 
 * Intuition:
 * The idea is to use pre-order traversal to serialize the tree. For deserialization, we use the same pre-order traversal sequence to reconstruct the tree. We use "X" to represent null nodes, which helps in the reconstruction process.
 * 
 * Approach:
 * - For serialization, perform pre-order traversal and convert the tree into a string with each value separated by commas. Use "X" to denote null nodes.
 * - For deserialization, split the string by commas to get the node values. Use a helper function to recursively rebuild the tree.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * - O(n), where n is the number of nodes in the binary tree. This is the space used by the serialized string and the recursion stack.
 */

#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    /**
     * @brief Splits a string into tokens based on the delimiter ','.
     * 
     * @param s The input string
     * @return vector<string> The tokens from the input string
     */
    vector<string> split(string &s) {
        char del = ',';
        if (s == "") {
            return {};
        }
        vector<string> tokens;
        string token;
        stringstream ss(s);
        
        while (getline(ss, token, del)) {
            if (token != "") tokens.push_back(token);
        }
        return tokens;
    }

    /**
     * @brief Encodes a tree to a single string using pre-order traversal.
     * 
     * @param root The root node of the binary tree
     * @return string The serialized string representation of the binary tree
     */
    string serialize(TreeNode* root) {
        if (!root) {
            return "X,";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right) + ",";
    }
    
    int ix = 0;
    
    /**
     * @brief Helper function to deserialize the list of node values into a binary tree.
     * 
     * @param nums The list of node values
     * @return TreeNode* The root node of the reconstructed binary tree
     */
    TreeNode *helper(vector<string> &nums) {
        if (ix >= nums.size()) {
            return nullptr;
        }
        if (nums[ix] == "X") {
            ix++;
            return nullptr;
        }
        
        TreeNode *newnode = new TreeNode(stoi(nums[ix++]));
        newnode->left = helper(nums);
        newnode->right = helper(nums);
        
        return newnode;
    }

    /**
     * @brief Decodes the serialized string data to a binary tree.
     * 
     * @param data The serialized string representation of the binary tree
     * @return TreeNode* The root node of the deserialized binary tree
     */
    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data);
        return helper(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

