class Solution {
public:
    struct cmp{
        bool operator()(vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(),cmp());

        priority_queue<int>pq;
        int time = 0;

        for(int i=0;i<n;i++){
            time += courses[i][0];
            pq.push(courses[i][0]);

            if(time>courses[i][1]){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};