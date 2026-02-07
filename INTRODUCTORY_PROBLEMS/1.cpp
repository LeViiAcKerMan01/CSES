#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> arr(n, "");
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    
    int count = 0;
    cin >> count;

    while(count--){
        string temp;
        getline(cin, temp);

        if(temp[0] == 'c'){
            vector<string> name1;
            stringstream s1(temp);
            string tempo1;
            while(s1 >> tempo1){
                name1.push_back(tempo1);
            }
            int indexOfName = mp[name1[2]];
            arr.insert(arr.begin() + indexOfName, name1[1]);
        }else{
            vector<string> name2;
            stringstream s2(temp);
            string tempo2;
            while(s2 >> tempo2){
                name2.push_back(tempo2);
            }
            int indexOfName = mp[name2[1]];
            arr.erase(arr.begin() + indexOfName);
        }
    }

    for(auto it : arr){
        cout<<it<<" ";
    }

}