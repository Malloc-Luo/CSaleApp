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
    int Command = 0;
    system("cls");
    endline; newline;
    beginline; printf("ȷ���˳���"); newline;
    beginline; printf("$-> ȷ�� ->[1]"); newline;
    beginline; printf("$-> ȡ�� ->[2]"); newline;
    beginline; command_char();
    scanf("%d", &Command);

    cmd = Command;

    return cmd;
}

int Exit_callback(int cmd)
{
    int Command = 0;
    switch(cmd)
    {
        case CONFIRM:
            Command = _EXIT;
            break;
        case CANCEL:
            Command = CANCEL;
            break;
        default:
            break;
    }

    return Command;
}

