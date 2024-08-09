/**
 * @file MinimumSpeedToArriveOnTime.cpp
 * @brief Solution to the LeetCode problem "Minimum Speed to Arrive on Time"
 * @link https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array `dist` where `dist[i]` represents the distance of the i-th train and a floating-point number `hour` representing the maximum allowed travel time, determine the minimum speed required to travel all distances within `hour` hours.
 * 
 * Intuition:
 * To minimize the speed required to reach the destination within the given time, we can apply binary search over possible speed values. We check if a particular speed can complete the journey in the allowed time, and adjust the search range based on this check.
 * 
 * Approach:
 * - Use binary search to find the minimum speed. The search range is from 1 to 10^7, which covers all practical speeds.
 * - For each midpoint speed, calculate the total travel time and check if it is within the allowed time.
 * - If the speed allows completing the journey within `hour`, adjust the search range to explore smaller speeds.
 * - If not, search for higher speeds.
 * - The edge case where the journey cannot be completed even at the highest speed is handled by returning `-1`.
 * 
 * Time Complexity:
 * - O(n * log(max_speed)), where `n` is the number of elements in `dist` and `max_speed` is the upper limit of the speed range.
 * 
 * Space Complexity:
 * - O(1), as no additional space is required beyond the input and a few variables.
 */

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the given speed allows arriving on time.
     * 
     * @param dist The distances of the train routes
     * @param speed The speed to be checked
     * @param hour The maximum allowed travel time
     * @return bool True if the speed is sufficient, otherwise false
     */
    bool checkSpeedHolds(vector<int> &dist, int &speed, double &hour) {
        double totalHours = 0;
        
        for (int i = 0; i < dist.size() - 1; i++) {
            totalHours += ceil(dist[i] / (double)speed);
        }
        
        totalHours += (double)(dist.back() / (double)speed);
        
        return totalHours <= hour;
    }
    
    /**
     * @brief Finds the minimum speed required to arrive on time.
     * 
     * @param dist The distances of the train routes
     * @param hour The maximum allowed travel time
     * @return int The minimum speed required, or -1 if it's impossible
     */
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1, end = 1e7;
        bool wasSpeedEnough = false;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            wasSpeedEnough = wasSpeedEnough || checkSpeedHolds(dist, mid, hour);
            if (checkSpeedHolds(dist, mid, hour)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return wasSpeedEnough ? start : -1;
    }
};

