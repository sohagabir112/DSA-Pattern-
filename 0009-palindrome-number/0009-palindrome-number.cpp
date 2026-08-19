class Solution {
public:
    bool isPalindrome(int x) {
        int og = x;
        long long  num = 0;
        if(x<0){
            return false;
        }
        while(x>0){
            int digit = x % 10;
            num = num*10 + digit;
            x/=10;
        }
        if(og == num){
            return true;
        }
        else{
            return false;
        }
    }
};