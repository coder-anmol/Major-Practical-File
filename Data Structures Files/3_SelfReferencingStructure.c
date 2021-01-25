/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [creation of self refrencing structure]
 */

#include <stdio.h>

typedef struct selfRefStruct {
    int a1;
    int a2;
    struct selfRefStruct *link;
} node;

int main() {
    node n1, n2;
    //  assigning values
    n1.a1 = 10;
    n1.a2 = 20;

    n2.a1 = 30;
    n2.a2 = 40;

    n1.link = &n2;    // linking

    printf("\nValue of a1 inside n1 = %d \n", n1.a1);
    printf("Value of a2 inside n1 = %d \n", n1.a2);

    printf("Value of a1 inside n1 = %d \n", n1.link->a1);
    printf("Value of a2 inside n1 = %d \n\n", n1.link->a2);

    return 0;
}
