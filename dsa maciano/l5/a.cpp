#include <iostream>
#include <cstring>
using namespace std;
#define INF 9999999
#define MAX_CREDITS 25000
#define MAX_usages 14

typedef struct Toy{
    
    int base_fun;
    int base_boredom;
    int cost; 
} Toy;

Toy *create_toy(int fun, int boredom, int cost){

    Toy *newtoy = new Toy;
    newtoy->base_fun = fun;
    newtoy->base_boredom = boredom;
    newtoy->cost = cost;

    return newtoy;
}

int max(int a, int b){
    if(a < b) return b;
    else return a;
}

int fun_factor(Toy *toy, int t){
    

    return toy->base_fun - (t-1)*(t-1)*toy->base_boredom;
}

int max_fun(int i, int credits, int times_taken[], Toy *toys[], int number_toys, int*** dp){

    if(dp[i][credits][times_taken[i]] >= 0) return dp[i][credits][times_taken[i]];
    if(i == 0) return 0;

    int not_pick = max_fun(i-1, credits, times_taken, toys, number_toys, dp);
    
    int *newvec = new int[number_toys + 1];
    copy(times_taken, times_taken + number_toys + 1, newvec);  
    newvec[i]++;
    
    int pick = 0;
    if(toys[i]->cost <= credits) pick = fun_factor(toys[i], newvec[i]) + max_fun(i, credits - toys[i]->cost, newvec, toys, number_toys, dp); 

    dp[i][credits][times_taken[i]] = max(pick, not_pick);

    return dp[i][credits][times_taken[i]];

}

int main(){

    int n;
    cin >> n;

    Toy **toys = new Toy*[n +1];
    toys[0] = create_toy(0, 0, 0);

    // 1 based for dp table coherence
    for(int i = 1; i < n +1 ; i++){
        
        int base_fun, base_boredom, cost;
        cin >> base_fun >> base_boredom >> cost;
        toys[i] = create_toy(base_fun, base_boredom, cost);
        
    }

    int k;
    cin >> k;

    int ***dp = new int**[n + 1];
    for(int i = 0; i < n + 1; i++){
        dp[i] = new int *[MAX_CREDITS + 1 ];
        for(int j = 0; j < MAX_CREDITS +1; j++){
            dp[i][j] = new int[MAX_usages + 1];
            for(int k = 0; k < MAX_usages + 1; k++){
                dp[i][j][k] = -INF;
            }
        }
    }

    for(int tc = 0; tc < k; tc++){
        
        int credits;
        cin >> credits;

        int times_taken[n + 1];

        for(int i = 0; i < n +1; i++){
            times_taken[i] = 0;
        }

        


        cout << tc << ": " << max_fun(n, credits, times_taken, toys, n, dp) << endl;

        

        
    }
}