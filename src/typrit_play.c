/*************************************************************************************
 * typrit_play.c
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

// 选项菜单
char fn_chose_playmenu(void);

/** 模式函数:
 *
 * 定义不同游戏模式的实现函数。
 */

void fn_timing_play(void);
void fn_word_play(void);
void fn_free_play(void);
void fn_god_play(void);
void fn_purgatory_play(void);

// 计算精确度
float fn_accuracy(string s_objective, string s_standard, int i_breadth);

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

extern void fn_typrit_play(void)
{
	char c_chose_playmenu;
	while ((c_chose_playmenu = fn_chose_playmenu()) != 'r') 
	{
		switch (c_chose_playmenu) 
		{
			case 't':
				fn_timing_play();
				break;
			case 'w':
				fn_word_play();
				break;
			case 'f':
				fn_free_play();
				break;
			case 'g':
				fn_god_play();
				break;
			case 'p':
				fn_purgatory_play();
				break;
			default:
				break;
		}
	}

	return;
}

/** 模式选择菜单:
 *
 * 提示用户输入, 如果达到期望, 返回输入值, 否则继续执行。
 */
char fn_chose_playmenu(void)
{
	_CLEARSCREEN_
	_STARS_PRINTF
	puts("Enter the letter of the desired: \n");
	puts("t)Timing Mode            w)Word Mode             \n");
	puts("f)Free Mode              g)God Mode              \n");
	puts("p)Purgatory Mode         r)Return                ");
	_STARS_PRINTF

	puts("Your chose: ");
	auto char chose;
	chose = tolower(GetChar());
	fn_eatline();
	while (strchr("twfgpr", chose) == NULL) // 检查是否有匹配的字符存在
	{
		puts("Please enter t, w, f, g, p or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

/** 时间模式:
 *
 * 定时游戏, 时间结束退出并返回结果
 */

void fn_timing_play(void)
{
	// TODO

	return;
}

/** 语句模式:
 *
 * 提示用户选择数据资料和句子数, 如果资料不存在, 提示重新输入; 
 * 如果句子数 <= 0, 提示检查重输。然后按句打印内容统计并计算
 * 结果。
 *
 * 优化: 为了更良好的体验, 我们应该将长句进行裁剪。
 * Bug: 也许计算结果并不总是精确的, 这和文章内容有关, 虽然对于
 *		数据库我已经进行了一定的整理。
 */

void fn_word_play()
{
	printf("Hi %s, Welcome to the word mode!\nDatabase in preparation...\n", 
		stu_player_contount.s_player_name);
	Sleep(_TWOSECONDS_);

	// 设置路径
	auto char s_location[_LOCATION_SIZE_] = "bank_data\\";
	auto string s_tail = ".txt";
	auto string s_get_select =NULL;

	// 句子计数
	auto int i_count_sentenc = 0;
	// 字符计数
	auto int i_count_character = 0;

	// 标记布尔值, 数据库未被查找或查找失败
	bool bul_data_is_unselect = true;

	while (bul_data_is_unselect)
	{
		// 初始化输入字符串
		char s_input[_SETENCE_SIZE_] = { '\0' };

		puts("Available data:");
		system("DIR bank_data /B"); // 调用系统dir
		puts("Please enter your choice or directly return back: ");

		s_get_select = GetString();

		// 组合路径
		strcat(s_get_select, s_tail);
		strcat(s_location, s_get_select);

		Fp_typrit_bank = fopen(s_location, "r");

		if (Fp_typrit_bank == NULL)
		{
			puts("Check and enter again:");
			strcpy(s_location,"bank_data\\");
		}
		else
		{
			// 标记布尔值为假, 数据库查找成功
			bul_data_is_unselect = false;

			puts("Please enter the number(>0) of sentences you want to play: ");

			// 检查键入句子数, <= 0 提示重输
			i_count_sentenc = GetInt();
			while (i_count_sentenc<= 0)
			{
				puts("The number munt be greater than 0,try Again: ");
				i_count_sentenc = GetInt();
				continue;
			}

			// 打印句子
			while (i_count_sentenc-- > 0)
			{
				char c = 0x0;
				int j = 0;

				// 初始化句子
				char s[_SETENCE_SIZE_] = { '\0' };

				// 重置指针至文件头
				fseek(Fp_typrit_bank, (long)i_count_character, SEEK_SET);

				do
				{
					c = getc(Fp_typrit_bank);
					putchar(c);
					j++;
				} while (c != EOF && c != '\n');

				fgets(s, j, stdin);
				
				// 整合输入
				strcat(s_input, s);
				strcat(s_input, "\n");

				// 计数字符数
				i_count_character += j+1;
			}

			// 重置标准化
			char s_standard[_SETENCE_SIZE_] = { '\0' };

			// 从目标文件提取信息并赋值标准化
			fseek(Fp_typrit_bank, 0L, SEEK_SET);
			fgets(s_standard, i_count_character, Fp_typrit_bank);

			// 匹配标准化与输入, 输出准确度
			printf("The accuracy: %.2f%%\n",
				100 * fn_accuracy(s_input, s_standard, i_count_character));

			system("pause");
		}
	}
	return;
}

/** 自由模式:
 *
 * 自由模式游戏, 任意时刻均可退出游戏并查看准确度
 */

void fn_free_play(void)
{
	// TODO

	return;
}

/** 上帝模式:
 *
 * 觉得游戏太难了, 叫上帝来帮你吧
 */

void fn_god_play(void)
{
	puts("No kidding , man!\n");
	Sleep(_TWOSECONDS_);

	return;
}

/** 地狱模式:
 *
 * 极度困难: 随机输入干扰拼写, 检查并标记
 * 当然我并没有实现。
 */

void fn_purgatory_play(void)
{
	// TODO

	return;
}

/** 计算精确度:
 *
 * 输入标准字符串与目标字符串以及考察字串长度,计算
 * 其匹配程度, 返回精确度float类型。
 */

float fn_accuracy(string s_objective, string s_standard, int i_breadth)
{
	int i = i_breadth;
	int right_count = 0;

	// 遍历字串, 进行统计
	while (i-- > 0) 
	{
		if (*s_objective == *s_standard)
			right_count++;
		s_objective++;
		s_standard++;
	}

	return (float)right_count / i_breadth;
}


