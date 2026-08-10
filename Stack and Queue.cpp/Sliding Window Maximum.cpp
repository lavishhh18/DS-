class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; //doubly ended queue
        vector<int> ans;

        for(int i = 0; i<n; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){ //while the curr el is bigger than the ones that came before, pop!
                dq.pop_back();
            }

            if(!dq.empty() && dq.front() < i - k + 1){ //if the el at front is out of the window, pop!
                dq.pop_front();
            }

            dq.push_back(i); //push the curr el in the window

            if(i - k + 1 >= 0){ //if the window size == k, return the el at front beacuse its the max el in the window
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};