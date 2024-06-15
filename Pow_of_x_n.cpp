class Solution {
public:
    double solve(double x,int n)
    {
        if(n == 0) return 1;
        if(n == 1) return x;
        double pro = solve(x,n/2);
        if(n%2 == 0) return pro*pro;
        else return x*pro*pro;
    }

    double myPow(double x, int n) {
        // Converting it into absolute value so that we can do modifications afterwards 
        if(x == 0) return 0;
        if(n == 0 || x == 1) return 1;
        if(n < 0) return solve(1/x,n);
        return solve(x,n);
    }
};