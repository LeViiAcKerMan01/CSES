#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){

    
}
int main(){
    int t;
    cin >> t;

    vector<ll> powerOfTen(19, 1);
    
    // better than pow function
    for(int i = 1; i < 19; i++){
        powerOfTen[i] = powerOfTen[i-1] * 10; 
    }
    
    while(t--){
        ll index;
        cin >> index;
        ll digitsSoFar = 0;
        ll digitsBeforeActualBlock = 0;
        int numberOfDigits;
        for(int i = 1; i <= 18; i++){
            
            digitsSoFar += (powerOfTen[i] - powerOfTen[i-1]) * i;
            if(digitsSoFar >= index){

                numberOfDigits = i;
                break;
            }
            digitsBeforeActualBlock += (powerOfTen[i] - powerOfTen[i-1]) * i;
        }

        // proceed to binary search
        // once you know the numberOfdigits and current block

        ll smallestValue = powerOfTen[numberOfDigits - 1];
        ll largestValue = powerOfTen[numberOfDigits] - 1;
        ll bestValue = 0;
        ll startingPositionOfBestValue;

        while(smallestValue <= largestValue){
            
            ll actualValue = (smallestValue + largestValue) / 2;
            ll startingPositionOfActualValue = digitsBeforeActualBlock + 1 + (actualValue - powerOfTen[numberOfDigits-1]) * numberOfDigits;

            if(startingPositionOfActualValue <= index){
                
                if(actualValue > bestValue){
                    bestValue = actualValue;
                    startingPositionOfBestValue = startingPositionOfActualValue;
                }
                smallestValue = actualValue + 1;
            }
            else{
                largestValue = actualValue - 1;
            }
        }

        string number = to_string(bestValue);
        cout<<number[index - startingPositionOfBestValue]<<'\n';
    }
}