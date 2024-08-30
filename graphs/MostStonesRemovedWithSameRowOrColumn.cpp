/**
 * @file MostStonesRemovedWithSameRowOrColumn.cpp
 * @brief Solution to the LeetCode problem "Most Stones Removed with Same Row or Column"
 * @link https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given an array of stones where each stone[i] = [xi, yi] represents the location of a stone. A stone can be removed if there is another stone in the same row or the same column. Find the maximum number of stones that can be removed.
 * 
 * Intuition:
 * The problem can be represented as a graph where each stone is a node, and an edge exists between two nodes if they share the same row or column. The problem is then reduced to finding the number of connected components in this graph, as we can remove all but one stone from each connected component.
 * 
 * Approach:
 * - Use the Union-Find (Disjoint Set Union, DSU) data structure to efficiently manage and merge sets of stones.
 * - Maintain mappings for each stone's row and column.
 * - Traverse each stone and merge sets using Union-Find operations.
 * - After processing all stones, count the number of unique sets (connected components). The result is the total number of stones minus the number of unique sets.
 * 
 * Steps:
 * 1. **Union-Find Initialization**: Use maps to store parent relationships for stones based on their coordinates.
 * 2. **Union Operation**: Merge stones in the same row or column into the same set.
 * 3. **Count Components**: Use a set to count unique root parents and subtract this count from the total number of stones.
 * 
 * Time Complexity:
 * - O(n * α(n)), where `n` is the number of stones and `α` is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant.
 * 
 * Space Complexity:
 * - O(n), for storing parent mappings and axis mappings.
 */

#include <unordered_map>
#include <set>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, string> parents;
    unordered_map<int, pair<int, int>> xAxis, yAxis;
    
    /**
     * @brief Splits a string by a delimiter into a pair of integers.
     * 
     * @param s The input string
     * @param del The delimiter character
     * @return pair<int, int> The parsed pair of integers
     */
    pair<int, int> split(string s, char del = ',') {
        string token;
        vector<string> tokens;
        stringstream ss(s);
        
        while (getline(ss, token, del)) {
            tokens.push_back(token);
        }
        
        return {stoi(tokens[0]), stoi(tokens[1])};
    }
    
    /**
     * @brief Generates a string key from a pair of integers.
     * 
     * @param x The input pair of integers
     * @return string The generated key as a string
     */
    string getKey(pair<int, int> x) {
        return to_string(x.first) + "," + to_string(x.second);
    }
    
    /**
     * @brief Retrieves the pair of integers represented by a string key.
     * 
     * @param key The string key
     * @return pair<int, int> The corresponding pair of integers
     */
    pair<int, int> getValue(string key) {
        return split(key, ',');
    }
    
    /**
     * @brief Finds the root parent of a given value using path compression.
     * 
     * @param val The string representation of a value
     * @return pair<int, int> The root parent pair
     */
    pair<int, int> getParent(string val) {
        if (parents[val] == val) {
            return getValue(val);
        }
        
        return getParent(parents[val]);
    }
    
    /**
     * @brief Union operation for Union-Find, merging stones in the same row or column.
     * 
     * @param x The x-coordinate of a stone
     * @param y The y-coordinate of a stone
     */
    void unionFind(int x, int y) {
        if (!xAxis.count(x) && !yAxis.count(y)) {
            xAxis[x] = yAxis[y] = {x, y};
            
            string key = getKey({x, y});
            parents[key] = key;
            return;
        }
        
        if (xAxis.count(x) && yAxis.count(y)) {
            pair<int, int> xParent = getParent(getKey(xAxis[x]));
            pair<int, int> yParent = getParent(getKey(yAxis[y]));
            
            parents[getKey({x, y})] = getKey(xParent);
            parents[getKey(yParent)] = getKey(xParent);
        } else if (xAxis.count(x)) {
            pair<int, int> xParent = getParent(getKey(xAxis[x]));
            
            yAxis[y] = {x, y};
            
            parents[getKey({x, y})] = getKey(xParent);
        } else {
            pair<int, int> yParent = getParent(getKey(yAxis[y]));
            
            xAxis[x] = {x, y};
            
            parents[getKey({x, y})] = getKey(yParent);
        }
    }
    
    /**
     * @brief Finds the maximum number of stones that can be removed.
     * 
     * @param stones The coordinates of each stone
     * @return int The maximum number of stones that can be removed
     */
    int removeStones(vector<vector<int>>& stones) {
        for (auto val : stones) {
            unionFind(val[0], val[1]);
        }
        
        set<string> uniqueParents;
        
        for (auto val : stones) {
            uniqueParents.insert(getKey(getParent(getKey({val[0], val[1]}))));
        }
        
        return stones.size() - uniqueParents.size();
    }
};

