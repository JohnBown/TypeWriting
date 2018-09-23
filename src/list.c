/*************************************************************************************
 * list.c
 *
 * Copyright (c) 2015,JohnBown
 * GMail <http://johnbown00@gmail.com>
 * Personal Homepage <http://www.johnbown.com>
 * All right reserved.
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this 
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * * Neither the name of the copyright holder nor the names of its contributors 
 *   may be used to endorse or promote products derived from this software 
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *************************************************************************************/

#include "list.h"

/** 复制节点:
 *
 * 局部函数, 将目标复制到一个节点中。
 */

static void CopyToNode(Item item, Node * pnode);

// 初始化链表
void InitializeList(List * plist)
{
	*plist = NULL;
}

// 如果链表为空, 则返回真
bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

// 如何链表已满, 则返回真
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

// 返回节点数
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;	// 设置到链表开始出

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next; // 把plist设置为下一个节点
	}
	return count;
}

// 存放项目节点, 并把他添加到由plist指向的链表尾部
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false; // 失败时退出函数

	CopyToNode(item, pnew);
	pnew->next = NULL;

	// 如果链表为空, 将pnew定义为链表头
	if (scan == NULL)
		*plist = pnew;
	else
	{
		// 否则, 找到链表尾部
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;	// 添加pnew
	}
	return true;
}

// 访问每个节点, 分别执行pfun指向的函数
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = *plist; // 设置到链表开头
	while (pnode != NULL)
	{
		// 将函数作用于链表中的项目
		(*pfun)(pnode->item);
		// 进行下一项
		pnode = pnode->next; 
	}
}

// 释放有malloc()分配的内存, 把链表指针设为NULL
void EmptyTheList(List * plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next; // 保存下一节点地址
		free(*plist); // 释放当前节点
		*plist = psave;	// 进行下一项
	}
}

// 将项目复制下一节点
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item; // 节点复制
}