class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        string result;
        
        for (int startCol = 0; startCol < cols; startCol++) {
            int row = 0;
            int col = startCol;
            
            while (row < rows && col < cols) {
                result += encodedText[row * cols + col];
                row++;
                col++;
            }
        }
        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};