class Solution {
public:
    // It is like we are taking only those indexes which are distinct by checking their previous element 
    // and add them to the ans as we want all subsets 
    void solve(int index,int n,vector <int> &nums,vector <int> &temp,vector<vector<int>> &ans)
    {
        ans.push_back(temp);
    
        for(int i=index;i<n;i++)
        {
            if(i > index && nums[i] == nums[i-1]) continue;
            
            // Include
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,nums,temp,ans);
        return ans;
    }
};