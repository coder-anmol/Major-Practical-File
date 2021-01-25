/**
 * @author [Coder Anmol]
 * @email [dev.anmolsharma@gmail.com]
 * @desc [this program implements recursion]
 */
#include <stdio.h>

// function to find factorial of a number using recursion 
int findFactorial(int number) {
    if (number == 1) {
        return 1;
    } else {
        return number * findFactorial(number - 1);
    }
}

int main() {
    int num;

    printf("\n\nEnter the number in order to find it's factorial: ");
    scanf("%d", &num);

    printf("\nFactorial of the number: %d is : %d\n\n", num, findFactorial(num));

    return 0;
}
