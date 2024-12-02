#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define heap priority queue
#define lng long long

int binary_search(vector<int> &arr, int key){
    int left = 0; 
    int right = arr.size() -1;
    int answer = right +1;
    

    while (left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] <= key){
            left = mid + 1;
        }
        else{
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int m;
        cin >> m;
        
        int c = binary_search(s, m);

        cout << c << endl;
    }


}