#include <stdio.h>
struct process{
    int pid,ci,ti,di,remaining,next_arrival,absolute_deadline;
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
int find_lcm(struct process p[],int n){
    int result=p[0].ti;
    for(int i=1;i<n;i++){
        result=lcm(result,p[i].ti);
    }
    return result;
}
int main(){
    int n;
    printf("Enter no. of tasks:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Process %d\n",i+1);
        printf("Ci:");
        scanf("%d",&p[i].ci);
        printf("Ti:");
        scanf("%d",&p[i].ti);
        p[i].pid=i+1;
        p[i].di=p[i].ti-1;
        p[i].remaining=0;
        p[i].next_arrival=0;
        p[i].absolute_deadline=p[i].di;
    }
    float u=0;
    for(int i=0;i<n;i++){
        u+=(float)p[i].ci/p[i].ti;
    }
    printf("CPU Utilization:%f\n",u);
    if(u<1){
        printf("Schedulable\n");
    }
    else{
        printf("Not schedulable\n");
    }
    int limit=find_lcm(p,n);
    printf("\nTimeline:\n");
}
