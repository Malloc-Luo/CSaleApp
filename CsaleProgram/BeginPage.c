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

    return 0;
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

    //show windows simpily
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ʼ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
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
        beginline; printf("$-> ע����¼        ->[5]"); newline;
    }

    do
    {
        beginline; command_char();
        scanf("%d", &cmd);

        if(OnlineFlag == LEAVE)
        {
            if(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4)
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
    switch(cmd)
    {
        case LOGIN:
            break;
        case SIGNIN:
            break;
       /*help complate*/
        case HELP:
            Help();
            break;
       /*exit complate*/
        case EXIT:
            Command = Exit();
            break;
        case SIGNOUT:
            break;
        default:
            break;
    }

    return Command;


}
