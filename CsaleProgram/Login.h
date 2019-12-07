/************************************************************
 * @filename: Login.h
 * @author: Malloc-Luo
 * @date: 2019.12.6
 * @Description: ×¢²áÄ£¿é
 *
 ***********************************************************/
#ifndef __LOGIN_H__
#define __LOGIN_H__
#include "AllFiles.h"

#define CREATE_ERROR NULL
typedef struct
{
    char province[30];
    char city[30];
    char block[30];
    char street[30];

}Address_Inf;

typedef struct
{
    char username[20];
    char password[20];
    char phone[15];
    char email[30];
    Address_Inf address;

}User_Inf;

int Login();

int Login_windows(int cmd, User_Inf * user_p);

int Login_create_user_file(int cmd, User_Inf * user_p);

int Login_callback(int cmd);

int check_username_std(char *);

int check_password_std(char *);

int check_phone(char *);

int check_email(char *);


#endif // __LOGIN_H__
