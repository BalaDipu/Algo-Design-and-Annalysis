#include <bits/stdc++.h>
using namespace std;
#define sz 1000
int main() {
    int n,a ;
    scanf("%d",&n);
    vector <int> numbers;
    vector <int> dp(n,1);
    vector <int> copydp;
    vector <int> path;
    vector <int> allpath(sz);
    for ( int i = 0 ; i < n ; i++) {
        scanf("%d",&a);
        numbers.push_back(a);
    }
    for ( int i = 1 ; i < n ; i++) {
        for ( int j = 0 ; j < i ; j++) {
            if ( numbers[i] > numbers[j] && dp[i] < dp[j]+1) { /*for LNDS in place of numbers[i] > number[j]
                                                                there will be numbers[i] >= numbers[j]; */
                dp[i] = dp[j]+1;
            }
        }
    }
    copydp = dp ;
    sort(dp.begin(),dp.end(),greater<int>());
    printf("The LIS is: %d\n",dp[0]);
    int value = dp[0];
    for ( int i = dp.size()-1 ; i >= 0 ; i-- ) {
        if ( copydp[i] == value) {
            path.push_back(numbers[i]);
            value-- ;
        }
    }
    reverse(path.begin(),path.end());
    printf("So the LIS path is: ");
    for ( int i = 0 ; i < path.size() ; i++) cout << path[i] << " ";
    cout << endl;

    return 0 ;
}
