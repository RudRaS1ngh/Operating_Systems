#include <stdio.h>

void main(){
    int arr[10],checks[10],dup,m=0,q=0;
    for(int i=0;i<10;i++){
        printf("Enter value of %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<10;i++){
        for(int k=0;k<m;k++){
            if(checks[k]==arr[i]){
                q=1;
                break;
            }
        }
        if(q==1){
            q=0;
            continue;
        }
        checks[m++]=arr[i];
        for(int j=i+1;j<10;j++){
            if(arr[i]==arr[j]){
                dup+=1;
            }
        }
        printf("Number of duplicates of %d = %d\n",arr[i],dup);
        dup=0;
    }
}
