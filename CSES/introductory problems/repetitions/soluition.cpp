#include <bits/stdc++.h>
using namespace std;



int main(){
    string dna;
    cin >> dna;

    int max_repeat = 1;
    int current_repeat = 1;
    for(int i = 0; i < dna.size() - 1; i++){
        if(current_repeat > max_repeat){
            max_repeat = current_repeat;
        }
        if(dna[i] == dna[i+1]){
            current_repeat += 1;
        }
        else{
            current_repeat = 1;
        }
    }
    if(current_repeat > max_repeat){
            max_repeat = current_repeat;
        }

    cout << max_repeat;

}