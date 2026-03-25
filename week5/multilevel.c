#include <stdio.h>
void take(int a[], int n){
    for(int i=0;i<n;i++){
        printf("Enter value for process %d: ",i);
        scanf("%d",&a[i]);
    }
}
void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int pid[n], at[n], bt[n], type[n];
    int ct[n], tat[n], wt[n];
    printf("Enter PID:\n");
    take(pid,n);
    printf("Enter Arrival Time:\n");
    take(at,n);
    printf("Enter Burst Time:\n");
    take(bt,n);
    printf("Enter Type (0=System, 1=User):\n");
    take(type,n);
    int sys_q[100], user_q[100];
    int s_front=0, s_rear=0;
    int u_front=0, u_rear=0;
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    int time = 0, completed = 0;
    for(int i=0;i<n;i++){
        if(at[i] <= time){
            if(type[i]==0)
                sys_q[s_rear++] = i;
            else
                user_q[u_rear++] = i;
            visited[i]=1;
        }
    }
    float avg_tat=0, avg_wt=0;
    printf("\nExecution Order:\n");
    while(s_front < s_rear){
        int i = sys_q[s_front++];
        if(time < at[i])
            time = at[i];
        printf("PID:%d ", pid[i]);
        time += bt[i];
        ct[i] = time;
        completed++;

        for(int j=0;j<n;j++){
            if(at[j] <= time && visited[j]==0){
                if(type[j]==0)
                    sys_q[s_rear++] = j;
                else
                    user_q[u_rear++] = j;
                visited[j]=1;
            }
        }
    }
    while(u_front < u_rear){
        int i = user_q[u_front++];

        if(time < at[i])
            time = at[i];
        printf("PID:%d ", pid[i]);
        time += bt[i];
        ct[i] = time;
        completed++;
        for(int j=0;j<n;j++){
            if(at[j] <= time && visited[j]==0){
                if(type[j]==0)
                    sys_q[s_rear++] = j;
                else
                    user_q[u_rear++] = j;
                visited[j]=1;
            }
        }
    }
    printf("\n\nPID\t AT\t BT\t TYPE\t CT\t TAT\t WT\t\n");
    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t\n",pid[i], at[i], bt[i], type[i],ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT = %f", avg_tat/n);
    printf("\nAverage WT = %f\n", avg_wt/n);
}
