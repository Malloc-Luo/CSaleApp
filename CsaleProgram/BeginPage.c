/************************************************************
 * @filename: BeginPage.c
 * @author: Malloc-Luo
 * @date: 2019.12.4
 * @Description: 开始页模块，用于绘制开始页，接收指令
 *
 ***********************************************************/
#include "BeginPage.h"

int Begin_page(void)
{
    int cmd = 0;

    while(1)
    {
        cmd = Begin_page_windows();
        cmd = Begin_page_callback(cmd);
        if(cmd == _EXIT)
            break;
    }

    return cmd;
}


int OnlineFlag = LEAVE;
/*
 * 绘制开始界面，读取指令
 */
int Begin_page_windows()
{
    int cmd = 0;
    int flag = 0;

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    //show windows simpily
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~开始~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    if(OnlineFlag == ONLINE)
    {
        beginline; printf("$-> 主页         ->[1]"); newline;
        beginline; printf("$-> 个人中心     ->[2]"); newline;
    }
    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> 登录         ->[1]"); newline;
        beginline; printf("$-> 新用户注册   ->[2]"); newline;
    }
    beginline; printf("$-> 帮助         ->[3]"); newline;

    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> 退出         ->[4]"); newline;
    }

    if(OnlineFlag == ONLINE)
    {
        beginline; printf("$-> 注销登录     ->[5]"); newline;
    }

    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> 忘记密码？   ->[6]"); newline;
    }

    do
    {
        beginline; command_char();
        scanf("%d", &cmd);

        if(OnlineFlag == LEAVE)
        {
            if(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd !=6)
                flag = 1;
            else
                flag = 0;
        }

        if(OnlineFlag == ONLINE)
        {
            if(cmd != 3 && cmd != 5)
                flag = 1;
            else
                flag = 0;
        }

        if(flag)
        {
            beginline; error_remind(NOCOMMAND); newline;
        }

    }while(flag);

    return cmd;
}



int Begin_page_callback(int cmd)
{
    int Command = 0;

    if(OnlineFlag == ONLINE)
    {
        switch(cmd)
        {
            case HOMEPAGE:
                break;
            case PERSION:
                break;
            case HELP:
                Help();
                break;
            case SIGNOUT:
                break;
            default:
                break;
        }
    }

    if(OnlineFlag == LEAVE)
    {
        switch(cmd)
        {
            case LOGIN:
                Command = Login();
                break;
            case SIGNIN:
                Command = Signin();
                break;
        /*help complate*/
            case HELP:
                Help();
                break;
        /*exit complate*/
            case EXIT:
                Command = Exit();
                break;
            case FINDPASSWORD:
                break;
            default:
                break;
        }
    }

    return Command;
}
