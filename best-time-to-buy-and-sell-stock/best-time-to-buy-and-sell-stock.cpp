class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minelem=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            minelem=min(minelem,prices[i]);
            profit=max(profit,prices[i]-minelem);
        }
        return profit;
        
    }
};