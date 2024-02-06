// C Program for Banker's Algorithm


#include <stdio.h>
void main()
{ // Here we need 3 arrays namely Allocation, Max and Available
    int nop, nor, i, j, k, alloc[20][20], max[20][20], available[20][20];
    int f[20], ans[20], ind = 0, need[20][20]; // We need the Need matrix.

    // taking input No. of processes 
    printf("Enter number of processes: ");
    scanf("%d", &nop);

    // input the number of resources 
    printf("Enter the number of Resources: ");
    scanf("%d", &nor);

    // input  the Allocation Values to the Matrix 'alloc[][]'
    printf("Enter the Values of Allocation Matrix: \n");
    for (i = 0; i < nop; i++)
    {
        printf("Enter Resource For P%d:", i);
        for (j = 0; j < nor; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // input  the Max values to the matrix 'max[][]'
    printf("Enter the Values of Max Matrix: \n");
    for (i = 0; i < nop; i++)
    {
        printf("Enter Resource For P%d:", i);
        for (j = 0; j < nor; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Reading the values of array available[]
    printf("Enter the values in available: \n");

    for (j = 0; j < nor; j++)
    {
        scanf("%d", &available[0][j]);
    }

    // We are using an array f to represent the finished status of each process.
    // Initially setting all processes as not finished. ie. Setting f[i]=0 for each process i.
    for (k = 0; k < nop; k++)
    {
        f[k] = 0;
    }

    // Calculating values of the NEED MATRIX using its equation, for all processes
    // Equation is need[i][j] = max[i][j] - allocation[i][j]
    for (i = 0; i < nop; i++)
    {
        for (j = 0; j < nor; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Finding safe sequence
    int y = 0, tu = 0;   
    // ans[] array will be used to store the SAFE SEQUENCE in the end.
    // tu use for store available 
    for (k = 0; k < nop; k++)
    {
        for (i = 0; i < nop; i++) // For each process
        {
            if (f[i] == 0)
            {
                int flag = 0;             // setting flag as 0 or false.
                for (j = 0; j < nor; j++) // For each Resource
                {
                    if (need[i][j] > available[tu][j]) // If Need greater than Available, then
                    {
                        flag = 1; // Setting flag as true or 1.
                        // flag=1 means the Need is greater than what is Available for that particular resource.
                        break; // Breaking out of this loop if need > available
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < nor; y++) // For each Resource
                    {
                        available[tu + 1][y] = available[tu][y] + alloc[i][y]; // Setting availability to current availability + allocation
                    }
                    f[i] = 1;// Declaring the current process as FINISHED.
                    tu += 1; 
                }
            }
        }
    }

    // Displaying the SAFE SEQUENCE.xz
    printf("The SAFE SEQUENCE is: \n");
    for (i = 0; i < nop - 1; i++) // Here loop ends at nop-1 because we don't want to print the arrowmark(->) at the end.
    {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d", ans[nop - 1]);

    // Printing the final state in safe sequence without printing the arrowmark.

    printf(" \n \t\t\t\tThe output table is \n ");
    printf("\n ====================================================================\n");
    printf("\n porcess id        allocaion \t\t  max \t\t\t need\n ");

    for (int i = 0; i < nop; i++)

    {
        printf("\n p%d\t ", f[i]);  // print the process 

        printf(" | ");

        for (int j = 0; j < nor; j++)
        {
            printf(" \t %d ", alloc[i][j]);  // print the allocation 
        }
        printf(" | ");

        for (int j = 0; j < nor; j++)
        {
            printf(" \t %d", max[i][j]); // print the maximum 
        }
        printf(" | ");

        for (int j = 0; j < nor; j++)
        {
            printf(" \t %d", need[i][j]);   // print the need 
        }
    }

    printf("\n\n\t\t allocation of resource : \n ");
    printf("\n +===================================+\n ");
    for (int i = 0; i <= nop; i++)
    {
        for (int j = 0; j < nor; j++)
        {
            printf(" \t %d", available[i][j]);   // print the available 
        }
        printf("\n");
    }
}

/* CODE ENDS HERE */
