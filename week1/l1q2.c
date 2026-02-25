#include <stdio.h>

void main(){
    int r,c;
    printf("Enter number of rows:");
    scanf("%d",&r);
    printf("Enter number of columns:");
    scanf("%d",&c);

    int mtx[r][c],sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter %d %d:",i,j);
            scanf("%d",&mtx[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j){
                sum+=mtx[i][j];
            }
        }
    }
    printf("Sum=%d",sum);
}