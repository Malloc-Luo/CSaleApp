#include "AllFiles.h"

//管理员
_Administ MainUser;


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
 * 错误提示，根据不同错误类型打印出提示
 * 参数：错误类型
 * 返回：void
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

/*
 * 准备程序，程序开始阶段运行，
 * 检查是否存在用户文件夹，若不存在则创建之
 * 加载管理员信息，为管理员模式做准备
 */
int prepare_for_program(void)
{
    FILE * fp;

    if(_access("D:\\ALessionProject", 0) == -1)
    {
        Frist_time_to_use();
        _mkdir("D:\\ALessionProject");

        fp = fopen("D:\\ALessionProject\\readme.txt", "w");
        fputs("\n", fp);
        fputs("\t this is a test file, you can delete it now\n", fp);
        fprintf(fp, "\n\t李昱棋\n\t20184023\n\t自动化1803\n");
        fprintf(fp, "\n\t最后果然没写完~");

        fclose(fp);
    }

    if(_access("D:\\ALessionProject\\Users", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\Users");
    }

    if(_access("D:\\ALessionProject\\UserLog", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\UserLog");
    }

    if(_access("D:\\ALessionProject\\Manager", 0) == -1)
    {
         _mkdir("D:\\ALessionProject\\Manager");

         fp = fopen("D:\\ALessionProject\\Manager\\readme.txt", "w");
         fprintf(fp, "\t\t什么是管理员模式？\n\t可以删除、修改商品信息，管理用户等");
         fprintf(fp, "\n\t进入管理员模式：输入特定账号与默认密码\n\t【账号：neu】【密码：123】 ");
         fclose(fp);

         MainUser.times = 0;
         MainUser.usernumber = 1;
         fp = fopen("D:\\ALessionProject\\Manager\\Administrator.administ", "wb");
         fwrite("123", CHAR_SIZE, 20, fp);
         fwrite(&MainUser.times, INT_SIZE, 1, fp);
         fwrite(&MainUser.usernumber, INT_SIZE, 1, fp);
         fclose(fp);

         fp = fopen("D:\\ALessionProject\\Manager\\AllUsers.neu", "ab+");
         fwrite("neu", CHAR_SIZE, 20, fp);
         fclose(fp);
    }

    //获取管理员信息
    strcpy(MainUser.username, "neu");
    fp = fopen("D:\\ALessionProject\\Manager\\Administrator.administ", "rb");
    fread(MainUser.password, CHAR_SIZE, 20, fp);
    fread(&MainUser.times, INT_SIZE, 1, fp);
    fread(&MainUser.usernumber, INT_SIZE, 1, fp);
    fclose(fp);

    return 0;
}


int Frist_time_to_use(void)
{
    endline;
    action_mode();
    endline; endline;
//    beginline; printf("-.-.-.-.-.-.-.-.-.-"); newline;
    beginline; printf("|欢迎使用本购物系统|\n"); newline;
//    beginline; printf("-.-.-.-.-.-.-.-.-.-"); newline;
    beginline; printf("须知："); newline;
    beginline; printf("用户信息将被储存于 d:\\ALessionProject\\Users 文件夹中\n"); newline;
    middle; middle; printf("用户文件 NEUusername.user"); newline;
    beginline; beginline; printf("任意键开始使用..");
    endline; endline;
    Sleep(1500);
    action_mode();
    getch();
    system("cls");
    Sleep(500);
}

int action_mode(void)
{
    int i = 0;
    for(i = 0;i<120;i++)
    {
        if(i%2)
            putchar('/');
        else
            putchar('\\');
        Sleep(10);
    }

    return 0;
}

void get_password(char *password)
{
    int i = 0;
    char buff;
    while((buff = getch()) != '\r')
    {
        fflush(stdin);
        if(buff == '\b')
        {
            i --;
            password[i] = '\0';
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
        else
        {
            password[i] = buff;
            putchar('*');
            i ++;
        }
    }
    password[i] = '\0';
}



