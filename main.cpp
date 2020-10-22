// Kolton Sumner
// CS225-01
// PP07 Word Letter Count
// 10/27/19
// This program calculates how many words and occurrences of each letter there are in a phrase.

//Input: input
//Const: N/A
//Formula: remove unnecessary characters
        //string to lowercase
        //count words
        //remove spaces
        //sort by alphabetical order
        //count occurrences of each letter and print

//Output: Number of words and occurrences of letters.

#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

int main()
{
    cout << "This program will analyze a given phrase and return some calculated data about it." << endl; //Inform user of program purpose

    regex word_regex("[^\\s]+"); //Prepare regex to identify words
    string input;
    cout << "Please enter a string to be analyzed:" << endl;
    getline(cin, input); //Get user input

    transform(input.begin(),input.end(),input.begin(),[](unsigned char c){ return std::tolower(c); }); //Lowercase entire string

    auto wBegin = sregex_iterator(input.begin(), input.end(), word_regex); //Create iterator of words from regex
    auto wEnd = sregex_iterator(); //Reference iterator

    cout << "The phrase contains " << distance(wBegin, wEnd) << " words." << endl; //Calc and print number of words in string

    input.erase(remove(input.begin(), input.end(), ' '), input.end()); //Remove unnecessary characters
    input.erase(remove(input.begin(), input.end(), ','), input.end());
    input.erase(remove(input.begin(), input.end(), '.'), input.end());
    sort(input.begin(),input.end()); //Sort string for counting

    cout << "Letters from the phrase: " << endl; //Nice output

    int counter = 1; //Character counter
    for(int i = 0; i < input.size(); i++){ //For loop to iterate once through the string while counting and printing character occurrences
        if(input[i] == input[i+1]){
            counter++;
        } else {
            cout << input[i] << ": " << counter << endl;
            counter = 1;
        }
    }

    return 0;
}
