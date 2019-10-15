#include<stdio.h>

int currAll[5][5], max[5][5];
int allocation[5] = {0,0,0,0,0};
int available[5],run[5], p,r,i,j,k=1;
int count=0, exec;
int safe = 0;

void main(){
	printf("\n Enter the number of processes : ");
	scanf("%d", &p);
	for(i=0;i<p;i++){
		run[i]=1;
		count++;
	}

	printf("\n Enter the number of resources: ");
	scanf("%d", &r);

	printf("\n Enter the allocated matrix: \n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d", &currAll[i][j]);
		}
	}

	printf("\n Enter the maximum required resources for each process: \n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d", max[i][j]);
		}
	}

	printf("\nEnter the Available resources: \n");
	for(i=0;i<r;i++){
		scanf("%d", &available[i]);
	}

	printf("\n The given allocated matrix: \n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			printf("%d", currAll[i][j]);
		}
		printf("\n");
	}
	printf("\n the Maximum Allocation matrix: ");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			printf("%d", max[i][j]);
		}
	}


while (count!= 0)
    {
            safe = 0;
            for (i = 0; i < p; i++)
        {
                    if (run[i])
            	{
                        exec = 1;
                        for (j = 0; j < r; j++)
                {
                                if (max[i][j] - currAll[i][j] > available[j])
                    {
                                    exec = 0;
                                    break;
                                }
                        }
                        if (exec)
                {
                                printf("\nProcess%d is executing\n", i + 1);
                                run[i] = 0;
                                count--;
                                safe = 1;

                                for (j = 0; j < r; j++)
                    {
                                    available[j] += currAll[i][j];
                                }
                            break;
                        }
                    }
            }
            if (!safe)
        {
                    printf("\nThe processes are in unsafe state.\n");
                    break;
            }
        else
        {
                    printf("\nThe process is in safe state");
                    printf("\nAvailable vector:");

                    for (i = 0; i < r; i++)
            {
                        printf("\t%d", available[i]);
                    }

                printf("\n");
            }
        }

}

