class Solution {
public:
  int nextgen(int n){
    int totalsum=0;
    int digit=0;
    while (n>0){
        digit=n%10;
        totalsum+=digit*digit;
        n=n/10;}
      return totalsum; 
    }
  
    bool isHappy(int n) {
        int slow=n;
        int fast=nextgen(n);
        while(slow!=fast && fast!=1){
            slow=nextgen(slow);
            fast=nextgen(nextgen(fast));
        }
        return fast==1;
    }
};
