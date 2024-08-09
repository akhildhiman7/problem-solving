/**
 * @file KokoEatingBananas.cpp
 * @brief Solution to the LeetCode problem "Koko Eating Bananas"
 * @link https://leetcode.com/problems/koko-eating-bananas/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Koko loves to eat bananas. There are `piles` where `piles[i]` is the number of bananas in the i-th pile. Koko can decide her eating speed `k`, which represents how many bananas she eats per hour. The task is to find the minimum integer `k` such that Koko can eat all bananas within `h` hours.
 * 
 * Intuition:
 * The problem is about finding the minimum possible value for `k`, Koko's eating speed, that allows her to eat all bananas within the given hours `h`. The key observation is that as `k` increases, the total time required decreases. Thus, we can use binary search to efficiently determine the smallest `k` that satisfies the condition.
 * 
 * Approach:
 * - Use binary search to find the minimum speed `k` that allows Koko to finish all the bananas within `h` hours.
 * - The search range for `k` is from 1 (minimum speed) to the maximum number of bananas in any pile (maximum speed).
 * - For each midpoint speed `mid`, calculate the total hours required for Koko to finish all the bananas at that speed using a helper function `valueHolds`.
 * - Adjust the search range based on whether the current speed allows Koko to eat all the bananas within `h` hours.
 * 
 * Time Complexity:
 * - O(n * log(max(piles))), where `n` is the number of piles and `max(piles)` is the maximum number of bananas in a pile.
 * 
 * Space Complexity:
 * - O(1), as no additional space is required beyond the input and a few variables.
 */

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the given eating speed `k` allows Koko to eat all bananas within `h` hours.
     * 
     * @param piles The piles of bananas
     * @param k The eating speed in bananas per hour
     * @param h The maximum allowed hours to eat all bananas
     * @return bool True if Koko can eat all bananas within `h` hours at speed `k`, otherwise false
     */
    bool valueHolds(vector<int> &piles, int &k, int &h) {
        long long totalHours = 0;
        
        for (int i = 0; i < piles.size(); i++) {
            totalHours += ceil(piles[i] / (double)k);
        }
        
        return totalHours <= h;
    }
    
    /**
     * @brief Finds the minimum eating speed `k` that allows Koko to eat all bananas within `h` hours.
     * 
     * @param piles The piles of bananas
     * @param h The maximum allowed hours to eat all bananas
     * @return int The minimum eating speed required
     */
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (valueHolds(piles, mid, h)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};

