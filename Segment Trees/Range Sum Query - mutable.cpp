class NumArray {
public:
    int n;
    vector<int> segTree;

    void build(int i, int l, int r, vector<int>& nums){ // build the segTree
        if(l == r){
            segTree[i] = nums[r];
            return;
        }

        int mid = (l + r)/2;
        build(2*i + 1, l, mid, nums);
        build(2*i + 2, mid + 1, r, nums);

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

    void updateQ(int ind, int val, int i, int l, int r){ //update segTree
        if(l == r && l == ind){
            segTree[i] = val;
            return;
        }

        int mid = (l + r)/2;
        if(ind <= mid){
            updateQ(ind, val, 2*i + 1, l, mid);
        } else {
            updateQ(ind, val, 2*i + 2, mid + 1, r);
        }

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

    int query(int s, int e, int i, int l, int r){ // process query
        if(e < l || s > r){
            return 0;
        } 
        else if(l >= s && r <= e){
            return segTree[i];
        }
        
        int mid = (l + r)/2;
        return query(s, e, 2*i + 1, l, mid) + query(s, e, 2*i + 2, mid + 1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateQ(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
