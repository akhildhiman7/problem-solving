/**
 * @file MinimumWindowSubstring.cpp
 * @brief Solution to the LeetCode problem "Minimum Window Substring"
 * @link https://leetcode.com/problems/minimum-window-substring/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given two strings `s` and `t`, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * 
 * Approach:
 * - Use two vectors to count the frequency of characters in `s` and `t`.
 * - Use a sliding window approach to expand the window by moving the end pointer.
 * - Shrink the window from the start to find the minimum window that contains all characters of `t`.
 * - Check if the current window contains all characters of `t` and update the minimum length and start index accordingly.
 * 
 * Time Complexity:
 * - O(n * m), where n is the length of the string `s` and m is the size of the character set (52 in this case).
 * 
 * Space Complexity:
 * - O(1), as the size of the character set is constant (52 characters, considering both uppercase and lowercase letters).
 */

#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the index of the character in the frequency array.
     * 
     * @param c The character
     * @return int The index of the character in the frequency array
     */
    constexpr int index(const char &c) {
        return c < 'a' ? c - 'A' + 26 : c - 'a';
    }
    
    /**
     * @brief Checks if the current window contains all characters of the target string.
     * 
     * @param a Frequency array of the current window
     * @param b Frequency array of the target string
     * @return bool True if the current window contains all characters of the target string, otherwise false
     */
    bool areEqual(const vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * @brief Finds the minimum window substring of `s` that contains all characters of `t`.
     * 
     * @param s The input string
     * @param t The target string
     * @return string The minimum window substring that contains all characters of `t`
     */
    string minWindow(string s, string t) {
        vector<int> vs(52, 0), vt(52, 0);
        for (auto &c : t) {
            vt[index(c)]++;
        }
        
        int start = 0, maxLen = INT_MAX, resStart = 0;
        
        for (int i = 0; i < s.size(); i++) {
            vs[index(s[i])]++;
            
            if (areEqual(vs, vt)) {
                while (start < i && vs[index(s[start])] > vt[index(s[start])]) {
                    --vs[index(s[start])];
                    start++;
                }
                
                if (i - start + 1 < maxLen) {
                    maxLen = i - start + 1;
                    resStart = start;
                }
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(resStart, maxLen);
    }
};

