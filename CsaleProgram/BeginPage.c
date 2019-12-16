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
 //       beginline; printf("$-> �������룿   ->[6]"); newline;
    }

    cmd = check_command(cmd);

    return cmd;
}


/*
 * �������
 */
static int check_command(char cmd)
{
    int flag = 0;
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
            if(cmd != 3 && cmd != 5 && cmd != 1 && cmd != 2)
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
            HomePage();
            break;
        case PERSION:
            PersonalCenter();
            break;
        case HELP:
            Help();
            break;
        case SIGNOUT:
            Command = Exit();
            if(Command == _EXIT)
            {
                OnlineFlag = LEAVE;
                mark_log(USER.username, _Signout);
                Command = CANCEL;
            }
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
            if(Command == FINDPASSWORD || Command == ADMINISTATOR)
                cmd = Command;
            break;
        case HELP:
            Help();
            break;
        case EXIT:
            Command = Exit();
            break;
        default:
            break;
        }

        if(cmd == FINDPASSWORD)
            FindPassword();
        if(cmd == ADMINISTATOR)
            Command = Administrator();
    }
    return Command;
}
