#include <stdio.h>

#define m 10
#define n 10
int num, res;

int safety(int num,int finish[],int work[],int alloc[m][res],int need[m][res],int safeSequence[]){
    int count=0;
    while(count<num) {
        int found=0;
        for(int p=0;p<num;p++){
            if(finish[p]==0){
                int j;
                for(j= 0;j<res;j++) {
                    if(need[p][j]>work[j])
                        break;
                }

                if(j==res) {
                    for(int k=0;k<res;k++)
                        work[k]+=alloc[p][k];

                    safeSequence[count++]=p;
                    finish[p]=1;
                    found=1;
                }
            }
        }

        if(found==0){
            printf("\nSystem is unsafe.");
            return 1;
        }
    }

    printf("\nSystem is in a SAFE state.\n");
    printf("Safe Sequence:");
    for(int i = 0; i < num; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &num);
    printf("Enter number of resources: ");
    scanf("%d", &res);

    int instances[res];
    int finish[n], safeSequence[n], work[res];
    int avail[res], need[m][res], max[m][res], alloc[m][res];

    printf("Enter total instances of the resources: ");
    for(int i = 0; i < res; i++) {
        scanf("%d", &instances[i]);
        avail[i] = instances[i];
    }

    for(int i = 0; i < num; i++) {
        finish[i] = 0;
        printf("Enter allocated resources for process %d: ", i);
        for (int j = 0; j < res; j++) {
            scanf("%d", &alloc[i][j]);
            avail[j] -= alloc[i][j];
        }
        printf("Enter maximum needed resources for process %d: ", i);
        for(int j = 0; j < res; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int i = 0; i < res; i++) {
        work[i] = avail[i];
    }

    safety(num,finish,work,alloc,need,safeSequence);

    int req;
    int extra[res];
    printf("Enter process requesting resources:");
    scanf("%d",&req);
    printf("Enter requested resources:");
    for(int j=0;j<res;j++){
        scanf("%d",&extra[j]);
        alloc[req][j]+=extra[j];
        need[req][j]-=extra[j];
    }
    for(int i=0;i<num;i++){
        avail[i]=0;
    }
    for(int i = 0; i < res; i++) {
        avail[i] = instances[i];
    }
    for(int i = 0; i < num; i++) {
        finish[i] = 0;
        for (int j = 0; j < res; j++) {
            avail[j] -= alloc[i][j];
        }
    }

    for(int i = 0; i < res; i++) {
        work[i] = avail[i];
    }
    safety(num,finish,work,alloc,need,safeSequence);
    return 0;
}
