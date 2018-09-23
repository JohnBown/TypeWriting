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

// ѡ��˵�
char fn_chose_playmenu(void);

/** ģʽ����:
 *
 * ���岻ͬ��Ϸģʽ��ʵ�ֺ�����
 */

void fn_timing_play(void);
void fn_word_play(void);
void fn_free_play(void);
void fn_god_play(void);
void fn_purgatory_play(void);

// ���㾫ȷ��
float fn_accuracy(string s_objective, string s_standard, int i_breadth);

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

/** ģʽѡ��˵�:
 *
 * ��ʾ�û�����, ����ﵽ����, ��������ֵ, �������ִ�С�
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
	while (strchr("twfgpr", chose) == NULL) // ����Ƿ���ƥ����ַ�����
	{
		puts("Please enter t, w, f, g, p or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

/** ʱ��ģʽ:
 *
 * ��ʱ��Ϸ, ʱ������˳������ؽ��
 */

void fn_timing_play(void)
{
	// TODO

	return;
}

/** ���ģʽ:
 *
 * ��ʾ�û�ѡ���������Ϻ;�����, ������ϲ�����, ��ʾ��������; 
 * ��������� <= 0, ��ʾ������䡣Ȼ�󰴾��ӡ����ͳ�Ʋ�����
 * �����
 *
 * �Ż�: Ϊ�˸����õ�����, ����Ӧ�ý�������вü���
 * Bug: Ҳ��������������Ǿ�ȷ��, ������������й�, ��Ȼ����
 *		���ݿ����Ѿ�������һ��������
 */

void fn_word_play()
{
	printf("Hi %s, Welcome to the word mode!\nDatabase in preparation...\n", 
		stu_player_contount.s_player_name);
	Sleep(_TWOSECONDS_);

	// ����·��
	auto char s_location[_LOCATION_SIZE_] = "bank_data\\";
	auto string s_tail = ".txt";
	auto string s_get_select =NULL;

	// ���Ӽ���
	auto int i_count_sentenc = 0;
	// �ַ�����
	auto int i_count_character = 0;

	// ��ǲ���ֵ, ���ݿ�δ�����һ����ʧ��
	bool bul_data_is_unselect = true;

	while (bul_data_is_unselect)
	{
		// ��ʼ�������ַ���
		char s_input[_SETENCE_SIZE_] = { '\0' };

		puts("Available data:");
		system("DIR bank_data /B"); // ����ϵͳdir
		puts("Please enter your choice or directly return back: ");

		s_get_select = GetString();

		// ���·��
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
			// ��ǲ���ֵΪ��, ���ݿ���ҳɹ�
			bul_data_is_unselect = false;

			puts("Please enter the number(>0) of sentences you want to play: ");

			// �����������, <= 0 ��ʾ����
			i_count_sentenc = GetInt();
			while (i_count_sentenc<= 0)
			{
				puts("The number munt be greater than 0,try Again: ");
				i_count_sentenc = GetInt();
				continue;
			}

			// ��ӡ����
			while (i_count_sentenc-- > 0)
			{
				char c = 0x0;
				int j = 0;

				// ��ʼ������
				char s[_SETENCE_SIZE_] = { '\0' };

				// ����ָ�����ļ�ͷ
				fseek(Fp_typrit_bank, (long)i_count_character, SEEK_SET);

				do
				{
					c = getc(Fp_typrit_bank);
					putchar(c);
					j++;
				} while (c != EOF && c != '\n');

				fgets(s, j, stdin);
				
				// ��������
				strcat(s_input, s);
				strcat(s_input, "\n");

				// �����ַ���
				i_count_character += j+1;
			}

			// ���ñ�׼��
			char s_standard[_SETENCE_SIZE_] = { '\0' };

			// ��Ŀ���ļ���ȡ��Ϣ����ֵ��׼��
			fseek(Fp_typrit_bank, 0L, SEEK_SET);
			fgets(s_standard, i_count_character, Fp_typrit_bank);

			// ƥ���׼��������, ���׼ȷ��
			printf("The accuracy: %.2f%%\n",
				100 * fn_accuracy(s_input, s_standard, i_count_character));

			system("pause");
		}
	}
	return;
}

/** ����ģʽ:
 *
 * ����ģʽ��Ϸ, ����ʱ�̾����˳���Ϸ���鿴׼ȷ��
 */

void fn_free_play(void)
{
	// TODO

	return;
}

/** �ϵ�ģʽ:
 *
 * ������Ϸ̫����, ���ϵ��������
 */

void fn_god_play(void)
{
	puts("No kidding , man!\n");
	Sleep(_TWOSECONDS_);

	return;
}

/** ����ģʽ:
 *
 * ��������: ����������ƴд, ��鲢���
 * ��Ȼ�Ҳ�û��ʵ�֡�
 */

void fn_purgatory_play(void)
{
	// TODO

	return;
}

/** ���㾫ȷ��:
 *
 * �����׼�ַ�����Ŀ���ַ����Լ������ִ�����,����
 * ��ƥ��̶�, ���ؾ�ȷ��float���͡�
 */

float fn_accuracy(string s_objective, string s_standard, int i_breadth)
{
	int i = i_breadth;
	int right_count = 0;

	// �����ִ�, ����ͳ��
	while (i-- > 0) 
	{
		if (*s_objective == *s_standard)
			right_count++;
		s_objective++;
		s_standard++;
	}

	return (float)right_count / i_breadth;
}


