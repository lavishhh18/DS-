class Solution {
public:
    int n;
    vector<int> segMin, segMax, lazy;

    void propagate(int i, int l, int r){
        if(lazy[i] != 0){
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if(l != r){
                lazy[2*i + 1] += lazy[i];
                lazy[2*i + 2] += lazy[i];
            }

            lazy[i] = 0;
        }
    }

    void update(int s, int e, int i, int l, int r, int val){
        propagate(i, l, r); //check if there is something in lazy and update

        if(e < l || s > r) return;

        else if(l >= s && r <= e){
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = l + (r - l)/2;
        update(s, e, 2*i + 1, l, mid, val);
        update(s, e, 2*i + 2, mid + 1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int leftmostZero(int i, int l, int r){
        propagate(i, l, r);

        if(segMin[i] > 0 || segMax[i] < 0) return -1;

        if(l == r) return l;

        int mid = l + (r - l)/2;

        int left = leftmostZero(2*i + 1, l, mid);
        if(left != -1) return left;

        return leftmostZero(2*i + 2, mid + 1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> last;

        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        vector<int> cumSum(n, 0);

        int ans = 0;

        for(int r = 0; r<n; r++){
            int val = (nums[r]%2 == 0) ? 1 : -1;
            int prev = -1;
            
            if(last.count(nums[r])){
                prev = last[nums[r]];
            }

            if(prev != -1){ //agar repeating hai toh pehle -val add then range mai add val
                update(0, prev, 0, 0, n-1, -val);
            }

            update(0, r, 0, 0, n-1, val); //add the val from 0 to r

            int LeftmostIdxWithZero = leftmostZero(0, 0, n-1);

            if(LeftmostIdxWithZero != -1){
                ans = max(ans, r - LeftmostIdxWithZero + 1);
            }

            last[nums[r]] = r;
        }
        return ans;
    }
};
