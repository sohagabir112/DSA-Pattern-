class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>a(n);

        for(int i=0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];

            a[s - 1].push_back({d - 1, w});
        }

        vector<int>dist(n,INT_MAX);

        priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

        dist[k - 1] = 0;
        pq.push({0,k - 1});

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if(d > dist[node]){
                continue;
            }

            for(int j=0;j<a[node].size();j++){
                int neigh = a[node][j].first;
                int wt = a[node][j].second;

                if(d+wt < dist[neigh]){
                    dist[neigh] = d + wt;
                    pq.push({d+wt, neigh});
                }
            }
        }
        int maxTime = 0;

        for(int i=0;i<dist.size();i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};


// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x30000000;
alignas (std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *
operator new (size_t size){
    constexpr std::size_t alignment = alignof (std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete (void * /*unused*/, unsigned long /*unused*/) noexcept {}
void operator delete (void * /*unused*/) noexcept {}
void operator delete[] (void * /*unused*/) noexcept {}
void operator delete[] (void * /*unused*/, size_t /*unused*/) noexcept {}