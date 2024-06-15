void solve(int row,int col,vector<vector<int>> &arr,int n,int *rowin,int *colin,char *pathin,string &temp,vector<string> &ans,vector<vector<int> > &vis){
        if(row == n-1 && col == n-1){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int newr = row + rowin[i];
            int newc = col + colin[i];
            
            if(newr >= 0 && newr < n && newc >= 0 && newc < n && vis[newr][newc] == 0 && arr[newr][newc]  == 1)
            {
                vis[newr][newc] = 1;
                temp.push_back(pathin[i]);
                solve(newr,newc,arr,n,rowin,colin,pathin,temp,ans,vis);
                vis[newr][newc] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return {};
        int rowin[] = {-1,0,1,0};
        int colin[] = {0,1,0,-1};
        char pathin[] = {'U','R','D','L'};
        vector<vector<int>> vis(n,vector <int> (n,0));
        vector <string> ans;
        string temp = "";
        vis[0][0] = 1;
        solve(0,0,m,n,rowin,colin,pathin,temp,ans,vis);
        return ans;
    }