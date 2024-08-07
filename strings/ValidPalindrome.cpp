/**
 * @file ValidPalindrome.cpp
 * @brief Solution to the LeetCode problem "Valid Palindrome"
 * @link https://leetcode.com/problems/valid-palindrome/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `s`, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * Approach:
 * - Define a helper function to convert characters to lowercase and keep only alphanumeric characters.
 * - Use another helper function to check if a string is a palindrome.
 * - Iterate through the input string, filter and convert characters using the first helper function, and build a new string.
 * - Use the second helper function to check if the new string is a palindrome.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string `s`.
 * 
 * Space Complexity:
 * - O(n), where n is the length of the string `s` (for the new string).
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * @brief Converts a character to lowercase if it is an uppercase letter, and keeps alphanumeric characters.
     * 
     * @param c The input character
     * @return string The processed character as a string (lowercase or original alphanumeric character)
     */
    string getChar(const char &c) {
        string s = "";
        if (c >= 'a' && c <= 'z') {
            s += c;
        } else if (c >= 'A' && c <= 'Z') {
            s += char(97 + (c - 'A'));
        } else if (c >= '0' && c <= '9') {
            s += c;
        }
        
        return s;
    }
    
    /**
     * @brief Checks if the given string is a palindrome.
     * 
     * @param s The input string
     * @return bool True if the string is a palindrome, otherwise false
     */
    bool helper(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * @brief Determines if the input string is a valid palindrome, considering only alphanumeric characters and ignoring cases.
     * 
     * @param s The input string
     * @return bool True if the string is a valid palindrome, otherwise false
     */
    bool isPalindrome(string s) {
        string newString = "";
        for (const auto &c : s) {
            newString += getChar(c);
        }
        
        return helper(newString);
    }
};

