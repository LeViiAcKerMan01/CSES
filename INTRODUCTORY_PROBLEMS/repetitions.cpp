#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    // we are going to use two pointer technique
    int i = 0, j = 0;
    int tempSize = 0;
    int maxSize = 1;
    while(i <= j && j < n){
        if(s[i] == s[j]){
            j++;
            tempSize++;
            maxSize = max(maxSize, tempSize);
        }
        else{
            if(tempSize > 1){
                maxSize = max(maxSize, tempSize);
            }
            i = j;
            tempSize = 0;
        }
    }

    cout<<maxSize<<endl;
}