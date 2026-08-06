class Solution {
public:
    void fun(string &s, int n, int idx, string  &dairy, vector<string> &res){
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        if(idx == n){
            res.push_back(dairy);
            return;
        }
        string choice = f[s[idx]];
        for(int i=0;i<choice.size();i++){
            dairy.push_back(choice[i]);
            fun(s, n, idx+1, dairy, res);
            dairy.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        int idx = 0;
        string dairy = "";
        vector<string> res;

        fun(digits, n, idx, dairy, res);
        return res;
    }
};