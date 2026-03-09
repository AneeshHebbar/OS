#include<stdio.h>

int main()
{
    int n,i,time=0,remain;
    int at[20],bt[20],pr[20];
    int rt[20],ct[20],tat[20],wt[20];
    int highest,min;

    float avgtat=0,avgwt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority of P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    remain=n;

    while(remain!=0)
    {
        highest=-1;
        min=999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && pr[i]<min)
            {
                min=pr[i];
                highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            remain--;
            ct[highest]=time;
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avgtat+=tat[i];
        avgwt+=wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Waiting Time = %.2f",avgwt/n);

    return 0;
}
