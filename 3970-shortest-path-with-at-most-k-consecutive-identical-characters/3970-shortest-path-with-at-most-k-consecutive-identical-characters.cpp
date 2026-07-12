class Solution {
    struct Node {
        int u;
        int count;
        int wt;
        
        // Min-heap comparison based on weight
        bool operator>(const Node& other) const {
            return wt > other.wt;
        }
    };

public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Step 1: Make the Adjacency List
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges)
            adj[edge[0]].push_back({edge[1], edge[2]});
        
        // Step 2: Assign data structures
        // dist[node][consecutive_count] = min_weight
        // We use 1e9 as a safe equivalent for infinity to prevent overflow
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9)); 
        
        priority_queue<Node, vector<Node>, greater<Node>> minheap;
        
        // Start at node 0, with 1 consecutive character (labels[0]), weight 0
        dist[0][1] = 0;
        minheap.push({0, 1, 0});
        
        // Step 3: Apply Dijkstra with state (node, consecutive_count)
        while (!minheap.empty()) {
            auto [u, count, wt] = minheap.top();
            minheap.pop();
            
            // Found Destination
            if (u == n - 1)
                return wt;
            
            // Skip outdated states
            if (wt > dist[u][count])
                continue;
            
            // Process adjacent nodes
            for (const auto& [v, edge_wt] : adj[u]) {
                // Calculate new consecutive count
                int next_count = (labels[v] == labels[u]) ? count + 1 : 1;
                
                // If taking this edge violates the k-consecutive rule, skip it
                if (next_count > k)
                    continue;
                
                int next_wt = wt + edge_wt;
                
                // Relaxation step
                if (next_wt < dist[v][next_count]) {
                    dist[v][next_count] = next_wt;
                    minheap.push({v, next_count, next_wt});
                }
            }
        }
        return -1;
    }
};