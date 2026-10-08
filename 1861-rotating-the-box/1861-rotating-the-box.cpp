class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int row = 0; row < m; row++) {

            int emptyCol = n - 1;

            for (int col = n - 1; col >= 0; col--) {

                if (boxGrid[row][col] == '*') {

                    emptyCol = col - 1;
                }

                else if (boxGrid[row][col] == '#') {

                    boxGrid[row][col] = '.';

                    boxGrid[row][emptyCol] = '#';

                    emptyCol--;
                }
            }
        }

        vector<vector<char>> rotated(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotated;
    }
};