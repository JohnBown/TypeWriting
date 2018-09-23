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

// 定义两个布尔类型, 分别标记
_Bool bul_account_inexistence = true; // 账户存在性
_Bool bul_account_unmatch = true; // 密码正确性

// 用户登录检测的函数
void fn_account_check(void);
void fn_password_check(void);

// 登陆退出
void fn_atexit_logout(void);

/** 登陆面板:
 *
 * 分别进行账户存在性检查和密码正确性检查, 如果账户存在且
 * (规定次数内)密码正确, 退出程序; 否则继续循环, 直到成功
 * 或选择退出。
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
			// 账户检查
			fn_account_check();
			
			// 密码检查
			fn_password_check();
		}
		else
		{
			continue;
		}
	}

	return;
}

/** 账户检查
 * 
 * 检查用户键入账号是否存在, 如果存在, 标记布尔值为假;
 * 否则, 标记布尔值为真, 提示继续输入。
 */

void fn_account_check(void)
{
	while (bul_account_inexistence)
	{
		auto string s_tail = ".txt";

		puts("\nAccount : "); 

		auto string s_get_name = GetString();
		strcat(s_get_name, s_tail);

		// 考察赋值封装的返回值
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

/** 密码检查
 * 
 * 检查账户密码是否匹配, 如果匹配, 标记布尔值为假;
 * 否则, 标记布尔值为真。如果三次输入均错误, 退出
 * 循环。
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

		// 匹配检查
		auto string password = GetPassword();
		if (strcmp(password, stu_player_contount.s_player_cipher) == 0) 
		{
			bul_account_unmatch = false;
		}
	}

	return;
}

// 登陆退出
void fn_atexit_logout(void)
{	
	puts("LOGOUT");

	return;
}

