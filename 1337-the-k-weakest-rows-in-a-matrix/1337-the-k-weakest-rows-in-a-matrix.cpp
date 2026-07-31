class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++){
            int soldiers = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    soldiers++;
                }
                else{
                    break;
                }
            }

            pq.push({soldiers,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};