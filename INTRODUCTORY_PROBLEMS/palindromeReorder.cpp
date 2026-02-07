#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    unordered_map<char, int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }

    // check weather there are more then 1 characters with odd occurence
    int cnt = 0;
    for(auto it : mp){
        if(it.second % 2 != 0){
            cnt++;
        }
    }
    if(cnt > 1){
        cout<<"NO SOLUTION"<<endl;
    }else{
        
        string pal(n, '#');
        // cout<<pal<<endl;
        set<char> s;
        int j = 0;
        for(auto it : mp){
            int cnt2 = it.second;
            char ch = it.first;

            // cout<<ch<<" "<<cnt2<<endl;
            
            if(cnt2 % 2 == 0){
                s.insert(ch);
                int m = cnt2/2;
                // cout<<n<<endl;
                while(m--){
                    pal.at(j) = ch;
                    pal.at(n-1-j) = ch;
                    j++;
                }
            }
            
        }
        for(auto it : s){
            mp.erase(it);
        }


        if(mp.size() >= 1){
            auto it = mp.begin();
            char c = it -> first;
            while(pal[j] == '#'){
                pal[j] = c;
                j++;
            }
        }

        
        cout<<pal;
    }
}