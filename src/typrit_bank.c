/*************************************************************************************
 * typrit_bank.c
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

// ???????
char fn_chose_bankmenu(void);

// ????
void fn_look_bank(void);

/** ?????:
 *
 * ????????????????????????, ???????'r'?????????
 * ?????????windows???????????????,?????·??????????
 * ???, ?????????????????, ???????????????????????á?
 */

extern void fn_typrit_bank(void)
{
	char c_chose_bankmenu;
	while ((c_chose_bankmenu = fn_chose_bankmenu()) != 'r')
	{
		switch (c_chose_bankmenu)
		{
			case 'i':
				break;
			case 'd':
				break;
			case 'm':
				break;
			case 'l':
				fn_look_bank();
				break;
			default:
				break;
		}
	}

	return;
}

/** ???????:
 *
 * ??????????, ?????????, ?????????, ?????????С?
 */

char fn_chose_bankmenu(void)
{
	_CLEARSCREEN_
	_STARS_PRINTF
	puts("Enter the letter of the desired: \n");
	puts("i)Increase               d)Delete                \n");
	puts("m)Modification           l)Look Up               \n");
	puts("r)Return                                         ");
	_STARS_PRINTF

	puts("Your chose: ");
	auto char chose;
	chose = tolower(GetChar());
	fn_eatline();

	while (strchr("idmlr", chose) == NULL) // ???????????????????
	{
		puts("Please enter i, d, m, l or r.\n");
		chose = tolower(GetChar());
		fn_eatline();
	}

	return chose;
}

// ?г??????,????????
void fn_look_bank(void)
{
	puts("Available data:\n");

	// ??????? Windows dir????
	// ?г?????????????????, ??????? /B
	system("DIR bank_data /B"); // <????μ?: Windows ?????????>

	Sleep(_TWOSECONDS_); // ???2s

	return;
}

