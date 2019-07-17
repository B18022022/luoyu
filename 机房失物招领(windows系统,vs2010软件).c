#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int s1_time() { //比较当地时间，如果是每月1号则返回1
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%d", localtime(&timep));

    if (strcmp(shijian, "01") == 0) {
        return 1;
    } else {
        return 0;
    }
}
int s_time() { //比较当地时间，如果是每星期一则返回1
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%A", localtime(&timep));

    if (strcmp(shijian, "Monday") == 0) {
        return 1;
    } else {
        return 0;
    }
}
int s2_time() { //比较当地时间，如果是每月1号且是周一则返回1
    time_t timep;
    char shijian1[20];
    char shijian2[20];
    time(&timep);
    strftime(shijian1, sizeof(shijian1), "%d", localtime(&timep));
    strftime(shijian2, sizeof(shijian2), "%A", localtime(&timep));

    if (strcmp(shijian2, "Monday") == 0 && strcmp(shijian1, "01") == 0) {
        return 1;
    } else {
        return 0;
    }
}
typedef struct { //建立用户结构体
    char account[10];
    char key[20];
} User;
typedef struct { //建立领取人结构体
    char name[20];
    char xuehao[20];
    char thing[20];
    char shoujihao[20];
    char time[30];
    char zhuangtai[20];
    char zhonglei[20];
    char didian[20];
} Student1;
typedef struct { //建立登记人结构体
    char didian[20];
    char name[20];
    char thing[20];
    char time[30];
    char zhuangtai[20];
    char zhonglei[20];
} Student;
char *showtime() { //返回当地时间
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%Y-%m-%d", localtime(&timep));
    return shijian;
}
int suo(int a) { //建立管理员锁
    if (a == 0) {
        printf("\n\n\t\t\t\t\t\t请输入管理员密码:");
        FILE *fp;
        int fr;
        char password[20];
        scanf("%s", password);
        User temp;
        fp = fopen("user.txt", "rb");

        while (1) {
            fr = fread(&temp, sizeof(User), 1, fp);

            if (fr == 0) {
                break;
            }

            if (strcmp(temp.account, "admin") == 0 && strcmp(temp.key, password) == 0) { //与管理员密码比较
                system("cls");
                printf("\n\t\t\t\t\t\t\t功能已授权\n");
                a = 1;
                fclose(fp);
                return 0;
            }
        }

        if (a == 0) {
            system("cls");
            printf("\n\t\t\t\t\t\t\t密码错误!");
            fclose(fp);
            return 1;
        }
    }

    return 0;
}
int nian(char str[]) { //将读取字符串的前4位返回为整型数字
    int i, num = 0;

    for (i = 0; i < 4; i++) {
        num = num * 10 + str[i] - '0';
    }

    return (num);
}
int yue(char str[]) { //将读取字符串的第6第7位返回为整型数字
    int i, num = 0;

    for (i = 5; i < 7; i++) {
        num = num * 10 + str[i] - '0';
    }

    return (num);
}
int ri(char str[]) { //将读取字符串的第9第10位返回为整型数字
    int i, num = 0;

    for (i = 8; i < 10; i++) {
        num = num * 10 + str[i] - '0';
    }

    return (num);
}
bool isLeapYear(int year) { //判断是否是闰年，是则返回true，不是则false
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int getDays(int year, int month, int day) { //从公年1年到传入年月日的所有天数
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        m[2]++;
    }

    int result = 0;

    for (int i = 1; i < year; i++) {
        result += 365;

        if (isLeapYear(i)) {
            result ++;
        }
    }

    for (int i = 1; i < month; i++) {
        result += m[i];
    }

    result += day;

    return result;
}
int dayDis(int year1, int month1, int day1, int year2, int month2, int day2) { //两个日期的天数差
    return abs(getDays(year2, month2, day2) - getDays(year1, month1, day1));
}
int build2(int q) { //建立前一周以及超过一年的未领文本
    int flag1 = 0;//判断文件内部是否为空值
    int flag2 = 0;//判断文件内部是否为空值

    if (suo(q)) {
        return 0;
    }

    char a[20];
    strcpy(a, showtime());
    FILE *fp, *fp1, *fp2;
    int fr;
    time_t timep;
    char shijian1[20];
    char shijian2[20];
    time(&timep);
    strftime(shijian1, sizeof(shijian1), "%Y-%m-%d--7.txt", localtime(&timep));
    strftime(shijian2, sizeof(shijian2), "%Y-%m-%d--365.txt", localtime(&timep));
    fp = fopen("time.txt", "rb");
    fp1 = fopen(shijian1, "w");
    fp2 = fopen(shijian2, "w");
    Student student;

    while (1) {
        fr = fread(&student, sizeof(Student), 1, fp);

        if (fr == 0) {
            break;
        }

        if (dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) <= 7 && dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) >= 1) {
            flag1 = 1;
            fprintf(fp1, "姓名:%s\t物品:%s\t种类:%s\t找到地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.didian, student.zhuangtai, student.time);
        }

        if (dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) > 365) {
            flag2 = 1;
            fprintf(fp2, "姓名:%s\t物品:%s\t种类:%s\t找到地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.didian, student.zhuangtai, student.time);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp);

    if (flag1 && flag2) {
        system("cls");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian1);
        printf("文本!\n");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian2);
        printf("文本!\n");
    } else if (flag1 == 1 && flag2 == 0) {
        system("cls");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian1);
        printf("文本!\n");
        remove(shijian2);//内部为空值删除则删除
        printf("\t\t\t\t\t\t\t没有超过一年未认领的物品!文件未建立!\n");

    } else if (flag1 == 0 && flag2 == 1) {
        system("cls");
        remove(shijian1);//内部为空值删除则删除
        printf("\t\t\t\t\t\t\t上周没有未认领的物品!文件未建立!\n");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian2);
        printf("文本!\n");
    } else {
        system("cls");
        remove(shijian1);//内部为空值删除则删除
        printf("\t\t\t\t\t\t\t上周没有未认领的物品!文件未建立!\n");
        remove(shijian2);//内部为空值删除则删除
        printf("\t\t\t\t\t\t\t没有超过一年未认领的物品!文件未建立!\n");
    }

    return 0;
}
int build(int q) { //建立前一周未领文本
    int flag = 0;//判断是否有内容

    if (suo(q)) {
        return 0;
    }

    char a[20];
    strcpy(a, showtime());
    FILE *fp, *fp1;
    int fr;
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%Y-%m-%d--7.txt", localtime(&timep));
    fp = fopen("time.txt", "rb");
    fp1 = fopen(shijian, "w");
    Student student;

    while (1) {
        fr = fread(&student, sizeof(Student), 1, fp);

        if (fr == 0) {
            break;
        }

        if (dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) <= 7 && dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) >= 1) {
            flag = 1;
            fprintf(fp1, "姓名:%s\t物品:%s\t种类:%s\t找到地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.didian, student.zhuangtai, student.time);
        }
    }

    fclose(fp1);
    fclose(fp);

    if (flag) {
        system("cls");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian);
        printf("文本!\n");
    } else {
        system("cls");
        remove(shijian);//内部为空值删除则删除
        printf("\t\t\t\t\t\t\t上周没有未认领的物品!文件未建立!\n");
    }

    return 0;
}
int build1(int q) { //建立超过一年未领的文本
    int flag = 0;//判断是否有内容

    if (suo(q)) {
        return 0;
    }

    char a[20];
    strcpy(a, showtime());
    FILE *fp, *fp1;
    int fr;
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%Y-%m-%d--365.txt", localtime(&timep));
    fp = fopen("time.txt", "rb");
    fp1 = fopen(shijian, "w");
    Student student;

    while (1) {
        fr = fread(&student, sizeof(Student), 1, fp);

        if (fr == 0) {
            break;
        }

        if (dayDis(nian(student.time), yue(student.time), ri(student.time), nian(a), yue(a), ri(a)) > 365) {
            flag = 1;
            fprintf(fp1, "姓名:%s\t物品:%s\t种类:%s\t找到地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.didian, student.zhuangtai, student.time);
        }
    }

    fclose(fp1);
    fclose(fp);

    if (flag) {
        system("cls");
        printf("\t\t\t\t\t\t\t已经建立");
        printf(shijian);
        printf("文本!\n");
    } else {
        system("cls");
        remove(shijian);//删除无内容文本
        printf("\t\t\t\t\t\t\t没有超过一年未认领的物品!文件未建立!\n");
    }

    return 0;
}
int input(int q) { //登记找到的物品，保存到二进制文本以及当天操作文本
    time_t timep;
    char shijian[20];
    time(&timep);
    strftime(shijian, sizeof(shijian), "%Y-%m-%d.txt", localtime(&timep));
    system("cls");

    if (suo(q)) {
        return 0;
    }

    Student student;
    FILE *fp, *fp1;
    printf("\n\t\t\t\t\t\t请输入姓名:");
    scanf("%s", student.name);
    printf("\n\t\t\t\t\t\t请输入物品:");
    scanf("%s", student.thing);
    printf("\n\t\t\t\t\t\t请输入种类:(存储设备、书籍、文具等)");
    scanf("%s", student.zhonglei);
    printf("\n\t\t\t\t\t\t请输入地点:");
    scanf("%s", student.didian);
    strcpy(student.zhuangtai, "未认领");
    strcpy(student.time, showtime());
    fp = fopen("time.txt", "ab+");
    fp1 = fopen(shijian, "a");
    fprintf(fp1, "姓名:%s\t物品:%s\t种类:%s\t找到地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.didian, student.zhuangtai, student.time);
    fwrite(&student, sizeof(Student), 1, fp);
    fclose(fp1);
    fclose(fp);
    system("cls");
    printf("\n\t\t\t\t\t\t信息已保存!");
    return 0;
}
int regist() { //注册，区分管理员和普通学生
    int flag = 1;
    system("cls");
    User user, temp;
    FILE *fp;
    int fr;
    printf("\n\n\t\t\t\t\t\t\t请输入账号：");
    //gets(user.account);
    scanf("%s", user.account);
    printf("\n\t\t\t\t\t\t\t请输入密码：");
    //gets(user.name);
    scanf("%s", user.key);

    //先检查数据库中有没有该用户
    fp = fopen("user.txt", "rb"); //以二进制的方式打开文本

    if (fp == NULL) {
        printf("\n\t\t\t\t\t\t\t文件打开失败！\n");
    }

    while (1) {
        fr = fread(&temp, sizeof(User), 1, fp);

        if (fr == 0) {
            break;
        }

        if (strcmp(temp.account, user.account) == 0) {
            printf("\n\t\t\t\t\t\t\t用户已经存在,请重新注册！\n");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    //存储数据
    fp = fopen("user.txt", "ab+");
    fwrite(&user, sizeof(User), 1, fp);
    fclose(fp);

    if (strcmp(user.account, "admin") == 0) {
        printf("\n\t\t\t\t\t\t\t管理员注册成功！\n");
    } else {
        printf("\n\t\t\t\t\t\t\t注册成功！\n");
    }

    return 0;
}
void read() { //读取未领文本
    system("cls");
    FILE *fp;
    int fr;
    Student student;
    fp = fopen("time.txt", "rb");

    while (1) {
        fr = fread(&student, sizeof(Student), 1, fp);

        if (fr == 0) {
            break;
        }

        printf("\n\n\t姓名:%s\t物品:%s\t找到地点:%s\t种类:%s\t认领状态:%s\t\t%s", student.name, student.thing, student.didian, student.zhonglei, student.zhuangtai, student.time);
    }

    fclose(fp);
}
void read1() { //读取已领文本
    system("cls");
    FILE *fp;
    int fr;
    Student1 student;
    fp = fopen("time1.txt", "rb");

    while (1) {
        fr = fread(&student, sizeof(Student1), 1, fp);

        if (fr == 0) {
            break;
        }

        printf("\n\n姓名:%s\t物品:%s\t种类:%s\t学号:%s\t手机号:%s\t丢失地点:%s\t认领状态:%s\t\t%s", student.name, student.thing, student.zhonglei, student.xuehao, student.shoujihao,
               student.didian, student.zhuangtai, student.time);
    }

    fclose(fp);
}
int read_user() { //读取账户和密码信息
    if (suo(0)) { //上锁
        return 0;
    }

    system("cls");
    FILE *fp;
    int fr;
    User temp;
    fp = fopen("user.txt", "rb");

    while (1) {
        fr = fread(&temp, sizeof(User), 1, fp);

        if (fr == 0) {
            break;
        }

        printf("\n\n\t\t\t\t\t\t\t%s\t%s\n", temp.account, temp.key);
    }

    fclose(fp);
    return 0;
}
void del(char thing[], char zhonglei[], char didian[], char time[]) { //删除已领的信息
    Student temp;
    FILE *fp, *ft;
    int fr;
    fp = fopen("time.txt", "rb");
    ft = fopen("linshi.txt", "wb+");//读写新建一个临时文件

    while (1) {
        fr = fread(&temp, sizeof(Student), 1, fp);

        if (fr == 0) {
            break;
        }

        if (strcmp(temp.thing, thing) != 0 || strcmp(temp.zhonglei, zhonglei) != 0 || strcmp(temp.didian, didian) != 0 || strcmp(temp.time, time) != 0) {
            fwrite(&temp, sizeof(Student), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);
    remove("time.txt");
    rename("linshi.txt", "time.txt");
}
int Find(int a, char b[], int q) { //查询物品信息
    char x[20];
    int f = 0;
    int i;
    int flag = 0;
    FILE *fp;
    int fr;
    Student temp;
    fp = fopen("time.txt", "rb");

    while (1) {
        fr = fread(&temp, sizeof(Student), 1, fp);

        if (a == 1) {
            strcpy(x, temp.time);
        } else if (a == 2) {
            strcpy(x, temp.thing);
        } else if (a == 3) {
            strcpy(x, temp.zhonglei);
        } else if (a == 4) {
            strcpy(x, temp.didian);
        }

        if (fr == 0) {
            break;
        } else if (strcmp(b, x) == 0) {
            printf("\n\t\t\t\t\t\t查询成功! 是否认领?\n");
            printf("\n\n\t\t\t名称:%s\t种类:%s\t地点:%s\t时间:%s\n", temp.thing, temp.zhonglei, temp.didian, temp.time);
            printf("\n\t\t\t\t\t\t请输入:0.继续 1.认领 ");
            scanf("%d", &i);

            while (i < 0 || i > 1) {
                printf("\n\t\t\t\t\t\t请重新输入!");
                scanf("%d", &i);
            }

            if (i) {
                flag = 1;

                if (suo(q)) { //上锁
                    return 0;
                }

                time_t timep;
                char shijian[20];
                time(&timep);
                strftime(shijian, sizeof(shijian), "%Y-%m-%d.txt", localtime(&timep));
                Student1 student;
                FILE *fp1, *fp2;
                printf("\n\t\t\t\t\t\t请输入姓名:");
                scanf("%s", student.name);
                printf("\n\t\t\t\t\t\t请输入学号:");
                scanf("%s", student.xuehao);
                printf("\n\t\t\t\t\t\t请输入手机号:");
                scanf("%s", student.shoujihao);
                strcpy(student.didian, temp.didian);
                strcpy(student.zhuangtai, "已认领");
                strcpy(student.thing, temp.thing);
                strcpy(student.time, showtime());
                strcpy(student.zhonglei, temp.zhonglei);
                fp2 = fopen(shijian, "a");
                fprintf(fp2, "姓名:%s\t物品:%s\t种类:%s\t学号:%s\t手机号:%s\t丢失地点:%s\t状态:%s\t时间:%s\n", student.name, student.thing, student.zhonglei, student.xuehao, student.shoujihao,
                        student.didian, student.zhuangtai, student.time);
                fp1 = fopen("time1.txt", "ab+");
                fwrite(&student, sizeof(Student1), 1, fp1);
                fclose(fp);
                del(temp.thing, temp.zhonglei, temp.didian, temp.time);
                fclose(fp1);
                fclose(fp2);
                system("cls");
                printf("\n\t\t\t\t\t\t信息已保存!");
            }
        }
    }

    if (flag == 0) {
        system("cls");
        printf("\n\t\t\t\t\t\t\t查询失败!\n");
    }

    fclose(fp);
    return 0;
}
void find_shijian(int q) { //查询物品时间
    system("cls");
    int a = 1;
    char shijian[20];
    printf("\n\t\t\t\t\t\t请输入要查询的物品日期(YYYY-mm-dd):");
    scanf("%s", shijian);
    Find(a, shijian, q);
}
void find_zhonglei(int q) { //查询物品种类
    system("cls");
    int a = 3;
    char zhonglei[20];
    printf("\n\t\t\t\t\t\t请输入要查询的物品种类:");
    scanf("%s", zhonglei);
    Find(a, zhonglei, q);
}
void find_thing(int q) { //查询物品名称
    system("cls");
    int a = 2;
    char thing[20];
    printf("\n\t\t\t\t\t\t请输入要查询的物品名称:");
    scanf("%s", thing);
    Find(a, thing, q);
}
void find_didian(int q) { //查询物品地点
    system("cls");
    int a = 4;
    char didian[20];
    printf("\n\t\t\t\t\t\t请输入要查询的物品丢失地点:");
    scanf("%s", didian);
    Find(a, didian, q);
}
void find(int q) { //根据选项选择查询方式
    system("cls");
    int flag = 0;
    int i;
    printf("\n\n\t\t\t\t\t\t**************************************\n");
    printf("\n\t\t\t\t\t\t请选择:\t\t\t\t\n");
    printf("\t\t\t\t\t\t0. 名称 1. 时间 2. 地点 3. 种类 4.返回\n");
    printf("\t\t\t\t\t\t**************************************\n\t\t\t\t\t\t");
    scanf("%d", &i);

    while (i < 0 || i > 4) {
        printf("\n\t\t\t\t\t\t请重新输入!");
        scanf("%d", &i);
    }

    while (1) {
        switch (i) {
        case 0:
            find_thing(q);
            break;

        case 1:
            find_shijian(q);
            break;

        case 2:
            find_didian(q);
            break;

        case 3:
            find_zhonglei(q);
            break;

        case 4:
            flag = 1;
            break;
        }

        if (flag) {
            system("cls");
            break;
        }

        printf("\n\n\t\t\t\t\t\t**************************************\n");
        printf("\n\t\t\t\t\t\t请选择:\t\t\t\t\n");
        printf("\t\t\t\t\t\t0. 名称 1. 时间 2. 地点 3. 种类 4.返回\n");
        printf("\t\t\t\t\t\t**************************************\n\t\t\t\t\t\t");
        scanf("%d", &i);

        while (i < 0 || i > 4) {
            printf("\n\t\t\t\t\t\t请重新输入!");
            scanf("%d", &i);
        }
    }
}
int sign() { //登陆系统
    system("cls");
    FILE *fp;
    int fr;
    User temp;
    char key[20];
    char account[10];
    printf("\n\n\t\t\t\t\t\t\t请输入账号:");
    scanf("%s", account);
    printf("\n\t\t\t\t\t\t\t请输入密码:");
    scanf("%s", key);
    fp = fopen("user.txt", "rb");

    while (1) {
        fr = fread(&temp, sizeof(User), 1, fp);

        if (fr == 0) {
            break;
        } else if (strcmp(temp.account, account) == 0 && strcmp(temp.key, key) == 0) {
            if (strcmp(account, "admin") == 0) {
                printf("\n\t\t\t\t\t\t\t管理员登陆成功\n");
                fclose(fp);
                return 2;
            } else {
                printf("\n\t\t\t\t\t\t\t登陆成功\n");
                fclose(fp);
                return 1;
            }
        }
    }

    printf("\n\t\t\t\t\t\t\t登陆失败\n");
    fclose(fp);
    return 0;
}
void sign1(int q) { //登陆后界面
    int m;
    int k;
    int flag1 = 0;
    printf("\n\n\t\t\t***********************************************************************************************************************\n");
    printf("\n\t\t\t请选择:\t\t\t\t\n");
    printf("\t\t\t 0. 登记 1. 查询 2. 物品时间排序 3.上周未领物品整理(每周一自动整理) 4.超一年未领物品整理(每月一号自动整理) 5.退出该账号\n");
    printf("\t\t\t***********************************************************************************************************************\n\t\t\t\t\t\t");
    scanf("%d", &k);

    while (k < 0 || k > 5) {
        printf("\n\t\t\t\t\t\t请重新输入!");
        scanf("%d", &k);
    }

    while (1) {
        switch (k) {
        case 0:
            input(q);
            break;

        case 1:
            find(q);
            break;

        case 2:
            if (1) {
                system("cls");
                printf("\n\n\t\t\t\t\t\t***********************************\n");
                printf("\n\t\t\t\t\t\t 请选择:\t\t\t\t\n");
                printf("\t\t\t\t\t\t 0. 未认领 1.已认领 2.返回上级 \n");
                printf("\t\t\t\t\t\t***********************************\n\t\t\t\t\t\t");
                int flag2 = 0;
                scanf("%d", &m);

                while (m < 0 || m > 2) {
                    printf("\n\t\t\t\t\t\t请重新输入!");
                    scanf("%d", &m);
                }

                while (1) {
                    switch (m) {
                    case 0:
                        read();
                        break;

                    case 1:
                        read1();
                        break;

                    case 2:
                        flag2 = 1;
                        break;
                    }

                    if (flag2) {
                        system("cls");
                        break;
                    }

                    printf("\n\n\t\t\t\t\t\t***********************************\n");
                    printf("\n\t\t\t\t\t\t 请选择:\t\t\t\t\n");
                    printf("\t\t\t\t\t\t 0. 未认领 1.已认领 2.返回上级 \n");
                    printf("\t\t\t\t\t\t***********************************\n\t\t\t\t\t\t");
                    scanf("%d", &m);

                    while (m < 0 || m > 2) {
                        printf("\n\t\t\t\t\t\t请重新输入!");
                        scanf("%d", &m);
                    }
                }
            }

            break;

        case 3:
            build(q);
            break;

        case 4:
            build1(q);
            break;

        case 5:
            flag1 = 1;
            break;
        }

        if (flag1) {
            system("cls");
            break;
        }

        printf("\n\n\t\t\t***********************************************************************************************************************\n");
        printf("\n\t\t\t请选择:\t\t\t\t\n");
        printf("\t\t\t 0. 登记 1. 查询 2. 物品时间排序 3.上周未领物品整理(每周一自动整理) 4.超一年未领物品整理(每月一号自动整理) 5.退出该账号\n");
        printf("\t\t\t***********************************************************************************************************************\n\t\t\t\t\t\t");
        scanf("%d", &k);

        while (k < 0 || k > 5) {
            printf("\n\t\t\t\t\t\t请重新输入!");
            scanf("%d", &k);
        }
    }
}
int main() {
    system("title 机房失物招领系统");
    system("color f4");
    int a;
    FILE *ap, *ap1, *ap2;
    ap = fopen("user.txt", "a"); //建立空文件
    ap1 = fopen("time.txt", "a"); //建立空文件
    ap2 = fopen("time1.txt", "a"); //建立空文件
    fclose(ap);
    fclose(ap1);
    fclose(ap2);

    if (s2_time()) { //判断是否为1号和周一
        build2(1);
    } else if (s1_time()) { //判断是否仅为1号
        build1(1);
    } else if (s_time()) { //判断是否仅为周一
        build(1);
    }

    int i;
    printf("\n\n\t\t\t\t\t\t**********************************************************************\n");
    printf("\n\t\t\t\t\t\t 请选择:\t\t\t\t\n");
    printf("\t\t\t\t\t\t 0. 登录 1. 注册(请先注册:admin(管理员)) 2. 查看用户账号和密码 3. 退出 \n");
    printf("\t\t\t\t\t\t**********************************************************************\n\t\t\t\t\t\t");
    scanf("%d", &i);

    while (i < 0 || i > 3) {
        printf("\n\t\t\t\t\t\t请重新输入!");
        scanf("%d", &i);
    }

    int temp = 0;

    while (1) {
        switch (i) {
        case 0:
            temp = sign();

            if (temp == 1) {
                a = 0;
                sign1(a);//普通用户权限
            } else if (temp == 2) {
                a = 1;
                sign1(a);//管理员权限
            }

            break;

        case 1:
            regist();
            break;

        case 2:
            read_user();
            break;

        default:
            return 0;
        }

        printf("\n\n\t\t\t\t\t\t**********************************************************************\n");
        printf("\n\t\t\t\t\t\t 请选择:\t\t\t\t\n");
        printf("\t\t\t\t\t\t 0. 登录 1. 注册(请先注册:admin(管理员)) 2. 查看用户账号和密码 3. 退出 \n");
        printf("\t\t\t\t\t\t**********************************************************************\n\t\t\t\t\t\t");
        scanf("%d", &i);

        while (i < 0 || i > 3) {
            printf("\n\t\t\t\t\t\t请重新输入!");
            scanf("%d", &i);
        }
    }

    return 0;
}
