bool solve(int index,int n,vector <int>&a,int sum)
{
    if(sum == 0) return true;
    if(index == n) return false;

    bool pick = solve(index+1,n,a,sum-a[index]);
    if(pick == true) return true;

    bool unpick = solve(index+1,n,a,sum);
    if(unpick == true) return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return solve(0,n,a,k);
}