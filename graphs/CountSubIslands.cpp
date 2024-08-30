/**
 * @file CountSubIslands.cpp
 * @brief Solution to the LeetCode problem "Count Sub Islands"
 * @link https://leetcode.com/problems/count-sub-islands/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given two `m x n` binary matrices `grid1` and `grid2` containing only 0s (representing water) and 1s (representing land). An island is a group of 1s connected vertically or horizontally. An island in `grid2` is considered a sub-island if there is an island in `grid1` that completely covers this island in `grid2`. Return the number of sub-islands in `grid2`.
 * 
 * Intuition:
 * To solve this problem, we need to identify islands in `grid2` that are entirely covered by land in `grid1`. This can be achieved by using a modified Depth-First Search (DFS) to traverse `grid2` while checking if the corresponding positions in `grid1` also have land. If we find any part of the island in `grid2` that is not covered by land in `grid1`, we know this island is not a sub-island.
 * 
 * Approach:
 * 1. **Mark Islands**: Traverse both grids simultaneously. If `grid2[i][j]` is land:
 *    - Mark it as `2` in `grid1` if the corresponding cell in `grid1` is also land.
 *    - Mark it as `3` in `grid1` if the corresponding cell in `grid1` is water.
 * 2. **Identify Sub-Islands**: Traverse `grid1` to find all cells marked as `2` (potential sub-islands) and use DFS to check if these islands are completely covered by land.
 * 3. **Count Sub-Islands**: If during DFS traversal from a cell marked as `2`, no cells marked as `3` are encountered, count this island as a sub-island.
 * 
 * Time Complexity:
 * - O(m * n), where `m` is the number of rows and `n` is the number of columns. Each cell is visited a constant number of times.
 * 
 * Space Complexity:
 * - O(1), since we are modifying the input grids in place and only using a few additional variables for bookkeeping.
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int m, n;
    bool covered = true;
    
    /**
     * @brief Performs DFS to check if the island is fully covered by land from grid1.
     * 
     * @param grid The modified grid combining information from grid1 and grid2
     * @param i The current row index
     * @param j The current column index
     */
    void isFullyCovered(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 1) {
            return;
        }
        if (grid[i][j] == 3) {
            covered = false;
        }
        
        grid[i][j] = 0;
        
        isFullyCovered(grid, i + 1, j);
        isFullyCovered(grid, i - 1, j);
        isFullyCovered(grid, i, j + 1);
        isFullyCovered(grid, i, j - 1);
    } 
    
    /**
     * @brief Counts the number of sub-islands in grid2 that are covered by islands in grid1.
     * 
     * @param grid1 The first input grid representing land and water
     * @param grid2 The second input grid representing land and water
     * @return int The number of sub-islands
     */
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        // Mark grid2 lands on grid1: 2 if it's a potential sub-island, 3 if it's not
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j]) {
                    if (grid1[i][j]) {
                        grid1[i][j] = 2;
                    } else {
                        grid1[i][j] = 3;
                    }
                }
            }
        }
        
        int numIslands = 0;
        
        // Find sub-islands in the modified grid1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid1[i][j] == 2) {
                    covered = true;
                    isFullyCovered(grid1, i, j);
                    if (covered) {
                        numIslands++;
                    }
                }
            }
        }
        
        return numIslands;
    }
};

