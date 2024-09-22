# include <stdio.h>


/**
 * @brief Get the substring in a text
 * 
 * @param pos Number of the first substring char in the text(The index of the first substring char + 1) 
 * @param len The length of the substring
 * @param i Null
 * @param string Text
 * @param substring The string that you want to extract from the text
 */
void getString(int pos, int len, int i, char string[], char substring[])
{
    while (i < len)
    {
        substring[i] = string[pos + i - 1];
        i++;
    }

    substring[i] = '\0';
}



int main()
{
    char txt[] = "Hello how are you doing today?";
    char myStr[10];

    getString(11, 3, 0, txt, myStr);

    printf("%s", myStr);


    return 0;
}




/*************************************************/
# include <stdio.h>
# include <string.h>


/**
 * @brief Concatenate two strings
 * 
 * @param str1 
 * @param str2 
 */
void concatenateString(char* str1, char* str2)
{
    int i;

    int j = strlen(str1);

    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[i + j] = str2[i];
    }

    str1[i + j] = '\0';
}



int main()
{
    char txt[] = "Hello how are you doing today?\n";
    char txt2[] = "Thanks I am doing great.";

    concatenateString(txt, txt2);

    printf("%s", txt);



    return 0;
}




/*****************************************/
# include <stdio.h>
# include <string.h>


/**
 * @brief If we have more than one space between two words in a text, only one space remains
 * 
 * @param str Text
 */
void deleteExcessSpaceInString(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
            --i;
        }
    }
}




int main()
{
    char txt[] = "Hello      how are      you    doing    today?\n";

    printf("%s", txt); //Output: Hello      how are      you    doing    today?


    deleteExcessSpaceInString(txt);

    printf("%s", txt); //Output: Hello how are you doing today?

    return 0;
}




/********************************/
# include <stdio.h>
# include <string.h>


/**
 * @brief Get the substring in a text
 * 
 * @param pos Number of the first substring char in the text(The index of the first substring char + 1) 
 * @param len The length of the substring
 * @param i Null
 * @param string Text
 * @param substring The string that you want to extract from the text
 */
void getString(int pos, int len, int i, char string[], char substring[])
{
    while (i < len)
    {
        substring[i] = string[pos + i - 1];
        i++;
    }

    substring[i] = '\0';
}



/**
 * @brief If we have more than one space between two words in a text, only one space remains
 * 
 * @param str Text
 */
void deleteExcessSpaceInString(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
            --i;
        }
    }
}



/**
 * @brief Delete substring in a text and put speace (suggestion: use deleteExcessSpaceInString after calling it,
 * in this function used getString function as can be seen)
 * 
 * @param str Text
 * @param subStr Substring that needs to be removed
 */
void deleteSubStr(char str[], char subStr[])
{
    int strLength = strlen(str);
    int subStrLength = strlen(subStr);

    for(int i = 0; i < strLength; i++)
    {
        if(str[i] == subStr[0])
        {
            char SubStrTaken[subStrLength];
            getString(i+1, subStrLength, 0, str, SubStrTaken);
            if(strcmp(subStr, SubStrTaken) == 0)
            {
                for(int j = i; j < i+subStrLength; j++)
                {
                    str[j] = ' ';
                }
            }
        }
    }
}



int main()
{
    char txt[] = "Hello how are you doing today?\n";

    printf("%s", txt); //Output: Hello how are you doing today?


    char subStr[] = "doing";
    deleteSubStr(txt, subStr);
    printf("%s", txt); //Output: Hello how are you       today?


    deleteExcessSpaceInString(txt);
    printf("%s", txt); //Output: Hello how are you today?

    return 0;
}




/*************************************************/
# include <stdio.h>
# include <string.h>


/**
 * @brief If we have more than one space between two words in a text, only one space remains
 * 
 * @param str Text
 */
void deleteExcessSpaceInString(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
            --i;
        }
    }
}



/**
 * @brief this function delete substring since index1 to index2 and put space (suggestion: use deleteExcessSpaceInString after calling it)
 * 
 * @param str 
 * @param indx1 
 * @param indx2 
 */
void deleteSubStrWithIndex(char str[], int indx1, int indx2)
{
    for(int i = indx1; i <= indx2; i++)
    {
        str[i] = ' ';
    }   
}



int main()
{
    char txt[] = "Hello how are you doing today?\n";

    printf("%s", txt); //Output: Hello how are you doing today?


    deleteSubStrWithIndex(txt, 17, 28);
    printf("%s", txt); //Output: Hello how are you            ?


    deleteExcessSpaceInString(txt);
    printf("%s", txt); //Output: Hello how are you ?

    return 0;
}