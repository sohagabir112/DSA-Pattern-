class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(char c : s){
            if(isalnum(c)){
                res += tolower(c);
            }
        }
        int n = res.size();
        int i = 0, j = n-1;
        while(i<j){
            if(res[i] == res[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};