/************************************************************
 * @filename: BeginPage.c
 * @author: Malloc-Luo
 * @date: 2019.12.4
 * @Description: ��ʼҳģ�飬���ڻ��ƿ�ʼҳ������ָ��
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
 * ���ƿ�ʼ���棬��ȡָ��
 */
int Begin_page_windows()
{
    int cmd = 0;
    int flag = 0;

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    //show windows simpily
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ʼ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    if(OnlineFlag == ONLINE)
    {
        beginline; printf("$-> ��ҳ         ->[1]"); newline;
        beginline; printf("$-> ��������     ->[2]"); newline;
    }
    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> ��¼         ->[1]"); newline;
        beginline; printf("$-> ���û�ע��   ->[2]"); newline;
    }
    beginline; printf("$-> ����         ->[3]"); newline;

    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> �˳�         ->[4]"); newline;
    }

    if(OnlineFlag == ONLINE)
    {
        beginline; printf("$-> ע����¼     ->[5]"); newline;
    }

    if(OnlineFlag == LEAVE)
    {
        beginline; printf("$-> �������룿   ->[6]"); newline;
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
