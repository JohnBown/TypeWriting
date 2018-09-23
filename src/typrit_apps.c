/*************************************************************************************
 * typrit_apps.c
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

// 欢迎界面
void fn_typrit_welcome(void);

// 主菜单退出
void fn_atexit_mainmeun(void);

// 吃掉一行中冗余输入
void fn_eatline(void);

// 主菜单
char fn_typrit_mainmenu(void);

// 载入
void fn_loading(void);

/** 打字程序主函数:
 *
 * 执行程序, 提示并引导用户输入。我们会对部分非法或是
 * 不友好的输入进行检查, 并尝试校正用户的输入。
 *
 * 对于程序的流程图和相关信息请参见相关文档: 
 * ../typwrit_information.txt
 */

int main(void)
{
	fn_typrit_welcome();

	fn_loading();

	fn_typrit_loginpanel();

	char c_chose_mainmenu;
	while ((c_chose_mainmenu = fn_typrit_mainmenu()) != 'q') 
	{
		switch (c_chose_mainmenu)
		{
			case 't':	
					fn_typrit_play();	
				break;
			case 'p':	
					fn_typrit_bank();		
				break;
			case 'r':	
					fn_typrit_exchange();	
				break;
			case 'm':	
					fn_player_account();	
				break;
			default:
				break;
		}
	}

	// 定义退出执行函数
	atexit(fn_atexit_mainmeun);
	exit(EXIT_SUCCESS); // 成功退出
}

/** 欢迎界面:
 *
 * 提示欢迎,可以调用展示等进行扩展。
 */

void fn_typrit_welcome(void)
{
	// TODO
	return;
}

/** 主菜单:
 *
 * 提示用户输入, 如果达到期望, 返回输入值, 否则继续执行。
 */

char fn_typrit_mainmenu(void)
{
	_CLEARSCREEN_
	_STARS_PRINTF
	puts("Enter the letter of the desired: \n");
	puts("t)Typewriting Play       p)Play Bank              \n");
	puts("r)Ranking List           m)My Account             \n");
	puts("q)Quit                                            ");
	_STARS_PRINTF

	// 接收用户键入的输入, 不区分大小写
	puts("Your chose: ");
	auto char chose;
	chose =tolower(GetChar());
	fn_eatline(); // 消除冗余

	while (strchr("tprmq", chose) == NULL) // 检查是否有匹配的字符存在
	{
		puts("Please enter t, p, r, m or q.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	// 返回用户的输入
	return chose;
}

// 消除冗余的输入
void fn_eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

// 主菜单退出
void fn_atexit_mainmeun(void)
{
	puts("QUIT FROM MAINMEUN\N");
	Sleep(_TWOSECONDS_);

	return;
}

// 载入, 这是一个有趣的函数
// 他会显示一个简单的 ASCII ART 动画
void fn_loading(void)
{
	for (int i = 0;i < 3;i++)
	{
		printf(" \\Loading");
		Sleep(_HALFSECOND_);
		system("cls");

		printf(" |Loading.");
		Sleep(_HALFSECOND_);
		system("cls");

		printf(" /Loading..");
		Sleep(_HALFSECOND_);
		system("cls");

		printf(" -Loading...");
		Sleep(_HALFSECOND_);
		system("cls");
	}

	return ;
}

/** 赋值封装:
 *
 * 调入一个带后缀的文件名字符串, 通过指派路径查找, 实现变量赋值。
 * 如果文件指针为空, 返回-1, 如果5个变量都赋值成功, 返回0x5,  
 * 否则返回成功赋值的数目。
 */

int	 fn_scan_flie(	string s_filename,
					char * s_name[_NAME_SIZE_],
					char * s_cipher[_CIPHER_SIZE_],
					unsigned long long * ull_rank,
					unsigned long long * ull_credits,
					float * f_money)
{
	int i = 0;

	// 设置路径
	auto char s_location[_LOCATION_SIZE_] = "account_data\\";
	strcat(s_location, s_filename);

	FILE * Fp_account = NULL;
	Fp_account = fopen(s_location, "r");

	// 文件指针为空, 返回-1
	if (Fp_account == NULL)
	{
		return -1;
	}

	// 定义临时字符串, 用户存放待转换的数据
	auto char s_temp1[_TEMP_SIZE_];
	auto char s_temp2[_TEMP_SIZE_];
	auto char s_temp3[_TEMP_SIZE_];

	// 赋值
	fseek(Fp_account, 0L, SEEK_SET);
	i = fscanf(	Fp_account,
				"%s %s %s %s %s",
				s_name,
				s_cipher,
				s_temp1,
				s_temp2,
				s_temp3);

	// 转换
	*ull_rank = strtoul(s_temp1, NULL, 0xa);
	*ull_credits = strtoul(s_temp2, NULL, 0xa);
	*f_money = atof(s_temp3);

	fclose(Fp_account);

	return i;
}



