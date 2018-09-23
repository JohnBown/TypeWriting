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

/** _SIZE_ 宏定义:
 *
 * 定义字符串的尺码, 字符串包括: 临时字符串, 姓名, 密码, 访问路径
 * 和所打印的句长。
 */

#define _TEMP_SIZE_ 21
#define _NAME_SIZE_ 21
#define _CIPHER_SIZE_ 21
#define _LOCATION_SIZE_ 41
#define _SETENCE_SIZE_ 256

/** 结构体PLAYER:
 *
 * 定义结构体PLAYER用于存储每个账户的基本信息: 账户名, 密码, rank值,
 * 积分以及财富。
 */

struct PLAYER 
{
	char s_player_name[_NAME_SIZE_];
	char s_player_cipher[_CIPHER_SIZE_];
	unsigned long long ull_player_rank;
	unsigned long long ull_player_credits;
	float f_player_money;
};
 
// 目标数据类型的抽象封装
typedef struct PLAYER Item;


// 目标类型定义为ADT(抽象数据类型)
typedef struct node
{
	Item item;
	struct node * next;
} Node;
 
// 命名封装链表
typedef Node * List;

// 定义存储用户信息的全局变量
Item stu_player_contount;
Item * p_stu_player_contount;

#endif

/** 初始化一个链表:
 *
 * 操作前: plist指向一个链表。          
 * 操作后: 该链表初始化为空链表。
 */

void InitializeList(List * plist);

/** 链表是否为空:
 * 
 * 操作前: plist指向一个已初始化的链表。
 * 操作后: 如果该链表为空则返回true; 否则返回false。
 */

bool ListIsEmpty(const List * plist);

/** 链表是否已满:
 * 
 * 操作前: plist指向一个已初始化的链表。
 * 操作后: 如果该链表已满则返回true; 否则返回false。
 */

bool ListIsFull(const List * plist);

/** 确定节点个数:
 *
 * 操作前: plist指向一个已初始化的链表。
 * 操作后: 返回该链表中的项目个数。
 */

unsigned int ListItemCount(const List * plist);

/** 表尾添加新节点:
 * 
 * 操作前: item是要被增加到链表的项目,
 *		   plist指向一个已初始化的链表。
 * 操作后: 如果可能的话, 在链表尾部添加一个新项目,
 *		   函数返回true; 否则返回false。
 */

bool AddItem(Item item, List * plist);

/** 执行函数操作:
 *
 * 操作前: plist指向一个已初始化的链表, pfun指向一个
 *		   函数, 该函数接受一个Item参数并且无返回值。
 * 操作后: pfun指向的函数被作用到链表中的每个项目。
 */

void Traverse(const List * plist, void (* pfun) (Item item));

/** 释放已分配的内存(如果有):
 * 
 * 操作前: plist指向一个已初始化的链表。
 * 操作后: 为该链表分配的内存已被释放, 并且该链表被
 *		   重置为空。
 */

void EmptyTheList(List * plish);