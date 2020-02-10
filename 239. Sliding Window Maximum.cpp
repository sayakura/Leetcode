#include <deque>
#include <vector>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        deque<int> dq; // we are creating a monotonic queue here
        vector<int> ret;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            // pop what's on the front because the window is shifting to the right
            // and we need to drop that index
            if (!dq.empty() && (windowEnd - k) == dq.front()) 
                dq.pop_front();
            // use monotonic queue to only keep the relevant info and stores only 
            // the the index of those "maximums " we need 
            while (!dq.empty() && nums[windowEnd] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(windowEnd);
            // skip the first k - 1 element, and we need to store the max 
            // of the first k elements 
            if (windowEnd >= k - 1) 
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};