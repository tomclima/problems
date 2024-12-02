#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define heap priority queue
#define lng long long

lng int sum(int a0, int an){
    lng int first_term = (an + a0);
    lng int second_term = (an - a0 + 1);

    return(first_term * second_term)/2;
}

lng int binary_search_right(int first, int left, int right, int key){ // pass by reference for speed
    lng int mid;
    lng int answer = -1;

    while (left <= right){
        mid = left + (right - left)/2;

        if(first + sum(1, mid) <= key){
            left = mid + 1;
        }
        else{
            answer = mid;
            right = mid - 1;
        }
    }

    if(answer == -1){
        answer = left + (right - left)/2;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        lng int l, r;
        cin >> l >> r;

        lng int left = 1;
        lng int right = r - l;
        lng int cnt = binary_search_right(l, left, right, r);
        cout << cnt << endl;
    }
}