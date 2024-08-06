/**
 * @file GroupAnagrams.cpp
 * @brief Solution to the LeetCode problem "Group Anagrams"
 * @link https://leetcode.com/problems/group-anagrams/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.
 * 
 * Approach:
 * - Use an unordered map to store sorted versions of the strings as keys and vectors of the original strings as values.
 * - Iterate through each string in the input array, sort the string, and use it as a key in the unordered map.
 * - Append the original string to the vector corresponding to the sorted key.
 * - Finally, collect all the vectors from the unordered map and return them as the result.
 * 
 * Time Complexity:
 * - O(n * k * log(k)), where n is the number of strings and k is the maximum length of a string.
 * 
 * Space Complexity:
 * - O(n * k), where n is the number of strings and k is the maximum length of a string.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief Groups anagrams from the input list of strings.
     * 
     * @param strs The input vector of strings
     * @return vector<vector<string>> The grouped anagrams
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        
        for (auto &str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            um[temp].push_back(str);
        }
        
        vector<vector<string>> res;
        
        for (auto &entry : um) {
            res.push_back(entry.second);
        }
        
        return res;
    }
};

