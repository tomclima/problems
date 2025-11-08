#include <bits/stdc++.h>


int main(){

    // comparator for derecreasing order
    auto dec = [](auto &a, auto &b){
        return a > b;
    };

    // comparators for pairs
    auto f = [](auto &a, auto &b){ // compare the first
        return a.first < b.first;
    };
    auto s = [](auto &a, auto &b){ // compare the second
        return a.second < b.second;
    };

    

}