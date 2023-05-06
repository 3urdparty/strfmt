
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#include "strfmt.hpp"

string sanitizeString(string str) {
  str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
  return str;
}

vector<string> sanitizeStrings(vector<string> strings) {
  // iterates through every string in strings
  for (int x = 0; x < strings.size(); x++) {
    // and uses the santizeString function on that string
    // and then assigning it to the sanitized string
    strings[x] = sanitizeString(strings[x]);
  }
  // returns the vector of strings
  return strings;
}

vector<string> splitString(string str, char delimiter) {
  // declare a vector of strings
  vector<string> strings;

  // declare a string to store
  string buffer;

  // Iterates through every character in the string
  for (int x = 0; x < str.length(); x++) {
    // if the string is the delimiter or the null byte..
    if (str[x] == delimiter | str[x] == '\0') {
      // we check the contents of buffer
      if (buffer == "") {
        // if its empty, we leave it as it is
      } else {
        // if not, then we add the contents of the buffer to strings
        strings.push_back(buffer);
        // and reset the buffer to ""
        buffer = "";
      }
    } else {
      // otherwise append the character to the buffer to form the word
      buffer += str[x];
    }
  }
  // due to the way we constructed this solution, the last word will stay in
  // buffer since its not followed by a spacce (usually) so we check that the
  // content of buffer is not "", and if thats true, we add the last word to
  // strings
  if (!cmpstr(buffer, "")) strings.push_back(buffer);

  // finally we return strings
  return strings;
}

bool cmpstr(string str1, string str2) {
  // compares the first string to the second string and returns true if the are
  // the same
  return str1.compare(str2) == 0;
};

vector<string> convertToStrings(vector<int> numbers) {
  // declare a vector of strings
  vector<string> strings;
  // for each number in numbers
  for (int num : numbers) {
    // we convert the number and add it to strings
    strings.push_back(to_string(num));
  };
  // we return strings
  return strings;
}

vector<int> convertToInts(vector<string> strings) {
  // for this function we assume that the list of strings passed to this
  // function are all strings that represent ints this is done in the main code
  // by using function stringIsFloat to ensure every string represents a number
  // we declare a vector of int
  vector<int> values;
  // we iterate through every string in strings
  for (string str : strings) {
    // we convert the string to integer and add it to values
    values.push_back(stoi(str));
  };
  // we return values
  return values;
}

vector<float> convertToFloats(vector<string>& strings) {
  // we declare a list of values
  vector<float> values;
  // iterates through every string in strings
  for (string str : strings) {
    // converts it to float and adds it values
    values.push_back(stof(str));
  };

  // we return valuesƒ
  return values;
}

vector<string> convertToStrings(vector<float>& values) {
  // declare list of strings
  vector<string> rawValues;

  // iterate through every value in values
  for (float val : values) {
    // for each value, we convert to value to string and add it to rawValues
    rawValues.push_back(to_string(val));
  };
  // we return the list of strings
  return rawValues;
}

string join(vector<string>& strings, string delimiter) {
  string output;

  // if the size of strings is 0
  if (strings.size() == 0) {
    // we just return the empty output
    return output;
  } else {
    // however, if it isnt
    // we iterate through every string in strings until just before the last
    // string
    for (int x = 0; x < strings.size() - 1; x++) {
      // we concaternate every string in strings and the delimiter with output
      output += strings[x] + delimiter;
    };
    // then we add the last string so we dont put the delimiter in front of it
    output += strings[strings.size() - 1];
    // then we return the output
    return output;
  }
};

bool stringIsFloat(string str) {
  // first we sanitize the string to get rid of trailing white spaces
  str = sanitizeString(str);

  // https://stackoverflow.com/a/447307/20904220
  // we declare a istringstream object
  istringstream iss(str);

  // we declare a float
  float f;

  // noskipws - regards whitespaces as valid
  // outputs the stream in iss through noskipws and then pipes it to float f
  iss >> noskipws >> f;

  // if iss is finished and an error hasnt happened, we know we can convert
  // string to float
  return iss.eof() && !iss.fail();
};

// https://stackoverflow.com/questions/447206/c-isfloat-function

namespace fg {
// all the codes for ANSII foreground colors
int black = 30;
int red = 31;
int green = 32;
int yellow = 33;
int blue = 34;
int magenta = 35;
int cyan = 36;
int white = 37;

};  // namespace fg

namespace bg {
// all the codes for ANSII background colors
int black = 40;
int red = 41;
int green = 42;
int yellow = 43;
int blue = 44;
int magenta = 45;
int cyan = 46;
int white = 47;

};  // namespace bg

// code for ANSII clear format encoding
string clearfmt = "\x1b[0m";

// code for ANSII bold text encoding
string bold = "\e[1m";

string colorfmt(int fgcolor, int bgcolor) {
  string fmt;

  // if the background color is not 0 (default value of bgColor, represents a
  // blank backbground)
  if (bgcolor == 0) {
    // we add a ANSII color encoding sequence escape that creates the designated
    // foreground color
    fmt += "\x1b[" + to_string(fgcolor) + "m";
  } else {
    // we add a ANSII color encoding sequence escape that creates the designated
    // foreground color and the background color
    fmt = "\x1b[" + to_string(fgcolor) + ";" + to_string(bgcolor) + "m";
  }

  // we return the formatting
  return fmt;
}