class Solution {
public:
    bool fun(vector<int> &have, vector<int> &need){
        for(int i=0; i<256; i++){
            if(have[i] < need[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int low =0;
        int high =0;
        int n = s.size();
        int m = t.size();
        int start = -1;
        int res = INT_MAX;
        vector<int>have(256,0);
        vector<int>need(256,0);

        if(n<m){
            return "";
        }

        for(int i=0;i<m;i++){
            need[t[i]]++;
        }

        for(high=0; high<n; high++){
            have[s[high]]++;

            while(fun(have, need)){
                int len = high - low + 1;
                if(res>len){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return res == INT_MAX ? "" : s.substr(start,res) ;
    }
};