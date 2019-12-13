#include "Login.h"

/*
 * ��¼ģ��
 */
int Login()
{
    User_Inf user;
    int cmd = 0;

    cmd = Login_windows(cmd, &user);

    cmd = Login_create_user_file(cmd, &user);

    cmd = Login_callback(cmd);

    return cmd;
}

/*
 * ����ע����沢����ָ��
 */
int Login_windows(int cmd, User_Inf * user_p)
{
    int flag = 0, temp_flag = 0, phone_flag = 0, mail_flag = 0;
    char temppassword[20];
    CLS;
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ע��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("���������ʼע��.."); newline;
    beginline; command_char();
    getch();
    fflush(stdin);
    CLS;

    while(1)
    {
        /*�û���*/
        do
        {
            beginline; printf("$-> �û�����         ($-> ȡ�� ->[1])"); newline;
            beginline; printf("    (���ȣ�6~20  �������ֺ���ĸ�������������)"); newline;
            beginline; command_char();
            get_string(user_p->username);
            flag = check_username_std(user_p->username);

            if(flag == USERNAME_DISABLE)
            {
                beginline; error_remind(flag); newline;
            }

            if(flag == USERNAME_EXIST)
            {
                beginline; error_remind(flag); newline;
            }

        }while(flag == USERNAME_DISABLE || flag == USERNAME_EXIST);

        if(flag == CANCEL)
            break;

        /*����*/
        do
        {
            beginline; printf("$-> �������룺         ($-> ȡ�� ->[1])"); newline;
            beginline; printf("    (���ȣ�6~20  �������֡���ĸ�������ַ���@ # *���е������������"); newline;
            beginline; command_char();
            get_string(user_p->password);
            flag = check_password_std(user_p->password);

            if(flag == CANCEL)
                break;

            if(flag == PASSWORD_DISABLE)
            {
                beginline; error_remind(flag); newline;
            }
            /*ȷ������*/
            else
            {
                do
                {
                    beginline; printf("$-> ȷ�����룺        ($-> ȡ�� ->[1])"); newline;
                    beginline; command_char();
                    get_string(temppassword);
                    temp_flag = check_password_std(temppassword);
                    if(temp_flag == CANCEL)
                        break;
                    temp_flag = strcmp(temppassword, user_p->password);

                    if(temp_flag != 0)
                        temp_flag = PASSWORD_DIFFERENT;

                    if(temp_flag == PASSWORD_DIFFERENT)
                    {
                        beginline; error_remind(temp_flag); newline;
                    }

                }while(temp_flag == PASSWORD_DIFFERENT);
            }

        }while(flag == PASSWORD_DISABLE);

        if((flag == CANCEL) || (temp_flag == CANCEL))
            break;

        CLS;
        endline;
        beginline; printf("����д���绰���͡����䡿�����һ����룺"); newline;
        beginline; printf("$-> �绰 * ��          (������� $-> ȡ�� ->[1])"); newline;
        beginline; command_char();
        get_string(user_p->phone);
        phone_flag = check_phone(user_p->phone);
        if(phone_flag == CANCEL)
            break;

        beginline; printf("$-> ���䣺          ($-> ���� ->[1])"); newline;
        beginline; command_char();
        get_string(user_p->email);
        mail_flag = check_email(user_p->email);
        if(mail_flag == PASS)
            break;

        break;
    }

    if(flag == CANCEL || temp_flag == CANCEL || phone_flag == CANCEL)
        return CANCEL;

    return 0;
}


/*
 *
 */
