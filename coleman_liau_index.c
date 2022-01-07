#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau_index(int letter_count, int word_count, int sentence_count);


int main(void)

{
    // prompts user for a string and sets to var text type string
    string text = get_string("Text:");

    // calls count_letters func and passes in var text. Stored funcs return value as an int in var letter_count
    int letter_count = count_letters(text);



    // calls count_word func and passes in var text. Stores func return value as an int var called word_count
    int word_count = count_words(text);


    // calls counts_sentences func ad passes in var text. Stores func return values as an int var called sentence_count
    int sentence_count = count_sentences(text);


    // calls the coleman_liau_index function and passes in the letter_count, word_count, and sentence_count as auguments. Saves to var int index
    int index = coleman_liau_index(letter_count, word_count, sentence_count);

    // if statement that prints out the correct grade level based on the index test
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }




}

// func that counts # of chars in passed in text
int count_letters(string text)
{
    // declare a var type int and sets to 0
    int letter_count = 0;

    // loop over each element in the passed in text, increases element by one each pass until text[i] is greater than the int value of the text length
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // checks if the lowercase element i in text is an alphabetic char
        if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
        {
            // increase letter count by one
            letter_count += 1;
        }
    }
    return letter_count;
}

// func that counts # of words in passed in text
int count_words(string text)
{
    // declare a var type int and set it equal to 0
    int word_count = 0 ;

    // loop over each element in the passed in text, increases element by one each pass until text[i] is greater than the int value of the text length
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // checks to see if the element i in text is a space, or the dec value 32
        if (text[i] == 32)
        {
            // increases var word_count by 1
            word_count ++;
        }
    }
    // returning var word_count + 1 to deal with the fact that text WILL NOT end with a space
    return word_count + 1;
}

// func that counts # of sentences in passed in text
int count_sentences(string text)
{
    // declare a var type int and set it equal to 0
    int sentences = 0;

    // loop over each element in the passed in text, increases element by one each pass until text[i] is greater than the int value of the text length
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // checks to see if text[i] is a ".", "!", "?"
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            // increase sentences var
            sentences++;
        }
    }
    return sentences;
}


// a func that takes in the three count arugments and calculates the index using Coleman-Liau Index Test
int coleman_liau_index(int letter_count, int word_count, int sentence_count)
{
    double l = (float) letter_count / word_count * 100;
    double s = (float) sentence_count / word_count * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    return index;
}
