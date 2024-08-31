/**
 * @file ModifyGraphEdgeWeights.cpp
 * @brief Solution to the LeetCode problem "Modify Graph Edge Weights"
 * @link https://leetcode.com/problems/modify-graph-edge-weights/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given a graph represented by `n` nodes and a list of edges. Some of the edge weights are missing, represented by `-1`. Your task is to modify the missing weights so that the shortest path from the source node `src` to the destination node `dst` has a length equal to `target`. If it is impossible, return an empty list. If multiple solutions exist, return any valid one.
 * 
 * Intuition:
 * This problem can be tackled using a modified Dijkstra's algorithm to find the shortest path. By iteratively assigning values to the edges with `-1` and checking the shortest path, we can determine the minimum edge values required to achieve the desired path length. If the initial shortest path is already equal to or greater than the target, we adjust the weights to ensure the shortest path meets the target.
 * 
 * Approach:
 * 1. **Graph Representation**: Build an adjacency matrix representation of the graph with edge weights. Use `INF` to represent missing edges and `0` for no self-loops.
 * 2. **Modified Dijkstra’s Algorithm**: Use Dijkstra's algorithm to compute the shortest path from `src` to `dst`. Adjust edge weights incrementally to ensure the shortest path equals the target length.
 * 3. **Edge Weight Adjustment**: Iterate through the edges with `-1` values and adjust their weights to meet the target path length. Update the graph and check the shortest path after each adjustment.
 * 4. **Return Result**: Return the modified edges if a valid configuration is found; otherwise, return an empty list.
 * 
 * Time Complexity:
 * - O(E * log(V) + E * E * log(V)), where `E` is the number of edges, and `V` is the number of vertices (nodes). This accounts for running Dijkstra's algorithm multiple times.
 * 
 * Space Complexity:
 * - O(V^2), for storing the graph as an adjacency matrix and the additional space for distances and priority queue.
 */

#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF 2000000000
using pii = pair<int, int>;

class Solution {
public:
    vector<vector<int>> graph;
    
    /**
     * @brief Sets up the graph using the given edges.
     * 
     * @param edges The list of edges with possible unknown weights
     * @param n The number of nodes in the graph
     * @param src The starting node
     */
    void setupGraph(vector<vector<int>> &edges, int n, int src) {
        graph.clear();
        graph.resize(n, vector<int>(n, 0));
        
        for (auto &edge : edges) {
            graph[edge[1]][edge[0]] = edge[2] == -1 ? INF : edge[2];
            graph[edge[0]][edge[1]] = edge[2] == -1 ? INF : edge[2];
        }
    }
    
    /**
     * @brief Uses Dijkstra's algorithm to find the shortest path from src to dst.
     * 
     * @param src The starting node
     * @param dst The destination node
     * @param n The number of nodes in the graph
     * @return int The shortest path distance from src to dst
     */
    int dijkstra(int src, int dst, int n) {
        vector<long long> distances(n, INT_MAX);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();
            
            if (currDist > distances[currNode]) continue;
            
            distances[currNode] = currDist;
            
            if (currNode == dst) {
                break;
            }
            
            for (int child = 0; child < n; child++) {
                if (graph[currNode][child] > 0) {
                    long long newDist = graph[currNode][child] + (long long) 0 + currDist;
                    if (newDist < distances[child]) {
                        distances[child] = newDist;
                        pq.push({distances[child], child});
                    }
                }
            }
        }
        
        return distances[dst];
    }
    
    /**
     * @brief Modifies the graph edges to ensure the shortest path from src to dst meets the target distance.
     * 
     * @param n The number of nodes in the graph
     * @param edges The list of edges with possible unknown weights
     * @param src The starting node
     * @param dst The destination node
     * @param target The target shortest path distance
     * @return vector<vector<int>> The modified list of edges, or an empty list if impossible
     */
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int target) {
        setupGraph(edges, n, src);
        int currDist = dijkstra(src, dst, n);
        
        if (currDist < target) {
            return {};
        } else if (currDist == target) {
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][2] == -1) {
                    edges[i][2] = target;
                }
            }
            return edges;
        }
        for (int i = 0; i < edges.size() && currDist > target; i++) {
            if (edges[i][2] == -1) {
                
                graph[edges[i][0]][edges[i][1]] = 1;
                graph[edges[i][1]][edges[i][0]] = 1;
                
                edges[i][2] = 1;
                
                currDist = dijkstra(src, dst, n);
                
                if (currDist == target) {
                    for (int j = i + 1; j < edges.size(); j++) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = target;
                        }
                    }
                    
                    return edges;
                } else if (currDist < target) {
                    edges[i][2] = 1 + target - currDist;
                    
                    for (int j = i + 1; j < edges.size(); j++) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = target;
                        }
                    }
                    
                    return edges;
                }
            }
        }
        
        return {};
    }
};

