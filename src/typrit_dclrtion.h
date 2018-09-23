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

// Sleep()��ص���ʱ����, [1000L = 1s]
#define _TWOSECONDS_ 2000L
#define _HALFSECOND_ 500L

// �Ʊ������
#define _CLEARSCREEN_ system("cls");
#define _STARS_ "******************************"
#define _STARS_PRINTF printf("\n%s%s\n", _STARS_, _STARS_);

#endif

#ifndef _FP_TYPRIT_BANK_
	#define _FP_TYPRIT_BANK_

/** ȫ�ֱ���:
 *
 * ����ָ��������ݿ���ļ�ָ�롣
 */

FILE * Fp_typrit_bank;

#endif

/** ��½���:
 *
 * �ֱ�����˻������Լ���������ȷ�Լ��, ����˻�������
 * (�涨������)������ȷ, �˳�����; �������ѭ��, ֱ���ɹ�
 * ��ѡ���˳���
 */

void fn_typrit_loginpanel(void);

/** ���ݿ�:
 *
 * ͨ�������û�ѡ��������ݿ����, ֱ������'r'�˳�������
 * ����ʵ����windows�����µĿ���鿴����,��ָ��·���������� 
 * ��Ϣ, ���������ġ���ȹ���, ����Ϊ�û������˸����ɵ����á�
 */

void fn_typrit_bank(void);

/** ��Ϸ:
 * 
 * ͨ�������û���ѡ��ִ����Ӧ��Ϸģ��, ֱ������'r'�˳���Ϸ,
 * ����ִ����Ӧ��Ϸģ�顣��Ϸ��ģʽ��Ϊ t)ʱ��ģʽ: ��ʱ����
 * ����ˮƽ; w)���ģʽ: ѡ�������ľ��������п���; f)����ģʽ:
 * ��ʱ��/ƪ���Կ���, �����˳�; g)�ϵ�ģʽ: Ҳ���ϵۻ�������;
 * p)����ģʽ: �������ѡ�
 *
 * ����: ����ֻʵ���˲���ģʽ, Ȼ����Щ���ǿ���չ�ġ�
 */

void fn_typrit_play(void);

/** ����:
 * 
 * �û�ѡ��ִ����������ҽ��н���, �������������������鿴�Լ�
 * �û������ҡ����ǶԵ�����ִ�п�������, ʵ���˸�Ч����������; 
 * ִ���û�������, ʹ���Ѽ����Ϣ�鿴���ӷ��㡣��������������:
 * a) rankֵ����; c) ����ֵ����; t) �Ƹ�ֵ����; n) ����������
 * ǰ���߶���������Ҫ��, �����ֵ���������Ϊ�˸��õĽ�����ϣɢ��
 * ����ֵ�����
 */

void fn_typrit_exchange(void);

/** �ҵ��˻�:
 *
 * �����û�������б��˻����ݵĲ鿴, ֱ������'r'�˳��ҵ��˻���
 * ���������û�����ͨ����ģ��ʵ���˻����ݵ��޸�, �������֡�����
 * ���������ֵ�ˢ��,��Ȼ�û�Ҳ����ѡ���ֵ��
 */

void fn_player_account(void);

/** ��ֵ��װ:
 *
 * ����һ������׺���ļ����ַ���, ͨ��ָ��·������, ʵ�ֱ�����ֵ��
 * ����ļ�ָ��Ϊ��, ����-1, ���5����������ֵ�ɹ�, ����0x5,  
 * ���򷵻سɹ���ֵ����Ŀ��
 */

int fn_scan_flie(	string, 
					char *[_NAME_SIZE_], 
					char *[_CIPHER_SIZE_], 
					unsigned long long *, 
					unsigned long long *, 
					float *);
