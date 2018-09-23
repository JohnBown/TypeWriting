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

// ��ӭ����
void fn_typrit_welcome(void);

// ���˵��˳�
void fn_atexit_mainmeun(void);

// �Ե�һ������������
void fn_eatline(void);

// ���˵�
char fn_typrit_mainmenu(void);

// ����
void fn_loading(void);

/** ���ֳ���������:
 *
 * ִ�г���, ��ʾ�������û����롣���ǻ�Բ��ַǷ�����
 * ���Ѻõ�������м��, ������У���û������롣
 *
 * ���ڳ��������ͼ�������Ϣ��μ�����ĵ�: 
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

	// �����˳�ִ�к���
	atexit(fn_atexit_mainmeun);
	exit(EXIT_SUCCESS); // �ɹ��˳�
}

/** ��ӭ����:
 *
 * ��ʾ��ӭ,���Ե���չʾ�Ƚ�����չ��
 */

void fn_typrit_welcome(void)
{
	// TODO
	return;
}

/** ���˵�:
 *
 * ��ʾ�û�����, ����ﵽ����, ��������ֵ, �������ִ�С�
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

	// �����û����������, �����ִ�Сд
	puts("Your chose: ");
	auto char chose;
	chose =tolower(GetChar());
	fn_eatline(); // ��������

	while (strchr("tprmq", chose) == NULL) // ����Ƿ���ƥ����ַ�����
	{
		puts("Please enter t, p, r, m or q.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	// �����û�������
	return chose;
}

// �������������
void fn_eatline(void)
{
	while (getchar() != '\n')
	{
		continue;
	}
}

// ���˵��˳�
void fn_atexit_mainmeun(void)
{
	puts("QUIT FROM MAINMEUN\N");
	Sleep(_TWOSECONDS_);

	return;
}

// ����, ����һ����Ȥ�ĺ���
// ������ʾһ���򵥵� ASCII ART ����
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

/** ��ֵ��װ:
 *
 * ����һ������׺���ļ����ַ���, ͨ��ָ��·������, ʵ�ֱ�����ֵ��
 * ����ļ�ָ��Ϊ��, ����-1, ���5����������ֵ�ɹ�, ����0x5,  
 * ���򷵻سɹ���ֵ����Ŀ��
 */

int	 fn_scan_flie(	string s_filename,
					char * s_name[_NAME_SIZE_],
					char * s_cipher[_CIPHER_SIZE_],
					unsigned long long * ull_rank,
					unsigned long long * ull_credits,
					float * f_money)
{
	int i = 0;

	// ����·��
	auto char s_location[_LOCATION_SIZE_] = "account_data\\";
	strcat(s_location, s_filename);

	FILE * Fp_account = NULL;
	Fp_account = fopen(s_location, "r");

	// �ļ�ָ��Ϊ��, ����-1
	if (Fp_account == NULL)
	{
		return -1;
	}

	// ������ʱ�ַ���, �û���Ŵ�ת��������
	auto char s_temp1[_TEMP_SIZE_];
	auto char s_temp2[_TEMP_SIZE_];
	auto char s_temp3[_TEMP_SIZE_];

	// ��ֵ
	fseek(Fp_account, 0L, SEEK_SET);
	i = fscanf(	Fp_account,
				"%s %s %s %s %s",
				s_name,
				s_cipher,
				s_temp1,
				s_temp2,
				s_temp3);

	// ת��
	*ull_rank = strtoul(s_temp1, NULL, 0xa);
	*ull_credits = strtoul(s_temp2, NULL, 0xa);
	*f_money = atof(s_temp3);

	fclose(Fp_account);

	return i;
}



