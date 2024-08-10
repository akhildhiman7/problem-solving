/**
 * @file MaximumCandiesAllocatedToKChildren.cpp
 * @brief Solution to the LeetCode problem "Maximum Candies Allocated to K Children"
 * @link https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array `candies` where `candies[i]` represents the number of candies in the i-th pile, and an integer `k` representing the number of children, the task is to find the maximum number of candies that can be evenly distributed to each child.
 * 
 * Intuition:
 * The goal is to maximize the number of candies each child can receive such that the total number of children receiving candies is at least `k`. We can use binary search to find this maximum number. The key insight is that if a certain number of candies per child is feasible, then all smaller numbers are also feasible, and vice versa.
 * 
 * Approach:
 * - Use binary search to find the maximum number of candies that can be allocated to each child. The search range is from 1 (minimum possible allocation) to the maximum number of candies in any pile.
 * - For each midpoint, check if it's possible to allocate that many candies to each child using a helper function `conditionHolds`.
 * - Adjust the search range based on whether the current midpoint allocation is feasible.
 * - Return the maximum feasible number of candies per child.
 * 
 * Time Complexity:
 * - O(n * log(max(candies))), where `n` is the number of piles and `max(candies)` is the maximum number of candies in a pile.
 * 
 * Space Complexity:
 * - O(1), as no additional space is required beyond the input and a few variables.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSplit = 0;
    
    /**
     * @brief Checks if the given number of candies per child `split` can be allocated to at least `k` children.
     * 
     * @param candies The piles of candies
     * @param k The required number of children to receive candies
     * @param split The number of candies to be allocated per child
     * @return bool True if the candies can be split accordingly, otherwise false
     */
    bool conditionHolds(vector<int> &candies, long long &k, int &split) {
        long long count = 0;
        
        for (auto &c : candies) {
            count += c / split;
        }
        
        if (count >= k) {
            maxSplit = split;
        }
        
        return count >= k;
    }
    
    /**
     * @brief Finds the maximum number of candies that can be allocated to each child.
     * 
     * @param candies The piles of candies
     * @param k The required number of children to receive candies
     * @return int The maximum number of candies that can be allocated to each child
     */
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int end = *max_element(candies.begin(), candies.end());
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (conditionHolds(candies, k, mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return maxSplit;
    }
};

