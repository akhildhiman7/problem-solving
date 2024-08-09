/**
 * @file MinimumTimeToRepairCars.cpp
 * @brief Solution to the LeetCode problem "Minimum Time to Repair Cars"
 * @link https://leetcode.com/problems/minimum-time-to-repair-cars/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given an integer array `ranks`, where `ranks[i]` is the rank of the i-th mechanic. The time taken by the i-th mechanic to repair one car is `ranks[i]`. You are also given an integer `cars` representing the number of cars to be repaired.
 * 
 * The task is to determine the minimum time required to repair all cars if the mechanics can repair multiple cars simultaneously.
 * 
 * Intuition:
 * To solve this problem, we need to minimize the time required to repair all cars. The key insight is that mechanics with lower ranks can repair cars faster. We use binary search on the time to find the minimum time required. For each mid-time during the binary search, we calculate how many cars can be repaired by all mechanics within that time. If the number of cars repaired is greater than or equal to the required number, we move to a smaller time; otherwise, we move to a larger time.
 * 
 * Approach:
 * - Use binary search to find the minimum time.
 * - For each mid-time, calculate how many cars each mechanic can repair.
 * - If the total number of cars repaired by all mechanics is greater than or equal to the required number, reduce the time; otherwise, increase it.
 * 
 * Time Complexity:
 * - O(n * log(max_time)), where n is the number of mechanics, and max_time is the maximum possible time.
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the given time allows repairing all cars.
     * 
     * @param ranks The array of mechanics' ranks
     * @param n The number of cars to repair
     * @param time The current time being checked
     * @return bool True if all cars can be repaired within the given time, otherwise false
     */
    bool checkForConditions(vector<int> &ranks, int n, long long time) {
        long long totalCars = 0;
        for (auto &r: ranks) {
            totalCars += (int)sqrt(time / r);
        }
        return totalCars >= n;
    }
    
    /**
     * @brief Finds the minimum time required to repair all cars.
     * 
     * @param ranks The array of mechanics' ranks
     * @param cars The number of cars to repair
     * @return long long The minimum time required to repair all cars
     */
    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1, end = (*min_element(ranks.begin(), ranks.end())) * (long long) cars * cars;
        
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            
            if (checkForConditions(ranks, cars, mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};

