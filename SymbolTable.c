#include <stdio.h>
#include <ctype.h>

int main() {
    char term;
    char ids[15][15];
    char ops[15];
    int nums[15];
    int i=0, idc=0, opc=0, numc=0;
    char c;
    
    printf("Enter the expression followed by the termination symbol : ");
    
    while((c = getchar()) != '$' && i<14) {
        if(isalpha(c)) {
            while(isalnum(c)) {
                ids[idc][i++] = c;
                c = getchar();
            }
            ungetc(c, stdin);
        }
        else if(isdigit(c)) {
            int num = 0;
            while(isdigit(c)) {
                num = (num * 10) + (c - '0');
                c = getchar();
            }
            ungetc(c, stdin);
            printf("Number -> %d\n", num);
            nums[numc++] = num;
        }
        else {
            if(i > 0) {
                ids[idc][i] = '\0';
                printf("Identifier -> %s\n", ids[idc]);
                i=0;
                idc++;
            }
            if(c != ' ') {
                ops[opc++] = c;
                printf("Operator -> %c\n", c);
            }
        }
    }
    
    if(i > 0) {
        ids[idc][i] = '\0';
        printf("Identifier -> %s\n", ids[idc]);
        i=0;
        idc++;
    }
    
    printf("\n=================================================\n");
    printf("                   Symbol Table                  \n");
    printf("=================================================\n");
    printf("    Symbol    |      Address     |      Type     \n");
    printf("=================================================\n");
    
    for(i=0; i<idc; i++) {
        printf("%-14s|  %p  | Identifier\n", ids[i], (void *)ids[i]);
    }
    
    for(i=0; i<numc; i++) {
        printf("%-14d|  %p  | Number\n", nums[i], (void *)&nums[i]);
    }
    
    for(i=0; i<opc; i++) {
        printf("%-14c|  %p  | Operator\n", ops[i], (void *)&ops[i]);
    }
    
    printf("=================================================\n");
    
    return 0;
}