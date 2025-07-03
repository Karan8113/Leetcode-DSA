class Solution {
public:
    char kthCharacter(int k) {
        string temp="a";
        int powr=0;
        int i=0;
        while(temp.size()<k){
            if(temp.size()==pow(2,powr)){
                i=0;
                powr++;
            }
            else{
                char ch;
                temp[i]=='z'?ch='a':ch = char(int(temp[i])+1);
            
                temp.push_back(ch);
                i++;
            }
        }
        return temp[temp.size()-1];
        
    }
};