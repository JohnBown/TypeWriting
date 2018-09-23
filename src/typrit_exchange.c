/*************************************************************************************
 * typrit_exchange.c
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

// �ڴ����
void fn_atexit_listfull(void);

// ����Ŀ¼
char fn_exchange_menu(void);

// �������Ͳ˵�
char fn_ranktype_menu(void);

/** ����ģ��:
 *
 * �����ĸ��������йؿ��������ģ�嶨��, ����: �����ڵ㡢
 * ����ָ���š�չʾ��
 */

void fn_swap_item(List, List);
List fn_get_portion(List, List, bool(*)(Item, Item));
void fn_quicksort(List, List, bool(*p_fn_sortype)(Item, Item));
void fn_show_sort(const List *, char);

/** �ж�:
 *
 * ���ĸ����������ж����ŵķ���, ���صĲ���ֵ�ǿ��Ž���������
 */

bool fn_sort_in_rank(Item, Item);
bool fn_sort_in_credit(Item, Item);
bool fn_sort_in_treasure(Item, Item);
bool fn_sort_in_name(Item, Item);

/** ����:
 *
 * �û�ѡ��ִ����������ҽ��н���, �������������������鿴�Լ�
 * �û������ҡ����ǶԵ�����ִ�п�������, ʵ���˸�Ч����������;
 * ִ���û�������, ʹ���Ѽ����Ϣ�鿴���ӷ��㡣��������������:
 * a) rankֵ����; c) ����ֵ����; t) �Ƹ�ֵ����; n) ����������
 * ǰ���߶���������Ҫ��, �����ֵ���������Ϊ�˸��õĽ�����ϣɢ��
 * ����ֵ�����
 */

