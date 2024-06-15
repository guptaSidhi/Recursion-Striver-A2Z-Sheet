class Solution {
public:                                                                    
    bool solve(int index,int n,string &s,unordered_set<string> &st)
    {
        if(index >= n)  return true;
        string temp = "";
        for(int i=index;i<n;i++)
        {
            temp.push_back(s[i]);
            if(st.find(temp) != st.end())
            {
                if(solve(i+1,n,s,st) ==  true) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        for(auto i: wordDict) st.insert(i);  
        if(solve(0,s.size(),s,st) == true) return true;
        return false;
    }
};