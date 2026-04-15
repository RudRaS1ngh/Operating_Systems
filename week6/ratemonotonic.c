#include <stdio.h>
#include <math.h>
void take(int a[], int n){
    for(int i=0;i<n;i++){
        printf("Enter value for process %d: ",i);
        scanf("%d",&a[i]);
    }
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int arr[], int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans))/(gcd(arr[i], ans)));
    return ans;
}


void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int c[n],t[n],prio[n],pid[n],rem_cap[n];
    printf("Enter process ID:\n");
    take(pid,n);
    printf("Enter capacity:\n");
    take(c,n);
    printf("Enter time period:\n");
    take(t,n);

    double u=0;
    double bound=n*(pow(2,(double)(1/n))-1);
    for(int i=0;i<n;i++){
        u+=(double)c[i]/t[i];
    }
    if(u<=bound){
        printf("Schedulable using RMS.\n");
    }
    else{
        printf("Utilization not within bound ");
        if(u<=1){
            printf("but less than 1.RMS can be used.\n");
        }
        else{
            printf("and not less than 1.RMS can't be used.\n");
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(t[j]<t[i]){
                int temp=t[i];
                t[i]=t[j];
                t[j]=temp;

                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        prio[i]=pid[i];
        rem_cap[i]=c[i];
    }
    int stopper=0;
    for(int i=0;i<n;i++){
        stopper+=(lcm(t,n)/t[i])*c[i];
    }
    int j=0;
    int timeline[lcm(t,n)];
    for(int i=0;i<lcm(t,n);i++){
        for(int k=0;k<n;k++){
            if(i%t[k]==0){
                rem_cap[k]=c[k];
                j=0;
            }
        }
        while(rem_cap[j]==0){
            j++;
        }
        if(j>=n){
            j=0;
        }
        timeline[i]=j;
        rem_cap[j]--;
        if(i==stopper){
            break;
        }
    }
    printf("Timeline:\n");
    for(int i=0;i<stopper;i++){
        printf("%d ",timeline[i]);
    }
}
