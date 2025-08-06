#include <stdio.h>
char*timeConversion(char*s){
    static char result[9];
    int hour =(s[0]-'0')*10+(s[1]-'0');
    
    if(s[8]=='A'){
        if(hour==12)
        hour=0;
    }
    else{
        if(hour!=12)
        hour+=12;
    }
    sprintf(result,"%02d:%c%c:%c%c",hour,s[3],s[4],s[6],s[7]);
    return result;
    
}
int main(){
    char time[11];
    scanf("%s",time);
    printf("%s\n",timeConversion(time));
    return 0;
}
