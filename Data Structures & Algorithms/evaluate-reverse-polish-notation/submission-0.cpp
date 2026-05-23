class Solution {
public:
int operate(int a,int b, string s){
    if(s=="+") return b+a;
        if(s=="*") return b*a;
        if(s=="-") return b-a;
        if(s=="/") return b/a;
        

        


}




    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int result=operate(a,b,s);
                st.push(result);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
