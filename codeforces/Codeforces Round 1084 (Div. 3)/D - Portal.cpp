/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
1
5 1 3
1 3 5 2 4

insight: se liberte do statement

*/

int solve(){
    int n, x, y; cin >> n >>  x >> y;
    vector<int> original_array(n);
    for(auto &i : original_array) cin >> i;

    vector<int> left, middle, right;

    
    for(int i = 0; i < x; i++){
        left.push_back(original_array[i]);
    }
    y--;
    int best_middle = 1000000;
    int best_middle_index = -1;
    for(int i = x; i <= y; i++){
        if(original_array[i] < best_middle){
            best_middle_index = i;
            best_middle = original_array[i];
        }
        middle.push_back(original_array[i]);
    }
    for(int i = y+1; i < n; i++){
        right.push_back(original_array[i]);
    }

    // get smallest rotation for the middle
    vector<int> new_middle;
    new_middle.push_back(best_middle);
    int middle_index = best_middle_index - x;
    int next_index = (middle_index + 1) % middle.size();
    while(next_index != middle_index){
        new_middle.push_back(middle[next_index]);
        next_index = (next_index + 1) % middle.size();
    }


    // get best left
    vector<int> new_left, right_prefix;

    int left_index_limit = -1;
    bool found_bigger = false;
    for(int i = 0; i < left.size(); i++){
        if(found_bigger){
            right_prefix.push_back(left[i]);
        }
        else if (left[i] < best_middle) {
            new_left.push_back(left[i]);
        }
        else{
            found_bigger = true;
            right_prefix.push_back(left[i]);
        }
    }
    
    int right_index  = 0;
    while(right_index < right.size() and right[right_index] < best_middle){
        right_index++;
    }
    right_index--;

    if(right_prefix.empty()){
        for(int i = 0; i<= right_index; i++){
            new_left.push_back(right[i]);
        }
    }
    else right_index = -1;
    

    vector<int> new_array;
    for(auto i : new_left) new_array.push_back(i);
    for(auto i : new_middle) new_array.push_back(i);
    for(auto i : right_prefix) new_array.push_back(i);
    for(int i = right_index + 1; i < right.size(); i++){
        new_array.push_back(right[i]);
    }

    for(auto i : new_array){
        cout << i << " ";
    }
    cout << endl;
    


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}