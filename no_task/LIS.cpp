#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr1[]={10,22,9,11,33};

    int arr2[5];
    for(int i=0; i<5; i++)
        arr2[i] = 1;

    for(int i=1; i<5; i++){
        for(int j=0; j<i; j++){
            if(arr1[i] > arr1[j] && arr2[j]+1 > arr2[i] && arr1[i] == arr1[j]+1)
                arr2[i] = arr2[j]+1;
        }
    }

    int big = arr2[0], in;

    for(int i=1; i<5; i++){
        if(big < arr2[i]){
            big = arr2[i];
            in = i;
        }
    }

    int b = big;
    vector<int > vec;

//    int odd = 1;
//    if(arr1[in] % 2 == 0) odd = 0;

    vec.push_back(arr1[in]);
    int c = arr1[in];
    b--;

    for(int i=in-1; b>0; i--){
        if(arr2[i] == b && arr1[i]+1 == c){
            vec.push_back(arr1[i]);
            b--;
            c = arr1[i];
        }
    }

    for(int i=vec.size()-1; i>-1; i--)
        cout << vec[i]<<" ";

    cout <<endl<< "The lis is : "<<big;
}
