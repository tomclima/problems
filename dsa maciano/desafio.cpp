#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long char
#define DELETED 0

int comps = 0;
int subs = 0;
int iters = 0;


vector<char> generate_even(vector<char> &vec, vector<char> newvec){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] % 2 == 0){
            newvec.push_back(vec[i]);
            vec[i] = DELETED;
        }
    }
}


vector<char> print_vector(vector<char> old_vec, vector<char> even_vec){
    char j = 0;
    for(int i = 0; i < old_vec.size(); i++){
        if(old_vec[i] == DELETED){
            cout << even_vec[j] << " ";
            j++;
        }
        else{
            cout << old_vec[i] << " ";
        }
    }
}


void swap(vector<char> vec, int a, int b){
    if(a >= 0 and b >= 0 and a < vec.size() and b < vec.size()){
        char temp = vec[a];
        a = vec[b];
        b = temp;
    }
}


void bubblesort_helper(vector<char> &evenvec, vector<char> &oldvec, char size){
    print_vector(oldvec, evenvec); //print do vetor semi ordenado
    iters++; //iter counter
    if(size <= 1){
        return;
    }
    for(int i = 0; i < size -1; i++){
        if(evenvec[i] > evenvec[i+1]){
            swap(evenvec, i, i+1);
            subs++; // sub counter
        }
        comps++; // comps counter
    }

    bubblesort_helper(evenvec, oldvec, size-1);
}


void bubblesort(vector<char> &vec){ //invólucro para a função recursiva bubblesort_helper

    vector<char> even_vec;
    generate_even(vec, even_vec);
    char size = even_vec.size();
    bubblesort_helper(even_vec, vec, size-1);
    
    cout << "vetor ordenado: ";
    print_vector(vec, even_vec);
    cout << endl;
    cout << "iterações: " << iters << endl;
    cout << "comparações: " << comps << endl;
    cout << "substuições: " << subs << endl;
    iters = 0;
    comps = 0;
    subs = 0;
}


void selection_sort(vector<char> vec, int n){
    vector<char> evenvec;
    generate_even(vec, evenvec);
    for(int i = 0; i < evenvec.size()-1; i++){
        int min = i;
        for(int j = i+1; j < n-1; j++){
            if(evenvec[j] < evenvec[min]){
                min = j;
                comps++;
            }
        }
        swap(evenvec, i, min);
        subs++;
        iters++;
        print_vector(vec, evenvec);
    }   

}

void copy_from_str(vector<char> vec, string str){
    for(int i = 0; i < str.size(); i++){
        vec.push_back(str[i]);
    }
}

char main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a = "RMQFPWZYKASIOHBJLVU";
    vector<char> vec;
    copy_from_str(vec, a);
    bubblesort(vec);
    vec.resize(0);   
}