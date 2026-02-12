#include<bits/stdc++.h>
using namespace std;

bool is_possible(map<char, int> &ft, char cur){
    char mode = cur;
    int total_left_to_fill = 0;
    for(auto it : ft){
        // it.first -> character
        // it.second -> frequency

        if(it.second > ft[mode]){
            mode = it.first;
        }
        total_left_to_fill += it.second;
    }
    return (ft[mode] <= ((total_left_to_fill + 1) / 2) && ft[cur] <= (total_left_to_fill / 2));
}
int main(){
    string s;
    cin >> s;
    int n = s.length();
    
    // creating a frequency map
    map<char, int> ft;
    for(auto ch : s){
        ft[ch]++;
    }

    string ans = "";
    char last = '\0';

    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < 26; j++){
            char ch = 'A' + j;
            // if that character doesn't exist
            if(ft[ch] == 0 || ch == last) continue;
            
            ft[ch]--;
            if(is_possible(ft, ch)){
                ans.push_back(ch);
                last = ch;
                break;
            }else{
                ft[ch]++;
            }

            
        }
    }
    if(ans.length() == n){
        cout<<ans<<"\n";
    }else{
        cout<<"-1"<<endl;
    }
    // cout<<ans<<endl;

}