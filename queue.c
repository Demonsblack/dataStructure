//链式队列
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemtype;

typedef struct QNode{
    QElemtype data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;     //队头指针
    QueuePtr rear;      //队尾指针
}LinkQueue;

int InitQueue(LinkQueue *Q)    //构造一个空队列
{
    Q -> front = Q -> rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q -> front)
        printf("ERROR");
    Q -> front -> next = NULL;
    return OK;
}

int ClearQueue(LinkQueue *Q)    //清空队列
{
    Q -> front -> next = NULL;
    return OK;
}

int QueueEmpty(LinkQueue Q)     //判断队列是否为空
{
    if(Q.front -> next == NULL && Q.rear -> next == NULL)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)      //求队列的长度
{
    int k;
    QueuePtr p;
    p = Q.front -> next;
    while(p != NULL){
        k++;
        p = p -> next;
    }
    return k;
}

int QueueTraverse(LinkQueue Q)      //遍历队列
{
    QueuePtr p;
    p = Q.front -> next;
    if(QueueEmpty(Q) == TRUE)
        printf("队列为空\n");
    else{
        while(p != NULL){
            printf("%d ",p -> data);
            p = p -> next;
        }
        printf("\n");
    }
    return OK;
}

void EnQueue(LinkQueue *Q,QElemtype e)    //插入新元素在队尾
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    p -> data = e;
    p -> next = NULL;
    Q -> rear -> next = p;      //在队尾增加元素
    Q -> rear = p;
}

int DeQueue(LinkQueue *Q)       //若队列不空则删除队头元素
{
    QueuePtr p;
    QElemtype e;
    if(Q -> front == Q -> rear)
        return ERROR;
    p = Q -> front -> next;
    e = p -> data;
    printf("要删除的元素:%d \n",e);
    Q -> front -> next = p -> next;
    if(Q -> rear == p)
        Q -> rear = Q -> front;
    free(p);
    return OK;
}
int main()
{
    LinkQueue Q;
    int n,i,x,flag;

    printf("构造一个空队列\n");
    InitQueue(&Q);
    while(1){
        printf("请输入你的选择:\n1、输入队列元素\n2、在队尾插入元素\n3、删除队头元素\n4、输出队长\n5、清空队列\n6、判断队列是否为空\n7、遍历队列\n0、退出\n");
        scanf("%d",&flag);
        switch(flag){
            case 1:
                printf("输入队列长度:\n");
                scanf("%d",&n);
                printf("输入队列元素:\n");
                for(i = 1;i <= n;i++){
                    scanf("%d",&x);
                    EnQueue(&Q,x);
                }
                QueueTraverse(Q);
                break;
            case 2:
                printf("请输入要插入的元素:\n");
                scanf("%d",&x);
                EnQueue(&Q,x);
                QueueTraverse(Q);
                break;
            case 3:
                DeQueue(&Q);
                QueueTraverse(Q);
                break;
            case 4:
                printf("队长：%d \n",QueueLength(Q));
                break;
            case 5:
                ClearQueue(&Q);
                if(QueueEmpty(Q) == TRUE)
                    printf("队列为空\n");
                else
                    printf("队列非空\n");
                break;
            case 6:
                if(QueueEmpty(Q) == TRUE)
                    printf("队列为空\n");
                else
                    printf("队列非空\n");
                break;
            case 7:
                QueueTraverse(Q);
                break;
            case 0:
                return 0;
            default:
                printf("请输入合法数字!\n");
        }
    }
    return 0;
}

