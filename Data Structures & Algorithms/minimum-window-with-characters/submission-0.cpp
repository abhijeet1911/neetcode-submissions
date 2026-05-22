class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n) return "" ;
        unordered_map<char,int>mpp;
       
        int windowsize=INT_MAX;
        int start_i=0;
        int cnt=t.size();
        for(char c:t){
            mpp[c]++;
        }
        int i=0;
        int j=0;
        while(j<n){
            char ch=s[j];
            if(mpp[ch]>0) cnt--;
            mpp[ch]--;
            while(cnt==0){
                int curr=j-i+1;
                if(windowsize>curr){
                    windowsize=curr;
                    start_i=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                    cnt++;
                }
                i++;
            }
            j++;


        }
        return windowsize==INT_MAX?"":s.substr(start_i,windowsize);
                       
    }
};                   