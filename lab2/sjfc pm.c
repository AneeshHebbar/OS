//sjfc Preemptive
#include<stdio.h>

int main()
{
    int n,i,time=0,remain,smallest;
    int at[20],bt[20],rt[20],ct[20],tat[20],wt[20];
    int min=999;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    remain=n;

    while(remain!=0)
    {
        smallest=-1;
        min=999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && rt[i]<min)
            {
                min=rt[i];
                smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0)
        {
            remain--;
            ct[smallest]=time;
        }
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    float avgtat = 0, avgwt = 0;
    for(i=0;i<n;i++)
{
    avgtat = avgtat + tat[i];
    avgwt = avgwt + wt[i];
}

avgtat = avgtat / n;
avgwt = avgwt / n;

printf("\nAverage Turnaround Time = %f", avgtat);
printf("\nAverage Waiting Time = %f", avgwt);
    return 0;
}
