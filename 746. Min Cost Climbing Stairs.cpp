#include <algorithm> 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()); 
        // copy cost[] to dp[]
        copy(cost.begin(), cost.end(), dp.begin());
        for (int i = 2; i < cost.size(); i++) {
            /**
                this is the reason why we copy cost[] to dp[] at the beginning
                because the cost at index i is equal to: 
                cost of this step + the best pick previoust step
                dp[i] is the cost of current step, and we pick the minimum 
                of what we have 1 or 2 steps before, it's simulating
                the fact that we are picking the minimum cost every time
            **/
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        // return the accumulated costs 
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

