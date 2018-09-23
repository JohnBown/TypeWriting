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

 /** char���Ͷ���:
  *
  * ��ȡһ�б�׼���ı����벢���صȼ��ַ�, ����ı�����char����ֵ, ��ʾ���ԡ�
  * ����ǰ�ú�β��Ŀո����δ�����ı�, ����CHAR_MAX��
  */

char GetChar(void)
{
	// ���Խ���char
	while (true)
	{
		// ����һ���ı����� ���ʧ�� ����CHAR_MAX
		string line = GetString();
		if (line == NULL)
		{
			return CHAR_MAX;
		}

		// �����ǰ�úͺ�׺�ո���ֻ��һ���ַ�
		// ��������ַ�
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

/** double���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���ؾ����ܾ�ȷ�ĸ���ֵ, ����ı�����double����ֵ,
 * ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, �������������������
 * ���δ�����ı�, ����DBL_MAX��
 */

double GetDouble(void)
{
	// ���Խ���double
	while (true)
	{
		// ����һ���ı����� ���ʧ�� ����DBL_MAX
		string line = GetString();
		if (line == NULL)
		{
			return DBL_MAX;
		}

		// �����ǰ�úͺ�׺�ո���ֻ��һ��double����
		// �������doubleֵ
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

/** float���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���ؾ����ܾ�ȷ�ĸ���ֵ, ����ı���float����ֵ,
 * ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, �������������������
 * ���δ�����ı�, ����FLT_MAX��
 */

float GetFloat(void)
{
	// ���Խ���float
	while (true)
	{
		// ����һ���ı����� ���ʧ�� ����FLT_MAX
		string line = GetString();
		if (line == NULL)
		{
			return FLT_MAX;
		}

		// �����ǰ�úͺ�׺�ո���ֻ��һ��float����
		// �������floatֵ
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

/** int���Ͷ���:
 * 
 * ��ȡһ�б�׼���ı����벢���� [-2^31 + 1, 2^31 - 2] ��Χ��������,
 * ����ı�������ֵ, ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, ����������
 * ������������δ�����ı�, ����INT_MAX��
 */

int GetInt(void)
{
	// ���Խ���int
	while (true)
	{
		// ����һ���ı����� ���ʧ�� ����INT_MAX
		string line = GetString();
		if (line == NULL)
		{
			return INT_MAX;
		}

		// �����ǰ�úͺ�׺�ո���ֻ��һ��int����
		// �������intֵ
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

/** long long���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���� [-2^63 + 1, 2^63 - 2] ��Χ��long long
 * ����ֵ������ı�����long long, ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����,
 * ���������������δ�����ı�, ����LLONG_MAX��
 */

long long GetLongLong(void)
{
	// ���Խ���long long
	while (true)
	{
		// ����һ���ı����� ���ʧ�� ����LLONG_MAX
		string line = GetString();
		if (line == NULL)
		{
			return LLONG_MAX;
		}

		// �����ǰ�úͺ�׺�ո���ֻ��һ��long long����
		// �������long longֵ
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

/** string���Ͷ���:
 *
 * ����һ�б�׼���ı����벢����string(char *)����ֵ, �޺�׺�����ַ�'\n'��
 * (����, ���ֻ����"\n", ���� "" ���� NULL), ����ֵΪNULLʱ��ʾ����
 * ��ʲô��û����(����: EOF)������ǰ�úͺ�׺�Ŀո�ʹ��malloc�����ջ
 * �ռ����洢�ַ�, ע��: Ϊ�����ڴ��ͻ, ������caller��free��
 */

string GetString(void)
{
	// �ɱ��ַ�������
	string buffer = NULL;

	// ����������
	unsigned int capacity = 0;

	// ��������ʵ���ַ���
	unsigned int n = 0;

	// �ɱ��ַ�: ��ȡ�����ַ���EOF
	int c;

	// ������׼�����ַ� ֱ���н������ļ�����
	while ((c = fgetc(stdin)) != '\n' && c != EOF)
	{
		// ��������
		if (n + 1 > capacity)
		{
			// �����´洢: "��������"Ϊһ��double�ڴ�
			// ����С��� log32 ���ֽ���
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

			// ��չ�洢
			string temp = (char*)realloc(buffer, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}

		// ��ӵ�ǰ�ַ�������
		buffer[n++] = c;
	}

	// δ�ṩ�����򷵻�NULL
	if (n == 0 && c == EOF)
	{
		return NULL;
	}

	// �ͷŻ�����
	string  minimal = (char*)malloc((n + 1) * sizeof(char));
	strncpy(minimal, buffer, n);
	free(buffer);

	// ��׺����
	minimal[n] = '\0';

	// �����ַ���
	return minimal;
}

/** string�����������:
 *
 * ����һ�б�׼���ı����벢����string(char *)����ֵ, �޺�׺�����ַ�'\n'��
 * (����, ���ֻ����"\n", ���� "" ���� NULL), ����ֵΪNULLʱ��ʾ����
 * ��ʲô��û����(����: EOF)������ǰ�úͺ�׺�Ŀո�ʹ��malloc�����ջ
 * �ռ����洢�ַ�, ע��: Ϊ�����ڴ��ͻ, ������caller��free��
 *
 * ������GetString()�Ļ������������������������, �������ַ�ʱ�ն˳ʷ���ʾ
 * ״̬, ʵ����ˢ����ǰ��ɾ����д�Ĺ��ܡ�
 *
 * Bug: ��δ�����ַ���ɾ����δ����״̬ǰʱ, ������ڴ��ͻ��
 */

string GetPassword(void)
{
	// �ɱ��ַ�������
	string buffer = NULL;

	// ����������
	unsigned int capacity = 0;

	// ��������ʵ���ַ���
	unsigned int n = 0;

	// �ɱ��ַ�: ��ȡ�����ַ���EOF
	int c;

	// ������׼�����ַ� ֱ���ļ�����
	while ((c = getch()) && c != EOF)
	{
		// �����Ƿ�ΪBackspace
		bool is_backspace = false;

		// ��ǲ�ʵ���������
		if (c == 0x8)
		{
			// ���Ϊ����Backspace
			is_backspace = true;

			// �˸���������ַ�
			putchar('\b');
			putchar(' ');
			putchar('\b');

			// ��bug�����ĵط�:
			// ���������ַ���������0 ����NULL
			if (--n < 0)
				return NULL;

			continue;
		}

		if (c == 0xD)
			break;

		putchar('*');

		// ��������
		if ((n + 1 > capacity) && !is_backspace)
		{
			// �����´洢: "��������"Ϊһ��double�ڴ�
			// ����С��� log32 ���ֽ���
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

			// ��չ�洢
			string temp = (char*)realloc(buffer, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}

		// ��ӵ�ǰ�ַ�������
		if (!is_backspace)
			buffer[n++] = c;
	}

	// δ�ṩ�����򷵻�NULL
	if (n == 0 && c == EOF)
	{
		return NULL;
	}

	// �ͷŻ�����
	string  minimal = (char*)malloc((n + 1) * sizeof(char));
	strncpy(minimal, buffer, n);
	free(buffer);

	// ��׺����
	minimal[n] = '\0';

	// �����ַ���
	return minimal;
}