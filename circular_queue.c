//循环队列
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXQIZE 100         //队列最大长度
typedef int QElemType;

typedef struct {        //建立循环队列结构体
    QElemType *base;    //初始化的动态分配存储空间
    int front;          //头指针
    int rear;           //尾指针
}SqQueue;

int InitQueue(SqQueue *Q)       //构造空队列
{
    Q -> base = (QElemType *)malloc(MAXQIZE *sizeof(QElemType));
    Q -> front = Q -> rear = 0;
    return OK;
}

int ClearQueue(SqQueue *Q)      //清空队列
{
    Q -> front = Q -> rear = 0;
    return OK;
}

int QueueEmpty(SqQueue Q)       //判断队列是否为空
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(SqQueue Q)      //返回队列长度
{
    return (Q.rear - Q.front + MAXQIZE) % MAXQIZE;
}

int EnQueue(SqQueue *Q,QElemType e)         //往队列中插入元素
{
    if((Q -> rear + 1) % MAXQIZE == Q -> front)
        return ERROR;       //队满
    Q -> base[Q -> rear] = e;
    Q -> rear = (Q -> rear + 1) % MAXQIZE;
    return OK;
}

int DeQueue(SqQueue *Q,int e)       //删除队头元素，并输出
{
    if(Q -> front == Q -> rear)
        return ERROR;
    e = Q -> base[Q -> front];
    printf("要删除的元素: %d \n",e);
    Q -> front = (Q -> front + 1) % MAXQIZE;
    return OK;
}

int QueueTraverse(SqQueue Q)        //遍历队列
{
    int i = Q.front;
    while(i != Q.rear){
        printf("%d ",Q.base[i]);
        i = (i + 1) % MAXQIZE;
    }
    printf("\n");
    return OK;
}

int main()
{
    SqQueue Q;
    int i,flag,n,e;
    
    printf("构造一个空队列\n");
    InitQueue(&Q);

    while(1){
        printf("请输入你的选择:\n");
        printf("0.退出\n1.输入队列元素\n2.清空队列\n3.判断队列是否为空\n4.输出队列长度\n5.插入元素\n6.删除元素\n7.遍历队列\n");
        scanf("%d",&flag);
        switch(flag){
        case 0:
            return 0;
            break;
        case 1:
            printf("输入队列元素个数:\n");
            scanf("%d",&n);
            printf("输入队列元素:\n");
            for(i = 0; i < n;i++){
                scanf("%d",&e);
                EnQueue(&Q,e);
            }
            QueueTraverse(Q);
            break;
        case 3:
             n = QueueEmpty(Q);
             if(n == 1)
                 printf("队列为空\n");
             else
                 printf("队列非空\n");
             break;
        case 2:
             ClearQueue(&Q);
             n = QueueEmpty(Q);
             if(n == 1)
                printf("队列为空\n");
             else
                printf("队列非空\n");
             break;
        case 4:
             printf("队列长度: %d \n",QueueLength(Q));
             break;
        case 5:
             printf("请输入要插入的元素:\n");
             scanf("%d",&e);
             EnQueue(&Q,e);
             QueueTraverse(Q);
             break;
        case 6:
             DeQueue(&Q,e);
             QueueTraverse(Q);
             break;
        case 7:
             QueueTraverse(Q);
             break;
        default:
             printf("请输入合法数字!\n");
        }
    }

    return 0;
}
