#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,flag ;
    scanf("%d",&n);
    vector < pair<int,int> > vec ;
    vector <int> path;
    for ( int i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        if ( a % 2 == 0) flag = 0;
        else flag = 1 ;
        vec.push_back(make_pair(a,flag));
    }


    vector <int> arr(n,1);

    for ( int i = 1 ; i < n ; i++) {
        for ( int j = 0 ; j < i ; j++) {
            if ( vec[i].first > vec[j].first && arr[i] < arr[j]+1 && (vec[i].second+vec[j].second == 1) ) {
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
    //cout << "maximum " << vec[index].first << endl;
    cout << "Length of LIS(ALTERNATIVE): " << maximum << endl;
    int last = !(vec[index].second);
    int value = vec[index].first+1;
    //cout << "LAST : " << last << endl;
    for ( int i = n-1 ; i >= 0 ; i--) {
        if ( maximum == arr[i] && vec[i].second+last == 1 && vec[i].first < value) {
            path.push_back(vec[i].first);
            last = vec[i].second;
            value = vec[i].first;
            maximum--;
        }
        if ( maximum == 0 ) break ;
    }

    //for ( int i =  0 ; i < vec.size() ; i++) cout << vec[i].first << " " << vec[i].second << " " << arr[i] << endl;
    reverse(path.begin(),path.end());
    cout << "THE LIS ALTERNATIVE PATH IS: " ;
    for ( int i = 0 ; i < path.size() ; i++) cout << path[i] << " ";
    cout << endl;

    return 0 ;
}
