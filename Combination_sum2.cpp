class Solution {
public:
    void solve(int index,int n,vector <int> &arr,vector <int> &temp, vector<vector<int>> &ans,int sum)
    {
        if(sum == 0) 
        {
            ans.push_back(temp);
            return;
        }

        if(index >= n || sum < 0) return;

        for(int i=index;i<n;i++)
        {
            if(i > index && arr[i] == arr[i-1]) continue;

            // Include
            temp.push_back(arr[i]);
            solve(i+1,n,arr,temp,ans,sum-arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector <int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,n,candidates,temp,ans,target);
        return ans;
    }
};