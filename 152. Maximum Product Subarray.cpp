class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int finalMax = nums[0], n = nums.size();
        int localMax = nums[0];
        int localMin = nums[0];
        int tmp;
        for (int i = 1; i < n; i++) {
            tmp = localMax;
            localMax = max(max(localMax * nums[i], localMin * nums[i]), nums[i]);
            localMin = min(min(tmp * nums[i], localMin * nums[i]), nums[i]);
            finalMax = max(finalMax, localMax);
        }
        return finalMax;
    }
};