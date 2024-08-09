/**
 * @file CapacityToShipPackagesWithinDDays.cpp
 * @brief Solution to the LeetCode problem "Capacity To Ship Packages Within D Days"
 * @link https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given an array `weights` where `weights[i]` is the weight of the i-th package, and an integer `days` representing the number of days required to ship all packages. Your task is to find the minimum capacity of the ship that can ship all the packages within the given number of days.
 * 
 * Intuition:
 * The idea is to use binary search to determine the minimum capacity required for the ship. We can define the search space as the range between the maximum single package weight and the sum of all weights. For each midpoint in this range, we check if the ship can transport all packages within the given number of days.
 * 
 * Approach:
 * - Use binary search to find the minimum ship capacity. The search range is from the maximum single package weight to the sum of all package weights.
 * - For each midpoint capacity, check if it's feasible to ship all packages within the required number of days using a helper function.
 * - Adjust the search space based on whether the current midpoint capacity is feasible.
 * - Return the minimum feasible capacity.
 * 
 * Time Complexity:
 * - O(n * log(sum(weights))), where `n` is the number of packages and `sum(weights)` is the sum of all weights.
 * 
 * Space Complexity:
 * - O(1), as no additional space is required beyond the input and a few variables.
 */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the given maximum ship weight capacity can ship all packages within the required number of days.
     * 
     * @param weights The weights of the packages
     * @param maxWeight The maximum weight capacity of the ship
     * @param days The required number of days to ship all packages
     * @return bool True if the ship can carry all packages within the required days, otherwise false
     */
    bool checkForCondition(vector<int> &weights, int maxWeight, int days) {
        int cSum = 0, currDays = 1;
        
        for (auto &w : weights) {
            if (w > maxWeight) return false;
            if (cSum + w > maxWeight) {
                currDays++;
                cSum = w;
            } else {
                cSum += w;
            }
        }
        return currDays <= days;
    }
    
    /**
     * @brief Finds the minimum ship capacity to ship all packages within the given number of days.
     * 
     * @param weights The weights of the packages
     * @param days The required number of days to ship all packages
     * @return int The minimum ship capacity required
     */
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (checkForCondition(weights, mid, days)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};

