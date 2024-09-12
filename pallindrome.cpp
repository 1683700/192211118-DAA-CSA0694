#include <stdio.h>
#include <string.h>
int is_palindrome(char *s, int start, int end) 
{
   if (start >= end) 
	{
        return 1;
    }
    if (s[start] != s[end]) 
	{
        return 0;
    }
    return is_palindrome(s, start + 1, end - 1);
}
int main() 
{
    char input_str[100];
    printf("Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin);
    input_str[strcspn(input_str, "\n")] = 0;
    
    int length = strlen(input_str);
    if (is_palindrome(input_str, 0, length - 1)) 
	{
        printf("'%s' is a palindrome.\n", input_str);
    } else 
	{
        printf("'%s' is not a palindrome.\n", input_str);
    }
    
    return 0;
}