extern void fn_typrit_exchange(void)
{
	// ��������ѡ��
	char c_chose_rankmenu; // �����˵�ѡ��
	char c_chose_ranktype; // ��������ѡ��

	// ���ڼ�¼Ŀ��·������ͳ�Ƶ��ļ���
	long l_handle;

	// ����һ���洢�ļ���Ϣ�Ľṹ��
	struct _finddata_t s_fileinfo; // ����_finddata_t, ���Windows˵���ĵ�

	// ������ʱ�ڵ�
	Item stu_PLAYER_temp;

	// ��������
	List p_stu_PLAYER_account;

	// ����һ������ָ��, �����ж����ŷ���
	bool(*p_fn_sortype)(Item, Item);

	// �����ʼ��
	InitializeList(&p_stu_PLAYER_account);
	if (ListIsFull(p_stu_PLAYER_account))
	{
		atexit(fn_atexit_listfull);
		exit(EXIT_FAILURE);

	}

	// ��¼���, ��ֵ·���µĵ�һ���ļ�
	if ((l_handle = _findfirst("account_data\\*.txt", &s_fileinfo)) == -1L)
	{
		printf("No match is found.\n");
	}
	else 
	{
		// �����ļ�·��, ��ֵ��ʱ�ڵ㲢��������
		while (_findnext(l_handle, &s_fileinfo) == 0) 
		{
			// ��׼����ֵ��ʱ�ڵ�
			fn_scan_flie(s_fileinfo.name,
				&stu_PLAYER_temp.s_player_name,
				&stu_PLAYER_temp.s_player_cipher,
				&stu_PLAYER_temp.ull_player_rank,
				&stu_PLAYER_temp.ull_player_credits,
				&stu_PLAYER_temp.f_player_money);

			// ��ӽڵ�ʧ��, �˳�
			if (AddItem(stu_PLAYER_temp, &p_stu_PLAYER_account) == false) 
			{
				fprintf(stderr, "PROBLEM ALLOCATING MEMORY.\n");
				break;
			}

			// �������, �˳�
			if (ListIsFull(p_stu_PLAYER_account)) {
				puts("The list is now full.\n");
				break;
			}
		}
	}
	
	while ((c_chose_rankmenu = fn_exchange_menu()) != 'r') 
	{
		// �û�������
		if (c_chose_rankmenu == 'f') 
		{
			puts("Enter a name of the players you expect : ");

			string s_name;
			while ((s_name = GetString()) != NULL) 
			{
				// ����·��
				auto char s_location[_LOCATION_SIZE_] = "account_data\\";
				strcat(s_location, s_name);
				strcat(s_location, ".txt");

				/** ���������Ϣ:
				 *
				 * �ⲿ��������Ҷ���(�������)�Ĺ�����Ϣ, ������Ҫ
				 * �ƶ�һ����׼������ʵ��ֵ�ı�׼�������������ͽ��
				 * �Ĳ�������Ӧ��Ϊ�û��𵽱���, ���Խ������ĳ��򲢷�
				 * ��Ȼ��, ���ǻᾡ������Ȼ����������������
				 */

				FILE * Fp_name = fopen(s_location, "r");
				if (Fp_name == NULL)
				{
					puts("\nNo Account! Try again");
				}
				else 
				{
					// ��ǰ�ַ�
					auto char ch;
					// ������������
					auto int i_sequence = 1;

					// ǰһ�ַ��Ƿ�Ϊ��
					bool is_blank = false;
					// �Ƿ�Ҫ���
					bool is_output = true;

					_CLEARSCREEN_
					_STARS_PRINTF
					printf("Player  : ");
					while ((ch = getc(Fp_name)) != EOF)
					{
						// ����ch��is_blank��ǵ�ǰ�ַ����
						// ����is_sequence��is_output����Ƿ����
						// ���ǵ�Ŀ�����������Ϊ1��3��4�����ݶ�
						if (ch == ' ' && is_blank)
						{
							is_blank = true;
						} 
						else if (ch == ' ' && !is_blank) 
						{
							is_blank = true;
						} 
						else if (ch != ' ' && is_blank) // ��ǰ�ַ���' 'ʱ�ж����
						{
							is_blank = false;
							++i_sequence;
							switch (i_sequence) // �������ݵ�����
							{
								case 1:
									// 1)����, ���Ϊ���
									printf("Player  : ");
									is_output = true;
									break;
								case 2:
									is_output = false;
									break;
								case 3:
									// 3)rankֵ, ���Ϊ���
									printf("\nRanking : ");
									is_output = true;
									break;
								case 4:
									// 4)����ֵ, ���Ϊ���
									printf("\nCredits : ");
									is_output = true;
									break;
								case 5:
									is_output = false;
									break;
								default:
									is_output = false;
									break;
							}
						}
						else is_blank = false;

						// ���ִ��
						if (is_output)
							putc(ch, stdout);
					}
					_STARS_PRINTF

					system("pause");
					break;
				}
			}
		}
		else 
		{	
			// ����ѡ����������
			while ((c_chose_ranktype = fn_ranktype_menu()) != 'r') 
			{
				switch (c_chose_ranktype)
				{
					case 'a':
						p_fn_sortype = fn_sort_in_rank;
						break;
					case 'c':
						p_fn_sortype = fn_sort_in_credit;
						break;
					case 't':
						p_fn_sortype = fn_sort_in_treasure;
						break;
					case 'n':
						p_fn_sortype = fn_sort_in_name;
						break;
					default:
						break;
				}

				// �������
				fn_quicksort(p_stu_PLAYER_account, NULL, p_fn_sortype);

				// �������
				fn_show_sort(p_stu_PLAYER_account,c_chose_ranktype);

				system("pause");
			}
		}
	}

	// �ͷ���malloc()������ڴ�, ������ָ����ΪNULL
	EmptyTheList(&p_stu_PLAYER_account);

	return;
}

/** ����Ŀ¼:
 *
 * ��ʾ�û�����, ����ﵽ����, ��������ֵ, �������ִ�С�
 */

