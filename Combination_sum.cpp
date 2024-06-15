class Solution {
public:
    void solve(int index,int n, vector <int> &arr,vector <int> &temp, vector<vector<int>> &ans,int sum)
    {
        // Base Conditions
        if(index == n)
        {
            if(sum == 0) ans.push_back(temp);
            return;
        }

        if(sum < 0) return;

        // Include number
        temp.push_back(arr[index]);
        solve(index,n,arr,temp,ans,sum - arr[index]);
        temp.pop_back();

        // Exclude number
        solve(index+1,n,arr,temp,ans,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector <int> temp;
        int n = candidates.size();
        solve(0,n,candidates,temp,ans,target);
        return ans;
    }
};