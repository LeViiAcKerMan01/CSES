#include<bits/stdc++.h>
using namespace std;
void permutation(string s, string perm, map<string, int> &ans){
    if(s.size() == 0){
        ans[perm]++;
    }
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        string newString = s.substr(0, i) + s.substr(i+1);
        permutation(newString, perm+ch, ans);
    }
}
int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    map<string, int> ans;
    permutation(s, "", ans);

    cout<<ans.size()<<"\n";
    for(auto x : ans){
        cout<<x.first<<"\n";
    }
}