#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

bool check_operator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '<' || ch == '>' || ch == '=' || ch == '/'){
        return true;
    }
    return false;

}

bool check_keyword(char* str){

   if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
                              !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool check_integer(char* str){
    int s,len = strlen(str);
    if(s==0){
        return false;
    }

    for(int s=0;s<len;s++){
       // printf("%c\n",str[s]);
        if(str[s] != '0' && str[s] != '1' &&  str[s] != '2' &&  str[s] != '3'
        &&  str[s] != '4' &&  str[s] != '5'&& str[s] != '6' &&  str[s] != '7' 
         &&  str[s] != '8' && str[s] != '9' || (str[s] == '-' && s>0)){
            return false;
        }

    }

    return true;


}

bool check_delimeter(char ch){
    if(ch == ' ' || ch == '-' || ch == '+' || ch == '*' || ch == '/' || 
       ch == '/' || ch == ',' || ch == ';' || ch == '>' ||ch == '<' || 
       ch == '=' || ch == '(' || ch == ')' ||ch == '[' || ch == ']' || ch == '{' || ch == '}'){
        return true;
       }
       return false;
}

bool check_Identifier(char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || check_delimeter(str[0]) == true){
            return false;
        }    
        return true;
}

bool check_real_number(char* str){
    int s,len = strlen(str);
    bool is_decimal = false;
    if(len == 0){
        return false;
    }

    for(s=0;s<len;s++){
        if ( str[s] != '0' && str[s] != '1' && str[s] != '2'
            && str[s] != '3' && str[s] != '4' && str[s] != '5'
            && str[s] != '6' && str[s] != '7' && str[s] != '8'
            && str[s] != '9' && str[s] != '.' || (str[s] == '-'&&s>0)){
                return false;
            }  
                if(str[s]=='.'){
                    is_decimal = true;
                }   
    }

    return is_decimal;
}

char* sub_string(char* str , int start,int end){
    int i ;
    char* sub_String = (char*)malloc(sizeof(char)*(end-start+2));
    for(i=start ;i<=end;i++){
        sub_String[i-start] = str[i];
    }

    sub_String[end-start+1] = '\0';
    return (sub_String);
    
}

void parsing(char* str , FILE *ptr){
    ptr = fopen("output.txt","a");
    int start = 0, end = 0;
    int len = strlen(str);

    while(end<=len && start<=end){
        if(check_delimeter(str[end])==false){
            end++;
        }

        if(check_delimeter(str[end])==true && start == end){
            if(check_operator(str[end]) == true){
                  fprintf(ptr,"%s","------------------------------------\n");  
                fprintf(ptr,"%s","|     %c     |        OPERATOR      |\n",str[end]);
            }

            end++;
            start = end;
        }

else if (check_delimeter(str[end]) == true && start != end
                   || (end == len &&  start != end)) {
            char* subStr = sub_string(str, start, end - 1);
          //  printf("%s\n",subStr);
 
            if (check_keyword(subStr) == true){
                 fprintf(ptr,"%s","------------------------------------\n");  
                fprintf(ptr,"%s","|  '%s'   |         KEYWORD       |\n", subStr);
            }

            else if (check_Identifier(subStr) == true && check_delimeter(str[end - 1]) == false){
                 fprintf(ptr,"%s","------------------------------------\n");  
                fprintf(ptr,"%s","|   '%s'    |  VALID IDENTIFIER     |\n", subStr);
            }
 
            else if (check_Identifier(subStr) == false && check_delimeter(str[end - 1]) == false){
                 fprintf(ptr,"%s","------------------------------------\n");   
                fprintf(ptr,"%s","|   '%s'    | NOT VALID IDENTIFIER|\n", subStr);
            }
                
 
            else if (check_integer(subStr) == true){
                  fprintf(ptr,"%s","------------------------------------\n");  
                fprintf(ptr,"%s","|   '%s'    |         INTEGER          |\n", subStr);
            }
 
            else if (check_real_number(subStr) == true){
                 fprintf(ptr,"%s","------------------------------------\n");  
                   fprintf(ptr,"%s","|    '%s'    |         REAL NUMBER       |\n", subStr);
            }

                
 

            start = end;
        }
    }
    fprintf(ptr,"%s","------------------------------------\n");    
    return;



}


 int main()
{
    FILE *ptr = NULL;
    clock_t start_time, end_time;
    double total_time;
    start_time = clock();
    char str[100] = "int a = 2_2;";
    ptr = fopen("output.txt","w");
    fprintf(ptr,"%s","Lexical Analyzer\n");
    fclose(ptr);
    parsing(str , ptr);
    end_time = clock();
    total_time = ((double) (end_time - start_time));
    printf("Time Used by CPU to Generate token is : %f seconds\n", total_time);
 
    return (0);
}




