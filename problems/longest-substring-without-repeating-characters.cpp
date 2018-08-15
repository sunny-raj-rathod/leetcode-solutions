class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;

        map<char, int> hashMap;
        int start = 0;
        int end = 0;
        int longestSubstr = INT_MIN;
        for(int i=0;i<s.length();++i)
        {
            if(hashMap.find(s[i]) != hashMap.end() &&
               hashMap[s[i]] >= start)
            {
                start = hashMap[s[i]] + 1;
            }

            end = i + 1;
            hashMap[s[i]] = i;
            longestSubstr = max(longestSubstr, end - start);
        }
        return longestSubstr;
    }
};
