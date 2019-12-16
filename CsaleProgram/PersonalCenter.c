#include "PersonalCenter.h"


int PersonalCenter(void)
{
    int cmd = 0;

    while(1)
    {
        cmd = PersonalCenter_windows(cmd);
        cmd = PersonalCenter_deal(cmd);
        cmd = PersonalCenter_callback(cmd);
        if(cmd == BACKWARD)
            break;
    }

    return cmd;
}



int PersonalCenter_windows(int cmd)
{
    CLS;
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~个人中心~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("$-> 修改个人信息   ->[0]"); newline;
    beginline; printf("$-> 管理购物车     ->[1]"); newline;
    beginline; printf("$-> 返回主页       ->[2]"); newline;
    beginline; command_char();

    scanf("%d", &cmd);

    return cmd;
}



int PersonalCenter_deal(int cmd)
{
    if(cmd == 0)
        return CHANGE_INF;
    if(cmd == 1)
        return SHOPPING;
    if(cmd == 2)
        return BACKWARD;

    return 0;
}



int PersonalCenter_callback(int cmd)
{
    if(cmd == CHANGE_INF)
        cmd = change_user_information();
    if(cmd == SHOPPING)
    {
        CLS;
        endline; endline; endline;
        beginline; printf("该功能尚未开放！"); newline;
        Sleep(1500);
    }
    if(cmd == BACKWARD)
        return BACKWARD;

    return 0;
}

User_Inf_Buff USER_Buff;



int complate_information(void)
{
    CLS;
    endline; endline; endline;
    beginline; middle; printf("完善地址信息(必填)"); newline;
    beginline; printf("&-> 省份:"); newline;
    beginline; command_char();
    get_string(USER.address.province);
    beginline; printf("&-> 城市:"); newline;
    beginline; command_char();
    get_string(USER.address.city);
    beginline; printf("&-> 区域:"); newline;
    beginline; command_char();
    get_string(USER.address.block);
    beginline; printf("&-> 街道:"); newline;
    beginline; command_char();
    get_string(USER.address.street);
    CLS;
    endline; endline; endline;
    beginline; middle; printf("完成！");
    Sleep(1200);
    CLS;

    return 0;
}

int change_user_information(void)
{
    int option = 0;
    int flag = 1;
    int change_pswd_flag = 0;
    int change_phone_flag = 0;
    int change_email_flag = 0;
    char name_buff[20];

    strcpy(name_buff, USER.username);

    init_buff();

    while(flag)
    {
        system("cls");
        print_information(); newline;
        beginline; printf("请选择修改项..      $-> 取消 ->[0]"); newline;
        beginline; printf("                    $-> 保存 ->[9]");
        beginline; command_char();
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            if(change_username() == CANCEL)
                return CANCEL;
            save_information(USER.username);
            break;
        case 2:
            change_pswd_flag = change_password();
            if(change_pswd_flag == CANCEL)
                return CANCEL;
            break;
        case 3:
            change_phone_flag = change_phone();
            if(change_phone_flag == CANCEL)
                return CANCEL;
            break;
        case 4:
            change_email_flag = change_email();
            if(change_email_flag == CANCEL)
                return CANCEL;
            break;
        case 9:
            flag = 0;
            save_information(USER.username);
            break;
        default:
            flag = 0;
            save_information(USER.username);
            break;
        }
        if(flag == 0)
            break;
    }

    return 0;
}




int print_information(void)
{
    system("cls");
    endline; endline;
    PRINT_LINE;
    beginline; putchar('|'); printf("c-> [1] 用户名：%s         ", USER.username);
    PRINT_LINE;
    beginline; putchar('|'); printf("c-> [2] 密码  ：******     ");
    PRINT_LINE;
    beginline; putchar('|'); printf("c-> [3] 电话  ：%c%c***         ", USER.phone[0], USER.phone[1]);
    PRINT_LINE;
    beginline; putchar('|'); printf("c-> [4] 邮箱  ：%c%c***         ", USER.email[0], USER.email[1]);
    PRINT_LINE;
    beginline; putchar('|'); printf("   地址  ：                   ");newline;
    beginline; putchar('|'); printf("c-> [5] 省份  ：%s         ", USER.address.province); newline;
    beginline; putchar('|'); printf("c-> [6] 城市  ：%s         ", USER.address.city); newline;
    beginline; putchar('|'); printf("c-> [7] 区域  ：%s         ", USER.address.block); newline;
    beginline; putchar('|'); printf("c-> [8] 街道  ：%s         ", USER.address.province);
    PRINT_LINE;
    beginline;

    return 0;
}



