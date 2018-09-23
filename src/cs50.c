/*************************************************************************************
 * cs50.c
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

#include "cs50.h"

 /** char类型读入:
  *
  * 读取一行标准化文本输入并返回等价字符, 如果文本并非char类型值, 提示重试。
  * 忽略前置和尾随的空格。如果未读入文本, 返回CHAR_MAX。
  */

char GetChar(void)
{
	// 尝试接收char
	while (true)
	{
		// 接收一行文本输入 如果失败 返回CHAR_MAX
		string line = GetString();
		if (line == NULL)
		{
			return CHAR_MAX;
		}

		// 如果除前置和后缀空格外只有一个字符
		// 返回这个字符
		char c1, c2;
		if (sscanf(line, " %c %c", &c1, &c2) == 1)
		{
			free(line);
			return c1;
		}
		else
		{
			free(line);
			printf("Retry: ");
		}
	}
}

/** double类型读入:
 *
 * 读取一行标准化文本输入并返回尽可能精确的浮点值, 如果文本并非double类型值,
 * 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出和下溢出。
 * 如果未读入文本, 返回DBL_MAX。
 */

double GetDouble(void)
{
	// 尝试接收double
	while (true)
	{
		// 接收一行文本输入 如果失败 返回DBL_MAX
		string line = GetString();
		if (line == NULL)
		{
			return DBL_MAX;
		}

		// 如果除前置和后缀空格外只有一个double类型
		// 返回这个double值
		double d; char c;
		if (sscanf(line, " %lf %c", &d, &c) == 1)
		{
			free(line);
			return d;
		}
		else
		{
			free(line);
			printf("Retry: ");
		}
	}
}

/** float类型读入:
 *
 * 读取一行标准化文本输入并返回尽可能精确的浮点值, 如果文本并float类型值,
 * 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出和下溢出。
 * 如果未读入文本, 返回FLT_MAX。
 */

float GetFloat(void)
{
	// 尝试接收float
	while (true)
	{
		// 接收一行文本输入 如果失败 返回FLT_MAX
		string line = GetString();
		if (line == NULL)
		{
			return FLT_MAX;
		}

		// 如果除前置和后缀空格外只有一个float类型
		// 返回这个float值
		char c; float f;
		if (sscanf(line, " %f %c", &f, &c) == 1)
		{
			free(line);
			return f;
		}
		else
		{
			free(line);
			printf("Retry: ");
		}
	}
}

/** int类型读入:
 * 
 * 读取一行标准化文本输入并返回 [-2^31 + 1, 2^31 - 2] 范围的整型数,
 * 如果文本并整型值, 提示重试。忽略前置和尾随的空格。简单起见, 不检测上溢出
 * 和下溢出。如果未读入文本, 返回INT_MAX。
 */

int GetInt(void)
{
	// 尝试接收int
	while (true)
	{
		// 接收一行文本输入 如果失败 返回INT_MAX
		string line = GetString();
		if (line == NULL)
		{
			return INT_MAX;
		}

		// 如果除前置和后缀空格外只有一个int类型
		// 返回这个int值
		int n; char c;
		if (sscanf(line, " %i %c", &n, &c) == 1)
		{
			free(line);
			return n;
		}
		else
		{
			free(line);
			printf("Retry: ");
		}
	}
}

/** long long类型读入:
 *
 * 读取一行标准化文本输入并返回 [-2^63 + 1, 2^63 - 2] 范围的long long
 * 类型值。如果文本并非long long, 提示重试。忽略前置和尾随的空格。简单起见,
 * 不检测上溢出。如果未读入文本, 返回LLONG_MAX。
 */

long long GetLongLong(void)
{
	// 尝试接收long long
	while (true)
	{
		// 接收一行文本输入 如果失败 返回LLONG_MAX
		string line = GetString();
		if (line == NULL)
		{
			return LLONG_MAX;
		}

		// 如果除前置和后缀空格外只有一个long long类型
		// 返回这个long long值
		long long n; char c;
		if (sscanf(line, " %lld %c", &n, &c) == 1)
		{
			free(line);
			return n;
		}
		else
		{
			free(line);
			printf("Retry: ");
		}
	}
}

