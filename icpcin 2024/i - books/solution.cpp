#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    cin >> t;

    vector<int> books;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        books.push_back(a);

    }

    int max_size = 0;
    int sum = 0;
    int p1, p2;
    
    p1 = 0; 
    p2 = 0;

    while ((p1 < n)){
        sum += books[p1];
        if(sum <= t){
            if(max_size <= (1 + p1 - p2)){
                max_size = 1 + p1 - p2;
            }
            p1++;
        }
        else{
            sum -= books[p2] + books[p1];
            p2++;
        }
    }
    cout << max_size;
}

