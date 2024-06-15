class Solution {
public:
    void solve(int index,int n,vector <int> &nums,vector <int> &temp,vector<vector<int>> &ans)
    {
        if(index == n) 
        {
            ans.push_back(temp);
            return;
        }

        // Not wanted
        solve(index+1,n,nums,temp,ans);

        // Wanted
        temp.push_back(nums[index]);
        solve(index+1,n,nums,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> temp;
        solve(0,nums.size(),nums,temp,ans);
        return ans;
    }
};