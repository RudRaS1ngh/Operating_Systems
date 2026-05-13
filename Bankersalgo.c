#include <stdio.h>

#define MAX_P 10
#define MAX_R 10

int num, res;

int safety(int num,
           int finish[],
           int work[],
           int alloc[MAX_P][MAX_R],
           int need[MAX_P][MAX_R],
           int safeSequence[])
{
    int count = 0;

    while(count < num)
    {
        int found = 0;

        for(int p = 0; p < num; p++)
        {
            if(finish[p] == 0)
            {
                int j;

                for(j = 0; j < res; j++)
                {
                    if(need[p][j] > work[j])
                        break;
                }
                if(j == res)
                {
                    for(int k = 0; k < res; k++)
                    {
                        work[k] += alloc[p][k];
                    }

                    safeSequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state.\n");

    printf("Safe Sequence: ");
    for(int i = 0; i < num; i++)
    {
        printf("P%d ", safeSequence[i]);
    }

    printf("\n");

    return 1;
}

int main()
{
    printf("Enter number of processes: ");
    scanf("%d", &num);

    printf("Enter number of resources: ");
    scanf("%d", &res);

    int instances[MAX_R];
    int avail[MAX_R];
    int work[MAX_R];

    int finish[MAX_P];
    int safeSequence[MAX_P];

    int alloc[MAX_P][MAX_R];
    int max[MAX_P][MAX_R];
    int need[MAX_P][MAX_R];

    printf("Enter total instances of resources:\n");

    for(int i = 0; i < res; i++)
    {
        scanf("%d", &instances[i]);
        avail[i] = instances[i];
    }

    for(int i = 0; i < num; i++)
    {
        finish[i] = 0;

        printf("\nProcess P%d\n", i);

        printf("Enter allocated resources: ");
        for(int j = 0; j < res; j++)
        {
            scanf("%d", &alloc[i][j]);

            avail[j] -= alloc[i][j];
        }

        printf("Enter maximum resources needed: ");
        for(int j = 0; j < res; j++)
        {
            scanf("%d", &max[i][j]);

            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int i = 0; i < res; i++)
    {
        work[i] = avail[i];
    }

    int safe = safety(num, finish, work, alloc, need, safeSequence);

    if(!safe)
        return 0;

    int req;
    int extra[MAX_R];

    printf("\nEnter process requesting resources: ");
    scanf("%d", &req);

    printf("Enter requested resources: ");

    for(int j = 0; j < res; j++)
    {
        scanf("%d", &extra[j]);
    }
    for(int j = 0; j < res; j++)
    {
        if(extra[j] > need[req][j])
        {
            printf("\nError: Request exceeds process need.\n");
            return 0;
        }
    }
    for(int j = 0; j < res; j++)
    {
        if(extra[j] > avail[j])
        {
            printf("\nResources not available.\n");
            return 0;
        }
    }

    for(int j = 0; j < res; j++)
    {
        avail[j] -= extra[j];
        alloc[req][j] += extra[j];
        need[req][j] -= extra[j];
    }

    for(int i = 0; i < num; i++)
    {
        finish[i] = 0;
    }

    for(int i = 0; i < res; i++)
    {
        work[i] = avail[i];
    }
    safe= safety(num, finish, work, alloc, need, safeSequence);

    if(safe)
    {
        printf("\nRequest can be granted safely.\n");
    }
    else
    {
        printf("\nRequest cannot be granted.\n");
        for(int j = 0; j < res; j++)
        {
            avail[j] += extra[j];
            alloc[req][j] -= extra[j];
            need[req][j] += extra[j];
        }
    }

    return 0;
}
