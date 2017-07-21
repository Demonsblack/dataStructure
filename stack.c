#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100     //存储空间初始分配量
#define STACKINCREMENT 10      //存储空间分配增量
typedef int SElemType;
typedef int Status;

typedef struct      //顺序栈结构体
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S)    //构造一个空栈
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
    if(!S.base)
        printf("ERROR");
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestoryStack(SqStack &S)     //销毁栈S
{
    S.top = NULL;
    S.stacksize = 0;
    free(S.base);
    return OK;
}

Status ClearStack(SqStack &S)       //把栈S置为空栈
{
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack &S)       //判断是否为空栈
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack &S)     //返回栈的长度
{
    if(S.top == S.base)
        return FALSE;
    else
        return (S.top - S.base);
}

Status GetTop(SqStack &S,SElemType &e)       //栈非空则返回栈顶元素
{
    if(S.top == S.base)
        return FALSE;
    else
        e = *(S.top - 1);
    return e;
}

Status Push(SqStack &S,SElemType &e)    //往栈中插入新元素
{
    if(S.top - S.base >= STACK_INIT_SIZE){      //栈满，追加存储空间
        S.base = (SElemType*) realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base)
            printf("ERROR");
        S.top = S.base + STACK_INIT_SIZE;       //重新定位栈顶元素
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)     //删除栈顶元素，并返回其值
{
    if(S.top == S.base)
        return ERROR;
    S.top--;
    e = *S.top;
    return e;
}

Status StackTraverse(SqStack S)     //遍历栈
{
    SElemType *p;
    p = S.top;
    if(S.base == NULL)
        return ERROR;
    if(S.top == S.base)
        printf("栈空\n");
    while(p > S.base){
        p--;
        printf("%d ",*p);
    }

    return OK;
}

int main()
{
    SqStack S;
    int flag,i,m,e,n;

    printf("构造一个空栈:\n");
    InitStack(S);
    printf("输入栈的长度:\n");
    scanf("%d",&n);
    printf("输入栈的元素:\n");
    for(i = 0;i < n;i++){
        scanf("%d",S.top);
        S.top++;
    }

    while(1){
        printf("\n输入你要选择的操作:\n0、退出\n1、销毁栈\n2、清空栈\n3、判断栈是否为空\n4、求栈的长度\n5、输出栈顶元素\n6、插入栈顶元素\n7、删除栈顶元素\n8、输出栈\n");
        scanf("%d",&flag);
        switch(flag){
        case 0:
            return 0;
        case 1:
            DestoryStack(S);
            StackTraverse(S);
            break;
        case 2:
            ClearStack(S);
            StackTraverse(S);
            break;
        case 3:
           if(StackEmpty(S) == 1)
               printf("空\n");
           else
               printf("非空\n");
            break;
        case 4:
            m = StackLength(S);
            printf("栈的长度为:%d \n",m);
            break;
        case 5:
            m = GetTop(S,e);
            printf("栈顶元素为:%d \n",m);
            break;
        case 6:
            printf("请输入要插入的元素:\n");
            scanf("%d",&e);
            Push(S,e);
            StackTraverse(S);
            break;
        case 7:
            printf("要删除的元素:%d\n",GetTop(S,e));
            m = Pop(S,e);
            StackTraverse(S);
            break;
        case 8:
            StackTraverse(S);
            break;
        default:
            printf("请输入合法数字!\n");
         }
    }
    return 0;
}
