#include<bits/stdc++.h>
using namespace std;

void TOH1(int n, int src, int dst, int aux, int &cnt){
    if(n == 1){
        cnt++;
    }
    else{
        TOH1(n-1, src, aux, dst, cnt);
        cnt++;
        TOH1(n-1, aux, dst, src, cnt);
    }

}

void TOH2(int n, int src, int dst, int aux){
    if(n == 1){
        cout<<src<<" "<<dst<<"\n";
    }
    else{
        TOH2(n-1, src, aux, dst);
        cout<<src<<" "<<dst<<"\n";
        TOH2(n-1, aux, dst, src);
    }

}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    TOH1(n, 1, 2, 3, cnt);
    cout<<cnt<<endl;
    TOH2(n, 1, 3, 2);
}