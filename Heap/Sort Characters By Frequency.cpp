class Solution {
public:
    typedef pair<char, int> p;

    struct lambda {
        bool operator()(p& p1, p& p2){
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        priority_queue<p, vector<p>, lambda> pq;
        unordered_map<char, int> f;

        for(auto c : s){
            f[c]++;
        }

        for(auto it : f){
            pq.push({it.first, it.second});
        }

        string ans = "";

        while(!pq.empty()){
            p it = pq.top();
            pq.pop();

            ans += string(it.second, it.first);
        }

        return ans;
    }
};
