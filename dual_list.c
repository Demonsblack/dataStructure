//双向链表
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int data;
    struct point *next,*prior;
}Link,*List;

List builtLink(int n)   //建立链表
{
    List h,p,s;
    int i,x;
    h = (List)malloc(sizeof(Link));
    s = h;
    s -> prior = NULL;
    for(i = 1;i <= n;i++){      //p为第i个元素的位置指针
        p = (List)malloc(sizeof(Link));
        scanf("%d",&x);
        s -> next = p;
        p -> data = x;
        p -> prior = s;
        s = p;
    }
    p -> next = NULL;
    return h;
}

void print(List head)
{
    List p;
    p = head -> next;
    while(p){
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\n");
}

void delete(List head,int x)
{
    List p;
    p = head -> next;
    while(p){
        if(p -> data == x){
            p -> prior -> next = p -> next;
            p -> next -> prior = p -> prior;
            free(p);
        }
        else{
            p = p -> next;
        }
    }
}

void insert(List h,int n,int x,int elem)
{
    List p,s;
    int i = 0;
    s = (List)malloc(sizeof(Link));     //为新结点分配空间
    p = h -> next;
    if(x > 1 && x <= n+1){
        while((p -> next != NULL) && (i < x-1)){    //找到要插入的位置
            p = p -> next;
            i++;
        }
        s -> data = elem;
        s -> prior = p -> prior;
        p -> prior -> next = s;
        s -> next = p;
        p -> prior = s;
    }
    else
        printf("Error.\n");

}

int main()
{
    int n,x,a,flag;
    List head;
    
    printf("输入链表长度:\n");
    scanf("%d",&n);
    printf("输入链表元素:\n");
    head = builtLink(n);

    while(1){
        printf("\n输入0退出程序\n");
        printf("输入1输出双向链表\n");
        printf("输入2删除指定元素\n");
        printf("输入3在指定位置插入元素\n");
        scanf("%d",&flag);
       
        switch(flag){
        case 0:
            return 0;
        case 1:
            print(head);
            break;
        case 2:
            printf("输入要删除的元素:\n");
            scanf("%d",&x);
            delete(head,x);
            n--;
            print(head);
            break;
        case 3:
            printf("输入要插入元素的位置和值:\n");
            scanf("%d%d",&x,&a);
            insert(head,n,x,a);
            print(head);
            n++;
            break;
        default:
            printf("请输入合法数字\n");
        }
    }

    return 0;

}
