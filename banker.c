#include<stdio.h>
int main()
{
    int p,r,i,j,k,x;
    int alloc[10][10],need[10][10],avail[10];
    int f[10],flag,ans[10],ind=0;
    printf("Enter number of processes\n");
    scanf("%d",&p);
    printf("Enter the number of resources\n");
    scanf("%d",&r);
    printf("Enter Allocation matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        scanf("%d",&alloc[i][j]);
    }
    printf("Enter need matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        scanf("%d",&need[i][j]);
    }
    printf("Enter available matrix\n");
    for(i=0;i<r;i++)
    scanf("%d",&avail[i]);

    for(i=0;i<p;i++)
    f[i]=0;

    for(k=0;k<p;k++)
    {
        for(i=0;i<p;i++)
        {
            if(f[i]==0)
            {
                flag=0;
                for(j=0;j<r;j++)
                {
                   if(need[i][j]>avail[j])
                   {
                       flag=1;
                       break;
                   }
                }
                if(flag==0)
                {
                    f[i]=1;
                    ans[ind++]=i;
                    for(x=0;x<r;x++)
                    avail[x]+=alloc[i][x];
                }
            }
        }
    }
    flag=0;
    for(i=0;i<p;i++)
    {
        if(f[i]==0)
        {flag=1;
        break;}
    }
    if(flag==1)
    printf("The following system is not safe\n");
    else
    {
        printf("System is safe\n");
        printf("Order of execution: ");
        for(i=0;i<p-1;i++)
        printf("P%d->",ans[i]);
        printf("P%d",ans[i]);
    }
}