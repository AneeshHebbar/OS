//ps non-preemptive
#include<stdio.h>

int main()
{
    int n,i,j,pos,min;
    int at[20],bt[20],pr[20],ct[20],tat[20],wt[20],done[20]={0};
    int time=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority of P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    for(i=0;i<n;i++)
    {
        min=999;

        for(j=0;j<n;j++)
        {
            if(at[j]<=time && done[j]==0 && pr[j]<min)
            {
                min=pr[j];
                pos=j;
            }
        }

        time=time+bt[pos];
        ct[pos]=time;
        tat[pos]=ct[pos]-at[pos];
        wt[pos]=tat[pos]-bt[pos];
        done[pos]=1;
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
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
