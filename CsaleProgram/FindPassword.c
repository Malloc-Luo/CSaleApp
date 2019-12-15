#include "FindPassword.h"

int FindPassword(void)
{
    int cmd = 0;

    cmd = FindPassword_windows(cmd);

    cmd = FindPassword_deal(cmd);

    cmd = FindPassword_callback(cmd);

    return cmd;
}

int FindPassword_windows(int cmd)
{
    char number_buff[30];
    char pswd_buff[20];
    int flag = 0;
    CLS;
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~ÕÒ»ØÃÜÂë~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("press anyone to continue.."); newline;
    getch();
    CLS;
    endline; endline; endline;
    middle; printf("[Provide you Phone or Email to confrim your identify:]  $-> Cancel ->[1]"); newline;

    while(1)
    {
        beginline; command_char();
        get_string(number_buff);
        if(strlen(number_buff) == 1 && number_buff[0] == '1')
            return CANCEL;

        if(strcmp(number_buff, USER.email) == 0 || strcmp(number_buff, USER.phone) == 0)
            break;
        else
        {
            beginline; printf("Phone or Email error, please try again    $-> Cancel ->[1]"); newline;
        }
    }
    CLS;
    beginline; printf("Now your can reset your password !"); newline;
    beginline; printf("New Password:"); newline;

    while(1)
    {
        beginline; command_char();
        get_string(pswd_buff);
        flag = check_password_std(pswd_buff);
        if(flag == CANCEL)
            return CANCEL;
        if(flag == PASSWORD_DISABLE)
        {
            beginline; error_remind(flag);
        }
        else
            break;
    }
    strcpy(USER.password, pswd_buff);
    return 0;
}

int FindPassword_deal(int cmd)
{
    if(cmd == CANCEL)
        return cmd;
    save_information(USER.username);
    CLS;
    endline; endline; endline;
    beginline; printf("Reset password successfully!"); newline;
    Sleep(1000);

    return 0;
}

int FindPassword_callback(int cmd)
{
    if(cmd == CANCEL)
        return cmd;
    return 0;
}
