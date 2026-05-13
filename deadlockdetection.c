#include <stdio.h>

#define MAX_P 10
#define MAX_R 10

int main()
{
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[MAX_P][MAX_R];
    int request[MAX_P][MAX_R];

    int available[MAX_R];
    int work[MAX_R];

    int finish[MAX_P];

    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);

        work[i] = available[i];
    }

    /* Step 1: Initialize Finish[] */
    for(int i = 0; i < n; i++)
    {
        int zeroAllocation = 1;

        for(int j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                zeroAllocation = 0;
                break;
            }
        }

        if(zeroAllocation)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    int found;

    do
    {
        found = 0;

        for(int i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int j;

                /* Check Request[i] <= Work */
                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                        break;
                }

                /* Process can finish */
                if(j == m)
                {
                    printf("\nP%d can complete.", i);

                    for(int k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    /* Step 4: Detect Deadlock */
    int deadlock = 0;

    printf("\n\nDeadlocked Processes: ");

    for(int i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock)
    {
        printf("\n\nSystem is in DEADLOCK state.\n");
    }
    else
    {
        printf("\nNone");
        printf("\n\nSystem is NOT in deadlock.\n");
    }

    return 0;
}
