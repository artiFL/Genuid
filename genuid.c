#include "genuid.h"

static const char* exceptionSymbol = "DFGJMQV0";

static bool check_rules_gen(char* ch_src)
{
    for (int i = 0; i < 8; i++)
    {
        if (ch_src == exceptionSymbol[i])
        {
            return true;
        }
    }
    return false;
}

static bool check_input_correct_str(const char* str)
{
    size_t len = strlen(str);
    for (int x = 0; x < len; x++)
    {
        if (check_rules_gen(str[x]))
        {
            return true;
        }
    }
    return false;
}

int generate_uid_str(const char* str, char* result)
{
    if (str == NULL)
        return 1;
    int size = strlen(str);                 //Get size string
    if (size == 0)
        return 2;
    if (check_input_correct_str(str))
        return 3;


    int couter_up = 0;

    char* buff = (char*)malloc(size + 1);   //create conteain buffer

    strcpy(buff, str);
    buff[size - 1] ++;                      //create iteration on 1
    
    for (int i = size - 1; i >= 0;)         //glob iterator
    {
        for (int j = 0; j < 5;)             //parse duplet
        {
            if (buff[i - j] != '-')         
            {
                if ((buff[i - j] > '0' &&
                    buff[i - j] <= '9' + 1) ||
                    couter_up > 0)         //parse (char)number
                {
                    if (couter_up > 0)      
                    {
                        buff[i - j] ++;
                        couter_up--;
                    }
                    if (buff[i - j] > '9')
                    {
                        buff[i - j] = '1';
                        couter_up++;
                    }
                }
                j++;                        //increment on next char
                if ((buff[i - j] > 'A' &&
                    buff[i - j] <= 'Z' + 1)
                    || couter_up > 0)      //parse char
                {
                    if (couter_up > 0)                                        
                    {
                        do
                        {
                            buff[i - j] ++;
                        } while (check_rules_gen(buff[i - j])); //check rules exeption char
                        couter_up--;
                    }
                    if (buff[i - j] > 'Z')
                    {
                        buff[i - j] = 'A';
                        couter_up++;
                    }
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        i -= 5;
    }
    strcpy(result, buff);
    free(buff);

    return false;
}