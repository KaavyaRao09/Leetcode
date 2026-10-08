#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));  // 0: unvisited, 1: wall, 2: guard, 3: guarded

        // Mark guards and walls
        for (const auto& w : walls)
            grid[w[0]][w[1]] = 1;  // wall
        for (const auto& g : guards)
            grid[g[0]][g[1]] = 2;  // guard

        // Four directions: left, right, up, down
        for (int i = 0; i < m; ++i) {
            // Left to right
            bool seen = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) seen = false;         // wall blocks vision
                else if (grid[i][j] == 2) seen = true;     // guard starts vision
                else if (seen && grid[i][j] == 0) grid[i][j] = 3; // mark as guarded
            }
            // Right to left
            seen = false;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen && grid[i][j] == 0) grid[i][j] = 3;
            }
        }

        for (int j = 0; j < n; ++j) {
            // Top to bottom
            bool seen = false;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen && grid[i][j] == 0) grid[i][j] = 3;
            }
            // Bottom to top
            seen = false;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen && grid[i][j] == 0) grid[i][j] = 3;
            }
        }

        // Count unoccupied, unguarded cells
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++count;
        return count;
    }
};
