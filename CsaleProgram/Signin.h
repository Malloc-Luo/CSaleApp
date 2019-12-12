/**
 * @filename: Signin.h
 * @author: Malloc-Luo
 * @date: 2019.12.8
 * @Description:
 */
#ifndef __SIGNIN_H__
#define __SIGNIN_H__

#include "AllFiles.h"


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
    int usernameLen;
    char password[20];
    int passwordLen;
    char phone[15];
    int phoneLen;
    char email[30];
    int emailLen;
    char timeflag;
    Def_Address_Inf address;

}Def_User_Inf;

//#define User_Inf struct _User_Inf

int Signin(void);

int Signin_windows(int cmd);

int Signin_check_information(int cmd);

int Signin_callback(int cmd);

int Check_Name(char *);

int Check_Password(char *, char *);

int Get_user_inf(Def_User_Inf *userp);

#endif // __SIGNIN_H__

