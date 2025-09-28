class Solution {
public:
    int splitNum(int num) {
        string a=to_string(num);
        sort(a.begin(),a.end());
        string b,c;
        for(int i=0;i<a.length();i++){
            if(i%2==0){
                b+=a[i];
            }else{
                c+=a[i];
            }
        }
        return (stoi(b)+stoi(c));
    }
};