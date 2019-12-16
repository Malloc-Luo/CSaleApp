#include "Signin.h"

int Signin(void)
{
    int cmd = 0;

    Init_user_inf();

    cmd = Signin_windows(cmd);

    cmd = Signin_check_information(cmd);

    cmd = Signin_callback(cmd);

    return cmd;
}

/*用户信息*/
Def_User_Inf USER;


/*
 * 绘制登录界面并接收指令
 * return CANCEL         取消
 * return FORGETPASSWORD 忘记密码
 * return 0              成功登录
 */
int Signin_windows(int cmd)
{
    static int try_times = 0;
    FILE * userf;
    int name_flag = 0;
    int inf_flag = 0;
    int pass_flag = 0;
    char temp_password[20];
    char command;

    system("cls");
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~登录~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;

    do
    {
        beginline; printf("$-> 用户名：         $-> 取消 ->[1]"); newline;
        beginline; command_char();
        get_string(USER.username);
        name_flag = Check_Name(USER.username);
        if(name_flag == CANCEL || name_flag == ADMINISTATOR)
            return name_flag;

        if(name_flag == USERNAME_NOT_EXIST)
        {
            beginline; error_remind(name_flag); newline;
            beginline; command_char();
        }

    }while(name_flag == USERNAME_NOT_EXIST);

    //从文件中读取用户信息
    inf_flag = Get_user_inf(&USER);
    init_buff();

    if(inf_flag == CANCEL)
        return CANCEL;

    do
    {
        beginline; printf("$-> 密码:           $-> 取消     ->[1]"); newline;
        beginline; printf("                    $-> 忘记密码 ->[2]"); newline;
        beginline; command_char();
        get_password(temp_password);
        pass_flag = Check_Password(temp_password, USER.password);

        if(pass_flag == CANCEL || pass_flag == FINDPASSWORD)
            return pass_flag;
        if(pass_flag != 0)
        {
            beginline; error_remind(PASSWORD_ERROR); newline;
            try_times ++;
        }

        //尝试次数过多，提示找回密码
        if(try_times >=4)
        {
            try_times = 0;
            beginline; error_remind(TRY_TOOMANY); newline;
            beginline; printf("忘记密码？            $-> 取消      ->[1]"); newline;
            beginline; printf("                      $-> 找回密码  ->[2]"); newline;
            beginline; command_char();
            command = get_char();

            if(command == '2')
                return FINDPASSWORD;
            else
                return CANCEL;
        }

    }while(pass_flag != 0 );
    movie();
    USER.timeflag ++;

    if(USER.timeflag == 1)
        complate_information();

    mark_log(USER.username, _Signin);
    OnlineFlag = ONLINE;
    return 0;
}

int Signin_check_information(int cmd)
{
    if(cmd == CANCEL || cmd == FINDPASSWORD || cmd == ADMINISTATOR)
        return cmd;

    return 0;
}

int Signin_callback(int cmd)
{
    if(cmd == CANCEL || cmd == FINDPASSWORD || cmd == ADMINISTATOR)
        return cmd;

    return 0;
}

/*
 * 检查用户名是否存在
 * 不存在此用户 return USERNAME_NOT_EXIT
 * 取消         return CANCEL
 * 用户存在     return 0
 */
int Check_Name(char *name)
{
    int flag = 0;
    char filename[50] = "D:\\ALessionProject\\Users\\NEU";
    char type[] = ".user";
    FILE * fp;

    if(strcmp(name, "neu") == 0)
        return ADMINISTATOR;

    strcat(filename, name);
    strcat(filename, type);

    if((fp = fopen(filename, "r")) == NULL)
    {
        flag = USERNAME_NOT_EXIST;
    }
    else
        fclose(fp);

    if(strlen(name) == 1 && name[0] == '1')
        flag = CANCEL;

    return flag;
}

int Check_Password(char *input, char *trueone)
{
    int cmd = 0;
    if(strlen(input) == 1)
    {
        if(input[0] == '1')
            return CANCEL;
        if(input[0] == '2')
            return FINDPASSWORD;
    }

    cmd = strcmp(input, trueone);
    return cmd;
}

/*
 * 根据用户文件读取用户信息
 * 打开文件失败 return CANCEL
 * 读取成功     return 0
 *
 ****************************************/
int Get_user_inf(Def_User_Inf *userp)
{
    FILE * userf;
    char ch_pass, ch_ph, ch_email ,ch;

    char filename[50] = "D:\\ALessionProject\\Users\\NEU";
    char type[] = ".user";
    int i = 0;

    strcat(filename, userp->username);
    strcat(filename, type);

    if((userf = fopen(filename, "rb")) == NULL)
    {
        beginline; printf("打开用户文件出现未知错误，请联系管理员解决.."); newline;
        return CANCEL;
    }

    fread(userp->password, CHAR_SIZE, 20, userf);
    fread(userp->phone, CHAR_SIZE, 20, userf);
    fread(userp->email, CHAR_SIZE, 30, userf);
    fread(&userp->timeflag, INT_SIZE, 1, userf);
    fread(&userp->number, INT_SIZE, 1, userf);

    if(userp->timeflag >=1)
    {
        fread(userp->address.province, CHAR_SIZE, 30, userf);
        fread(userp->address.city, CHAR_SIZE, 30, userf);
        fread(userp->address.block, CHAR_SIZE, 30, userf);
        fread(userp->address.street, CHAR_SIZE, 30, userf);
    }

    fclose(userf);

    return 0;
}

void movie(void)
{
    int i = 0;
    CLS;
    endline; endline;
    for(i = 0;i<120;i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);
        if(i<20 || (i>40 && i<60) || (i>80 && i<100))
            putchar('/');
        if((i>=20 && i<=40) || (i>=60 && i<=80) || (i>=100 && i<=120))
            putchar(' ');
        Sleep(10);
    }
    endline;
    beginline; middle; printf("登录成功！");
    Sleep(1200);
    CLS;
}


void Init_user_inf(void)
{
    int i = 0;

    for(i = 0;i<20;i++)
    {
        USER.username[i] = '\0';
        USER.password[i] = '\0';
        USER.phone[i] = '\0';
    }

    for(i = 0;i<30;i++)
    {
        USER.email[i] = '\0';
        USER.address.province[i] = '\0';
        USER.address.city[i] = '\0';
        USER.address.block[i] = '\0';
        USER.address.street[i] = '0';
    }
}
