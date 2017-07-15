//单链表，链表是对数组的操作
#include <stdio.h>
#include <stdlib.h>

typedef struct point	//建立单链表的结构体
{
	int data;   //单链表数据域
	struct point *next;     //单链表指针域
}Link,*List;

List builtLink(List head)
{
	List p,s,h;
	int x;

	printf("请输入几个数，EOF表示结束\n");	//linux下 crtl+d
	head = (List)malloc(sizeof(Link));  //分配地址空间
	head->next = NULL;  
	h = head;
	s = h;
	while(scanf("%d",&x) != EOF){
		p = (List)malloc(sizeof(Link));
		p->data = x;
		p->next = NULL;
		s->next = p;
		s = p;
	}

	return h;
}

void print(List head)
{
	List p;
	p = head->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

void count(List head)
{
	int count=0;
	List p;
	p = head->next;
	while(p){
		count++;
		p = p->next;
	}
	printf("链表长度为:%d \n",count);
}

void delete(List head)
{
    int x;
    List p,q,s;
    printf("请输入一个数:\n");
    scanf("%d",&x);
    p = head->next;
    s = head;
    while(p){
        if(x == p->data){
            q = p;
            p = p->next;
            s->next = p;
            free(q);
        }
        else{
            p = p->next;
            s = s->next;
        }     
    }
}

List inver(List head)
{
    List h,h1,p,q;
    h1=h=head;
    p = head->next;
    while(p){
        q = p->next;
        p->next = h;
        h = p;
        p = q;
    }
    q = h1->next;
    q->next = NULL;
    h1->next = h;

    return h1;
}

void findPre(List head)
{
    List p,q;
    int x,flag=0;
    p = head->next;
    q = head;
    printf("请输入一个数:\n");
    scanf("%d",&x);

    while(p){
        flag++;
        if(x == p->data){
            if(flag == 1)
                printf("x没有前驱\n");
            else
                printf("x的前驱结点是: %d\n",q->data);
        }
        p = p->next;
        q = q->next;
    }
}

void devide()  //把单链表拆分成奇数表和偶数表
{
    List ho,p,q,hj,t,s;
    hj = (List)malloc(sizeof(Link));    //奇数表的表头
    ho = builtLink(ho);
    t = hj;
    p = ho->next;
    s = ho;

    while(p){
        if(p->data % 2 == 1){
            q = p;
            t->next = q;
            s->next = p->next;
            p = p->next;
            t = t->next;
            q->next = NULL;
        }
        else{
            p = p->next;
            s = s->next;
        }
    }
    printf("偶数链表:\n");
    print(ho);
    printf("奇数链表:\n");
    print(hj);
}

int main()
{
	int n,tmp;
	List head;

	printf("建立一个带头结点的单链表:\n");
	head = builtLink(head);

    while(1){
        printf("选择你需要的操作:\n1、计算链表长度并且输出单链表\n2、查找值为x的直接前驱结点\n3、删除值为x的结点\n4、单链表倒置\n5、退出\n6、把链表拆分为奇数链表和偶数链表\n");
        scanf("%d",&n);
        switch(n){
        case 1:
            count(head);
            print(head);
            break;
        case 2:
            findPre(head);
            break;
        case 3:
            delete(head);
            print(head);
            break;
        case 4:
            inver(head);
            print(head);
            break;
        case 5:
            return 0;
        case 6:
            devide();
            break;
        default:
            printf("请输入合法数字!\n");
        }
}

    return 0;
}
