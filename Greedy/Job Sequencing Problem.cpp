class dsu {
  public:
    vector<int> parent;
    dsu(int n){
        parent.resize(n + 1);
        
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int find(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = find(parent[node]);
    }
    
    void occupy(int day){
        parent[day] = day - 1;
    }
};

class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<p> vec;
        
        int maxD = 0;
        for(int i = 0; i<n; i++){
            vec.push_back({deadline[i], profit[i]});
            maxD = max(maxD, deadline[i]);
        }
        
        dsu uni(maxD);
        
        int jobs = 0;
        int maxProfit = 0;
        
        sort(vec.begin(), vec.end(), [](p& a, p& b){
            return a.second > b.second;
        });
        
        for(int i = 0; i<n; i++){
            int d = vec[i].first;
            
            int idx = uni.find(d); //latest free day
            
            if(idx == 0) continue;
            
            maxProfit += vec[i].second;
            jobs++;
            
            uni.occupy(idx);
        }
        
        return {jobs, maxProfit};
        
    }
};