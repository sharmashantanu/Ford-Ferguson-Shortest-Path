#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#include <queue>
using namespace std;
void ford(int a[100][100],int n,int s[100], int e[100]);
int main()
{
    int gd=DETECT,gm;
    char str[2],str1[2];
    initwindow(700,900,"Shortest Path Algorithm");
    int n=0,g[100][100],a[100][100],flag=0,x[100],y[100],s[100],k[100],i=0,c1=0,pr[100][100],temp=0,u,f,v,b,edge[100],z,weight[10];

    outtextxy(310,20,"INPUT GRAPH");
    for(int o=0;o<100;o++)
    {
        s[o]=0;
        k[o]=0;
    }
    rectangle(550,30,650,80);
    outtextxy(582,48,"DONE");

    cout<<"\t\t\tFORD FULKERSON METHOD\n\n\n";

    cout<<"\n Enter number of nodes : ";
    cin>>n;
    cout<<"\n Enter the weight matrix of graph : \n"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=g[i][j];
        }
    }

    for(z=0;z<n;z++)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
        }
        getmouseclick(WM_LBUTTONDOWN, x[i], y[i]);
            circle(x[i],y[i],15);
            sprintf(str, "%d", i+1);
            outtextxy(x[i]-5,y[i]-8,str);
        s[i]=x[i];
        k[i]=y[i];
        i++;
    }
    /*while(temp==0)
    {
        int h=0,t=0;
        for(int p=0;p<2;p++)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
            }
            getmouseclick(WM_LBUTTONDOWN, v, b);
            if(v>550 && v<650 && b>30 && b<80)
            {
                temp=1;
                break;
            }
            for(int j=0;j<n;j++)
            {
                if(abs(v-s[j])<=15 && abs(b-k[j])<=15)
                {
                    edge[h]=s[j];
                    edge[h+1]=k[j];
                    h+=2;
                    weight[t++]=j;
                }
            }
        }
        line(edge[0],edge[1],edge[2],edge[3]);
        sprintf(str,"%d",a[weight[0]][weight[1]]);
        outtextxy(abs(edge[0]+(edge[2]-edge[0])/2),abs(edge[1]+(edge[3]-edge[1])/2),str);
        circle((5*edge[2]+edge[0])/6,(5*edge[3]+edge[1])/6,3);
    }*/

    for(u=0;u<n;u++)
            {
                for(f=0;f<n;f++)
                {
                    if(a[u][f]!=0)
                    {
                        line(s[u],k[u],s[f],k[f]);
                        sprintf(str1,"%d",a[u][f]);
                        //outtextxy((5*s[f]+s[u])/6,(5*(k[f])+k[u])/6,str1);
                        outtextxy(abs(s[u]+(s[f]-s[u])/2),abs(k[u]+(k[f]-k[u])/2),str1);
                        circle((5*s[f]+s[u])/6,(5*(k[f])+k[u])/6,3);
                    }
                }
            }
    delay(10000);
    cleardevice();
    ford(a,n,s,k);
    return 0;
}

void ford(int a[100][100], int n,int s[100],int e[100])
{
    int flow=0,t=1,w,c=0,arr[100],k,m[100],mini,k1=0,u,f;
    int visited[100],arrparent[100];
    char str1[3],str2[3];
    queue <int> q;

    while(t)
    {
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        q.push(0);
        visited[0]=1;
        arrparent[0]=-1;
        while(!q.empty())
        {
            w=q.front();
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(visited[i]==0 && a[w][i]!=0)
                {
                    q.push(i);
                    arrparent[i]=w;
                    visited[i]=1;
                }
            }
        }
         c=0;
        for(int i=0;i<n;i++)
        {

            if(visited[i]==1)
            {
                c++;
            }
        }
        if(c!=n)
        {
            t=0;
        }


        if(t==1)
        {
            int j1=1;
            arr[0]=n-1;
            for(int i=n-1;i>0;i=k)
            {
                int v=arrparent[i];
                k=v;
                arr[j1]=k;
                j1++;
            }
            arr[j1]=0;
            k1=0;
            for(int i=j1-1;i>0;i--)
            {
                int v1=arr[i];
                int v2=arr[i-1];
                m[k1]=a[v1][v2];
                k1++;
            }
            mini=INT_MAX;
            for(int i=0;i<k1;i++)
            {
                if(m[i]<mini)
                {
                    mini=m[i];
                }
            }

            flow+=mini;
           for(int i=j1-1;i>0;i--)
           {
                int v1=arr[i];
                int v2=arr[i-1];
                a[v1][v2]-=mini;
                a[v2][v1]+=mini;
           }

           cout<<"\n\n\n";

           cout<<"\t\t\t PATHS";

           /*for(u=0;u<n;u++)
           {
               for(f=0;f<n;f++)
               {
                   cout<<a[u][f]<<" ";
               }
               cout<<endl;
           }*/

           cout<<"\n\n\nPath is : ";
            for(u=0;u<j1;u++)
            {
                cout<<arr[u]<<"<-";
            }
            cout<<"\nFlow = "<<flow;

           for(u=0;u<n;u++)
            {
                circle(s[u],e[u]+250,15);
                sprintf(str1, "%d", u+1);
                outtextxy(s[u]-5,e[u]+242,str1);
            }

            outtextxy(310,100,"INTERMEDIATE STAGES");
            for(u=0;u<n;u++)
            {
                for(f=0;f<n;f++)
                {
                    if(a[u][f]!=0)
                    {
                        line(s[u],e[u]+250,s[f],e[f]+250);
                        sprintf(str2,"%d",a[u][f]);
                        outtextxy((5*s[f]+s[u])/6,(5*(e[f]+250)+e[u]+250)/6,str2);
                        //outtextxy(abs(s[u]+(s[f]-s[u])/2),abs(e[u]+350+(e[f]+350-e[u]+350)/2),str2);
                        circle((5*s[f]+s[u])/6,(5*(e[f]+250)+e[u]+250)/6,3);
                    }
                }
            }
            delay(15000);
            cleardevice();
        }
    }
    cout<<"\n\nTotal Flow : "<<flow<<endl;
}
