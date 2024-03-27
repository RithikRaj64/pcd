#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c, i=0, j=0, z;
char st[15], in[15], ac[15];

void chek() {
    for(z=0; z<c; z++) {
        if(st[z] == '4') {
            st[z] = 'E';
            st[z+1]='\0';
            printf("$%s\t%s$\t", st, in);
            printf("Reduce to E->4");
        }
    }
    for(z=0; z<c-2; z++) {
        if(st[z] == '2' && st[z+1] == 'E' && st[z+2] == '2') {
            st[z] = 'E';
            st[z+1]='\0';
            st[z+2]='\0';
            i = i-2;
            printf("$%s\t%s$\t", st, in);
            printf("Reduce to E->2E2");
        }
    }
    for(z=0; z<c-2; z++) {
        if(st[z] == '3' && st[z+1] == 'E' && st[z+2] == '3') {
            st[z] = 'E';
            st[z+1]='\0';
            st[z+2]='\0';
            i = i-2;
            printf("$%s\t%s$\t", st, in);
            printf("Reduce to E->3E3");
        }
    }
}

void main() {
    printf("The grammar is : \nE->2E2\nE->3E3\nE->4\n\nEnter input string : ");
    scanf("%s", in);
    c = strlen(in);
    
    printf("\n\nstack\tinput\taction\n");
    printf("$\t%s$\t", in);
    strcpy(ac, "SHIFT");
    
    for(i=0; j<c; i++, j++) {
        printf("%s\n", ac);
        st[i] = in[j];
        st[i+1] = '\0';
        in[j] = ' ';
        chek();
        printf("\n$%s\t%s$\t", st, in);
    }
    chek();
    
    if(st[0] == 'E' && st[1] == '\0') {
        printf("Accepted");
    }
    else {
        printf("Not Accepted");
    }
}