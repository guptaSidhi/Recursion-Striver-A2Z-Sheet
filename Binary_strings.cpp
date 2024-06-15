void solve(int index,int num,string &temp,vector <string> &ans)
    {
        // Base Condition
        if(index == num)
        {
            ans.push_back(temp);
            return;
        }
        
        // Include 0 in string
        temp.push_back('0');
        solve(index+1,num,temp,ans);
        temp.pop_back();
        
        // Include 1 in string
        if(temp[index-1] != '1')
        {
            temp.push_back('1');
            solve(index+1,num,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector <string> ans;
        string temp = "";
        solve(0,num,temp,ans);
        return ans;
    }