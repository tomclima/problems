#include <bits/stdc++.h>

using namespace std;

int binary_search_right(vector<int> &arr, int key){ // pass by reference for speed
    int left = 0; 
    int right = arr.size() - 1;
    int mid;
    int answer = -1;

    while (left <= right){
        mid = left + (right - left)/2;

        if(arr[mid] <= key){
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
    int n, h;
    cin >> n >> h;
    vector<int> high, low;

    for(int i = 0; i < n; i++){
        int height;
        cin >> height;
        
        if(i % 2 == 0){
            low.push_back(height);
        }
        else{
            high.push_back(h - height);
        }
    }
    
    sort(low.begin(), low.end());
    sort(high.begin(), high.end()); 
    
    int best = n;
    int best_ammount;
    for(int i = 0; i < h; i++){
        int low_col;
        int high_col;
        int total_col;

        high_col = binary_search_right(high, i);
        low_col = n/2 - binary_search_right(low, i);

        total_col = low_col + high_col;

        if (total_col < best){
            best = total_col;
            best_ammount = 1;
        }
        else if(total_col == best){
            best_ammount++;
        }
    }

    cout << best << " " << best_ammount;

}
