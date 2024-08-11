/**
 * @file MinDaysToMakeMBouquets.cpp
 * @brief Solution to the LeetCode problem "Minimum Number of Days to Make m Bouquets"
 * @link https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array `bloomDay` where `bloomDay[i]` is the day on which the i-th flower will bloom, you are tasked with making `m` bouquets. Each bouquet requires `k` adjacent flowers. Determine the minimum number of days required to make `m` bouquets.
 * 
 * Intuition:
 * The problem can be solved using binary search on the number of days required. The goal is to find the smallest number of days `dayVal` such that at least `m` bouquets can be made. If for a given day `dayVal`, we can make the required number of bouquets, we try to find a smaller number of days. If not, we need to increase the number of days.
 * 
 * Approach:
 * - Use binary search to determine the minimum number of days required. The search range is from 1 to the maximum value in `bloomDay`.
 * - For each midpoint in the binary search, use a helper function `conditionHolds` to check if it's possible to make `m` bouquets by that day.
 * - Adjust the search range based on whether the current midpoint day allows for the required number of bouquets.
 * - Return the minimum number of days required.
 * 
 * Time Complexity:
 * - O(n * log(max(bloomDay))), where `n` is the number of elements in `bloomDay` and `max(bloomDay)` is the maximum number of days required for any flower to bloom.
 * 
 * Space Complexity:
 * - O(1), as no additional space is required beyond the input and a few variables.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalWait = -1;
    
    /**
     * @brief Checks if it's possible to make `m` bouquets by the given day.
     * 
     * @param bloomDays The days on which each flower blooms
     * @param m The number of bouquets required
     * @param k The number of adjacent flowers needed to make a bouquet
     * @param dayVal The current day being checked
     * @return bool True if it's possible to make `m` bouquets by `dayVal`, otherwise false
     */
    int conditionHolds(vector<int>& bloomDays, int &m, int &k, int &dayVal) {
        int noOfBouquets = 0, currStreak = 0;
        
        for (auto &bloomDay : bloomDays) {
            if (bloomDay > dayVal) {
                noOfBouquets += currStreak / k;
                currStreak = 0;
            } else {
                currStreak++;
            }
        }
        
        noOfBouquets += currStreak / k;
        
        if (noOfBouquets >= m) {
            totalWait = dayVal;
        }
        
        return noOfBouquets >= m;
    }
    
    /**
     * @brief Finds the minimum number of days required to make `m` bouquets.
     * 
     * @param bloomDay The days on which each flower blooms
     * @param m The number of bouquets required
     * @param k The number of adjacent flowers needed to make a bouquet
     * @return int The minimum number of days required to make `m` bouquets
     */
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (conditionHolds(bloomDay, m, k, mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return totalWait;
    }
};

