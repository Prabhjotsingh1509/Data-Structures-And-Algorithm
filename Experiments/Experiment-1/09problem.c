//  Wap to demonstrate a structure?
#include <stdio.h>
struct students
{
    char name[30];
    int SAPID;
    char course[50];
};
int main()
{
    struct students std;

    printf("Enter the name:");
    fgets(std.name, 30, stdin);
    printf("Enter Sap-Id");
    scanf("%d", &std.SAPID);
    printf("Enter the course");
    fgets(std.course, 30, stdin);

    printf("Enter the name:%s", std.name);
    printf("Enter Sap-Id:%d\n", std.SAPID);
    printf("Enter the course:%s", std.course);
}