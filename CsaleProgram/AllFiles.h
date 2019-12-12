/***************************************************************
 * @Filename: AllFiles.h
 * @Author: Malloc-Luo
 * @Date: 2019-12-2
 * @Description: 头文件汇总，各个文件仅需引用此文件作为头文件
 *
 * @Modified:
 ***************************************************************/

#ifndef __ALL_FILES_H__
#define __ALL_FILES_H__

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <thread>
#include <string.h>
#include <conio.h>

#include "BeginPage.h"
#include "Help.h"
#include "Exit.h"
#include "Login.h"
#include "Signin.h"
#include "FindPassword.h"

#define endline   printf("\n\n\n")
#define newline   printf("\n")
#define middle    printf("                    ")
#define beginline {newline; middle; middle; }
#define CLS system("cls")

//error type
#define NOCOMMAND          0x01
#define USERNAME_DISABLE   0x02
#define USERNAME_EXIST     0x03
#define PASSWORD_DISABLE   0x04
#define PASSWORD_DIFFERENT 0x05
#define PASSWORD_ERROR     0x06
#define USERNAME_NOT_EXIST 0x07
#define TRY_TOOMANY        0x08

#define CONFIRM 101
#define CANCEL  202
#define PASS    303

#define _EXIT 242


/*如果在函数执行中某个变量被赋值为 CANCEL 则 return CANCEL*/


void get_string(char *data);

char get_char(void);

void command_char(void);

void error_remind(int );





#endif // __ALL_FILES_H__
