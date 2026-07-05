class Solution {
public:
    string toLowerCase(string s) {
        string t = s;
        for(int i = 0; i < s.length(); i++){
            t[i] = tolower(s[i]); 
        }
        return t;
    }
};