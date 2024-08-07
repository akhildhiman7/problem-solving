/**
 * @file ValidParentheses.cpp
 * @brief Solution to the LeetCode problem "Valid Parentheses"
 * @link https://leetcode.com/problems/valid-parentheses/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 
 * Approach:
 * - Use a stack to keep track of the opening brackets.
 * - Iterate through each character in the string.
 * - If the character is an opening bracket, push it onto the stack.
 * - If the character is a closing bracket, check if the stack is not empty and if the top of the stack is the corresponding opening bracket. If so, pop the stack.
 * - If the stack is empty at the end, the string is valid; otherwise, it is not.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string `s`.
 * 
 * Space Complexity:
 * - O(n), where n is the length of the string `s` (in the worst case, all characters are opening brackets).
 */

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the input string has valid parentheses.
     * 
     * @param s The input string
     * @return bool True if the string is valid, otherwise false
     */
    bool isValid(string s) {
        stack<char> stk;
        
        for (const auto &c : s) {
            if (c == '[' || c == '{' || c == '(') {
                stk.push(c);
            } else if (c == '}') {
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                } else return false;
            } else if (c == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else return false;
            } else if (c == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else return false;
            }
        }
        
        return stk.empty();
    }
};

