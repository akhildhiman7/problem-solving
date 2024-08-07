/**
 * @file ImplementTrie.cpp
 * @brief Solution to the LeetCode problem "Implement Trie (Prefix Tree)"
 * @link https://leetcode.com/problems/implement-trie-prefix-tree/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Implement a Trie (Prefix Tree) with `insert`, `search`, and `startsWith` methods.
 * 
 * Intuition:
 * A Trie (Prefix Tree) is a tree-like data structure that stores a dynamic set of strings, where the keys are usually strings. Each node in the Trie represents a single character of a string. By traversing the Trie, we can check if a word or prefix exists in the set of strings efficiently.
 * 
 * Approach:
 * - Define a TrieNode class to represent each node in the Trie.
 * - The Trie class contains methods to insert a word, search for a word, and check if a prefix exists.
 * - Use recursion to implement the `insert` and `search` methods.
 * - Each TrieNode has a boolean flag to indicate if it represents the end of a word and a vector of children nodes.
 * 
 * Time Complexity:
 * - Insert: O(n), where n is the length of the word.
 * - Search: O(n), where n is the length of the word.
 * - StartsWith: O(n), where n is the length of the prefix.
 * 
 * Space Complexity:
 * - O(n * m), where n is the number of words and m is the average length of the words. This is the space used by the Trie.
 */

#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    
    TrieNode() {
        isEnd = false;
        children.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode *globalRoot;
    
    Trie() {
        globalRoot = new TrieNode();
    }
    
    TrieNode *insertHelper(TrieNode *root, string &word, int i) {
        if (i >= word.size()) {
            root->isEnd = true;
            return root;
        }
        
        if (!root->children[word[i] - 'a']) {
            root->children[word[i] - 'a'] = new TrieNode();
        }
        
        root->children[word[i] - 'a'] = insertHelper(root->children[word[i] - 'a'], word, i + 1);
        return root;
    }
    
    void insert(string word) {
        globalRoot = insertHelper(globalRoot, word, 0);
    }
    
    bool searchHelper(TrieNode *root, string &word, int i, int mode) {
        if (!root) {
            return false;
        }
        if (i >= word.size()) {
            return mode == 1 ? root->isEnd : true;
        }
        
        return searchHelper(root->children[word[i] - 'a'], word, i + 1, mode);
    }
    
    bool search(string word) {
        int mode = 1;
        return searchHelper(globalRoot, word, 0, mode);
    }
    
    bool startsWith(string prefix) {
        int mode = 2;
        return searchHelper(globalRoot, prefix, 0, mode);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

