class Solution {
  public: 
    void solve(int index,int n,string temp,string s,set<string> &ans)
    {
        if(index == n)
        {
            ans.insert(temp);
            return;
        }
        
        solve(index+1,n,temp,s,ans);
        solve(index+1,n,temp+s[index],s,ans);
    }
    
    string betterString(string str1, string str2) {
        // code here
        string temp = "";
        set<string> ans1;
        set<string> ans2;
        solve(0,str1.size(),"",str1,ans1);
        solve(0,str2.size(),"",str2,ans2);
        if(ans1.size() >= ans2.size()) return str1;
        return str2;
    }
};