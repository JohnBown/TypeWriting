/*************************************************************************************
* typrit_myinfo.c
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

// 我的账户菜单
char fn_chose_mycount(void);

/** 我的账户:
 *
 * 考察用户键入进行本账户数据的查看, 直到键入'r'退出我的账户。
 * 我们期望用户可以通过此模块实现账户数据的修改, 包括名字、密码
 * 排名、积分的刷新,当然用户也可以选择充值, 查看有戏记录等。
 */

extern void fn_player_account(void)
{
	char c_chose_mycount;
	while ((c_chose_mycount = fn_chose_mycount()) != NULL) 
	{
		switch (c_chose_mycount)
		{
			case 'a':
				printf("Hi %s !\n", stu_player_contount.s_player_name);
				puts("This week yours ranking:  ");
				printf("%ull .\n", stu_player_contount.ull_player_rank);
				Sleep(_TWOSECONDS_);
				break;
			case 'c':
				printf("Hi %s !\n", stu_player_contount.s_player_name);
				printf("You have %ull credits.\n", stu_player_contount.ull_player_credits);
				Sleep(_TWOSECONDS_);
				break;
			case 'o':
				printf("Ahh, your record!\n");
				Sleep(_TWOSECONDS_);
				//TODO
				break;
			case 'g':
				printf("Hi %s !\n", stu_player_contount.s_player_name);
				printf("You have $%.2f money.\n", stu_player_contount.f_player_money);
				puts("Your balance has Little money, please recharge in time! \n");
				Sleep(_TWOSECONDS_);
				break;
			case 'r':
				return;
			default:
				break;
		}
	}

	return;
}

/** 我的账户菜单:
 *
 * 提示用户输入, 如果达到期望, 返回输入值, 否则继续执行。
 */
char fn_chose_mycount(void)
{
	_CLEARSCREEN_
	_STARS_PRINTF
	puts("Enter the letter of the desired: \n");
	puts("a)Ranking                c)Credits               \n");
	puts("o)Record                 g)Gold                  \n");
	puts("r)Return                                         ");
	_STARS_PRINTF

	puts("Your chose: ");
	auto char chose;
	chose = tolower(GetChar());
	fn_eatline();
	while (strchr("acogr", chose) == NULL) // 检查是否有匹配的字符存在
	{
		puts("Please enter a, c, o, g or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

