void solve(int index,int n,vector <int> &arr,int sum,vector <int> &temp)
    {
        if(index == n)
        {
            temp.push_back(sum);
            return;
        }
        
        // Exclude
        solve(index+1,n,arr,sum,temp);
        
        // Include
        solve(index+1,n,arr,sum+arr[index],temp);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector <int> ans;
        solve(0,n,arr,0,ans);
        return ans;
    }