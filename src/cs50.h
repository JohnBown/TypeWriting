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

/** �ַ������Ͷ���:
 *
 * ����һ���ַ�������string, ���洢�ַ�ָ�����͵��ַ���
 */

typedef char * string;

/** char���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���صȼ��ַ�, ����ı�����char����ֵ, ��ʾ���ԡ�
 * ����ǰ�ú�β��Ŀո����δ�����ı�, ����CHAR_MAX��
 */

char GetChar(void);


/** double���Ͷ���:
 * 
 * ��ȡһ�б�׼���ı����벢���ؾ����ܾ�ȷ�ĸ���ֵ, ����ı�����double����ֵ,
 * ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, �������������������
 * ���δ�����ı�, ����DBL_MAX��
 */

double GetDouble(void);

/** float���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���ؾ����ܾ�ȷ�ĸ���ֵ, ����ı���float����ֵ,
 * ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, �������������������
 * ���δ�����ı�, ����FLT_MAX��
 */

float GetFloat(void);

/** int���Ͷ���:
 * 
 * ��ȡһ�б�׼���ı����벢���� [-2^31 + 1, 2^31 - 2] ��Χ��������,
 * ����ı�������ֵ, ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����, ����������
 * ������������δ�����ı�, ����INT_MAX��
 */

int GetInt(void);

/** long long���Ͷ���:
 *
 * ��ȡһ�б�׼���ı����벢���� [-2^63 + 1, 2^63 - 2] ��Χ��long long
 * ����ֵ������ı�����long long, ��ʾ���ԡ�����ǰ�ú�β��Ŀո񡣼����,
 * ���������������δ�����ı�, ����LLONG_MAX��
 */

long long GetLongLong(void);

/** string���Ͷ���:
 *
 * ����һ�б�׼���ı����벢����string(char *)����ֵ, �޺�׺�����ַ�'\n'��
 * (����, ���ֻ����"\n", ���� "" ���� NULL), ����ֵΪNULLʱ��ʾ����
 * ��ʲô��û����(����: EOF)������ǰ�úͺ�׺�Ŀո�ʹ��malloc�����ջ
 * �ռ����洢�ַ�, ע��: Ϊ�����ڴ��ͻ, ������caller��free��
 */

string GetString(void);
