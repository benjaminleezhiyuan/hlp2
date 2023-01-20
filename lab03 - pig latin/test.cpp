/*!*****************************************************************************
 \file q.cpp
 \author Seetoh Wei Tung
 \par DP email: seetoh.w\@digipen.edu
 \par Course: HLP2
 \par Section: A
 \par Programming Labatory #3
 \date 20-01-2023
 \brief
	This program simulates the constructed language game called Pig Latin. 
    This game applies a simple set of rules to convert an English word into
    Pig Latin so that people can speak an argot for fun.
*******************************************************************************/

/* Compile, Run and Compare
make test
*/

#include <string>

namespace //Helper functions
{
    //string containing all the vowels
    std::string vowels{"aeiouAEIOU"};

    //If y is not the first letter of the word, treat it as a vowel (rule .4)
    std::string rule4Vowels{"aeiouyAEIOUY"};

    /*!*****************************************************************************
     \brief 
     Checks a char (c) whether if it's a vowel and returns true or false.
     \param[in] c 
     \return true 
     \return false 
    *******************************************************************************/
    bool isVowel(char c)
    {
        //set the checking char to lowercase for simplicity
        c = std::tolower(c);
        //vowel.find(c) will return std::string::npos if the character can't be found.
        if (vowels.find(c) != std::string::npos)
            return true; //Vowel is found, return true.
        return false; //Else, return false.
    }

    /*!*****************************************************************************
     \brief 
     Checks a char (c) whether if it's a vowel or 'y' and returns true or false.
     \param[in] c 
     \return true 
     \return false 
    *******************************************************************************/
    bool isRule4Vowel(char c)
    {
        //set the checking char to lowercase for simplicity
        c = std::tolower(c);
        //vowel.find(c) will return std::string::npos if the character can't be found.
        if (rule4Vowels.find(c) != std::string::npos)
            return true; //Match is found, return true.
        return false; //Else, return false
    }
}

namespace hlp2
{
    /*!*****************************************************************************
     \brief 
     pig_latin applies a simple set of rules to convert an English word into
     Pig Latin. Rules are stated in comments within function. This function makes
     use of helper functions to identify vowels.
     \param[in,out] word 
     The string containing the word to convert to pig-latin
     \return std::string word 
    *******************************************************************************/
    std::string to_piglatin(std::string word) 
    {
/*
If the word starts with a vowel [and their upper case versions], the Pig Latin
version is the original word with suffix added at the end. Some examples:
*/

        //Checks if first letter is vowel.
        if (isVowel(word[0]))
            return word + "-yay";

        //Now we know for sure the first letter is a consonant already since the
        //function would've returned above.
        
/*
3. If a word contains no vowels, the Pig Latin version is the original word with suffix 
-way added to the end. 
*/ 
        //If there are no matches (no vowels), return original word with suffix -way
        if (word.find_first_of(rule4Vowels) == std::string::npos) //CAPITAL LETTER
            return word + "-way";

/*
2. If a word starts with a consonant, or a series of consecutive consonants, the Pig 
Latin version transfers all consonants up to the first vowel to the end of the word,
and adds suffix -ay to the end.

4. The letter y or Y should be treated as a consonant if it is the first letter of the 
word, otherwise, it is treated as a vowel.

5. If the English word is capitalized, the Pig Latin version of the word should be
capitalized in the first letter.
*/
        bool firstLetterWasCaps{false};
        // Check if the first letter of the word is capitalized
        if (std::isupper(word[0]))
        {
            //Convert the first letter to lowercase, as the first letter will
            //be shifted around. Keep track that this was originally an uppercase
            //word so that we can capitalize the new first letter after the word
            //have been shifted around.
            firstLetterWasCaps = true;
            word[0] = std::tolower(word[0]);
        }
        
        //Transfer all consonants up to the first vowel + y (rule .4) to the end of the word.
        do //Transfer the first letter first, because we know the first char is not a vowel
        {
            word += word[0]; //Append the first char to the last char of the word.
            word.erase(0,1); //Erase the first char of the word.
        }
        while (!isRule4Vowel(word[0])); //While the first char is not a vowel

        //Now that the transfer is done, we need to check if the word started with caps.
        if (firstLetterWasCaps)
            word[0] = std::toupper(word[0]); //Set the first letter to caps.

        //Return the final sliced up word with added suffix -ay to the end
        return word + "-ay";
    }
}