/**
 * @file MinCostConnectPoints.cpp
 * @brief Solution to the LeetCode problem "Minimum Cost to Connect All Points"
 * @link https://leetcode.com/problems/minimum-cost-to-connect-all-points/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given a list of points represented as coordinates on a 2D plane. You are to connect all the points such that the total cost of connecting the points is minimized. The cost of connecting two points `(x1, y1)` and `(x2, y2)` is the Manhattan distance `|x1 - x2| + |y1 - y2|`. Return the minimum cost required to connect all the points.
 * 
 * Intuition:
 * This problem can be solved using the Minimum Spanning Tree (MST) concept, where we aim to connect all nodes (points) with the minimum possible total edge weight (distance). Prim's algorithm is well-suited for finding the MST, especially when using a priority queue to handle the minimum edge selection efficiently.
 * 
 * Approach:
 * 1. **Graph Representation**: Represent the graph as an adjacency matrix, where each cell `(i, j)` contains the Manhattan distance between points `i` and `j`.
 * 2. **Prim's Algorithm**: Start from an arbitrary point, using a priority queue to always extend the MST with the smallest edge weight. Use a distances array to track the minimum edge weight required to connect each point to the growing MST.
 * 3. **Update and Select**: Use the priority queue to select the next point with the smallest connection cost. Update the connection costs for the remaining points accordingly.
 * 4. **Result Calculation**: The sum of the connection costs for all points gives the minimum cost to connect all points.
 * 
 * Time Complexity:
 * - O(n^2 * log(n)), where `n` is the number of points. Building the graph requires `O(n^2)`, and Prim's algorithm with a priority queue requires `O(n^2 * log(n))` for extracting and updating the queue.
 * 
 * Space Complexity:
 * - O(n^2), for storing the graph as an adjacency matrix.
 */

#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

#define INF 1e9
using pii = pair<int, int>;

class Solution {
public:
    vector<vector<int>> graph;
    
    /**
     * @brief Sets up the graph using the given points.
     * 
     * @param points The list of points represented as coordinates on a 2D plane
     */
    void setupGraph(vector<vector<int>> &points) {
        graph.resize(points.size(), vector<int>(points.size(), 0));
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
    }
    
    /**
     * @brief Uses Prim's algorithm to find the minimum cost to connect all points.
     * 
     * @param points The list of points represented as coordinates on a 2D plane
     * @return int The minimum cost to connect all points
     */
    int primAlgorithm(vector<vector<int>> &points) {
        setupGraph(points);
        
        vector<int> distances(points.size(), INF);
        vector<bool> visited(points.size(), false);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.push({0, 0}); // Start from the first point with a cost of 0
        
        while (!pq.empty()) {
            auto [currWeight, currNode] = pq.top();
            pq.pop();
            
            if (currWeight > distances[currNode]) {
                continue;
            }
            
            distances[currNode] = currWeight;
            visited[currNode] = true;
            
            for (int child = 0; child < points.size(); child++) {
                if (child != currNode && !visited[child] && graph[currNode][child] < distances[child]) {
                    distances[child] = graph[currNode][child];
                    pq.push({distances[child], child});
                }
            }
        }
        
        return accumulate(distances.begin(), distances.end(), 0);
    }
    
    /**
     * @brief Finds the minimum cost to connect all given points using Prim's algorithm.
     * 
     * @param points The list of points represented as coordinates on a 2D plane
     * @return int The minimum cost to connect all points
     */
    int minCostConnectPoints(vector<vector<int>>& points) {
        return primAlgorithm(points);
    }
};

