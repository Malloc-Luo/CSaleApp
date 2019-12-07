#include "Login.h"

/*
 * 登录模块
 */
int Login()
{
    User_Inf user;
    int cmd = 0;

    cmd = Login_windows(cmd, &user);

    cmd = Login_create_user_file(cmd, &user);

    cmd = Login_callback(cmd);

    return cmd;
}

/*
 * 绘制注册界面并接收指令
 */
int Login_windows(int cmd, User_Inf * user_p)
{
    int flag = 0, temp_flag = 0, phone_flag = 0, mail_flag = 0;
    char temppassword[20];
    CLS;
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~注册~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("按任意键开始注册.."); newline;
    beginline; command_char();
    getch();
    fflush(stdin);
    CLS;

    while(1)
    {
        /*用户名*/
        do
        {
            beginline; printf("$-> 用户名：         ($-> 取消 ->[1])"); newline;
            beginline; printf("    (长度：6~20  仅由数字和字母中至多两种组成)"); newline;
            beginline; command_char();
            get_string(user_p->username);
            flag = check_username_std(user_p->username);

            if(flag == USERNAME_DISABLE)
            {
                beginline; error_remind(flag); newline;
            }

        }while(flag == USERNAME_DISABLE);

        if(flag == CANCEL)
            break;

        /*密码*/
        do
        {
            beginline; printf("$-> 设置密码：         ($-> 取消 ->[1])"); newline;
            beginline; printf("    (长度：6~20  仅由数字、字母、特殊字符（@ # *）中的至多三种组成"); newline;
            beginline; command_char();
            get_string(user_p->password);
            flag = check_password_std(user_p->password);

            if(flag == CANCEL)
                break;

            if(flag == PASSWORD_DISABLE)
            {
                beginline; error_remind(flag); newline;
            }
            /*确认密码*/
            else
            {
                do
                {
                    beginline; printf("$-> 确认密码：        ($-> 取消 ->[1])"); newline;
                    beginline; command_char();
                    get_string(temppassword);
                    temp_flag = check_password_std(temppassword);
                    if(temp_flag == CANCEL)
                        break;
                    temp_flag = strcmp(temppassword, user_p->password);

                    if(temp_flag != 0)
                        temp_flag = PASSWORD_DIFFERENT;

                    if(temp_flag == PASSWORD_DIFFERENT)
                    {
                        beginline; error_remind(temp_flag); newline;
                    }

                }while(temp_flag == PASSWORD_DIFFERENT);
            }

        }while(flag == PASSWORD_DISABLE);

        if((flag == CANCEL) || (temp_flag == CANCEL))
            break;

        CLS;
        endline;
        beginline; printf("请填写【电话】和【邮箱】便于找回密码："); newline;
        beginline; printf("$-> 电话 * ：          (！必填项！ $-> 取消 ->[1])"); newline;
        beginline; command_char();
        get_string(user_p->phone);
        phone_flag = check_phone(user_p->phone);
        if(phone_flag == CANCEL)
            break;

        beginline; printf("$-> 邮箱：          ($-> 跳过 ->[1])"); newline;
        beginline; command_char();
        get_string(user_p->email);
        mail_flag = check_email(user_p->email);
        if(mail_flag == PASS)
            break;

        break;
    }

    if(flag == CANCEL || temp_flag == CANCEL || phone_flag == CANCEL)
        return CANCEL;

    return 0;
}


/*
 *
 */
int Login_create_user_file(int cmd, User_Inf * user_p)
{
    FILE * userf = NULL;
    char filename[50] = "D:\\userinformation\\NEU";
    char type[] = ".user";
    char username[20];
    char password[20];
    char phone[15];
    char email[30];
    int flag = 0;
    int write_flag = 0;

    if(cmd == CANCEL)
        return CANCEL;

    //文件名 filename
    strcat(filename, user_p->username);
    strcat(filename, type);

    strcpy(password, user_p->password);
    strcpy(phone, user_p->phone);
    strcpy(email, user_p->email);

    userf = fopen(filename, 'w');

    //创建用户失败
    if(userf == CREATE_ERROR)
    {
        CLS;
        endline;
        beginline; printf("创建用户失败，按任意键返回..."); newline;
        beginline; command_char();
        getch();
        return CANCEL;
    }

    //'+' 作为分隔符
    write_flag = fputs(password, userf);
    fseek(userf, 0L, SEEK_END);
    fputc('+', userf);

    write_flag = fputs(phone, userf);
    fseek(userf, 0L, SEEK_END);
    fputc('+', userf);

    write_flag = fputs(email, userf);
    fseek(userf, 0L, SEEK_END);
    fputc('+', userf);

    fclose(userf);
    return 0;
}

int Login_callback(int cmd)
{
    if(cmd == CANCEL)
        return CANCEL;
    return 0;
}


/*
 * 检查用户名是否符合规范
 * 符合 return 0
 * 取消 return CANCEL
 * 否则 return USERNAME_DISABLE
 */
int check_username_std(char *username)
{
    int flag = 0;
    int i=0;
    int len;
    int EN = 1;
    len = strlen(username);

    if(len==1 && username[0]=='1')
    {
        flag = CANCEL;
        EN = 0;
    }

    if((len<6 || len>20) && EN)
    {
        flag = USERNAME_DISABLE;
        EN = 0;
    }

    if(EN)
    {
        for(i = 0; i<len; i++)
        {
            if(username[i]<'0' || (username[i]>'9' && username[i]<'A') || (username[i]>'Z' && username[i]<'a') || username[i]>'z')
            {
                flag = USERNAME_DISABLE;
                break;
            }
        }
    }

    return flag;
}


/*
 * 检查密码是否符合规范
 * 符合 return 0
 * 取消 return CANCEL
 * 否则 return PASSWORD_DISABLE
 */
int check_password_std(char *password)
{
    int flag = 0;
    int i = 0;
    int len;
    int EN = 1;
    len = strlen(password);

    if(len == 1 && password[0] == '1')
    {
        flag = CANCEL;
        EN = 0;
    }

    if((len<6 || len>20) && EN)
    {
        flag = PASSWORD_DISABLE;
        EN = 0;
    }

    if(EN)
    {
        for(i = 0;i<len; i++)
        {
            if(password[i]<'0' || (password[i]>'9' && password[i]<'A') || (password[i]>'Z' && password[i]<'a') || password[i]>'z'
                && password[i] != '@' && password[i] != '#' && password[i] != '*')
            {
                flag = PASSWORD_DISABLE;
                break;
            }
        }
    }
    return flag;
}


/*
 * 检查电话规范
 * 取消 return CANCEL
 * 否则 return 0
 */
int check_phone(char *phone)
{
    int flag = 0;
    int len = 0;

    len = strlen(phone);
    if(len == 1 && phone[0] == '1')
        flag = CANCEL;

    return flag;
}


/*
 * 检查邮件规范
 * 跳过 return PASS
 * 否则 return 0
 */
int check_email(char *email)
{
    int flag = 0;
    char Mymail[] = "2423049596@qq.com";

    if(email[0] == '1' && email[1] == '\0')
    {
        flag = PASS;
        strcpy(email, Mymail);
    }

    return flag;
}


