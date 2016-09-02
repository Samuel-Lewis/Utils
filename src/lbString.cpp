//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//

#include <string>
#include <vector>
#include <algorithm>

#include "../lunchbox.h"

// Split a string up by at least one delimeter string. Return it all in a vector of substrings
std::vector<std::string> lbString::split (std::string& sentString, std::string delim)
{
	// The vector to return with the sub strings
	std::vector<std::string> newStrings;

	// Store the sent string into a working string, so as not to mutate users string.
	std::string workingString = sentString;

	// Find the first delim
	std::size_t nextPos = workingString.find(delim);
	while(nextPos != std::string::npos)
	{
		// Get up to the found delim, and add to vector of sub strings
		newStrings.push_back(workingString.substr(0,nextPos));

		// Erase that phrase, so as to allow checking for next delim
		// This is why we have a workingString, so we don't erase users' sent string
		workingString.erase(0,nextPos+delim.length());

		nextPos = workingString.find(delim);
	}

	// Add the last value, where there are no more delims
	newStrings.push_back(workingString);

	return newStrings;
}


// Removes a given string from another given string.
void lbString::remove(std::string& sentString, std::string item)
{
	std::size_t nextPos = sentString.find(item);
	while(nextPos != std::string::npos)
	{
		// Keep removing the substring until it no longer exsists
		sentString.erase(nextPos,item.length());
		nextPos = sentString.find(item);
	}

}

// Make all chars in string upper case
void lbString::toUpper(std::string& sentString)
{
	for (unsigned i = 0; i < sentString.length(); i++)
	{
		sentString[i] = toupper(sentString[i]);
	}
}

// Make all chars in string lower case
void lbString::toLower(std::string& sentString)
{
	for (unsigned i = 0; i < sentString.length(); i++)
	{
		sentString[i] = tolower(sentString[i]);
	}
}

// Strip non alphabet characters
void lbString::getAlpha(std::string& sentString)
{
	std::string returnString = "";
	for (unsigned i = 0; i < sentString.length(); i++)
	{
		if (isalpha(sentString[i]))
		{
			returnString += sentString[i];
		}
	}

	sentString = returnString;
}

// Trims
void lbString::trim(std::string& sentString, std::string toTrim)
{
	// Trim leading whitespace or tabs
	sentString.erase(0, sentString.find_first_not_of(toTrim));

	// Trimp trailing whitespace or tabs
	std::reverse(sentString.begin(), sentString.end());
	sentString.erase(0, sentString.find_first_not_of(toTrim));
	std::reverse(sentString.begin(), sentString.end());
}

void lbString::trim(std::string& sentString)
{
	trim(sentString, " \t\n\r");
}
