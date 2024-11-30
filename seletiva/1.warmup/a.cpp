#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        long long int n;
        long double d, h;
        cin >> n >> d >> h;
        long double cotan = d/(2 * h);

        vector<long double> heights;
        for(int i = 0; i<n; i++){
            long double y;
            cin >> y;
            heights.push_back(y);
        }

        heights.push_back(heights.back() + 2*h); // garantir que não há nada acima da ultima branch
        
        long double sum = 0;
        for(int i = 0; i < n; i++){

            int j = i + 1;
            long double base_menor = 0;
            long double altura = h;

            if(heights[i] + h > heights[j]){
                altura = (heights[j] - heights[i]);
                base_menor = 2*(d/2 -  cotan * altura);

            }
            
            long double area = (base_menor * altura)/2 + (d * altura)/2;
            sum += area;
        }

        cout << fixed << sum << setprecision(9) << endl;
    }
}