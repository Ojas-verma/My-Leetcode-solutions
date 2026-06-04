class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int r=0;
        int l=0;
        int ans=0;
        int n = s.length();
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                if (mp[s[l]]==1) mp.erase(s[l]);
                else mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};