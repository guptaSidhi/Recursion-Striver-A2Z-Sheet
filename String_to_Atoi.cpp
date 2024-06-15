class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int index = 0;
        bool sign = false;
        // Checking for whitespaces 
        while(s[index] == ' ') index++;

        // Checking for the sign
        if(s[index] == '-' || s[index] == '+')
        {
            if(s[index] == '-') sign = true;
            index++;
        }

        // Main part of checking integer values
        for(int i=index;i<s.size();i++)
        {
            if(s[i] >= '0' && s[i] <= '9') 
                ans = ans*10 + (s[i]-'0');
            else break;
            if (ans > INT_MAX) {
                return sign ? INT_MIN : INT_MAX;
            }
        }

        // Arranging the ans according to conditions

        if (sign) {
            ans = -ans;
            if (ans < INT_MIN) {
                return INT_MIN;
            }
        } 
        else {
            if (ans > INT_MAX) {
                return INT_MAX;
            }
        }

        return int(ans);
    }
};