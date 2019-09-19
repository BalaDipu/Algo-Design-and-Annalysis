#include<bits/stdc++.h>
using namespace std;
int main(){
    int coins[]={2,3};
    int value=5;

int mat[2][5];
for(int i=0;i<2;i++){
    for(int j=0;j<5;j++){
        mat[i][j]=INT_MAX;//1e9;
    }
}
mat[0][0]=0;
mat[1][0]=0;
for(int i=0;i<2;i++){
    for(int j=0;j<value+1;j++){
        if(j-coins[i]<0&&i>0){
            mat[i][j]=mat[i-1][j];
        }
        else{
            mat[i][j]=min(mat[i-1][j],mat[i][j-coins[i]]+1);
        }
    }

}
cout<<mat[2][5]<<endl;


}
