#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;

        int sum = a + b;
        int threshold = sum / 3;
        if(sum % 3 == 0 && a >= threshold && b >= threshold){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}