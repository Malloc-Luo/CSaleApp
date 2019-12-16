#ifndef __PERSONAL_H__
#define __PERSONAL_H__
#include "AllFiles.h"

#define PRINT_LINE {beginline; printf("--------------------------------------------------"); }

#define CHANGE_INF 1024
#define BACKWARD   1023
#define SHOPPING   1022

typedef struct
{
    int flag;
    char province[30];
    char city[30];
    char block[30];
    char street[30];

}Adress_Inf_Buff;

typedef struct
{
    int flag;
    char username[20];
    char password[20];
    char phone[20];
    char email[30];
    int timeflag;
    Adress_Inf_Buff address;

}User_Inf_Buff;

extern User_Inf_Buff USER_Buff;

void Init_user_inf_buff(void);

int PersonalCenter(void);

int PersonalCenter_windows(int cmd);

int PersonalCenter_deal(int cmd);

int PersonalCenter_callback(int cmd);

int change_user_information(void);

int print_information(void);

int check_command_personal(int cmd);

int save_information(char *);

int init_buff(void);

int change_username(void);

int change_password(void);

int change_phone(void);

int change_email(void);

int complate_information(void);

#endif // __PERSONAL_H__
