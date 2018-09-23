/*************************************************************************************
 * list.h
 *
 * Based on David J.Malan's "cs50.h"
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

#pragma once

#ifndef _LIST_
	#define _LIST_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cs50.h"

/** _SIZE_ �궨��:
 *
 * �����ַ����ĳ���, �ַ�������: ��ʱ�ַ���, ����, ����, ����·��
 * ������ӡ�ľ䳤��
 */

#define _TEMP_SIZE_ 21
#define _NAME_SIZE_ 21
#define _CIPHER_SIZE_ 21
#define _LOCATION_SIZE_ 41
#define _SETENCE_SIZE_ 256

/** �ṹ��PLAYER:
 *
 * ����ṹ��PLAYER���ڴ洢ÿ���˻��Ļ�����Ϣ: �˻���, ����, rankֵ,
 * �����Լ��Ƹ���
 */

struct PLAYER 
{
	char s_player_name[_NAME_SIZE_];
	char s_player_cipher[_CIPHER_SIZE_];
	unsigned long long ull_player_rank;
	unsigned long long ull_player_credits;
	float f_player_money;
};
 
// Ŀ���������͵ĳ����װ
typedef struct PLAYER Item;


// Ŀ�����Ͷ���ΪADT(������������)
typedef struct node
{
	Item item;
	struct node * next;
} Node;
 
// ������װ����
typedef Node * List;

// ����洢�û���Ϣ��ȫ�ֱ���
Item stu_player_contount;
Item * p_stu_player_contount;

#endif

/** ��ʼ��һ������:
 *
 * ����ǰ: plistָ��һ������          
 * ������: �������ʼ��Ϊ������
 */

void InitializeList(List * plist);

/** �����Ƿ�Ϊ��:
 * 
 * ����ǰ: plistָ��һ���ѳ�ʼ��������
 * ������: ���������Ϊ���򷵻�true; ���򷵻�false��
 */

bool ListIsEmpty(const List * plist);

/** �����Ƿ�����:
 * 
 * ����ǰ: plistָ��һ���ѳ�ʼ��������
 * ������: ��������������򷵻�true; ���򷵻�false��
 */

bool ListIsFull(const List * plist);

/** ȷ���ڵ����:
 *
 * ����ǰ: plistָ��һ���ѳ�ʼ��������
 * ������: ���ظ������е���Ŀ������
 */

unsigned int ListItemCount(const List * plist);

/** ��β����½ڵ�:
 * 
 * ����ǰ: item��Ҫ�����ӵ��������Ŀ,
 *		   plistָ��һ���ѳ�ʼ��������
 * ������: ������ܵĻ�, ������β�����һ������Ŀ,
 *		   ��������true; ���򷵻�false��
 */

bool AddItem(Item item, List * plist);

/** ִ�к�������:
 *
 * ����ǰ: plistָ��һ���ѳ�ʼ��������, pfunָ��һ��
 *		   ����, �ú�������һ��Item���������޷���ֵ��
 * ������: pfunָ��ĺ��������õ������е�ÿ����Ŀ��
 */

void Traverse(const List * plist, void (* pfun) (Item item));

/** �ͷ��ѷ�����ڴ�(�����):
 * 
 * ����ǰ: plistָ��һ���ѳ�ʼ��������
 * ������: Ϊ�����������ڴ��ѱ��ͷ�, ���Ҹ�����
 *		   ����Ϊ�ա�
 */

void EmptyTheList(List * plish);