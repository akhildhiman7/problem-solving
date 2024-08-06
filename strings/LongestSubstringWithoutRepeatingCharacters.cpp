/**
 * @file LongestSubstringWithoutRepeatingCharacters.cpp
 * @brief Solution to the LeetCode problem "Longest Substring Without Repeating Characters"
 * @link https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `s`, find the length of the longest substring without repeating characters.
 * 
 * Approach:
 * - Use a hash map to keep track of the last seen index of each character.
 * - Use two pointers to represent the start of the current substring and the current index.
 * - Iterate through the string, updating the start index if a repeating character is found within the current substring.
 * - Update the maximum length of the substring found so far.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string `s`.
 * 
 * Space Complexity:
 * - O(min(n, m)), where n is the length of the string `s` and m is the size of the character set (typically 128 for ASCII).
 */

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the length of the longest substring without repeating characters.
     * 
     * @param s The input string
     * @return int The length of the longest substring without repeating characters
     */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};

