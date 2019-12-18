#include "UserLog.h"

time_t Now;
struct tm * Time_Now;
TIME Now_Time;


int mark_log(char * name, ACTION action)
{
    char filepath[] = "D:\\ALessionProject\\UserLog\\";
    char type[] = ".txt";
    FILE * fp = NULL;

    //获取时间
    Get_current_time();

    strcat(filepath, name);
    strcat(filepath, type);

    fp = fopen(filepath, "a+");

    if(USER.timeflag == 0)
        fprintf(fp, "\t%s的用户日志\n\n", name);

    if(action == _Login)
        fprintf(fp, "\t%d 注册        ", USER.timeflag);
    else if(action == _Signin)
        fprintf(fp, "\t%d 登录        ", USER.timeflag);
    else if(action == _Signout)
        fprintf(fp, "\t%d 注销登录    ", USER.timeflag);
    else if(action == Change_information)
        fprintf(fp, "\t%d 修改个人信息", USER.timeflag);
    else if(action == Change_name)
        fprintf(fp, "\t%d 修改名称    ", USER.timeflag);
    else if(action == Change_password)
        fprintf(fp, "\t%d 修改密码    ", USER.timeflag);
    else if(action == Reset_password)
        fprintf(fp, "\t%d 重置密码    ", USER.timeflag);

    fprintf(fp, "  %d-%d-%d %d:%d:%d\n", Now_Time.year, Now_Time.month, Now_Time.day, Now_Time.hour, Now_Time.mini, Now_Time.sec);

    fclose(fp);

    return 0;
}



void open_user_log(char *name)
{
    CLS;
    char filepath[80] = "D:\\ALessionProject\\UserLog\\";
    char type[] = ".txt";
    strcat(filepath, name);
    strcat(filepath, type);

    system(filepath);

    endline; endline; endline;
    beginline; printf("press anyone to continue..");
    beginline; command_char();
    getch();
}

int Get_current_time(void)
{
    time(&Now);
    Time_Now = localtime(&Now);

    Now_Time.year = Time_Now->tm_year + 1900;
    Now_Time.month = Time_Now->tm_mon + 1;
    Now_Time.day = Time_Now->tm_mday;
    Now_Time.hour = Time_Now->tm_hour;
    Now_Time.mini = Time_Now->tm_min;
    Now_Time.sec = Time_Now->tm_sec;

    return 0;
}






