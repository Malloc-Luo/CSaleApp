#include "Signin.h"

int Signin(void)
{
    int cmd = 0;

    cmd = Signin_windows(cmd);

    cmd = Signin_check_information(cmd);

    cmd = Signin_callback(cmd);

    return cmd;
}


/*
 * ���Ƶ�¼���沢����ָ��
 * return CANCEL ȡ��
 * return FORGETPASSWORD ��������
 * return 0 �ɹ���¼
 */
int Signin_windows(int cmd)
{
    static int try_times = 0;
    Def_User_Inf user;
    FILE * userf;
    int name_flag = 0;
    int inf_flag = 0;
    int pass_flag = 0;
    char temp_password[20];
    char command;

    system("cls");
    endline; endline; newline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��¼~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;

    do
    {
        beginline; printf("$-> �û�����         $-> ȡ�� ->[1]"); newline;
        beginline; command_char();
        get_string(user.username);
        name_flag = Check_Name(user.username);
        if(name_flag == CANCEL)
            return CANCEL;

        if(name_flag == USERNAME_NOT_EXIST)
        {
            beginline; error_remind(name_flag); newline;
            beginline; command_char();
        }

    }while(name_flag == USERNAME_NOT_EXIST);

    //���ļ��ж�ȡ�û���Ϣ
    inf_flag = Get_user_inf(&user);

    if(inf_flag == CANCEL)
        return CANCEL;

 //   get_string(temp_password);

    do
    {
        beginline; printf("$-> ����:           $-> ȡ��     ->[1]"); newline;
        beginline; printf("                    $-> �������� ->[2]"); newline;
        beginline; command_char();
        get_string(temp_password);
        pass_flag = Check_Password(temp_password, user.password);
        if(pass_flag == CANCEL)
            return CANCEL;
        if(pass_flag != 0)
        {
            beginline; error_remind(PASSWORD_ERROR); newline;
            try_times ++;
        }

        //���Դ������࣬��ʾ�һ�����
        if(try_times >=4)
        {
            beginline; error_remind(TRY_TOOMANY); newline;
            beginline; printf("�������룿            $-> ȡ��      ->[1]"); newline;
            beginline; printf("                      $-> �һ�����  ->[2]"); newline;
            beginline; command_char();
            command = get_char();

            switch(command)
            {
                try_times = 0;
                case '1':
                    return CANCEL;
                case '2':
                    return FINDPASSWORD;
                default:
                    return CANCEL;
                    break;
            }
        }

    }while(pass_flag != 0 );

    OnlineFlag = ONLINE;
    return 0;
}

int Signin_check_information(int cmd)
{
    if(cmd == CANCEL)
        return CANCEL;

    return 0;
}

int Signin_callback(int cmd)
{
    if(cmd == CANCEL)
        return CANCEL;
    if(cmd == FINDPASSWORD)
        return FINDPASSWORD;

    return 0;
}

/*
 * ����û����Ƿ����
 * �����ڴ��û� return USERNAME_NOT_EXIT
 * ȡ��         return CANCEL
 * �û�����     return 0
 */
int Check_Name(char *name)
{
    int flag = 0;
    char filename[50] = "userinformation\\NEU";
    char type[] = ".user";
    FILE * fp;

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
    if(strlen(input) == 1 && input[0] == '1')
        return CANCEL;

    cmd = strcmp(input, trueone);
    return cmd;
}

/*
 * �����û��ļ���ȡ�û���Ϣ
 * ���ļ�ʧ�� return CANCEL
 * ��ȡ�ɹ�     return 0
 *
 ****************************************/
int Get_user_inf(Def_User_Inf *userp)
{
    FILE * userf;
    char ch_pass, ch_ph, ch_email ,ch;

    char filename[50] = "userinformation\\NEU";
    char type[] = ".user";
    int i = 0;

    strcat(filename, userp->username);
    strcat(filename, type);

    if((userf = fopen(filename, "r")) == NULL)
    {
        beginline; printf("���û��ļ�����δ֪��������ϵ����Ա���.."); newline;
        return CANCEL;
    }

    i = 0;
    while((ch_pass = fgetc(userf)) != '+')
    {
        userp->password[i] = ch_pass;
        i++;
    }
    userp->passwordLen = strlen(userp->password);

    puts(userp->password);

    i = 0;
    while((ch_ph = fgetc(userf)) != '+')
    {
        userp->phone[i] = ch_ph;
        i ++;
    }
    userp->phoneLen = strlen(userp->phone);

    puts(userp->phone);

    i = 0;
    while((ch_email = fgetc(userf)) != '+')
    {
        userp->email[i] = ch_email;
        i ++;
    }
    userp->emailLen = strlen(userp->email);

    puts(userp->email);

    while((ch = fgetc(userf)) != '+')
    {
        userp->timeflag = ch;
    }

    putchar(userp->timeflag);

    fclose(userf);

    return 0;
}


