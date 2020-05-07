//Written in C
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int letters(string A);
int words(string A);
int sentences(string A);

int main(void)
{

    string text = get_string("Text :");
    float L = letters(text);
    float S = sentences(text);
    float W = words(text);

    L = ((float)L / ( float)W) * 100;
    S = ((float)S / (float)W) * 100;

    float index =(float)((0.0588 *(float) L) - (0.296 *(float)S) - 15.8);

    index = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ( index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }

}

int letters(string A)
{
    int count=0;
    for (int i=0;A[i]!='\0';i++)
    {
        if (((A[i]>64) && (A[i]<91)) || ((A[i]>94) && (A[i]<123))){
            count++;
        }
    }
    //printf("%i \n",count);
    return count;
}

int words(string A)
{
    // number of words = number of spaces + 1
    int count=0;

    for(int i=0;A[i]!='\0';i++){
        if (A[i]==' '){
            count++;
        }
    }
    count++ ;
    //printf("%i \n",count);
    return count;
}

int sentences(string A)
{
    //occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    int count=0;
    for (int i=0;A[i]!='\0';i++){
        if ((A[i] == '.') || (A[i] == '!') || (A[i] == '?'))
        {
            count++;
        }
    }
    //printf("%i \n", count);
    return count;

}