/*
 * 检查命令，正确返回 0  否则返回 1
 */
int check_command_personal(int cmd)
{
    int flag = 0;

    if(cmd != 0 && cmd != 1 && cmd != 2)
    {
        flag = 1;
        beginline; error_remind(NOCOMMAND); newline;
        beginline; command_char();
    }

    return flag ;
}


int init_buff(void)
{
    strcpy(USER_Buff.username, USER.username);
    strcpy(USER_Buff.password, USER.password);
    strcpy(USER_Buff.phone, USER.phone);
    strcpy(USER_Buff.email, USER.email);
    strcpy(USER_Buff.address.province, USER.address.province);
    strcpy(USER_Buff.address.city, USER.address.city);
    strcpy(USER_Buff.address.block, USER.address.block);
    strcpy(USER_Buff.address.street, USER.address.street);

    return 0;
}

/*
 * 将修改后的信息写入文件
 * 保存修改信息
 */
int save_information(char *name)
{
    FILE * fp = NULL;
   // FILE * defp;
    char filename[80] = "D:\\ALessionProject\\Users\\NEU";
    char oldfilename[80] = "D:\\ALessionProject\\Users\\NEU";

    char logfile[80] = "D:\\ALessionProject\\UserLog\\";
    char oldlogfile[80] = "D:\\ALessionProject\\UserLog\\";

    char type[] = ".user";
    char logtype[] = ".txt";

    int flag;
    strcat(filename, name);
    strcat(filename, type);

    strcat(logfile, name);
    strcat(logfile, logtype);

    if(strcmp(USER.username, USER_Buff.username) != 0)
    {
        strcat(oldfilename, USER_Buff.username);
        strcat(oldfilename, type);

        strcat(oldlogfile, USER_Buff.username);
        strcat(oldlogfile, logtype);

        rename(oldfilename, filename);
        rename(oldlogfile, logfile);
    }

    fp = fopen(filename, "wb");

    if(fp == NULL)
    {
        system("cls");
        endline; endline;
        beginline; printf("save failed !");
        return CANCEL;
    }
 //   flag = fwrite(USER.username, CHAR_SIZE, 20, fp);
    flag = fwrite(USER.password, CHAR_SIZE, 20, fp);
    flag = fwrite(USER.phone, CHAR_SIZE, 20, fp);
    flag = fwrite(USER.email, CHAR_SIZE, 30, fp);
    flag = fwrite(&USER.timeflag, INT_SIZE, 1, fp);
    flag = fwrite(&USER.number, INT_SIZE, 1, fp);
    flag = fwrite(USER.address.province, CHAR_SIZE, 30, fp);
    flag = fwrite(USER.address.city, CHAR_SIZE, 30, fp);
    flag = fwrite(USER.address.block, CHAR_SIZE, 30, fp);
    flag = fwrite(USER.address.street, CHAR_SIZE, 30, fp);

    fclose(fp);

    return 0;
}

int change_username(void)
{
    int flag = 0;
    char username_buff[20];
    FILE * fp;
    char filename[] = "D:\\ALessionProject\\Manager\\AllUsers.neu";
    beginline; printf("New username:               &-> Cancel ->[1]"); newline;
    while(1)
    {
        beginline; command_char();
        get_string(username_buff);
        flag = check_username_std(username_buff);
        if(flag == CANCEL)
            return CANCEL;
        if(flag == USERNAME_DISABLE || flag == USERNAME_EXIST)
        {
            beginline; error_remind(flag);
        }
        else
            break;
    }
    fp = fopen(filename, "rb+");
    fseek(fp, (CHAR_SIZE * 20 * (USER.number-1)), SEEK_SET);
    fwrite(username_buff, CHAR_SIZE, 20, fp);
    fclose(fp);
    mark_log(USER.username, Change_name);
    strcpy(USER.username, username_buff);

    return 0;
}

