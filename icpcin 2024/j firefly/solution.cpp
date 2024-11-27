#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int key){
    int left = 0; 
    int right = arr.size() -1;
    int answer;

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
            high.push_back(h - height + 1);
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

        high_col = binary_search(high, i);
        low_col = n/2 - binary_search(low, i);

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
