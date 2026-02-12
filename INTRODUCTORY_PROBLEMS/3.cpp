#include<bits/stdc++.h>
using namespace std;
int i = 0;

int main(){
    string input;

    // map<int, int> mp;
    // while(cin >> input){
    //     if(input == "#"){
    //         int size = mp.size();
    //         if(size % 2){
    //             auto it = mp.begin();
    //             int middleIndex = size / 2;
                
                
    //             if(it != mp.end()){
    //                 cout<<it -> first<<endl;
    //                 mp.erase(it -> first);
    //             }
                
    //         }
    //         else if(size % 2 == 0){
    //             auto it = mp.begin();
    //             int middleIndex = size / 2;

                
    //             if(it != mp.end()){
    //                 cout<<it -> first<<endl;
    //                 mp.erase(it -> first);
    //             }
                
    //         }
    //     }else if(input != "#"){
    //         int temp = stoi(input);
    //         mp[temp]++;
    //     }
    // }

    int arr[5]  = {1, 2, 3,4 , 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    // cout<<arr[middle]<<endl;
    cout<<arr[size / 2]<<endl;
}

