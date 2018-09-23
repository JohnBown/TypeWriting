/*************************************************************************************
 * typrit_loginpanel.c
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

#include "cs50.h"
#include "list.h"
#include "typrit_dclrtion.h"

// ����������������, �ֱ���
_Bool bul_account_inexistence = true; // �˻�������
_Bool bul_account_unmatch = true; // ������ȷ��

// �û���¼���ĺ���
void fn_account_check(void);
void fn_password_check(void);

// ��½�˳�
void fn_atexit_logout(void);

/** ��½���:
 *
 * �ֱ�����˻������Լ���������ȷ�Լ��, ����˻�������
 * (�涨������)������ȷ, �˳�����; �������ѭ��, ֱ���ɹ�
 * ��ѡ���˳���
 */

extern void fn_typrit_loginpanel(void)
{
	while (bul_account_inexistence || bul_account_unmatch)
	{
		puts("Start?\n");
		puts("And your chose:\n");
		puts("     s) to start   q) to quit\n");

		auto char chose = GetChar();
		if (chose == 'q') 
		{
			atexit(fn_atexit_logout);
			exit(EXIT_SUCCESS);
		}
		else if (chose == 's') 
		{
			// �˻����
			fn_account_check();
			
			// ������
			fn_password_check();
		}
		else
		{
			continue;
		}
	}

	return;
}

/** �˻����
 * 
 * ����û������˺��Ƿ����, �������, ��ǲ���ֵΪ��;
 * ����, ��ǲ���ֵΪ��, ��ʾ�������롣
 */

void fn_account_check(void)
{
	while (bul_account_inexistence)
	{
		auto string s_tail = ".txt";

		puts("\nAccount : "); 

		auto string s_get_name = GetString();
		strcat(s_get_name, s_tail);

		// ���츳ֵ��װ�ķ���ֵ
		auto int i_examine;
		i_examine = fn_scan_flie(s_get_name,
			&stu_player_contount.s_player_name,
			&stu_player_contount.s_player_cipher,
			&stu_player_contount.ull_player_rank,
			&stu_player_contount.ull_player_credits,
			&stu_player_contount.f_player_money);

		if (i_examine != 0x5)
		{
			puts("\nNo Account! Try again");
			bul_account_inexistence = true;
		}
		else 
		{
			bul_account_inexistence = false;
		}
	}

	return;
}

/** ������
 * 
 * ����˻������Ƿ�ƥ��, ���ƥ��, ��ǲ���ֵΪ��;
 * ����, ��ǲ���ֵΪ�档����������������, �˳�
 * ѭ����
 */

void fn_password_check(void)
{
	auto int times = 0;

	while (bul_account_unmatch && times++ < 3)
	{
		switch (times) 
		{
			case 1:
				printf("\nPassword (You have three chances): ");
				break;
			case 2:
				printf("\nTry again (You have two chances): ");
				break;
			case 3:
				printf("\nTry again (You have only one chance): ");
				break;
			default:
				break;
		}

		// ƥ����
		auto string password = GetPassword();
		if (strcmp(password, stu_player_contount.s_player_cipher) == 0) 
		{
			bul_account_unmatch = false;
		}
	}

	return;
}

// ��½�˳�
void fn_atexit_logout(void)
{	
	puts("LOGOUT");

	return;
}

