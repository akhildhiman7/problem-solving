/**
 * @file WordSearchII.cpp
 * @brief Solution to the LeetCode problem "Word Search II"
 * @link https://leetcode.com/problems/word-search-ii/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an m x n board of characters and a list of strings words, return all words on the board.
 * Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 * 
 * Intuition:
 * We can use a Trie to efficiently store the list of words and perform prefix-based search. We then use Depth-First Search (DFS) to explore the board and find all words that match the prefixes stored in the Trie.
 * 
 * Approach:
 * - Use a Trie (Prefix Tree) to store all words.
 * - For each cell in the board, perform a DFS to search for words starting from that cell.
 * - Use a helper function to add words to the Trie.
 * - Use a recursive function to perform DFS and search for words in the board.
 * - Mark cells as visited during the search to avoid using the same cell more than once in a word.
 * 
 * Time Complexity:
 * - O(m * n * 4^l), where m is the number of rows, n is the number of columns, and l is the length of the longest word.
 * 
 * Space Complexity:
 * - O(n), where n is the total number of characters in all words. This is the space used by the Trie.
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

class Solution {
public:
    TrieNode *globalRoot;
    
    /**
     * @brief Helper function to add words to the Trie.
     * 
     * @param root The current Trie node
     * @param word The word to be added
     * @param i The current index in the word
     * @return TrieNode* The updated Trie node
     */
    TrieNode* addWordsHelper(TrieNode *root, string &word, int i) {
        if (i >= word.size()) {
            root->isEnd = true;
            return root;
        }
        
        if (!root->children[word[i] - 'a']) {
            root->children[word[i] - 'a'] = new TrieNode();
        }
        
        root->children[word[i] - 'a'] = addWordsHelper(root->children[word[i] - 'a'], word, i + 1);
        return root;
    }
    
    /**
     * @brief Adds a list of words to the Trie.
     * 
     * @param words The list of words to be added
     */
    void addWords(vector<string> &words) {
        globalRoot = new TrieNode();
        
        for (auto &w : words) {
            globalRoot = addWordsHelper(globalRoot, w, 0);
        }
    }
    
    vector<string> resWords;
    int m, n;
    
    /**
     * @brief Searches for words in the board using DFS.
     * 
     * @param root The current Trie node
     * @param board The board of characters
     * @param i The current row index
     * @param j The current column index
     * @param currWord The current word being formed
     */
    void search(TrieNode *root, vector<vector<char>> &board, int i, int j, string currWord) {
        if (!root || board[i][j] == '-') {
            return;
        }
        if (root->isEnd) {
            resWords.push_back(currWord + board[i][j]);
            root->isEnd = false;
        }
        char c = board[i][j];
        board[i][j] = '-';
        
        if (i > 0) search(root->children[board[i - 1][j] - 'a'], board, i - 1, j, currWord + c);
        if (i < m - 1) search(root->children[board[i + 1][j] - 'a'], board, i + 1, j, currWord + c);
        if (j > 0) search(root->children[board[i][j - 1] - 'a'], board, i, j - 1, currWord + c);
        if (j < n - 1) search(root->children[board[i][j + 1] - 'a'], board, i, j + 1, currWord + c);
        
        board[i][j] = c;
    }
    
    /**
     * @brief Finds all words in the board.
     * 
     * @param board The board of characters
     * @param words The list of words to be found
     * @return vector<string> The list of words found in the board
     */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        addWords(words);
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(globalRoot->children[board[i][j] - 'a'], board, i, j, "");
            }
        }
        
        return resWords;
    }
};

