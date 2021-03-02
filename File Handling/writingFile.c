#include <stdio.h>
#include <stdlib.h>

void insertNumberInFile(char fileName[], int number) {
    FILE *fptr;
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        printf("Error occured!!");
        exit(1);
    }
    fprintf(fptr, "Your Number is : %d", number);
    fclose(fptr);
}

void readTextFromFile(char fileName[]) {
    char fileData;
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("Error in opening File!!\n");
        exit(1);
    }
    printf("\n\nOutput from text file\n\n");
    while ((fileData = fgetc(fptr)) != EOF) {
        printf("%c", fileData);
    }
    printf("\n\n-----------------\n\n");
    fclose(fptr);
}

void writeBinaryFile(char fileName[],int data){
    FILE *fptr;
    fptr = fopen(fileName, "wb");
    if (fptr == NULL) {
        printf("Error in opening File!!\n");
        exit(3);
    }
    fwrite(&data, sizeof(data), 1, fptr);
    fclose(fptr);
}

void readBinaryFile(char fileName[]){
    int data;
    FILE *fptr;
    fptr = fopen(fileName, "rb");
    if (fptr == NULL) {
        printf("Error in opening File!!\n");
        exit(4);
    }
    fread(&data, sizeof(data), 1, fptr);
    printf("\n\nOutput from binary file\n\n");
    printf("Value is : %d \n\n", data);
    fclose(fptr);
}

int main(void) {
    int num;

    printf("\nEnter number you want to write into your file: ");
    scanf("%d", &num);

    insertNumberInFile("helloworld.txt", num);

    readTextFromFile("helloworld.txt");

    writeBinaryFile("firstBinary.bin", num);

    readBinaryFile("firstBinary.bin");

    return 0;
}
