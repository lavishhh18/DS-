/* The functions which
builds the segment tree */
void build(int i, int l, int r, int segTree[], int arr[]){
    if(l == r){
        segTree[i] = arr[r];
        return;
    }
    
    int mid = l + (r-l)/2;
    build(2*i + 1, l, mid, segTree, arr);
    build(2*i + 2, mid + 1, r, segTree, arr);
    
    segTree[i] = min(segTree[2*i + 1], segTree[2*i + 2]);
}

int *constructST(int arr[], int n) {
    int *segTree = new int[4*n];
    build(0, 0, n-1, segTree, arr);
    
    return segTree;
    
}

/* The functions returns the
 min element in the range
 from a and b */
int query(int s, int e, int i, int l, int r, int st[]){
    if(e < l || s > r){
        return INT_MAX;
    }
    
    else if(s <= l && r <= e){
        return st[i];
    }
    
    int mid = l + (r - l)/2;
    return min(query(s, e, 2*i + 1, l, mid, st), query(s, e, 2*i + 2, mid+1, r, st));
}
 
int RMQ(int st[], int n, int a, int b) {
    return query(a, b, 0, 0, n-1, st);
}
