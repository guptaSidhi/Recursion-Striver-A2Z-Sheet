const int MOD = 1000000007;

    void solve(int index, int n, int *arr, int sum, int &cnt) {
        // Base cases
        // Here comes the edge case where (1,0) me index 1 pe aayenge aur sum = 0 
        // ho chuka tb agr humne pehle hi check krliya ki sum = 0 h to hm aage jaa hi nhi payenge
        
        if(index == n)
        {
            if(sum == 0) cnt = (cnt+1)%MOD;
            return;
        }
    
        // Recursively check subsets
        solve(index + 1, n, arr, sum, cnt); // Exclude current element
        solve(index + 1, n, arr, sum - arr[index], cnt); // Include current element
    }
    
    int perfectSum(int arr[], int n, int sum) {
        int cnt = 0; // Initialize count
        solve(0, n, arr, sum, cnt); // Start recursion
        return cnt;
    }