/** string类型读入:
 *
 * 读入一行标准化文本输入并返回string(char *)类型值, 无后缀换行字符'\n'。
 * (所以, 如果只输入"\n", 返回 "" 并非 NULL), 返回值为NULL时表示错误
 * 或什么都没输入(例如: EOF)。忽略前置和后缀的空格。使用malloc申请堆栈
 * 空间来存储字符, 注意: 为避免内存冲突, 必须用caller来free。
 */

string GetString(void)
{
	// 可变字符缓冲区
	string buffer = NULL;

	// 容器缓冲区
	unsigned int capacity = 0;

	// 缓冲区内实际字符数
	unsigned int n = 0;

	// 可变字符: 读取常规字符或EOF
	int c;

	// 迭代标准输入字符 直到行结束或文件结束
	while ((c = fgetc(stdin)) != '\n' && c != EOF)
	{
		// 增添缓冲区
		if (n + 1 > capacity)
		{
			// 增添新存储: "量子特性"为一个double内存
			// 即最小添加 log32 的字节数
			if (capacity == 0)
			{
				capacity = 32;
			}
			else if (capacity <= (UINT_MAX / 2))
			{
				capacity *= 2;
			}
			else
			{
				free(buffer);
				return NULL;
			}

			// 扩展存储
			string temp = (char*)realloc(buffer, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}

		// 添加当前字符缓冲区
		buffer[n++] = c;
	}

	// 未提供输入则返回NULL
	if (n == 0 && c == EOF)
	{
		return NULL;
	}

	// 释放缓冲区
	string  minimal = (char*)malloc((n + 1) * sizeof(char));
	strncpy(minimal, buffer, n);
	free(buffer);

	// 后缀结束
	minimal[n] = '\0';

	// 返回字符串
	return minimal;
}

/** string类型密码读入:
 *
 * 读入一行标准化文本输入并返回string(char *)类型值, 无后缀换行字符'\n'。
 * (所以, 如果只输入"\n", 返回 "" 并非 NULL), 返回值为NULL时表示错误
 * 或什么都没输入(例如: EOF)。忽略前置和后缀的空格。使用malloc申请堆栈
 * 空间来存储字符, 注意: 为避免内存冲突, 必须用caller来free。
 *
 * 我们在GetString()的基础上增添了密码输入的特性, 即键入字符时终端呈非显示
 * 状态, 实现了刷新行前可删除重写的功能。
 *
 * Bug: 在未键入字符或删除到未键入状态前时, 会产生内存冲突。
 */

string GetPassword(void)
{
	// 可变字符缓冲区
	string buffer = NULL;

	// 容器缓冲区
	unsigned int capacity = 0;

	// 缓冲区内实际字符数
	unsigned int n = 0;

	// 可变字符: 读取常规字符或EOF
	int c;

	// 迭代标准输入字符 直到文件结束
	while ((c = getch()) && c != EOF)
	{
		// 键入是否为Backspace
		bool is_backspace = false;

		// 标记并实现清除回显
		if (c == 0x8)
		{
			// 标记为键入Backspace
			is_backspace = true;

			// 退格并清除回显字符
			putchar('\b');
			putchar(' ');
			putchar('\b');

			// 这bug产生的地方:
			// 当缓冲区字符数减降到0 返回NULL
			if (--n < 0)
				return NULL;

			continue;
		}

		if (c == 0xD)
			break;

		putchar('*');

		// 增添缓冲区
		if ((n + 1 > capacity) && !is_backspace)
		{
			// 增添新存储: "量子特性"为一个double内存
			// 即最小添加 log32 的字节数
			if (capacity == 0)
			{
				capacity = 32;
			}
			else if (capacity <= (UINT_MAX / 2))
			{
				capacity *= 2;
			}
			else
			{
				free(buffer);
				return NULL;
			}

			// 扩展存储
			string temp = (char*)realloc(buffer, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}

		// 添加当前字符缓冲区
		if (!is_backspace)
			buffer[n++] = c;
	}

	// 未提供输入则返回NULL
	if (n == 0 && c == EOF)
	{
		return NULL;
	}

	// 释放缓冲区
	string  minimal = (char*)malloc((n + 1) * sizeof(char));
	strncpy(minimal, buffer, n);
	free(buffer);

	// 后缀结束
	minimal[n] = '\0';

	// 返回字符串
	return minimal;
}