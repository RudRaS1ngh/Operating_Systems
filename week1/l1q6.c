#include <stdio.h>

void main(){
    int arr[10],pos;
    for(int i=0;i<10;i++){
        printf("Enter value of %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter position to delete:");
    scanf("%d",&pos);
    for(int i=pos;i<10;i++){
        arr[i-1]=arr[i];
    }
    printf("New array:\n");
    for(int i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
}