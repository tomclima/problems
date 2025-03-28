#include <iostream>
#include <cstring>
using namespace std;


int max(int a, int b){
    if(a < b) return b;
    else return a;
}

int fun_factor(int index, int t, int base_fun[], int base_boredom[]){
    

    return base_fun[index] - (t-1)*(t-1)*base_boredom[index];
}

int main(){

    int n;
    cin >> n;

    int base_fun[n+1];
    int base_boredom[n+1];
    int c[n+1];
    
    // 1 based for dp table coherence
    for(int i = 1; i <= n; i++){
        
        cin >> base_fun[i] >> base_boredom[i] >> c[i]; 
    }

    int k;
    cin >> k;

    for(int tc = 0; tc < k; tc++){
        
        int credits;
        cin >> credits;

        int **dp = new int*[n + 1];
        int **times_taken = new int*[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new int[credits + 1];
            times_taken[i] = new int[credits + 1];
            memset(times_taken[i], 0, sizeof(times_taken[i]));
        }
        

        

        // base case dp[0][j] for all == 0;
        for(int j = 0; j <= credits; j++){
            dp[0][j] = 0;
        }
        // base case dp[i][0] for all == 0;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        // dp[i][0] and dp[0][j] are already defined, so start from 1
        // recursive relation: dp[i][j] = max(dp[i-1][j], dp[i][j - c[i]] + fun_factor(i), 0)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= credits; j++){
                
                if(j == 6038){
                    cout << "";
                }
                if(j == 2 *6038){
                    cout << "";
                }
                
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                times_taken[i][j] = times_taken[i][j-1];

                if(j - c[i] >= 0){
                    
                    int toy_fun = dp[i][j-c[i]] + fun_factor(i, times_taken[i][j - c[i]] +1, base_fun, base_boredom);
                    if(toy_fun > dp[i][j]){
                        times_taken[i][j] = times_taken[i][j - c[i]] + 1;
                        dp[i][j] = toy_fun;
                    }
                } 
              
                
            }
        }

        cout << tc << ": " << dp[n][credits] << endl;

        

        for(int i = 0; i <= n; i++) delete[] dp[i];
        delete[] dp;
        
    }
}