int Login_create_user_file(int cmd, User_Inf * user_p)
{
    FILE * userf = NULL;
    char filename[80] = "D:\\ALessionProject\\Users\\NEU";
    char type[] = ".user";
//    char username[20];
    char password[20];
    char phone[15];
    char email[30];
//    int flag = 0;
    int write_flag = 0;

    if(cmd == CANCEL)
        return CANCEL;

    //�ļ��� filename
    strcat(filename, user_p->username);
    strcat(filename, type);

    strcpy(password, user_p->password);
    strcpy(phone, user_p->phone);
    strcpy(email, user_p->email);

    userf = fopen(filename, "wb");
    //�����û�ʧ��
    if(userf == CREATE_ERROR)
    {
        CLS;
        endline;
        beginline; printf("�����û�ʧ�ܣ������������..."); newline;
        beginline; command_char();
        getch();
        return CANCEL;
    }

    write_flag = fwrite(password, CHAR_SIZE, 20, userf);
    write_flag = fwrite(phone, CHAR_SIZE, 20, userf);
    write_flag = fwrite(email, CHAR_SIZE, 30, userf);
    write_flag = fwrite("1", CHAR_SIZE, 1, userf);

    fclose(userf);

    return CREATE_SUCCESS;
}

int Login_callback(int cmd)
{
    if(cmd == CANCEL)
        return CANCEL;
    else
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
        endline; endline; newline;
        beginline; printf("ע��ɹ���  �����������..");
        getch();
    }

    return cmd;
}


/*
 * ����û����Ƿ���Ϲ淶
 * ���� return 0
 * ȡ�� return CANCEL
 * ���� return USERNAME_DISABLE
 */
int check_username_std(char *username)
{
    int flag = 0;
    int i=0;
    int len;
    int EN = 1;
//    int exit_flag = 0;
    char filename[50] = "D:\\ALessionProject\\Users\\NEU";
    char type[] = ".user";
    FILE * fp;

    len = strlen(username);
    strcat(filename, username);
    strcat(filename, type);

    if(len==1 && username[0]=='1')
    {
        flag = CANCEL;
        EN = 0;
    }

    if((len<6 || len>20) && EN)
    {
        flag = USERNAME_DISABLE;
        EN = 0;
    }

    if(EN)
    {
        for(i = 0; i<len; i++)
        {
            if(username[i]<'0' || (username[i]>'9' && username[i]<'A') || (username[i]>'Z' && username[i]<'a') || username[i]>'z')
            {
                flag = USERNAME_DISABLE;
                break;
            }
        }
    }

    if((fp = fopen(filename, "r")) != NULL)
    {
        flag = USERNAME_EXIST;
        fclose(fp);
    }

    return flag;
}


/*
 * ��������Ƿ���Ϲ淶
 * ���� return 0
 * ȡ�� return CANCEL
 * ���� return PASSWORD_DISABLE
 */
int check_password_std(char *password)
{
    int flag = 0;
    int i = 0;
    int len;
    int EN = 1;
    len = strlen(password);

    if(len == 1 && password[0] == '1')
    {
        flag = CANCEL;
        EN = 0;
    }

    if((len<6 || len>20) && EN)
    {
        flag = PASSWORD_DISABLE;
        EN = 0;
    }

    if(EN)
    {
        for(i = 0;i<len; i++)
        {
            if(password[i]<'0' || (password[i]>'9' && password[i]<'A') || (password[i]>'Z' && password[i]<'a') || password[i]>'z'
                && password[i] != '@' && password[i] != '#' && password[i] != '*')
            {
                flag = PASSWORD_DISABLE;
                break;
            }
        }
    }
    return flag;
}


/*
 * ���绰�淶
 * ȡ�� return CANCEL
 * ���� return 0
 */
int check_phone(char *phone)
{
    int flag = 0;
    int len = 0;

    len = strlen(phone);
    if(len == 1 && phone[0] == '1')
        flag = CANCEL;

    return flag;
}


/*
 * ����ʼ��淶
 * ���� return PASS
 * ���� return 0
 */
int check_email(char *email)
{
    int flag = 0;
    char Mymail[] = "2423049596@qq.com";

    if(email[0] == '1' && email[1] == '\0')
    {
        flag = PASS;
        strcpy(email, Mymail);
    }

    return flag;
}




