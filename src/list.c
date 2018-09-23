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

/** ���ƽڵ�:
 *
 * �ֲ�����, ��Ŀ�긴�Ƶ�һ���ڵ��С�
 */

static void CopyToNode(Item item, Node * pnode);

// ��ʼ������
void InitializeList(List * plist)
{
	*plist = NULL;
}

// �������Ϊ��, �򷵻���
bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

// �����������, �򷵻���
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

// ���ؽڵ���
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;	// ���õ�����ʼ��

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next; // ��plist����Ϊ��һ���ڵ�
	}
	return count;
}

// �����Ŀ�ڵ�, ��������ӵ���plistָ�������β��
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false; // ʧ��ʱ�˳�����

	CopyToNode(item, pnew);
	pnew->next = NULL;

	// �������Ϊ��, ��pnew����Ϊ����ͷ
	if (scan == NULL)
		*plist = pnew;
	else
	{
		// ����, �ҵ�����β��
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;	// ���pnew
	}
	return true;
}

// ����ÿ���ڵ�, �ֱ�ִ��pfunָ��ĺ���
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = *plist; // ���õ�����ͷ
	while (pnode != NULL)
	{
		// �����������������е���Ŀ
		(*pfun)(pnode->item);
		// ������һ��
		pnode = pnode->next; 
	}
}

// �ͷ���malloc()������ڴ�, ������ָ����ΪNULL
void EmptyTheList(List * plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next; // ������һ�ڵ��ַ
		free(*plist); // �ͷŵ�ǰ�ڵ�
		*plist = psave;	// ������һ��
	}
}

// ����Ŀ������һ�ڵ�
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item; // �ڵ㸴��
}