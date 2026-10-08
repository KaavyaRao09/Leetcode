class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        int prevGroup = 0;
        int currGroup = 1;
        int result = 0;
        
        for (int i = 1; i < n; i++) {
            
            if (s[i] == s[i - 1]) {
                currGroup++;
            } else {
                result += min(prevGroup, currGroup);
                
                prevGroup = currGroup;
                
                currGroup = 1;
            }
        }
        
        result += min(prevGroup, currGroup);
        
        return result;
    }
};