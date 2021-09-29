#include <errno.h>
extern int errno;
struct school
{
    // A,B,C,D,E,F
    char group;
    // Matituno (M) o Vespertino (V)
    char turn;
};
struct student
{
    char *name;
    // A+, A, A-, B+, B, B-, C
    char *grade;
    int age;
    struct school s;
};
