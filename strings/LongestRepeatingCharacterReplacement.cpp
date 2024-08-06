/**
 * @file LongestRepeatingCharacterReplacement.cpp
 * @brief Solution to the LeetCode problem "Longest Repeating Character Replacement"
 * @link https://leetcode.com/problems/longest-repeating-character-replacement/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `s` and an integer `k`, you can choose any character of the string and change it to any other uppercase English character. 
 * Find the length of the longest substring containing the same letter you can get after performing the above operations at most `k` times.
 * 
 * Approach:
 * - Use a sliding window approach to keep track of the count of characters within the window.
 * - Use a vector to count the frequency of characters and a variable to track the maximum frequency.
 * - Expand the window by moving the end pointer.
 * - If the window size minus the maximum frequency character count exceeds `k`, shrink the window from the start.
 * - Update the maximum length of the window during each iteration.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string `s`.
 * 
 * Space Complexity:
 * - O(1), as the size of the character set is constant (26 uppercase English letters).
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the length of the longest substring with repeating characters after at most `k` replacements.
     * 
     * @param s The input string
     * @param k The maximum number of replacements allowed
     * @return int The length of the longest valid substring
     */
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int maxCount = 0, start = 0, n = s.size(), maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            maxCount = max(maxCount, ++v[s[i] - 'A']);
            
            while (start < i && i - start + 1 - maxCount > k) {
                --v[s[start] - 'A'];
                start++;
            }
            
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};

