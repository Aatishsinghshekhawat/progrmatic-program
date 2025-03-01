#include <stdio.h>
 #include <string.h>
 
 void sort(char str[]);
 int main(){
     
     
     char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    sort(str1);
    sort(str2);

    if (strcmp(str1,str2)== 0 )
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    else
        printf("\"%s\" and \"%s\" are not anagrams.\n", str1, str2);
     return 0;
 }

void sort(char str[] ){
    int i,j,temp;
    int len = strlen(str);
    
    for(i=0;i<len; i++){
        for(j=0;j<len; j++){
            if( str[i]< str[j]){
                
                temp = str[i];
                str[i] = str[j];
                str[j]= temp;
            }
        }
    }
}
