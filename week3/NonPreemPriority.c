#include <stdio.h>

void take(int a[], int n){
    for(int i=0;i<n;i++){
        printf("Enter value for process %d: ",i);
        scanf("%d",&a[i]);
    }
}

int main(){
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n],prio[n],at[n],bt[n];
    int ct[n],tat[n],wt[n];
    int done[n];

    printf("Enter PID:\n");
    take(pid,n);

    printf("Enter Priority:\n");
    take(prio,n);

    printf("Enter Arrival Time:\n");
    take(at,n);

    printf("Enter Burst Time:\n");
    take(bt,n);

    for(int i=0;i<n;i++)
        done[i]=0;

    int completed=0;
    int time=0;

    while(completed<n){

        int x=-1;
        int bp=10;

        for(int i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(prio[i] < bp){
                    bp=prio[i];
                    x=i;
                }
            }
        }

        if(x==-1){
            time++;
            continue;
        }

        time += bt[x];
        ct[x]=time;

        done[x]=1;
        completed++;
    }

    printf("\nPID  PRIO  AT  BT  CT  TAT  WT\n");

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        printf("%d    %d    %d   %d   %d   %d   %d\n",
               pid[i],prio[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
