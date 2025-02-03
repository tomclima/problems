#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define MAX_ARRAY 1000000


typedef struct Trip{
    lng time;
    lng client;
    lng place;
};

int h(int x, int n){
    int result;
    for(int i = 0; i <= n; i++){
        result = (7 * x) % MAX_ARRAY;
    }
    return result;
}

int hash_insert(Trip **table, lng time, lng client){
    for(int i = 1; i < MAX_ARRAY; i++){
        int j = h(time, i);
        if(table[j] == NULL){
            Trip *trip = new Trip;
            trip->time = time;
            trip->client = client;
            table[j] = trip;
            return j;
        }
    }
}


int hash_search(Trip **table, lng time){
    int i = 1;
    int j = -1;
    do{
        j = h(time, i);
        if(table[j] and table[j]->time == time){
            return j;
        }

    }while(table[j] != NULL and i < MAX_ARRAY);
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Trip *table[MAX_ARRAY];
    
    
    string cmd = "";
    int insertions = 0;
    while(cmd != "END"){
        cin >> cmd;
        if(cmd == "NEW"){
            lng time, client;
            cin >> time >> client;
            int j = hash_insert(table, time, client);
            table[j]->place = insertions;
            insertions++;
        }
        else if(cmd == "QRY"){
            int time;
            cin >> time;
            int j = hash_search(table,time);
            if(j == -1){
                cout << "-1 -1" << endl;
            }
            else{
                cout << table[j]->client << " " <<  table[j]->place << endl;
            }
        }
    }
}