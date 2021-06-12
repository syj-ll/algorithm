
#include <iostream>
using namespace std;
#define INF 10000
#define MAX 100
int G[MAX][MAX];                //�ڽӾ���
char vertex[MAX];               //�ڵ���Ϣ
int dis[MAX],vis[MAX];          //���룬���ʱ��
int n;
void Dijkstra(int n,int G[][MAX],int start,int end,int dis[],int path[]){
    int min,v=0;                //min�����洢��̾��룬v������ʱ��ŵ�ǰ���·�������ĵ�����
    for(int i=0;i<n;i++){       //��ʼ��
        dis[i]=G[start][i];     //ÿ����������ľ���
        vis[i]=0;               //��ǰδ����
        if(G[start][i]<INF)     //�����ǰ���������ͨ������Ϊ·��
            path[i]=start;
        else
            path[i]=-1;
    }
    vis[start]=1;               //�����Ϊ�Ѿ����ʹ�
    path[start]=-1;             //��㲻����·������Ҫ��������ж�
    for(int i=0;i<n-1;i++){     //�������ඥ��
        min=INF;                //���·����ʼ��
        for(int j=0;j<n;j++){
            if(vis[j]==0&&dis[j]<min){//���jδ���ʹ�������㵽j��·��С�ڵ�ǰ���·��
                v=j;            //���j
                min=dis[j];     //�������·��
            }
        }
        vis[v]=1;               //ʣ�µ��������·���ĵ���Ϊ�ѷ���
        for(int j=0;j<n;j++){   //���¾���;����ĵ�
            if(vis[j]==0&&dis[v]+G[v][j]<dis[j]){
                dis[j]=dis[v]+G[v][j];
                path[j]=v;
            }
        }
        if(v==end)              //���յ�����
            return;
    }
}
int main() {
    int start,end,i;
    int path[MAX],dis[MAX];
    char temp[MAX+5];
    scanf("%d",&n);             //����ڵ�����
    scanf("%s",temp);           //����ڵ���Ϣ��abcdefgh��
    for(int i=0;i<n;i++)
        vertex[i]=temp[i];      //�ڵ���±�Ժ�����
    for(int k=0;k<n;k++){       //����Ȩֵ�����ڽӾ���
        for(int j=0;j<n;j++){
           scanf("%d",&G[k][j]);
        }
    }
    scanf("%d%d",&start,&end);  //������ֹ���±�
    Dijkstra(n,G,start,end,dis,path);
    printf("��%d��%d�����·��Ϊ:",start,end);
    for(i=end;path[i]!=-1;i=path[i]){  //���
        printf("%c <- ",vertex[i]);
    }
    printf("%c\n",vertex[start]);
    return 0;
}

