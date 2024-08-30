/**
 * @file LongestCycleInGraph.cpp
 * @brief Solution to the LeetCode problem "Longest Cycle in a Graph"
 * @link https://leetcode.com/problems/longest-cycle-in-a-graph/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a directed graph represented as an array `edges`, where `edges[i]` is the destination node from node `i`, find the longest cycle in the graph. Return the length of the longest cycle. If no cycle exists, return -1.
 * 
 * Intuition:
 * This problem can be approached using Kosaraju’s algorithm, which is typically used to find strongly connected components (SCCs) in a directed graph. By running DFS twice—first to determine the order of nodes by finish times and second to discover SCCs—we can identify the largest cycle.
 * 
 * Approach:
 * 1. **Build Reverse Graph**: Construct a reverse graph where the edges point in the opposite direction to facilitate the second pass of DFS.
 * 2. **First DFS Pass (Finish Order)**: Perform DFS on the original graph to get the nodes' finish order. This helps in processing nodes in the right order for SCC discovery.
 * 3. **Second DFS Pass (SCC Detection)**: Process nodes in the reverse finish order using the reverse graph to discover SCCs and calculate the size of each SCC.
 * 4. **Determine the Longest Cycle**: From the sizes of SCCs, determine the longest cycle by ignoring components with only a single node since they do not form a cycle.
 * 
 * Time Complexity:
 * - O(V + E), where `V` is the number of vertices (nodes) and `E` is the number of edges. Each node and edge is processed twice (once in each DFS pass).
 * 
 * Space Complexity:
 * - O(V + E), for storing the graph and reverse graph, as well as additional space for tracking visited nodes and the stack for finish order.
 */

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    vector<vector<int>> reverseGraph;
    vector<int> graph;
    vector<bool> visited;
    stack<int> finishOrder;
    
    /**
     * @brief Builds the reverse graph to facilitate the second DFS pass.
     * 
     * @param edges The original graph represented as an edge list
     */
    void buildReverseGraph(vector<int> &edges) {
        reverseGraph.resize(edges.size());
        visited.resize(edges.size(), false);
        
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1) {
                reverseGraph[edges[i]].push_back(i);
            }
        }
    }
    
    /**
     * @brief First DFS pass to populate the finish order of nodes.
     * 
     * @param node The current node being visited
     */
    void firstDfs(int node) {
        if (node == -1 || visited[node]) return;
        visited[node] = true;
        if (graph[node] != -1 && !visited[graph[node]]) firstDfs(graph[node]);
        finishOrder.push(node);
    }
    
    /**
     * @brief Second DFS pass to discover SCCs and calculate their sizes.
     * 
     * @param node The current node being processed
     * @return int The size of the SCC including this node
     */
    int secondDfs(int node) {
        if (visited[node] || node == -1) return 0;
        
        int node_count = 0;
        visited[node] = true;
        
        for (int child : reverseGraph[node]) {
            node_count += secondDfs(child);
        }
        
        return 1 + node_count;
    }
    
    /**
     * @brief Runs Kosaraju’s algorithm to find the longest cycle in the graph.
     * 
     * @param edges The original graph represented as an edge list
     * @return int The length of the longest cycle, or -1 if no cycle exists
     */
    int kosaraju(vector<int> &edges) {
        graph = edges;
        buildReverseGraph(edges);
        
        // First pass: Get finish order
        for (int i = 0; i < edges.size(); i++) {
            if (!visited[i]) {
                firstDfs(i);
            }
        }
        
        // Reset visited array for second DFS pass
        fill(visited.begin(), visited.end(), false);
        int maxSize = -1; // Default to -1 to handle no cycle cases
        
        // Second pass: Process nodes in reverse finish order
        while (!finishOrder.empty()) {
            int node = finishOrder.top();
            finishOrder.pop();
            
            if (!visited[node]) {
                int cycleSize = secondDfs(node);
                if (cycleSize > 1) {  // Ignore single node as it can't be a cycle
                    maxSize = max(maxSize, cycleSize);
                }
            }
        }
        
        return maxSize;
    }
    
    /**
     * @brief Finds the longest cycle in the graph.
     * 
     * @param edges The original graph represented as an edge list
     * @return int The length of the longest cycle, or -1 if no cycle exists
     */
    int longestCycle(vector<int>& edges) {
        return kosaraju(edges);
    }
};

