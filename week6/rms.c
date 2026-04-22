#include <stdio.h>
#include <math.h>
struct tasks{
    int pid,ci,ti,remaining,next_arrival;
};
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int tasks_lcm(struct tasks t[],int n){
    int result=t[0].ti;
    for(int i=0;i<n;i++){
        result=lcm(result,t[i].ti);
    }
    return result;
}

int main(){
    int n;
    printf("Enter no. of tasks:");
    scanf("%d",&n);
    struct tasks t[n];
    for(int i=0;i<n;i++){
        printf("Task %d\n",i+1);
        printf("Ci:");
        scanf("%d",&t[i].ci);
        printf("Ti:");
        scanf("%d",&t[i].ti);
        t[i].pid=i+1;
        t[i].remaining=0;
        t[i].next_arrival=0;
    }
    float u=0;
    for(int i=0;i<n;i++){
        u+=(float)t[i].ci/t[i].ti;
    }
    printf("CPU Utilization:%f\n",u);
    float bound=n*(pow(2,(float)1/n)-1);
    printf("Bound:%f\n",bound);
    if(u<=bound){
        printf("Schedulable using RMS.\n");
    }
    else{
        printf("Not schedulable using RMS.\n");
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(t[i].ti>t[j].ti){
                struct tasks temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
    int limit=tasks_lcm(t,n);
    printf("\nTimeline:\n");
    for(int tim=0;tim<limit;tim++){
        for(int i=0;i<n;i++){
            if(tim==t[i].next_arrival){
                t[i].remaining=t[i].ci;
                t[i].next_arrival+=t[i].ti;
            }
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(t[i].remaining>0){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            printf("Time %d:Task %d\n",tim,t[idx].pid);
            t[idx].remaining--;
        }
        else{
            printf("Time %d:Idle\n",tim);
        }
    }
    return 0;
}
