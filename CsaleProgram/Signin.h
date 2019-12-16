/**
 * @filename: Signin.h
 * @author: Malloc-Luo
 * @date: 2019.12.8
 * @Description:
 */
#ifndef __SIGNIN_H__
#define __SIGNIN_H__

#include "AllFiles.h"

#define ADMINISTATOR 0x199

typedef struct
{
    char province[30];
    char city[30];
    char block[30];
    char street[30];

}Def_Address_Inf;

typedef struct
{
    char username[20];
    char password[20];
    char phone[20];
    char email[30];
    int timeflag;
    int number;
    Def_Address_Inf address;

}Def_User_Inf;

extern Def_User_Inf USER;

//#define User_Inf struct _User_Inf

int Signin(void);

int Signin_windows(int cmd);

int Signin_check_information(int cmd);

int Signin_callback(int cmd);

int Check_Name(char *);

int Check_Password(char *, char *);

int Get_user_inf(Def_User_Inf *userp);

//简单的登录过场
void movie(void);

void Init_user_inf(void);

#endif // __SIGNIN_H__

