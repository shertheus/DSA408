#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/*
 * 存储结构
 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/*
 * 初始化线性表
 */
void InitList(LinkList *L)
{
    *L = (LinkList) malloc(sizeof(LNode));
    if (!L)
    {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
}

/*
 * 销毁线性表
 */
void DestroyList(LinkList *L)
{
    LinkList temp;
    while (*L)
    {
        temp = (*L)->next;
        free(*L);
        *L = temp;
    }
}

/*
 * 清空线性表
 */
void ClearList(LinkList L)
{
    LinkList p = L->next;
    L->next = NULL;
    DestroyList(&p);
}

/*
 * 判断是否为空
 */
Status isEmpty(LinkList L)
{
    if (L->next)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/*
 * 获取长度
 */
int GetLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

/*
 * 根据位置获取元素
 */
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        j++;
        p = p->next;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

/*
 * 比较两个元素是否相等
 */
Status compare(ElemType e1, ElemType e2)
{
    if (e1 == e2)
    {
        return 0;
    }
    else if (e1 < e2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/*
 * 查找指定元素的位置
 */
int FindElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (!compare(p->data, e))
        {
            return i;
        }
        p = p->next;
    }
    return 0;
}

/*
 * 获取前驱元素
 */
Status PreElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList q, p = L->next;
    while (p->next)
    {
        q = p->next;
        if (q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return ERROR;
}

/*
 * 获取后继元素
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L->next;
    while (p->next)
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

/*
 * 插入元素
 */
Status InsertElem(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList s, p = L;
    while (p && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/*
 * 删除元素并返回值
 */
Status DeleteElem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LinkList q, p = L;
    while (p->next && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (!p->next || j > i - 1)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/*
 * 访问元素
 */
void visit(ElemType e)
{
    printf("%d ", e);
}

/*
 * 遍历线性表
 */
void TraverseList(LinkList L, void (*visit)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}

void Del_X(LinkList &L,int x){//正确代码
	LNode* p=NULL;
	LNode* q=NULL;
	if(L==NULL) return;
	if(L->data==x){
		p=L;
		L=L->next;
		free(p);
		p=NULL;
		Del_X(L,x);
	}
	else
		Del_X(L->next,x);
}

void Del_X_2(LinkList &L,int x){//尾插删除
    LNode *p=L->next, *r=L, *q;
    while (p!=NULL) {
        if (p->data!=x) {
            r->next = p;
            r=p;
            p=p->next;
        } else {
            q=p;
            p=p->next;
            free(q);
        }
    }
    r->next=NULL;
}

void reverse(LinkList &L) {//就地逆置
    LNode *p=L->next, *next;
    L->next = NULL;
    while (p!=NULL) {
        next = p->next;
        p->next = L->next;
        L->next = p;
        p = next;
    }
}
void sort(LinkList &L){
    LNode *p=L->next, *r=p->next, *pre;
    p->next = NULL;
    p = r;
    while (p!=NULL) {
        pre = L;
        while (pre!=p && pre->next->data < p->data) {
            pre = pre->next;
        }
        r = p->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
//void Del_X(LinkList &L,int x){//错误代码
//	LNode* p=NULL;
//	LNode* q=NULL;
//	if(L==NULL) return;
//	if(L->data==x){
//		p=L;
//		L=L->next;
//		free(p);
//		p=NULL;
//		Del_X(L,x);
//	}
//	else {
//		q=L->next;
//		Del_X(q,x);
//	}
//}

int main()
{
    LinkList L;
    InitList(&L);
    ElemType e;
    int i;
    if (L)
    {
        printf("init success\n");
    }

    if (isEmpty(L))
    {
        printf("list is empty\n");
    }

    for (i = 0; i < 5; i++)
    {
        InsertElem(L, i + 1, 100-i);
    }


    TraverseList(L,visit);
//	Del_X_2(L,2);
    sort(L);
    printf("\n");
    TraverseList(L,visit);
    return 0;
}
