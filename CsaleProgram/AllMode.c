#include "AllFiles.h"

/*
 * 获取字符串并清除缓冲区
 */

void get_string(char *data)
{
    fflush(stdin);
    gets(data);
    fflush(stdin);
}

/*
 * 读取一个字符并清空缓冲区
 */
char get_char(void)
{
    char ch;
    fflush(stdin);
    ch = getchar();
    fflush(stdin);

    return ch;
}

/*
 * 打印命令提示符
 */
void command_char(void)
{
    printf("$->  ");
}

/*
 * 错误提示
 */
void error_remind(int error_type)
{
    switch(error_type)
    {
        case NOCOMMAND:
            printf("！命令无效，请重新选择！");
            break;
        case USERNAME_DISABLE:
            printf("！用户名不可用，请按要求填写！");
            break;
        case USERNAME_EXIST:
            printf("！用户名不可用，该用户名已被使用，请重新填写！");
            break;
        case USERNAME_NOT_EXIST:
            printf("！用户不存在，请重新输入！");
            break;
        case PASSWORD_DISABLE:
            printf("！密码不可用，请按要求填写！");
            break;
        case PASSWORD_DIFFERENT:
            printf("！密码验证不符合，请重新输入！");
            break;
        case PASSWORD_ERROR:
            printf("！密码错误！");
            break;
        case TRY_TOOMANY:
            printf("尝试次数过多，请稍后重试..");
            break;
        default:
            break;
    }
}

int prepare_for_program(void)
{
    FILE * fp;
    if(_access("D:\\ALessionProject", 0) == -1)
    {
        Frist_time_to_use();
        _mkdir("D:\\ALessionProject");

        fp = fopen("D:\\ALessionProject\\readme.txt", "w");
        fputs("1 flag\n", fp);
        fputs("this is a test file, you can delete it now", fp);
        fprintf(fp, "\n\t李昱棋\n\t20184023\n\t自动化1803");

        fclose(fp);
    }

    if(_access("D:\\ALessionProject\\Users", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\Users");
    }

    if(_access("D:\\ALessionProject\\Manager", 0) == -1)
    {
         _mkdir("D:\\ALessionProject\\Manager");
    }
    return 0;
}


int Frist_time_to_use(void)
{
    endline;
    action_mode();
    endline; endline;
    beginline; printf("欢迎使用本购物系统\n"); newline;
    beginline; printf("须知："); newline;
    beginline; printf("用户信息将被储存于  d:\\ALessionProject\\Users 文件夹中\n");
    middle; middle; printf("用户文件 NEUusername.user"); newline;
    beginline; beginline; printf("任意键开始使用..");

    getch();
    system("cls");
}

int action_mode(void)
{
    int i = 0;
    for(i = 0;i<120;i++)
    {
        putchar('|');
        Sleep(10);
    }

    return 0;
}



