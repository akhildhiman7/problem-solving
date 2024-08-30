/**
 * @file CriticalConnectionsInNetwork.cpp
 * @brief Solution to the LeetCode problem "Critical Connections in a Network"
 * @link https://leetcode.com/problems/critical-connections-in-a-network/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a network of `n` nodes labeled from `0` to `n-1` represented by `connections` in the form of edges, determine which connections, if removed, would make the network disconnected. These connections are known as critical connections.
 * 
 * Intuition:
 * This problem can be solved using Tarjan's algorithm, a depth-first search (DFS) based algorithm to find bridges (critical connections) in a graph. A bridge is an edge in a graph that, when removed, increases the number of connected components.
 * 
 * Approach:
 * - Build the graph using adjacency lists.
 * - Use DFS to explore each node, keeping track of discovery times and the lowest discovery times reachable from each node.
 * - Identify edges where the lowest reachable discovery time of the adjacent node is greater than the discovery time of the current node. These edges are critical connections.
 * 
 * Steps:
 * 1. **Graph Construction**: Build an adjacency list representation of the graph.
 * 2. **Tarjan's Algorithm**: Use DFS to find bridges:
 *    - For each unvisited node, mark its discovery time and initialize its lowest reachable time.
 *    - For each child, if it has not been visited, recursively perform DFS and update the lowest reachable time.
 *    - If the lowest reachable time of the child is greater than the discovery time of the current node, the edge is a critical connection.
 * 3. **Edge Case**: If there's only one node, return an empty list since there are no connections.
 * 
 * Time Complexity:
 * - O(V + E), where `V` is the number of vertices (nodes) and `E` is the number of edges. Each edge and node is processed once.
 * 
 * Space Complexity:
 * - O(V + E), due to storing the graph and additional structures for tracking discovery times and parents.
 */

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visitedTime, lowTime, parents;
    vector<bool> visited;
    int currTime = 0;
    
    /**
     * @brief Builds the adjacency list representation of the graph.
     * 
     * @param n The number of nodes in the graph
     * @param edges The edges representing connections in the graph
     */
    void buildGraph(int n, vector<vector<int>> &edges) {
        graph.resize(n, vector<int>(0));
        visitedTime.resize(n, INT_MAX);
        lowTime.resize(n, INT_MAX);
        parents.resize(n, -1);
        visited.resize(n, false);
        
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    
    /**
     * @brief Uses DFS to find and record all critical edges (bridges).
     * 
     * @param node The current node being processed
     * @param res The result vector storing all critical connections
     */
    void criticalEdges(int node, vector<vector<int>> &res) {
        visited[node] = true;
        lowTime[node] = visitedTime[node] = currTime++;
        
        for (auto &child : graph[node]) {
            if (parents[node] == child) continue;
            
            if (!visited[child]) {
                parents[child] = node;
                
                criticalEdges(child, res);
                
                lowTime[node] = min(lowTime[node], lowTime[child]);
                
                if (visitedTime[node] < lowTime[child]) {
                    res.push_back({node, child});
                }
                
            } else {
                lowTime[node] = min(lowTime[node], visitedTime[child]);
            }
        }
    }
    
    /**
     * @brief Initiates the Tarjan's algorithm for finding critical connections.
     * 
     * @param n The number of nodes in the graph
     * @param connections The edges representing connections in the graph
     * @return vector<vector<int>> The list of critical connections
     */
    vector<vector<int>> tarjan(int n, vector<vector<int>> &connections) {
        buildGraph(n, connections);
        vector<vector<int>> res;
        
        criticalEdges(0, res);
        
        return res;
    }
    
    /**
     * @brief Finds all critical connections in the network.
     * 
     * @param n The number of nodes in the graph
     * @param connections The edges representing connections in the graph
     * @return vector<vector<int>> The list of critical connections
     */
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        return tarjan(n, connections);
    }
};

