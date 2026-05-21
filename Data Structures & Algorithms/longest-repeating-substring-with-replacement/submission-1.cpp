class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int len=0;
        int maxlen=0;
        int maxfreq=0;
        int l=0;
        unordered_map<char,int>mpp;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            maxfreq=max(maxfreq,mpp[s[r]]);
            len=r-l+1;
            while(len-maxfreq>k){
                mpp[s[l]]--;
                l++;
                len = r - l + 1;
            }
              
            maxlen=max(maxlen,len);

        }
        return maxlen;


    }
};
