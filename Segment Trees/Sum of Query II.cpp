class Solution {
  public:
    int N;
    vector<int> seg; 
  
    void build(int i, int l, int r, int arr[]){
        if(l == r){
            seg[i] = arr[r];
            return;
        }
        
        int mid = (l + r)/2;
        build(2*i + 1, l, mid, arr);
        build(2*i + 2, mid + 1, r, arr);
        
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
  
    int query(int s, int e, int i, int l, int r){
        if(e < l || s > r){
            return 0;
        }
        
        if(s <= l && r <= e){
            return seg[i];
        }
        
        int mid = (l + r)/2;
        return query(s, e, 2*i + 1, l, mid) + query(s, e, 2*i + 2, mid + 1, r);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
       N = n;
       seg.resize(4*N);
       build(0, 0, n-1, arr);
       
       vector<int> ans;
       
       for(int i = 0; i<2*q; i += 2){
           int s = queries[i] - 1;
           int e = queries[i + 1] - 1;

           ans.push_back(query(s, e, 0, 0, n-1));
       }
       return ans;
    }
};