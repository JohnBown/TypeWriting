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

// 内存溢出
void fn_atexit_listfull(void);

// 交流目录
char fn_exchange_menu(void);

// 排名类型菜单
char fn_ranktype_menu(void);

/** 快排模板:
 *
 * 以下四个函数是有关快速排序的模板定义, 包含: 交换节点、
 * 计算分割、快排、展示。
 */

void fn_swap_item(List, List);
List fn_get_portion(List, List, bool(*)(Item, Item));
void fn_quicksort(List, List, bool(*p_fn_sortype)(Item, Item));
void fn_show_sort(const List *, char);

/** 判定:
 *
 * 此四个函数用于判定快排的方向, 返回的布尔值是快排交换的依据
 */

bool fn_sort_in_rank(Item, Item);
bool fn_sort_in_credit(Item, Item);
bool fn_sort_in_treasure(Item, Item);
bool fn_sort_in_name(Item, Item);

/** 交流:
 *
 * 用户选择执行与其他玩家进行交流, 具体体现在类型排名查看以及
 * 用户名查找。我们对单链表执行快速排序, 实现了高效的类型排名;
 * 执行用户名查找, 使好友间的信息查看更加方便。具体排名类型有:
 * a) rank值排名; c) 积分值排名; t) 财富值排名; n) 名字排名。
 * 前三者都是我们想要的, 而名字的排名则是为了更好的建立哈希散列
 * 表和字典树。
 */

