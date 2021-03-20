class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // 用一个数组表示到某日为止的最少买入成本，然后和原数组相减得到每天卖出的最大收益
        // 因为只用到i-1和i，可以用两个变量来优化掉这个数组
        int ans=0;
        vector<int> pre_mins(prices.size(), prices[0]);
        for(int i=1; i<prices.size(); i++){
            pre_mins[i] = min(pre_mins[i-1], prices[i]);
            ans = max(ans, prices[i] - pre_mins[i-1]);
        }
        return ans;
    }
};