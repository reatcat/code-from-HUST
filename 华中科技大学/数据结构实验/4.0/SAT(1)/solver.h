#pragma once
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cnfparser.h"
extern SqList Back;
extern int key[3500], keynum[3500],numa;
int ExistOne(cnf L)
{
	pcNode p = L.firstc;
	while (p)
	{
		if (p->l_count == 1 && p->mark == 1)
		{
			plNode q = p->firstl;
			while (q)
			{
				if (q->mark == 1)return q->l;
				q = q->next;
			}
		}
		p = p->next;
	}
	return FALSE;
}

int EmptyClause(cnf L) {        //查看是否有空句
	pcNode p = L.firstc;
	while (p) {
		if (p->l_count == 0 && p->mark == 1) return OK;    //当文字数为0，且子句未经过删减，则是空句
		p = p->next;
	}
	return FALSE;
}

int RemoveClause(cnf &L, int flag) {            //一次找出一个变元，并删除
	pcNode p= L.firstc;
	plNode q;
	while (p) {
		if (p->mark == 0) { p = p->next; continue; }
		q = p->firstl;
		while (q) 
		{
			if (q->l == flag) 
			{           //子句中有flag，删除子句
				p->mark = 0;
				p->flag = flag;
				L.claunum--;      //子句数目减一
				break;
			}
			else if (q->l == -flag) 
			{       //子句中有-flag，删除该文字
				q->mark = 0;
				p->l_count--;   //文字数目减一
				break;
			}
			else q = q->next;
		}
		p = p->next;
	}
	L.varinum--; //删除变元后，变元数目减一
	return OK;
}

int AddClause(cnf &L, int flag)
{
	pcNode p= L.firstc;
	plNode q;
	while (p) {	
		if (p->mark == 1) {  //恢复非L规则删除的文字
			q = p->firstl;               
			while (q) {
				if (q->mark == 0 && q->l == -flag) {
					q->mark = 1;
					p->l_count++;      //子句文字数目加一
					break;
				}
				q = q->next;
			}
		}
		else if (p->mark == 0 && p->flag == flag) {       //恢复子句
			p->mark = 1;
			p->flag = 0;
			L.claunum++;
		}
		p = p->next;
	}
	L.varinum++;             //变元数目加一
	return OK;
}

int oppo(cnf& L, int flag)
{
	pcNode p = L.firstc;
	while (p)
	{
		if (p->flag == -flag)
		{
			p->flag = 0; 
			p->mark = 1;
			p->l_count--;
			plNode q = p->firstl;
			while (q->l != -flag)q = q->next;
			q->mark = 0;
			L.claunum++;
		}
		else if(p->mark==1)
		{
			plNode q = p->firstl;
			while (q)
			{
				if (q->l == flag)
				{
					p->flag = flag;
					p->mark = 0;
					q->mark = 1;
					p->l_count++;
					L.claunum--;
					break;
				}
				q = q->next;
			}
		}
		p = p->next;
	}
	return OK;
}

void Cancel(cnf& L)
{
	pcNode p=L.firstc;
	plNode q,qn;
	while (p)
	{
		q = p->firstl;
		while (q)
		{
			qn = q->next;
			while (qn)
			{
				if (qn->l == -q->l) { p->mark = 0; p->flag = 0; L.claunum--; break; }
				qn = qn->next;
			}
			if (p->mark==0)break;
			q = q->next;
		}
		p = p->next;
	}
}

int select1l(int *m)
{
	int i = 0;
	while (1)
	{
		if (keynum[i])
		{
			int j = 0;
			for (; j < Back.length; j++) { if (key[i] == abs(Back.elem[j]))break; }
			if (j == Back.length)
			{
				keynum[i] = 0; 
				*m = i; 
				return key[i];
			}
		}
		i++;
	}
}
int select2l(cnf L)
{
	int i = 2;
	pcNode p;
	plNode q;
	for (; i; i++)
	{
		p = L.firstc;
		while (p)
		{
			if (p->l_count == i&&p->mark==1)
			{
				q = p->firstl;
				while (q)
				{
					if (q->mark == 1)return q->l;
					q = q->next;
				}
			}
			p = p->next;
		}
	}
}
int dpllimproving(cnf &L,SqList An)
{
	if (L.claunum == 0)return OK;
	if (EmptyClause(L) == OK)return FALSE;
	int a = ExistOne(L), b = Back.length;
	while (a)
	{
		Back.elem[Back.length++] = a;
		RemoveClause(L,a);
		if (L.claunum == 0)//如果求解成功，记录所有单子句变元
		{
			for (int i = 0; i < Back.length; i++)
			{
				int m = Back.elem[i];
				if (m> 0) An.elem[m] = 1;
				else An.elem[-m] = -1;		
			}
			Back.length = 0;
			return OK;
		}
		else if (EmptyClause(L) == OK)//若求解失败，回溯部分单子句变元
		{
			for (int i = Back.length - 1; i >= b; i--) 
			{ 
				AddClause(L, Back.elem[i]);
			}
			Back.length = b;
			return FALSE;
		}
		a = ExistOne(L);
	}
	int t = 1;
	int m;
	if (t == 1)a = select1l(&m);
	else if (t == 2)a = select2l(L);
	RemoveClause(L, a);
	if (dpllimproving(L, An) == OK)
	{
		if (a > 0) An.elem[a] = 1;
		else An.elem[-a] = -1;
		for (int i = 0; i < Back.length; i++)
		{
			int m = Back.elem[i];
			if (m > 0) An.elem[m] = 1;
			else An.elem[-m] = -1;
		}
		Back.length = 0;
		return OK;
	}
	a = -a;
	oppo(L, a);
	if (dpllimproving(L, An) == OK)
	{
		if (a > 0) An.elem[a] = 1;
		else An.elem[-a] = -1;
		for (int i = 0; i < Back.length; i++)
		{
			int m = Back.elem[i];
			if (m > 0) An.elem[m] = 1;
			else An.elem[-m] = -1;
		}
		Back.length = 0;
		return OK;
	}
	AddClause(L, a);
	if(t==1)keynum[m] = 1;
	for (int i = Back.length - 1; i >= b; i--)
	{
		AddClause(L, Back.elem[i]);
	}
	Back.length = b;
	return FALSE;
}
