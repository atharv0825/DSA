#include<bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
        
        for(int i =0 ;i<10000;i++){
                x1 += v1;
                x2 += v2;
                
                if(x1 == x2){
                        return "YES";
                }        
        }
        return "NO";
}


int main() {
    int x1, v1, x2, v2;

    cout << "Enter the starting position and velocity of the first kangaroo (x1 v1): ";
    cin >> x1 >> v1;

    cout << "Enter the starting position and velocity of the second kangaroo (x2 v2): ";
    cin >> x2 >> v2;

    string result = kangaroo(x1, v1, x2, v2);

    cout << "Do the kangaroos meet? " << result << endl;

    return 0;
}