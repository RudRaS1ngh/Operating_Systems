#include <stdio.h>

void main(){
    int arr[10],a;
    for(int i=0;i<10;i++){
        printf("Enter value of %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
                a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
    }
    printf("Second smallest element is %d",arr[1]);
}