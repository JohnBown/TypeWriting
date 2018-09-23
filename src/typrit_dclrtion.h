/*************************************************************************************
 * typrit_dclrtion.c
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

#ifndef _TYPRIT_DCLRTION_ 
	#define _TYPRIT_DCLRTION_

#include <io.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#endif

#ifndef _DCLRTION_
	#define _DCLRTION_

// Sleep()相关的延时参数, [1000L = 1s]
#define _TWOSECONDS_ 2000L
#define _HALFSECOND_ 500L

// 制表和清屏
#define _CLEARSCREEN_ system("cls");
#define _STARS_ "******************************"
#define _STARS_PRINTF printf("\n%s%s\n", _STARS_, _STARS_);

#endif

#ifndef _FP_TYPRIT_BANK_
	#define _FP_TYPRIT_BANK_

/** 全局变量:
 *
 * 定义指向打字数据库的文件指针。
 */

FILE * Fp_typrit_bank;

#endif

/** 登陆面板:
 *
 * 分别进行账户存在性检查和密码正确性检查, 如果账户存在且
 * (规定次数内)密码正确, 退出程序; 否则继续循环, 直到成功
 * 或选择退出。
 */

void fn_typrit_loginpanel(void);

/** 数据库:
 *
 * 通过考察用户选择进行数据库操作, 直到键入'r'退出函数。
 * 我们实现了windows环境下的口令查看功能,于指定路径调用数据 
 * 信息, 对于增、改、查等功能, 我们为用户进行了更自由的设置。
 */

void fn_typrit_bank(void);

/** 游戏:
 * 
 * 通过考察用户的选择执行相应游戏模块, 直到键入'r'退出游戏,
 * 否则执行相应游戏模块。游戏的模式分为 t)时间模式: 定时考察
 * 打字水平; w)语句模式: 选择期望的句子数进行考察; f)自由模式:
 * 非时间/篇幅性考察, 自由退出; g)上帝模式: 也许上帝会来帮你;
 * p)炼狱模式: 极度困难。
 *
 * 补充: 我们只实现了部分模式, 然而这些都是可扩展的。
 */

void fn_typrit_play(void);

/** 交流:
 * 
 * 用户选择执行与其他玩家进行交流, 具体体现在类型排名查看以及
 * 用户名查找。我们对单链表执行快速排序, 实现了高效的类型排名; 
 * 执行用户名查找, 使好友间的信息查看更加方便。具体排名类型有:
 * a) rank值排名; c) 积分值排名; t) 财富值排名; n) 名字排名。
 * 前三者都是我们想要的, 而名字的排名则是为了更好的建立哈希散列
 * 表和字典树。
 */

void fn_typrit_exchange(void);

/** 我的账户:
 *
 * 考察用户键入进行本账户数据的查看, 直到键入'r'退出我的账户。
 * 我们期望用户可以通过此模块实现账户数据的修改, 包括名字、密码
 * 排名、积分的刷新,当然用户也可以选择充值。
 */

void fn_player_account(void);

/** 赋值封装:
 *
 * 调入一个带后缀的文件名字符串, 通过指派路径查找, 实现变量赋值。
 * 如果文件指针为空, 返回-1, 如果5个变量都赋值成功, 返回0x5,  
 * 否则返回成功赋值的数目。
 */

int fn_scan_flie(	string, 
					char *[_NAME_SIZE_], 
					char *[_CIPHER_SIZE_], 
					unsigned long long *, 
					unsigned long long *, 
					float *);
