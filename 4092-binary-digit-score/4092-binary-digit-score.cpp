class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0;
        int s2 = 0;
        while(a>0){
            s1++;
            a = a & (a-1);
        }
        while(b>0){
            s2++;
            b = b & (b-1);
        }
        if(s1 >= s2){
            return s1*s2;
        }
        else{
            return s2/s1;
        }
    }
};