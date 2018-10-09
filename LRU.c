#include<stdio.h>

void main()
{
    int n,p;
    int i,j,k;
    print("Enter the No of element of series: ");
    scanf("%d", &n);

    int series[n];
    print("Enter the series: ");
    for(i=0;i<n;i++)
    {
            scanf("%d", &series);
    }
    print("Enter the size of Page Slot: ");
    scanf("%d", &p);

    int page[p];
    int prio[p];
    for(i=0;i<p;i++)
    {
        page[i] = -1;
        prio[i] = 1;
        print("page slot : %d", page[i]);
        print("Priority : %d", prio[i]);
    }
    int index =0;
    int flag =1;
    int curr = 0'
    int pageFault =0;
    for(i=0;i<n;i++)
    {
        flag =1;
        for(j=0;j<p;j++])
        {
            if(series(i)==page(j))
            {
                flag =0;
                curr =j;
                break;
            }
        }

        if(flag==1)
        {
            print("Priority \n");
            for(k=0;k<p;k++)
            {
                print("%d", prio[k]);
            }
            print("\n");

            for(j=0;j<p;j++)
            {
                if(prio[j]==1)
                {
                    index =j;
                    break;
                }

            }

            page[index] = series[i];

            for(j=0;j<p;j++)
            {
                if(prio[j]<p&&prio[j]>1)
                {
                    prio[j]-=1;
                }
            }

            prio[index] = p;
            pageFault++;

            for(j=0;j<p;j++)
            {
                printf("%d", page[j]);
            }
            print("\n");


        }

        if(flag==0)
        {
            for(j=0;j<p;j++)
            {
                if(prio[j]>prio[curr])
                {
                    prio[j]-=1;
                }
            }
            prio[curr] = p;
        }

        print("Page Falts: %d", pageFault);
    }


}

