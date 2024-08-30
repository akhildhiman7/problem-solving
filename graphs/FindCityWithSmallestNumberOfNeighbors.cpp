/**
 * @file FindCityWithSmallestNumberOfNeighbors.cpp
 * @brief Solution to the LeetCode problem "Find the City With the Smallest Number of Neighbors at a Threshold Distance"
 * @link https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given `n` cities numbered from `0` to `n-1` and a set of weighted edges representing bidirectional roads between the cities, find the city that has the smallest number of neighbors at a distance less than or equal to a given distanceThreshold. If there are multiple cities, return the city with the greatest number.
 * 
 * Intuition:
 * The problem is about finding the shortest paths between all pairs of nodes (cities) and then counting the reachable neighbors for each city that are within a given distance threshold. The Floyd-Warshall algorithm is well-suited for this task as it efficiently computes shortest paths for all pairs of nodes.
 * 
 * Approach:
 * 1. **Graph Representation**: Use an adjacency matrix `graph` to represent the distances between cities. Initialize the distances with `INT_MAX` (infinity) to denote no direct connection and `0` for self-loops.
 * 2. **Floyd-Warshall Algorithm**: Update the adjacency matrix to find the shortest paths between all pairs of nodes. This is done by checking if a path through an intermediate node `k` offers a shorter path between `i` and `j`.
 * 3. **Count Reachable Neighbors**: For each city, count the number of other cities that can be reached within the distance threshold. Track the city with the minimum count of reachable neighbors, prioritizing higher-numbered cities in case of ties.
 * 
 * Time Complexity:
 * - O(n^3), where `n` is the number of cities. The Floyd-Warshall algorithm processes each triplet of cities once.
 * 
 * Space Complexity:
 * - O(n^2), for storing the graph (adjacency matrix).
 */

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the city with the smallest number of neighbors within the given distance threshold.
     * 
     * @param n The number of cities
     * @param edges The list of edges representing roads between cities with their weights
     * @param distanceThreshold The maximum distance threshold to consider a city as a neighbor
     * @return int The city number with the smallest number of neighbors within the distance threshold
     */
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> graph(n, vector<long long>(n, INT_MAX));
        
        // Initialize the graph with given edges
        for (auto &i: edges) {
            graph[i[0]][i[1]] = i[2];
            graph[i[1]][i[0]] = i[2];
            graph[i[0]][i[0]] = 0;
            graph[i[1]][i[1]] = 0;
        }
        
        // Floyd-Warshall algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        
        int minCities = n;
        int cityNumber = 0;
        
        // Count reachable neighbors for each city and find the city with the smallest number
        for (int i = 0; i < n; i++) {
            int cityReach = 0;
            for (int j = 0; j < n; j++) {
                cityReach += (graph[i][j] <= distanceThreshold ? 1 : 0);
            }
            
            if (cityReach <= minCities) {
                minCities = cityReach;
                cityNumber = i;
            }
        }
        
        return cityNumber;
    }
};

