class Solution {
   public:
  string generate(string word){
    int arr[26]={0};
    for(char ch:word){
        arr[ch-'a']++;
    }
    string new_word="";
    for(int i=0;i<26;i++){
        int freq=arr[i];
        if(freq>0){
            new_word+=string(freq,i+'a');
        }
    }
    return new_word;
  }



    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
      unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string str2=strs[i];
            string new_word=generate(str2);
           
            
                mpp[new_word].push_back(str2);
            }
        
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

        






        
    

