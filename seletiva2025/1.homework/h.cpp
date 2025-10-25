#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define heap priority_queue

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c; 
    cin >> c;
    for(int k = 0; k < c; k++){
        lng l, m;
        cin >> l >> m;
        l*=100;
        vector<lng> left;
        vector<lng> right;
        for(int i = 0; i < m; i++){
            lng len;
            string side;
            cin >> len >> side;
            if(side == "left"){
                left.push_back(len);
            }
            else{
                right.push_back(len);
            }
        }      
        int cl = 0;
        int cr = 0;
        int cross = 0;
        char is_left = 1;
        bool is_first = true;
        while(cl < left.size() or cr < right.size()){
            int bestl = 0;
            int bestr = 0;
            int suml = 0;
            int sumr = 0;
            for(int i = cl; i < left.size()+1; i++){
                bestl = i - cl;
                if(i < left.size()){
                    suml += left[i];
                }
                if(suml > l){
                    i = left.size();
                }
            }
            for(int i = cr; i < right.size() + 1; i++){
                bestr = i - cr;
                if(i < right.size()){
                    sumr += right[i];
                }
                if(sumr > l){
                    i = right.size();
                }
            }
            if(is_left){
                cl += bestl;
                cross++;
                is_left = !is_left;
            }
            else{
                cr += bestr;
                cross++;
                is_left = !is_left;
            }
        }
        cout << cross << endl;
    }
}