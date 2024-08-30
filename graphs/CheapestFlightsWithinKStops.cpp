/**
 * @file CheapestFlightsWithinKStops.cpp
 * @brief Solution to the LeetCode problem "Cheapest Flights Within K Stops"
 * @link https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given a set of `n` nodes labeled from `0` to `n-1` representing a network of flights. Each flight is represented as `[from, to, price]`, indicating a flight from `from` to `to` with a cost of `price`. Given the number of nodes, the flights, a source node `src`, a destination node `dst`, and an integer `k`, find the cheapest flight from `src` to `dst` that has at most `k` stops. If no such flight exists, return `-1`.
 * 
 * Intuition:
 * The problem is a variation of the shortest path problem where we need to find the cheapest path from a source node to a destination node with a constraint on the maximum number of stops. This can be solved using a modified Dijkstra's algorithm with a priority queue. Instead of minimizing the number of edges (as in BFS) or simply finding the shortest path (as in Dijkstra's), we keep track of the minimum cost to reach each node with up to `k` stops.
 * 
 * Approach:
 * 1. **Graph Representation**: Build an adjacency list representation of the graph where each node points to its neighbors with the associated cost.
 * 2. **Dijkstra’s Algorithm with Stop Count**: Use a priority queue to process nodes based on the current total cost, the current node, and the number of stops made.
 * 3. **Track Distances**: Maintain a distance array that tracks the minimum cost to reach each node with a specific number of stops.
 * 4. **Update and Traverse**: For each node, update the distances of its neighbors and push them into the priority queue if a cheaper path is found with fewer stops.
 * 5. **Result Calculation**: After processing, check the minimum cost to reach the destination node within the allowed stops.
 * 
 * Time Complexity:
 * - O((E + V) * logV), where `E` is the number of edges, and `V` is the number of vertices (nodes). Each edge is processed, and each node is pushed into the priority queue.
 * 
 * Space Complexity:
 * - O(V * k), for storing the distance array.
 */

#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    
    /**
     * @brief Finds the cheapest flight from src to dst with at most k stops.
     * 
     * @param n The number of nodes (cities)
     * @param flights The list of flights where each flight is represented as [from, to, price]
     * @param src The starting node
     * @param dst The destination node
     * @param k The maximum number of stops allowed
     * @return int The minimum cost to reach the destination or -1 if it's not possible
     */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> graph(n);
        vector<vector<int>> distances(n, vector<int>(k + 2, numeric_limits<int>::max()));
        
        // Build the graph
        for (auto &flight: flights) {
            graph[flight[0]].push_back({flight[2], flight[1]});
        }
        
        // Priority queue to process nodes: {current distance, current node, number of stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, src, 0});
        vector<int> con(k + 2, 0);
        distances[src] = con;
        
        while (!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            int currDist = temp[0], currNode = temp[1], level = temp[2];
            
            if (currDist > distances[currNode][level] || level > k) {
                continue;
            }
            
            distances[currNode][level] = currDist;
            
            for (auto [weight, neighbor]: graph[currNode]) {
                int newDistance = weight + currDist;
                
                if (newDistance < distances[neighbor][level + 1]) {
                    distances[neighbor][level + 1] = newDistance;
                    pq.push({newDistance, neighbor, level + 1});
                }
            }
        }
        
        int res = INT_MAX;
        
        for (int i = 0; i < k + 2; i++) {
            res = min(distances[dst][i], res);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};

