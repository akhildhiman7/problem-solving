/**
 * @file PalindromicSubstrings.cpp
 * @brief Solution to the LeetCode problem "Palindromic Substrings"
 * @link https://leetcode.com/problems/palindromic-substrings/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `s`, return the number of palindromic substrings in it. A string is a palindrome when it reads the same backward as forward. A substring is a contiguous sequence of characters within a string.
 * 
 * Intuition:
 * The idea is to consider each character and the gap between each pair of characters as the center of a palindrome and try to expand outward while the characters on both ends are the same. This way, we can count all palindromic substrings.
 * 
 * Approach:
 * - Define a helper function that expands around the center to count palindromic substrings for a given center.
 * - Iterate through each character in the string and use the helper function to count palindromic substrings centered at each character (both single character center and two character center).
 * - Sum the counts from all centers to get the total number of palindromic substrings.
 * 
 * Time Complexity:
 * - O(n^2), where n is the length of the string `s`.
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * @brief Expands around the center to count palindromic substrings for a given center.
     * 
     * @param s The input string
     * @param i The starting index for expansion
     * @param j The ending index for expansion
     * @return int The count of palindromic substrings found from the given center
     */
    int helper(const string &s, int i, int j) {
        int count = 0;
        
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        
        return count;
    }
    
    /**
     * @brief Counts the number of palindromic substrings in the input string.
     * 
     * @param s The input string
     * @return int The total number of palindromic substrings
     */
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            count += helper(s, i, i) + helper(s, i, i + 1);
        }
        
        return count;
    }
};

