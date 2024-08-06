/**
 * @file ValidAnagram.cpp
 * @brief Solution to the LeetCode problem "Valid Anagram"
 * @link https://leetcode.com/problems/valid-anagram/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and false otherwise.
 * 
 * Approach:
 * - Use two vectors to count the frequency of characters in `s` and `t`.
 * - Iterate through each character in `s` and `t`, updating the respective frequency vectors.
 * - Compare the two frequency vectors to determine if they are equal.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the strings `s` and `t`.
 * 
 * Space Complexity:
 * - O(1), as the size of the character set is constant (26 lowercase English letters).
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if string `t` is an anagram of string `s`.
     * 
     * @param s The first input string
     * @param t The second input string
     * @return bool True if `t` is an anagram of `s`, otherwise false
     */
    bool isAnagram(string s, string t) {
        vector<int> vs(26, 0), vt(26, 0);
        
        for (auto &c : s) {
            vs[c - 'a']++;
        }
        
        for (auto &c : t) {
            vt[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (vt[i] != vs[i]) {
                return false;
            }
        }
        
        return true;
    }
};

