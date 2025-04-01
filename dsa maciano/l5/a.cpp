#include <iostream>
#include <cstring>
using namespace std;


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

int max_fun(int credits, int times_taken[], Toy *toys[], int number_toys, int dp[]){

    if(dp[credits] >= 0) return dp[credits];

    dp[credits] = 0;

    for(int i = 1; i < number_toys + 1; i++){
        
        if(credits >= toys[i]->cost){
            
            int *newvec = new int[number_toys + 1];
            copy(times_taken, times_taken + number_toys + 1, newvec);
            
            newvec[i]++;

            dp[credits] = max(dp[credits], fun_factor(toys[i], newvec[i]) + max_fun(credits - toys[i]->cost, newvec, toys, number_toys, dp));
            delete[] newvec;
        }
    }

    return dp[credits];
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

    for(int tc = 0; tc < k; tc++){
        
        int credits;
        cin >> credits;

        int times_taken[n + 1];
        int dynamic[credits+1];

        for(int i = 0; i < credits + 1; i++){
            dynamic[i] = -999999;
        }

        for(int i = 0; i < n +1; i++){
            times_taken[i] = 0;
        }

        


        cout << tc << ": " << max_fun(credits, times_taken, toys, n, dynamic) << endl;

        

        
    }
}