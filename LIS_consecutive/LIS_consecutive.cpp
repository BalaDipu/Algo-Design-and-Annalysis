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
 
    vector <int> arr(n,1);
 
    for ( int i = 1 ; i < n ; i++) {
        for ( int j = 0 ; j < i ; j++) {
            if ( vec[i] == vec[j]+1 && arr[i] < arr[j]+1  ) {
                arr[i] = arr[j]+1 ;
            }
        }
    }
    int maximum = 0 ;
    int index ;
    for ( int i = 0 ; i < n ; i++) {
        if ( arr[i] > maximum) {
                maximum = arr[i];
                index = i ;
        }
    }
    cout << "Length of LIS(CONSECUTIVE): " << maximum << endl;
    int last = vec[index]+1;
    for ( int i = n-1 ; i >= 0 ; i--) {
        if ( maximum == arr[i] && vec[i] == last-1 ) {
            path.push_back(vec[i]);
            last = vec[i];
            maximum--;
        }
        if ( maximum == 0 ) break ;
    }
    reverse(path.begin(),path.end());
    cout << "THE LIS CONSECUTIVE PATH IS: " ;
    for ( int i = 0 ; i < path.size() ; i++) cout << path[i] << " ";
    cout << endl;
 
    return 0 ;
}
