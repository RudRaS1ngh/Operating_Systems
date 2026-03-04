#include <stdio.h>

void main(){
    int n,a,tct=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    for(int i=0;i<n;i++){
        printf("Enter PID:");
        scanf("%d",&pid[i]);
        printf("Enter AT:");
        scanf("%d",&at[i]);
        printf("Enter BT:");
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                a=at[i];
                at[i]=at[j];
                at[j]=a;

                a=bt[i];
                bt[i]=bt[j];
                bt[j]=a;

                a=pid[i];
                pid[i]=pid[j];
                pid[j]=a;
            }
        }
    }
    for(int i=0;i<n;i++){
        tct+=bt[i];
        ct[i]=tct;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        rt[i]=wt[i];
    }
    for(int i=0;i<n;i++){
        printf("PID:%d ",pid[i]);
        printf("AT:%d ",at[i]);
        printf("BT:%d ",bt[i]);
        printf("CT:%d ",ct[i]);
        printf("TAT:%d ",tat[i]);
        printf("WT:%d ",wt[i]);
        printf("RT:%d \n",rt[i]);
    }

}