char fn_exchange_menu(void)
{
	puts("Looking(l) the rankings, finding(f) for other ");
	puts("players Or return(r)?\n");

	auto char chose;
	chose = tolower(GetChar());
	fn_eatline();

	while (strchr("lfr", chose) == NULL) // ����Ƿ���ƥ����ַ�����
	{
		puts("Please enter l(not 1), f or r ");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

/** �������Ͳ˵�:
 *
 * ��ʾ�û�����, ����ﵽ����, ��������ֵ, �������ִ�С�
 */
char fn_ranktype_menu(void)
{
	_CLEARSCREEN_
	_STARS_PRINTF
	puts("Enter the letter of the ranking type you desired: \n");
	puts("a)ranking                c)credit                 \n");
	puts("t)treasure               n)name                   \n");
	puts("r)return                                          ");
	_STARS_PRINTF

	puts("Your chose: ");
	auto char chose;
	chose =tolower(GetChar());
	fn_eatline();
	while (strchr("actnr", chose) == NULL) // ����Ƿ���ƥ����ַ�����
	{
		puts("Please enter a, c, t, n or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

// �����ڵ�
void fn_swap_item(List p_stu_a, List p_stu_b)
{
	auto Item temp;
	temp = p_stu_a->item;
	p_stu_a->item = p_stu_b->item;
	p_stu_b->item = temp;

	return;
}

/** �ָ�:
 *
 * ������ͷΪ��׼, ����p_fn_sortype�ķ���ֵ���������
 * ���ηָ�, �����ص�һ��������β���ڵ㡣
 */

List fn_get_portion(List p_stu_beign, List p_stu_end, bool(*p_fn_sortype)(Item, Item))
{
	Item key = p_stu_beign->item;
	List p_stu_a = p_stu_beign;
	List p_stu_b = p_stu_a->next;

	while (p_stu_b != p_stu_end)
	{
		if (p_fn_sortype(p_stu_b->item, key))
		{
			p_stu_a = p_stu_a->next;
			fn_swap_item(p_stu_a, p_stu_b);
		}

		p_stu_b = p_stu_b->next;
	}
	fn_swap_item(p_stu_a, p_stu_beign);

	return p_stu_a;
}

/** ��������:
 *
 * ����˼��, ������ʵ����������
 */

void fn_quicksort(List p_stu_beign, List p_stu_end, bool(*p_fn_sortype)(Item, Item))
{
	if (p_stu_beign != p_stu_end)
	{
		List partion = fn_get_portion(p_stu_beign, p_stu_end, p_fn_sortype);
		fn_quicksort(p_stu_beign, partion, p_fn_sortype);
		fn_quicksort(partion->next, p_stu_end, p_fn_sortype);
	}
}

/** ���:
 *
 * �ǵ�, ��������, Ȼ�������, ������ô��^_^
 */

void fn_show_sort(const List p_list, char c_show_sort)
{
	puts("Show!");
	unsigned long long ull_count = 0;
	Node * pnode = p_list;
	while (pnode != NULL) 
	{
		// һ��Сtrick, ���ǲ�ϣ���������̫���޴�
		if (++ull_count == 1)
			printf("%3.ust : ", ull_count);
		else if (ull_count == 2)
			printf("%3.und : ", ull_count);
		else if (ull_count == 3)
			printf("%3.urd : ", ull_count);
		else
			printf("%3.uth : ", ull_count);

		switch (c_show_sort) 
		{
			case 'a':
				printf(" %-8.u ", pnode->item.ull_player_rank);
				printf("%s\n", pnode->item.s_player_name);
				break;
			case 'c':
				printf(" %-8.u ", pnode->item.ull_player_credits);
				printf("%s\n", pnode->item.s_player_name);
				break;
			case 't':
				printf(" %-8.2f ", pnode->item.f_player_money);
				printf("%s\n", pnode->item.s_player_name);
				break;
			case 'n':
				printf(" %s\n",
					pnode->item.s_player_name);
				break;
			default:
				break;
		}

		// ��������
		pnode = pnode->next;
	}
	Sleep(_TWOSECONDS_);
}

void fn_atexit_listfull(void)
{
	fprintf(stderr, "NO MEMORY AVALIABLE!\n");
	Sleep(_TWOSECONDS_);
}

// ����ڵ�a����ֵ�Ƚڵ�b��, ������
bool fn_sort_in_rank(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.ull_player_rank > stu_b.ull_player_rank);
}

// ����ڵ�a����ֵ�Ƚڵ�b��, ������
bool fn_sort_in_credit(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.ull_player_credits > stu_b.ull_player_credits);
}

// ����ڵ�a�Ƹ�ֵ�Ƚڵ�b��, ������
bool fn_sort_in_treasure(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.f_player_money > stu_b.f_player_money);
}

// ����ڵ�a���ֱȽڵ�b��ǰ, ������
bool fn_sort_in_name(Item stu_a, Item stu_b)
{
	return (bool)(strcmp(stu_a.s_player_name, stu_b.s_player_name) <= 0);
}