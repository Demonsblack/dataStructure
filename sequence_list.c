//顺序表,开始确定了表的长度就不能更改
#include <stdio.h>
#include <stdlib.h>

void builtArray(int *s,int n)	//建立顺序表
{
	printf("输入顺序表元素:\n");
	int i=0;
	int a;
	while(n--){
		scanf("%d",&s[i++]);
		//s[i++]=a;
	}
}

void insert(int *s,int x,int n,int h)	//插入一个元素,s为数组，x为插入的值，n为顺序表元素个数，h为插入的位置
{
	int i=n-h+1,k=n,p=n-1;	//i为需要更改的数据值

	while(i--){
		s[k] = s[p];
		k--;
		p--;
	}
	s[h-1] = x;
}

int delete(int *s,int x,int n)	//删除所有值为x的元素.s为数组元素的值，x为要删除的值，n为数组的项数
{
	int i=0,p=0,k=0;//p为x在数组中出现的次数

	while(i < n){
		if(s[i] == x){
			p++;
			s[k] = s[i++];
		}
		else
			s[k++] = s[i++];		
	}
	return p;
}

void print(int *s,int n)
{
	int i=0;

	while(i < n){
		printf("%d ",s[i++]);
	}
	printf("\n");
}

void printOne(int *s,int n)
{
	int i=0;

	while(1){
		if(i == n-1){
			printf("%d\n",s[i++]);
			break;
		}
		else
			i++;
	}
}

void invert(int *s,int n)
{
	int t,i;

	if(n == 1)
		return ;
	for(i = 0;i < n/2;i++){
		t = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = t;
	}
}

int main()
{
	int *s;
	int n,i,x,k,j;

	printf("输入元素个数: \n");
	scanf("%d",&n);
	s = (int *)malloc(sizeof(int));
	builtArray(s,n);
	while(1){
		printf("选择操作:\n1、输出顺序表\n2、删除一个元素\n3、退出\n4、输出一个元素\n5、元素倒置\n6、插入元素\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				print(s,n);
				break;
			case 2:
				printf("输入要删除的元素的值:\n");
				scanf("%d",&x);
				k = delete(s,x,n);
				n = n - k;
				print(s,n);
				break;
			case 3:
				return 0;
			case 4:
				printf("输入要输出几号元素:\n");
				scanf("%d",&j);
				printOne(s,j);
				break;
			case 5:
				invert(s,n);
				print(s,n);
				break;
			case 6:
				printf("输入要插入的位置以及元素:\n");
				scanf("%d%d",&i,&x);
				insert(s,x,n,i);
				n++;
				print(s,n);
				break;
			default:
				printf("请输入合法数字\n");
		}
	}

	return 0;
}
