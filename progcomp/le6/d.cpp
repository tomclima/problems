/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define vec vector<long double> 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long double a, b, c;

    while(cin >> a >> b >> c){
    
        long double s = (a + b + c)/2;

        long double a_triangle = sqrt(s*(s-a) * (s-b) * (s - c));

        long double r_incentro = a_triangle/s;
        long double a_incentro = 4 * atan(1) * r_incentro * r_incentro;

        long double a_violets = a_triangle - a_incentro;

        long double R_circuncentro = (a * b * c)/(4 * a_triangle);
        long double a_circuncentro = 4 * atan(1) * R_circuncentro * R_circuncentro;


        cout << fixed << setprecision(4) << a_circuncentro - a_triangle << " " << a_violets << " " << a_incentro << endl; 
    }




}