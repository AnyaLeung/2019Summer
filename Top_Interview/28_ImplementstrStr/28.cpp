class Solution {
public:
    int strStr(string haystack, string needle) {
        int lena = haystack.size();
        int lenb = needle.size();
        
        if(lenb==0){
            return 0;
        }
        if(lena==lenb){
            if(haystack==needle){
                return 0;
            }
        }
        for(int i=0; i<=lena-lenb; i++){
            cout << haystack.substr(i, lenb) << endl;
            if(haystack.substr(i, lenb)==needle){
                return i;
            }
        }
        return -1;
    }
};
