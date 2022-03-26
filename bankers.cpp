#include <stdio.h>

int n, m, i, j, k, alloc[10][10], max[10][10], avail[10], need[10][10], c, finished,
process;

// Defining Safety Function
void safety()
{
    process = 1; // While Loop Condition
    finished = 0;
    int l = n*n*m; //Limit for Safety Algorithm is n*n*m
    int x = 0;
    while ((process != 0) && (x < l))
    {
        x = x + 1;
        for (i = 0; i < n; i++)
        {
            // comparing need with available instance and checking
            // if the process is done or not.
            // counter if condition TRUE
            c = 0;
            for (j = 0; j < m; j++)
            {
                if (need[i][j] <= avail[j] && (need[i][0] != -1))
                {
                    c++;
                }
            }
            // if need <= available TRUE for all resources then condition is TRUE
            if (c == m)
            {
                // Work = Work + Allocated
                for (k = 0; k < m; k++)
                {
                    avail[k] += alloc[i][k];
                }
                // assign -1 if Process done and continue to next Process
                need[i][0] = -1;
                if (need[i][0] == -1)
                {
                    printf("\nProcess %d has finished execution", i); // Print the Process
                }
                finished++;
            }
        }
        // if all Processes are done then exit while loop
        if (finished == n)
        {
            printf("\nThe System is in a Safe State");
            process = 0;
        }
    }
    if (finished != n)
    {
        printf("\nThe System is in an Unsafe State");
    }
}
// Defining Resource Request Function
void resource()
{
    int req[10],p,co;
    // Enter Process Number that is Requesting Resources
    printf("\nEnter Process that is Requesting : ");
    scanf("%d", &p);
    // Enter Request Vector of size 1*m
    for (i = 0; i < m; i++)
    {
        printf("\nRequest Resource, req[%d] = ",i);
        scanf("%d", &req[i]);
    }
    // Checking if Request is lesser than Need and Availability
    co = 0;
    for(i = 0; i < n; i++)
    {
        if (req[i] <= avail[i] && (req[i] <= need[p][i]))
        {
            co++;
        }
    }
    printf("\nco :%d \nm : %d ",co,m);
    if (co == m)
    {
        for(i = 0; i < n; i++)
        {
            avail[i] = avail[i] - req[i];
            alloc[p][i] = alloc[p][i] + req[i];
            need[p][i] = need[p][i] - req[i];
        }
    }
    // New Predicted Need Matrix after Resource Request
    printf("\nPredicted Need Matrix after Resource Request:\n");
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\t %d", need[i][j]);
        }
        printf("\n");
    }
    // New Predicted Available Vector after Resource Request
    printf("\nPredicted Available Vector after Resource Request: ");
    for (i = 0; i < m; i++)
    {
        printf("%d\t", avail[i]);
    }
    safety();
}
// Main Function
void main()
{
    // Enter numbers of Processes
    printf("\nEnter no of processes : ");
    scanf("%d", &n);
    // Enter numbers of Resources
    printf("\nEnter no of resources : ");
    scanf("%d", &m);
    // Enter Allocated Matrix of size n*m
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\nEnter instances for alloc[%d][%d] = ", i,j);
            scanf("%d", &alloc[i][j]);
        }
    }
    // Enter Max Matrix of size n*m
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\nEnter instances for max[%d][%d] = ", i,j);
            scanf("%d", &max[i][j]);
        }
    }
    // Enter Available Vector of size 1*m
    for (i = 0; i < m; i++)
    {
        printf("\nAvailable Resource, avail[%d] = ",i);
        scanf("%d", &avail[i]);
    }
    // Print Allocation Matrix
    printf("Allocation Matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" \t %d", alloc[i][j]);
        }
        printf("\n");
    }
    // Print Max Matrix
    printf("Max Matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" \t %d", max[i][j]);
        }
        printf("\n");
    }
    // Calculate and Print Need Matrix
    printf("Need Matrix :\n");
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("\t %d", need[i][j]);
        }
        printf("\n");
    }
    // Menu
    int ch;
    printf("\n1. Run Safety Algorithm");
    printf("\n2. Run Resource Request Algorithm");
    printf("\nEnter Your choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: safety();
                break;
        case 2: resource();
                break;
        default : printf("\nNo such Cases");
    }
    printf("\n");
}