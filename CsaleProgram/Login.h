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
#define CREATE_SUCCESS 17
#define CHAR_SIZE sizeof(char)
#define INT_SIZE  sizeof(int)

typedef struct
{
    char province[30];
    char city[30];
    char block[30];
    char street[30];

}Address_Inf;

struct _User_Inf
{
    char username[20];
    char password[20];
    char phone[20];
    char email[30];
    int timeflag;
    int number;
    Address_Inf address;

};

#define User_Inf struct _User_Inf

//extern User_Inf ;

int Login();

int Login_windows(int cmd, User_Inf * user_p);

int Login_create_user_file(int cmd, User_Inf * user_p);

int Login_callback(int cmd);

int check_username_std(char *);

int check_password_std(char *);

int check_phone(char *);

int check_email(char *);


#endif // __LOGIN_H__
