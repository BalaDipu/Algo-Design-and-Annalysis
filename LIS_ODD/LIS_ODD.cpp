#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a ;
    scanf("%d",&n);
    vector <int> vec ;
    vector <int> path;
    for ( int i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        vec.push_back(a);
    }

    //for ( int i =  0 ; i < vec.size() ; i++) cout << vec[i] << " ";

    vector <int> arr(n,0);
    for ( int i = 0 ; i < vec.size() ; i++) {
        if ( vec[i] % 2 != 0 ) arr[i] = 1 ;
    }

    for ( int i = 1 ; i < n ; i++) {
        for ( int j = 0 ; j < i ; j++) {
            if ( vec[i] > vec[j] && arr[i] < arr[j]+1 && vec[i] % 2 != 0 && vec[j] % 2 != 0 ) {
                arr[i] = arr[j]+1 ;
            }
        }
    }
    int maximum = 0 ;
    for ( int i = 0 ; i < n ; i++) {
        if ( arr[i] > maximum) maximum = arr[i];
    }
    cout << "Length of LIS(ODD): " << maximum << endl;
    for ( int i = n-1 ; i >= 0 ; i--) {
        if ( maximum == arr[i]) {
            path.push_back(vec[i]);
            maximum--;
        }
        if ( maximum == 0) break ;
    }
    reverse(path.begin(),path.end());
    cout << "THE LIS ODD PATH IS: " ;
    for ( int i = 0 ; i < path.size() ; i++) cout << path[i] << " ";
    cout << endl;

    return 0 ;
}
