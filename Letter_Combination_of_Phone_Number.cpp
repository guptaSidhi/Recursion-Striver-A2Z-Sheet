class Solution {
public:
    void solve(int index,int n,string digits,unordered_map <int,string> &mp,string &temp,vector <string> &ans)
    {
        // Base Condition
        if(index >= n)
        {
            ans.push_back(temp);
            return;
        }
        
        // Finding the string wrt to number
        int value = digits[index];
        string num = mp[value-'0'];

        // Iterating over the string
        for(int i=0;i<num.size();i++)
        {
            temp.push_back(num[i]);
            solve(index+1,n,digits,mp,temp,ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map <int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector <string> ans;
        string temp = "";
        int n = digits.size();
        solve(0,n,digits,mp,temp,ans);
        return ans;
    }
};