class Solution {
public:
    string longestPalindrome(string s) {
        string result;

        if(s.empty())
            return result;

        int maxLength = 0;
        int start = 0;
        int end = 0;
        bool dp[1000][1000] = {false};

        for(int i=0;i<s.length();++i)
        {
            dp[i][i] = true;
        }

        for(int k=2;k<=s.length();++k)
        {
            for(int i=0;i<=s.length()-k;++i)
            {
                if(i + 1 == i + k - 1)
                {
                    if(s[i] == s[i+k-1])
                    {
                        dp[i][i+k-1] = true;
                        start = i;
                        end = i + k - 1;
                    }
                    else
                    {
                        dp[i][i+k-1] = false;
                    }
                }
                else
                {
                    if(s[i] == s[i+k-1])
                    {
                        dp[i][i+k-1] = dp[i+1][i+k-1-1];
                        if(dp[i][i+k-1])
                        {
                            start = i;
                            end = i + k - 1;
                        }
                    }
                    else
                    {
                        dp[i][i+k-1] = false;
                    }
                }
            }
        }

        result = s.substr(start, end - start + 1);

        return result;
    }
};