/*
 * 修改密码
 * return cancel 取消
 * return 0      修改成功
 */
int change_password(void)
{
    char password_buff[20];
    char number_buff[30];
    int flag1 = 0;
    int flag2 = 0;
    int passwordflag = 0;
    beginline; printf("Please enter your phone number or email to comfirm your identify");
    beginline; printf("Phone or Email:         $-> Cancel ->[1]"); newline;
    while(1)
    {
        beginline; command_char();
        get_string(number_buff);
        if(strlen(number_buff) == 1 && number_buff[0] == '1')
            return CANCEL;

        if(strcmp(number_buff, USER_Buff.email) == 0 || strcmp(number_buff, USER_Buff.phone) == 0)
        {
            flag1 = PASS;
            break;
        }
        else
        {
            beginline; printf("phone number or email error, please try again!    $-> Cancel ->[1]"); newline;
        }
    }

    if(flag1 == PASS)
    {
        while(1)
        {
            beginline; printf("Previous Password:             $-> Cancel ->[1]"); newline;
            beginline; command_char();
            get_password(password_buff);
            if(strlen(password_buff) == 1 && password_buff[0] == '1')
                return CANCEL;

            if(strcmp(password_buff, USER_Buff.password) == 0)
            {
                flag2 = PASS;
                break;
            }
            else
            {
                beginline; error_remind(PASSWORD_ERROR);
            }
        }
    }

    system("cls");
    endline; endline; endline;
    while(1)
    {
        beginline; printf("Enter new password:");
        beginline; command_char();
        get_password(USER.password);
        passwordflag = check_password_std(USER.password);
        if(passwordflag == PASSWORD_DISABLE)
        {
            beginline; error_remind(passwordflag);
        }

        if(passwordflag == CANCEL)
        {
            strcpy(USER.password, USER_Buff.password);
            return CANCEL;
        }
        else
            break;
    }
    system("cls");
    endline; endline; endline;
    beginline; printf("Change password successfully!");
    mark_log(USER.username, Change_password);
    getch();
    return 0;
}


int change_phone(void)
{
    char password_buff[20];
    beginline; printf("enter your password:         $-> Cancel ->[1]"); newline;
    while(1)
    {
        beginline; command_char();
        get_password(password_buff);
        if(strlen(password_buff) == 1 && password_buff[0] == '1')
            return CANCEL;

        if(strcmp(password_buff, USER.password) == 0)
        {
            beginline; printf("enter your new phone number:"); newline;
            beginline; command_char();
            get_string(USER.phone);
            break;
        }
        else
        {
            beginline; error_remind(PASSWORD_ERROR);
        }
    }
    mark_log(USER.username, Change_information);
    return 0;
}

int change_email(void)
{
    char password_buff[20];
    beginline; printf("enter your password:         $-> Cancel ->[1]"); newline;
    while(1)
    {
        beginline; command_char();
        get_password(password_buff);
        if(strlen(password_buff) == 1 && password_buff[0] == '1')
            return CANCEL;

        if(strcmp(password_buff, USER.password) == 0)
        {
            beginline; printf("enter your new email:"); newline;
            beginline; command_char();
            get_string(USER.email);
            break;
        }
        else
        {
            beginline; error_remind(PASSWORD_ERROR);
        }
    }
    mark_log(USER.username, Change_information);
    return 0;
}


void Init_user_inf_buff(void)
{
    int i = 0;
    USER_Buff.flag = 0;

    for(i = 0;i<20;i++)
    {
        USER_Buff.username[i] = '\0';
        USER_Buff.password[i] = '\0';
        USER_Buff.phone[i] = '\0';
    }

    for(i = 0;i<30;i++)
    {
        USER_Buff.email[i] = '\0';
        USER_Buff.address.province[i] = '\0';
        USER_Buff.address.city[i] = '\0';
        USER_Buff.address.block[i] = '\0';
        USER_Buff.address.street[i] = '0';
    }
}
