#ifndef __LOG_H__
#define __LOG_H__
#include "AllFiles.h"

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int mini;
    int sec;
}TIME;

typedef enum
{
    _Login,
    _Signin,
    _Signout,
    Change_name,
    Change_password,
    Reset_password,
    Change_information
}ACTION;

extern time_t Now;
extern struct tm * Time_Now;
extern TIME Now_Time;

int mark_log(char * name, ACTION action);

void open_user_log(char *name);

int Get_current_time(void);

#endif // __LOG_H__


