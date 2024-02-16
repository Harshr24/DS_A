#include <stdio.h>

struct s1
{
    int id;
    char Name[10];
    float salary;
};

int main () {
    struct s1 emp[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Employee id : ");
        scanf("%d", &emp[i].id);

        printf("Enter Employee name : ");
        scanf("%s", emp[i].Name);

        printf("Enter Employee salary : ");
        scanf("%f", &emp[i].salary);
    }

    return 0;
}
