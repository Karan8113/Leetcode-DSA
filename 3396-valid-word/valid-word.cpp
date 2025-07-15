class Solution {
public:


    bool isValid(string word) {
        if(word.length()<3)return false;
        bool vowel=false,consonent=false;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('u');
        st.insert('o');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('U');
        st.insert('O');
        for(int i=0;i<word.length();i++){
            if(!isalnum(word[i]))return false;
            if(st.count(word[i]))vowel=true;
            else if(isalpha(word[i]))consonent=true;
        }

        if(vowel && consonent)return true;
        return false;

    }
};