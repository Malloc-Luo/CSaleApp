#include "Help.h"

int Help(void)
{
    int cmd = 0;

    cmd = Help_windows(cmd);
    cmd = Help_callback(cmd);

    return 0;
}

int Help_windows(int cmd)
{
    system("cls");
    system("help.html");

    endline; newline;
    beginline; printf("按任意键返回.."); newline;
    beginline; command_char();
    getch();

    return cmd;
}

int Help_callback(int cmd)
{
    return cmd;
}
