#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 10
typedef struct
{
    int Number;
    char Description[30];
    char Supplier[20];
    float Price;
    int Quantity;
    int Order;
} part;

int main()
{
    part A_Parts[Max];
    FILE* infile = fopen("parts.txt","r");
    int Size = 0;
    while(fscanf(infile, "%d %s %s %f %d %d", &A_Parts[Size].Number, A_Parts[Size].Description, A_Parts[Size].Supplier, &A_Parts[Size].Price, &A_Parts[Size].Quantity, &A_Parts[Size].Order) != EOF)
    {
        Size++;
        if(Size == Max)
            break;
    }
    printf("Part Number\tPart Description\tSupplier\t  Price    \tQuantity On Hand\tOrder Limit\n");
    printf("------------\t----------------\t--------\t  -----    \t----------------\t-----------\n\n");
    for(int i = 0 ; i < Size; i++)
    {
        printf("\n    %d\t    %s\t        %s\t%f\t\t%d\t\t    %d\n\n", A_Parts[i].Number, A_Parts[i].Description, A_Parts[i].Supplier, A_Parts[i].Price, A_Parts[i].Quantity, A_Parts[i].Order);
        if(A_Parts[i].Quantity < A_Parts[i].Order)
            printf("\t\t\tThe Store Must Order Additional Parts From This Auto Part!\n");
        printf("************************************************************************************************************\n");
    }
    fclose(infile);
    return 0;
}
