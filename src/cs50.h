/*************************************************************************************
 * cs50.h
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

#ifndef _CS50_
	#define _CS50_

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#endif

/** 字符串类型定义:
 *
 * 定义一个字符串变量string, 来存储字符指针类型的字符串
 */

typedef char * string;

/** char类型读入:
 *
 * 读取一行标准化文本输入并返回等价字符, 如果文本并非char类型值, 提示重试。
 * 忽略前置和尾随的空格。如果未读入文本, 返回CHAR_MAX。
 */

char GetChar(void);


/** double类型读入:
 * 
 * 读取一行标准化文本输入并返回尽可能精确的浮点值, 如果文本并非double类型值,
 * 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出和下溢出。
 * 如果未读入文本, 返回DBL_MAX。
 */

double GetDouble(void);

/** float类型读入:
 *
 * 读取一行标准化文本输入并返回尽可能精确的浮点值, 如果文本并float类型值,
 * 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出和下溢出。
 * 如果未读入文本, 返回FLT_MAX。
 */

float GetFloat(void);

/** int类型读入:
 * 
 * 读取一行标准化文本输入并返回 [-2^31 + 1, 2^31 - 2] 范围的整型数,
 * 如果文本并整型值, 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出
 * 和下溢出。如果未读入文本, 返回INT_MAX。
 */

int GetInt(void);

/** long long类型读入:
 *
 * 读取一行标准化文本输入并返回 [-2^63 + 1, 2^63 - 2] 范围的long long
 * 类型值。如果文本并非long long, 提示重试。忽略前置和尾随的空格。简单起见,
 * 不检测上溢出。如果未读入文本, 返回LLONG_MAX。
 */

long long GetLongLong(void);

/** string类型读入:
 *
 * 读入一行标准化文本输入并返回string(char *)类型值, 无后缀换行字符'\n'。
 * (所以, 如果只输入"\n", 返回 "" 并非 NULL), 返回值为NULL时表示错误
 * 或什么都没输入(例如: EOF)。忽略前置和后缀的空格。使用malloc申请堆栈
 * 空间来存储字符, 注意: 为避免内存冲突, 必须用caller来free。
 */

string GetString(void);
