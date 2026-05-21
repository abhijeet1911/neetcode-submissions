class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string str2=strs[i];
            sort(str2.begin(),str2.end());
           
            
                mpp[str2].push_back(strs[i]);
            }
        
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
