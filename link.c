#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link{
    int  elem;//存储整形元素
    struct Link *next;//指向直接后继元素的指针
}link;

link * initLink();
void display(link *p);


//创建链表的函数
link * initLink(){
    int i;
    link * p = (link*)malloc(sizeof(link));//创建一个头结点
    link * temp = p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (i=1; i<5; i++) {
	//创建节点并初始化
	link *a=(link*)malloc(sizeof(link));
	a->elem=i;
	a->next=NULL;
	//建立新节点与直接前驱节点的逻辑关系
	temp->next=a;
	temp=temp->next;
    }
    return p;
}

int main() {
    
    link *p = initLink();
    display(p);
    return 0;

}

void display(link *p) {
    link *team = p;
    while(team->next) {
	team = team->next;
	printf("%d\n",team->elem);
    }
}

