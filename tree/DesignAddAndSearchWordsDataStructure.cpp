/**
 * @file DesignAddAndSearchWordsDataStructure.cpp
 * @brief Solution to the LeetCode problem "Design Add and Search Words Data Structure"
 * @link https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Design a data structure that supports adding new words and finding if a string matches any previously added string. The search string can contain the '.' character to represent any one letter.
 * 
 * Intuition:
 * We can use a Trie (Prefix Tree) to store the words. Each node in the Trie represents a character, and the Trie as a whole represents a set of words. For the search operation, we use recursion to handle the '.' wildcard character, which can match any letter.
 * 
 * Approach:
 * - Define a TrieNode class to represent each node in the Trie.
 * - The WordDictionary class contains methods to add a word and search for a word.
 * - Use recursion to implement the `addWord` and `search` methods.
 * - Each TrieNode has a boolean flag to indicate if it represents the end of a word and a vector of children nodes.
 * 
 * Time Complexity:
 * - AddWord: O(n), where n is the length of the word.
 * - Search: O(n), where n is the length of the word.
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

class WordDictionary {
public:
    TrieNode *globalRoot;
    
    WordDictionary() {
        globalRoot = new TrieNode();
    }
    
    TrieNode* insertHelper(TrieNode* root, string &word, int i) {
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
    
    void addWord(string word) {
        globalRoot = insertHelper(globalRoot, word, 0);
    }
    
    bool searchHelper(TrieNode *root, string &word, int i) {
        if (!root) {
            return false;
        }
        if (i >= word.size()) {
            return root->isEnd;
        }
        bool ans = false;
        if (word[i] == '.') {
            for (int ix = 0; ix < 26 && !ans; ix++) {
                ans = searchHelper(root->children[ix], word, i + 1);
            }
        } else {
            ans = searchHelper(root->children[word[i] - 'a'], word, i + 1);
        }
        
        return ans;
    }
    
    bool search(string word) {
        return searchHelper(globalRoot, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

