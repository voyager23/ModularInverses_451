#include <stdio.h>
#include <stdlib.h> // strtol() function

void xgcd(long *result, long a, long b){
    long aa[2]={1,0}, bb[2]={0,1}, q;
    while(1) {
        q = a / b; a = a % b;
        aa[0] = aa[0] - q*aa[1];  bb[0] = bb[0] - q*bb[1];
        if (a == 0) {
            result[0] = b; result[1] = aa[1]; result[2] = bb[1];
            return;
        };
        q = b / a; b = b % a;
        aa[1] = aa[1] - q*aa[0];  bb[1] = bb[1] - q*bb[0];
        if (b == 0) {
            result[0] = a; result[1] = aa[0]; result[2] = bb[0];
            return;
        };
    };
}
 
int main(int argc, char** argv){
    long a, b, c[3];
    char *end;
    if(argc < 3) {printf("Usage: %s a b  (compute xgcd(a,b))\n",argv[0]); exit(-1);};
    printf("long int is %lu bytes (or %lu bits)\n",sizeof(long),8*sizeof(long));
    a = strtol(argv[1], &end, 10);
    b = strtol(argv[2], &end, 10);
    printf("xgcd(%ld,%ld) = ",a,b);
    xgcd(c,a,b);
    printf("%ld = %ld*%ld + %ld*%ld\n",c[0],c[1],a,c[2],b);
return 0;
}
