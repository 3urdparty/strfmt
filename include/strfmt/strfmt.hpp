#ifndef STRFMT_HPP
#define STRFMT_HPP

#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

/// @brief splits a string based on a delimiter
/// @param str the string to split
/// @param delimiter the delimiter to split the string by
/// @return the vector of strings after splitting is complete
/// @MubarakAhmad0
vector<string> splitString(string str, char delimiter);

/// @brief compares two strings and returns true if they are the same, false if not
/// @param str1 the first string to compare
/// @param str2 the second string to compare
/// @return boolean representing wether they are the same or not
bool cmpstr(string str1, string str2);

/// @brief joins a vector of strings based on a delimiter
/// @param strings the vector of strings to be joined
/// @param delimiter the delimiter to join them by
/// @return the string after joining them
string join(vector<string>& strings, string delimiter);

/// @brief converts a vector of float
/// @param values vector of floats
/// @return a list of words
vector<string> convertToStrings(vector<float>& values);


/// @brief converst a list of strings to floats
/// @param strings list of strings to convert
/// @return list of floats
vector<float> convertToFloats(vector<string>& strings);

/// @brief converts a list of integers to a list of strings
/// @param numbers list of numbers
/// @return list of strings
vector<string> convertToStrings(vector<int> numbers);

/// @brief converts list of strings to list of integer
/// @param strings list of strings to convert to integer
/// @return the converted list of integers
vector<int> convertToInts(vector<string> strings);

/// @brief list of vectors
/// @param str string to check
/// @return returns true if the string can be converted to float
bool stringIsFloat(string str);

/// @brief removes trailing and leading spaces in the string
/// @param str the string to sanitize
/// @return the santized string
string sanitizeString(string str);

/// @brief sanitizes a list of strings
/// @param strings list of strings
/// @return a list of sanitized strings
vector<string> sanitizeStrings(vector<string> strings);

/// @brief 
/// @param  
/// @param  
void parseCSV(vector<string>&, vector<vector<string> >&);
extern string clearfmt;
extern string bold;
string colorfmt(int fgcolor, int bgcolor = 0);

namespace bg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;
};  // namespace bg

namespace fg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;

};  // namespace fg

#endif

