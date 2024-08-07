/**
 * @file LongestPalindromicSubstring.cpp
 * @brief Solution to the LeetCode problem "Longest Palindromic Substring"
 * @link https://leetcode.com/problems/longest-palindromic-substring/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `s`, return the longest palindromic substring in `s`.
 * 
 * Approach:
 * - Define a helper function `getPalindrome` that expands around the center to find the longest palindrome for a given center.
 * - Iterate through each character in the string and use the helper function to find the longest palindrome centered at each character (both single character center and two character center).
 * - Compare the length of the found palindrome with the current longest palindrome and update accordingly.
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
     * @brief Expands around the center to find the longest palindrome for a given center.
     * 
     * @param s The input string
     * @param i The starting index for expansion
     * @param j The ending index for expansion
     * @return string The longest palindrome found from the given center
     */
    string getPalindrome(const string &s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        i++;
        j--;
        return s.substr(i, j - i + 1);
    }
    
    /**
     * @brief Finds the longest palindromic substring in the input string.
     * 
     * @param s The input string
     * @return string The longest palindromic substring
     */
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string res = s.substr(0, 1);
        
        for (int i = 1; i < s.size(); i++) {
            string a = getPalindrome(s, i, i);
            string b = getPalindrome(s, i - 1, i);
            
            string longer = (a.size() < b.size()) ? b : a;
            
            if (res.size() < longer.size()) {
                res = longer;
            }
        }
        
        return res;
    }
};

