class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.length()==0) return 0;

        vector<int>seen(256,0);

        int maxlen=1;
        for(int i=0,s=0; i<str.length(); i++)
        {
            s= max(s, seen[str[i]]);
            maxlen=max(maxlen, i-s+1);
            seen[str[i]]=i+1;
        }
        return maxlen;
    }
};