#include<stdio.h>
#include<conio.h>
#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int start);

int main()
{
    int G[MAX][MAX],i,j,n,u;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adj matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    printf("\nEnter the starting node:");
    scanf("%d",&u);
    if(u>n-1){
        printf("wrong input enter new input which is less than %d",n);
        printf("\nEnter the starting node:");
        scanf("%d",&u);
    }
    dijkstra(G,n,u);
    return 0;
}
void dijkstra(int G[MAX][MAX],int n,int start)
{

    int cost[MAX][MAX],dist[MAX],pred[MAX];
    int visited[MAX],count,mindist,next,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }

    dist[start]=0;
    visited[start]=1;
    count=1;

    while(count<n-1)
    {
        mindist=INF;
        for(i=0;i<n;i++)
            if(dist[i]<mindist&&!visited[i])
            {
                mindist=dist[i];
                next=i;
            }
            visited[next]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindist+cost[next][i]<dist[i])
                    {
                        dist[i]=mindist+cost[next][i];
                        pred[i]=next;
                    }
        count++;
    }
    printf("vertex   distance    from source   path\n");
    for(i=0;i<n;i++)
        if(i!=start)
        {
            printf("\n  %d\t   %d\t \t %d\t   %d",i,dist[i],start,i);

            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=start);
    }
}
