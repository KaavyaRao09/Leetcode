class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        sort(cost.begin(),cost.end());
        int ans = 0;
        int cnt = 0;
        for(int i=cost.size()-1;i>=0;i--)
        {
            cnt++;
            if(cnt%3==0) continue;
            ans += cost[i];
        }
        return ans;
    }
};