class Solution {
public:
    using p = pair<int, int>;
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();

        vector<p> vec;

        for(int i = 0; i<n; i++){
            vec.push_back({a[i], b[i]});
        }

        sort(vec.begin(), vec.end(), [](p& o1, p& o2){
            return (o1.first + o1.second) > (o2.first + o2.second);
        });

        int alice = 0;
        int bob = 0;

        bool flag = true;
        for(int i = 0; i<n; i++){
            if(flag){
                alice += vec[i].first;
                flag = !flag;
            }
            else{
                bob += vec[i].second;
                flag = !flag;
            }
        }

        if(alice > bob) return 1;
        else if(bob > alice) return -1;
        else return 0;
    }
};