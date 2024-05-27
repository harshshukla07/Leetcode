// class Solution {

// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int fresh = 0,time=0,rotten=0;
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int,int>>q;
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     q.push({i,j});
//                     vis[i][j] = 2;
    
//                 }
//                 else{
//                     vis[i][j] = 0;
//                 }
//                 if(grid[i][j]==1){
//                     fresh++;
//                 }
//             }
//         }

//         vector<int> dx = {0,1,0,-1};
//         vector<int> dy = {1,0,-1,0};

//         while(!q.empty()){
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nr = r + dx[i];
//                 int nc = c + dy[i];
//                 if(vis[nr][nc]!=2 && nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
//                     q.push({nr,nc});
//                     vis[nr][nc]=2;
//                     rotten++;
//                 }
//             }   
//             time++;         

//         }
//         return rotten==fresh?time:-1;

//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, time = 0; // time starts at 0
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q; // queue to hold rotting oranges

        // Initialize the fresh count and the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { 
                    fresh++; // Count the fresh oranges
                } else if (grid[i][j] == 2) { 
                    q.push({i, j}); // Add rotten oranges to the queue
                }
            }
        }

        // Directions for BFS traversal (up, right, down, left)
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        // Perform Breadth-First Search (BFS)
        while (!q.empty()) {
            int size = q.size();  // Number of oranges to process at this time step

            for (int k = 0; k < size; k++) { 
                int r = q.front().first; // Row of current orange
                int c = q.front().second; // Column of current orange
                q.pop(); // Remove processed orange from the queue

                // Explore neighboring oranges
                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i]; 
                    int nc = c + dy[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Mark the neighboring orange as rotten
                        fresh--; // Decrease the count of fresh oranges
                        q.push({nr, nc}); // Add the newly rotten orange to the queue
                    }
                }
            }

            // Increment time only if there were oranges to process in this step
            if (!q.empty()) {
                time++; 
            }
        }

        // If all fresh oranges have been rotten, return the time taken
        return (fresh == 0) ? time : -1; // Return -1 if there are still fresh oranges
    }
};