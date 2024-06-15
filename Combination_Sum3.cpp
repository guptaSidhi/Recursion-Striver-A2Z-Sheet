class Solution {
public:
    void solve(int index,int sum,int k,int *arr,vector <int> &temp,vector<vector<int>> &ans){
        // Base Conditions
        if(sum == 0 && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
 
        if(sum < 0 || index >= 9) return;

        // Exclude
        solve(index+1,sum,k,arr,temp,ans);

        // Include
        temp.push_back(arr[index]);
        solve(index+1,sum-arr[index],k,arr,temp,ans);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > n) return {};
        int arr[9] = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector <int> temp;
        solve(0,n,k,arr,temp,ans);
        return ans;
    }
};