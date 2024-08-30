/**
 * @file MaxProbabilityPath.cpp
 * @brief Solution to the LeetCode problem "Path with Maximum Probability"
 * @link https://leetcode.com/problems/path-with-maximum-probability/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given a set of `n` nodes labeled from `0` to `n-1` representing a network of nodes connected by edges, each with an associated success probability. Given an array of edges and an array of success probabilities for each edge, find the path from the start node to the end node with the maximum success probability. If no path exists, return `0`.
 * 
 * Intuition:
 * This problem can be seen as a variant of the shortest path problem where instead of finding the path with the minimum distance, we are finding the path with the maximum probability. A modified Dijkstra's algorithm can be used, where the priority queue (max-heap) is based on the maximum probability instead of the minimum distance.
 * 
 * Approach:
 * 1. **Graph Representation**: Build an adjacency list representation of the graph where each edge is represented with its success probability.
 * 2. **HeapMap Class**: Implement a custom priority queue using a set for fast access, insertions, and deletions.
 * 3. **Modified Dijkstra’s Algorithm**: Use the custom heap to extract the node with the current maximum probability. Update the probabilities for its neighbors and push them into the heap if a higher probability path is found.
 * 4. **Return Result**: After processing, return the maximum probability to reach the end node. If no path is found, return `0`.
 * 
 * Time Complexity:
 * - O((E + V) * logV), where `E` is the number of edges, and `V` is the number of vertices (nodes). Each edge is processed, and each node is pushed into the heap.
 * 
 * Space Complexity:
 * - O(V + E), for storing the graph and additional space for the heap and distances.
 */

#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

using pii = pair<double, int>;

class HeapMap {
public:
    set<pii, greater<pii>> pq;
    unordered_map<int, set<pii, greater<pii>>::iterator> pos;
    
    /**
     * @brief Inserts an element with the given distance into the heap.
     * 
     * @param distance The distance/probability value
     * @param element The node element
     */
    void insert(double distance, int element) {
        auto it = pq.insert({distance, element}).first;
        pos[element] = it;
    }
    
    /**
     * @brief Checks if the element exists in the heap.
     * 
     * @param element The node element
     * @return bool True if the element exists, otherwise false
     */
    bool elementExist(int element) {
        return pos.find(element) != pos.end();
    }
    
    /**
     * @brief Checks if the heap is empty.
     * 
     * @return bool True if the heap is empty, otherwise false
     */
    bool isEmpty() {
        return pq.empty();
    }
    
    /**
     * @brief Increases the key (probability value) of an existing element in the heap.
     * 
     * @param distance The new probability value
     * @param element The node element
     */
    void increaseKey(double distance, int element) {
        if (elementExist(element)) {
            pq.erase(pos[element]);
            pos[element] = pq.insert({distance, element}).first;
        }
    }
    
    /**
     * @brief Extracts the element with the maximum probability from the heap.
     * 
     * @return pii The pair containing the maximum probability and its corresponding node
     */
    pii extractMax() {
        pii element = {-1, -1};
        if (!isEmpty()) {
            auto it = pq.begin();
            element = {it->first, it->second};
            pq.erase(it);
            pos.erase(element.second);
        }
        
        return element;
    }
};

class Solution {
public:
    vector<vector<pii>> graph;
    HeapMap *hmp;
    
    /**
     * @brief Builds the graph using the given edges and success probabilities.
     * 
     * @param n The number of nodes
     * @param edges The list of edges
     * @param succProb The list of success probabilities for each edge
     * @param start_node The starting node for the path
     */
    void buildGraph(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node) {
        graph.resize(n);
        
        hmp = new HeapMap();
        
        // Initialize the heap with default probability
        for (int i = 0; i < n; i++) {
            hmp->insert(0, i);
        }
        
        hmp->increaseKey(1, start_node);
        
        // Populate the graph with the given edges
        for (int k = 0; k < edges.size(); k++) {
            if (succProb[k] != 0) {
                graph[edges[k][0]].push_back({succProb[k], edges[k][1]});
                graph[edges[k][1]].push_back({succProb[k], edges[k][0]});
            }
        }
    }
    
    /**
     * @brief Uses a modified Dijkstra's algorithm to find the path with the maximum probability.
     * 
     * @param start_node The starting node
     * @param end_node The destination node
     * @param n The number of nodes
     * @return double The maximum probability to reach the destination node
     */
    double dijkstra(int start_node, int end_node, int n) {
        vector<double> distances(n, 0);
        
        distances[start_node] = 1;
        
        while (!hmp->isEmpty()) {
            auto [currDist, currElement] = hmp->extractMax();
            
            if (currDist < distances[currElement]) continue;
            
            for (auto [dist, child] : graph[currElement]) {
                if (hmp->elementExist(child) && ((dist * currDist) > distances[child])) {
                    hmp->increaseKey(dist * currDist, child);
                    distances[child] = dist * currDist;
                }
            }
        }
        
        return distances[end_node];
    }
    
    /**
     * @brief Finds the maximum probability path from the start node to the end node.
     * 
     * @param n The number of nodes
     * @param edges The list of edges
     * @param succProb The list of success probabilities for each edge
     * @param start_node The starting node
     * @param end_node The destination node
     * @return double The maximum probability to reach the destination node
     */
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        buildGraph(n, edges, succProb, start_node);
        
        return dijkstra(start_node, end_node, n);
    }
};

