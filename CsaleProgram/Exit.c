#include "Exit.h"

int Exit(void)
{
    int cmd = 0;

    cmd = Exit_windows(cmd);
    cmd = Exit_callback(cmd);

    return cmd;
}

int Exit_windows(int cmd)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    int Command = 0;
    system("cls");
    endline; newline;
    if(OnlineFlag == ONLINE)
    {
        beginline; printf("注销登录？"); newline;
    }
    else
    {
        beginline; printf("确认退出？"); newline;
    }
    beginline; printf("$-> 确认 ->[1]"); newline;
    beginline; printf("$-> 取消 ->[2]"); newline;
    beginline; command_char();
    scanf("%d", &Command);

    cmd = Command;

    return cmd;
}

int Exit_callback(int cmd)
{
    if(cmd == 1)
        return _EXIT;
    else
        return CANCEL;

    return 0;
}