extern void fn_typrit_exchange(void)
{
	// 定义两个选项
	char c_chose_rankmenu; // 交流菜单选项
	char c_chose_ranktype; // 快排类型选项

	// 用于记录目标路径下已统计的文件数
	long l_handle;

	// 定义一个存储文件信息的结构体
	struct _finddata_t s_fileinfo; // 关于_finddata_t, 请见Windows说明文档

	// 定义临时节点
	Item stu_PLAYER_temp;

	// 定义链表
	List p_stu_PLAYER_account;

	// 定义一个函数指针, 用来判定快排方向
	bool(*p_fn_sortype)(Item, Item);

	// 链表初始化
	InitializeList(&p_stu_PLAYER_account);
	if (ListIsFull(p_stu_PLAYER_account))
	{
		atexit(fn_atexit_listfull);
		exit(EXIT_FAILURE);

	}

	// 记录句柄, 赋值路径下的第一个文件
	if ((l_handle = _findfirst("account_data\\*.txt", &s_fileinfo)) == -1L)
	{
		printf("No match is found.\n");
	}
	else 
	{
		// 遍历文件路径, 赋值临时节点并建立链表
		while (_findnext(l_handle, &s_fileinfo) == 0) 
		{
			// 标准化赋值临时节点
			fn_scan_flie(s_fileinfo.name,
				&stu_PLAYER_temp.s_player_name,
				&stu_PLAYER_temp.s_player_cipher,
				&stu_PLAYER_temp.ull_player_rank,
				&stu_PLAYER_temp.ull_player_credits,
				&stu_PLAYER_temp.f_player_money);

			// 添加节点失败, 退出
			if (AddItem(stu_PLAYER_temp, &p_stu_PLAYER_account) == false) 
			{
				fprintf(stderr, "PROBLEM ALLOCATING MEMORY.\n");
				break;
			}

			// 链表充满, 退出
			if (ListIsFull(p_stu_PLAYER_account)) {
				puts("The list is now full.\n");
				break;
			}
		}
	}
	
	while ((c_chose_rankmenu = fn_exchange_menu()) != 'r') 
	{
		// 用户名查找
		if (c_chose_rankmenu == 'f') 
		{
			puts("Enter a name of the players you expect : ");

			string s_name;
			while ((s_name = GetString()) != NULL) 
			{
				// 计算路径
				auto char s_location[_LOCATION_SIZE_] = "account_data\\";
				strcat(s_location, s_name);
				strcat(s_location, ".txt");

				/** 输出查找信息:
				 *
				 * 这部分输出查找对象(如果存在)的公共信息, 我们需要
				 * 制定一个标准规则来实现值的标准输出。对于密码和金币
				 * 的部分我们应该为用户起到保密, 所以接下来的程序并非
				 * 显然的, 我们会尽量用自然的语言来解释它。
				 */

				FILE * Fp_name = fopen(s_location, "r");
				if (Fp_name == NULL)
				{
					puts("\nNo Account! Try again");
				}
				else 
				{
					// 当前字符
					auto char ch;
					// 数据所处序列
					auto int i_sequence = 1;

					// 前一字符是否为空
					bool is_blank = false;
					// 是否要输出
					bool is_output = true;

					_CLEARSCREEN_
					_STARS_PRINTF
					printf("Player  : ");
					while ((ch = getc(Fp_name)) != EOF)
					{
						// 利用ch和is_blank标记当前字符情况
						// 利用is_sequence和is_output标记是否输出
						// 我们的目的是输出序列为1、3、4的数据段
						if (ch == ' ' && is_blank)
						{
							is_blank = true;
						} 
						else if (ch == ' ' && !is_blank) 
						{
							is_blank = true;
						} 
						else if (ch != ' ' && is_blank) // 当前字符非' '时判定输出
						{
							is_blank = false;
							++i_sequence;
							switch (i_sequence) // 考察数据的序列
							{
								case 1:
									// 1)名字, 标记为输出
									printf("Player  : ");
									is_output = true;
									break;
								case 2:
									is_output = false;
									break;
								case 3:
									// 3)rank值, 标记为输出
									printf("\nRanking : ");
									is_output = true;
									break;
								case 4:
									// 4)积分值, 标记为输出
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

						// 标记执行
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
			// 键入选择排序类型
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

				// 链表快排
				fn_quicksort(p_stu_PLAYER_account, NULL, p_fn_sortype);

				// 输出排名
				fn_show_sort(p_stu_PLAYER_account,c_chose_ranktype);

				system("pause");
			}
		}
	}

	// 释放有malloc()分配的内存, 把链表指针设为NULL
	EmptyTheList(&p_stu_PLAYER_account);

	return;
}

/** 交流目录:
 *
 * 提示用户输入, 如果达到期望, 返回输入值, 否则继续执行。
 */

char fn_exchange_menu(void)
{
	puts("Looking(l) the rankings, finding(f) for other ");
	puts("players Or return(r)?\n");

	auto char chose;
	chose = tolower(GetChar());
	fn_eatline();

	while (strchr("lfr", chose) == NULL) // 检查是否有匹配的字符存在
	{
		puts("Please enter l(not 1), f or r ");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

/** 排名类型菜单:
 *
 * 提示用户输入, 如果达到期望, 返回输入值, 否则继续执行。
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
	while (strchr("actnr", chose) == NULL) // 检查是否有匹配的字符存在
	{
		puts("Please enter a, c, t, n or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

// 交换节点
void fn_swap_item(List p_stu_a, List p_stu_b)
{
	auto Item temp;
	temp = p_stu_a->item;
	p_stu_a->item = p_stu_b->item;
	p_stu_b->item = temp;

	return;
}

/** 分割:
 *
 * 以链表头为基准, 根据p_fn_sortype的返回值对链表进行
 * 二段分割, 并返回第一段子链表尾部节点。
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

/** 快速排序:
 *
 * 分治思想, 对链表实现物理排序。
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

/** 输出:
 *
 * 是的, 遍历链表, 然后按需输出, 就是这么简单^_^
 */

void fn_show_sort(const List p_list, char c_show_sort)
{
	puts("Show!");
	unsigned long long ull_count = 0;
	Node * pnode = p_list;
	while (pnode != NULL) 
	{
		// 一个小trick, 我们不希望这个程序太过愚蠢
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

		// 遍历链表
		pnode = pnode->next;
	}
	Sleep(_TWOSECONDS_);
}

void fn_atexit_listfull(void)
{
	fprintf(stderr, "NO MEMORY AVALIABLE!\n");
	Sleep(_TWOSECONDS_);
}

// 如果节点a排名值比节点b高, 返回真
bool fn_sort_in_rank(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.ull_player_rank > stu_b.ull_player_rank);
}

// 如果节点a积分值比节点b高, 返回真
bool fn_sort_in_credit(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.ull_player_credits > stu_b.ull_player_credits);
}

// 如果节点a财富值比节点b高, 返回真
bool fn_sort_in_treasure(Item stu_a, Item stu_b)
{
	return (bool)(stu_a.f_player_money > stu_b.f_player_money);
}

// 如果节点a名字比节点b靠前, 返回真
bool fn_sort_in_name(Item stu_a, Item stu_b)
{
	return (bool)(strcmp(stu_a.s_player_name, stu_b.s_player_name) <= 0);
}