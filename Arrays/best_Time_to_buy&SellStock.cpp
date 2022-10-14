class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxRight = prices[prices.size()-1];
      int maxProfit = 0;
      int n = prices.size()-1;
      for(int i = n-1; i >=0; i--){
          maxRight = max(maxRight, prices[i]);
          maxProfit = max(maxProfit, maxRight - prices[i]);
      }
      return maxProfit;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1);
