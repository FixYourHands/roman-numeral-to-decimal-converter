// RomanNumeralv1.1.cpp : A program that converts Roman Numerals to Decimal Numbers
//

#include <iostream>
#include <string>
void checkRepeats(std::string const userWord);
void largerAfters(std::string const userWord);
void subFormat(std::string const userWord);
void returnValue(std::string const userWord);

//function that makes sure only valid Roman Numerals are entered
void checkValidChar(std::string const userWord)
{
	//comparative string to use against 'userWord'; checks for valid Roman Numerals
	std::string validChar = "IVXLCDM";
	//checks to see if the number of valid Roman Numerals matches userWord.length()
	int counter = 0;
	for (int i = 0; i < userWord.length(); i++)
	{
		//nested loop that goes through all chars in 'validChar' before moving to the next iteration of the main loop
		for (int j = 0; j < validChar.length(); j++)
		{
			if (userWord[i] == validChar[j])
			{
				counter++;
			}
		}
	}
	//prints the result of the loop
	if (counter == userWord.length())
	{
		std::cout << "All letters entered are valid Roman Numerals! \n";
		checkRepeats(userWord);
	}
	else
	{
		std::cout << "Invalid characters were entered! \n";
		return;
	}
}

//this function will go over repeating letters as well as letters that only appear once in any valid Roman Numeral - V,L, and D
void checkRepeats(std::string const userWord)
{

	//this loop makes sure that 'V, L, and D' only appear in the number 1 time each
	for (int i = 0; i < userWord.length(); i++)
	{
		//if the current letter is not the last letter and the current letter is 'V'...
		if (i < userWord.length() - 1 && userWord[i] == 'V')
		{
			//checks all letters after the current one...
			for (int j = i + 1; j < userWord.length(); j++)
			{
				if (userWord[j] == 'V')
				{
					std::cout << "You have more than one 'V' in your code! Fix yourself! \n";
					return;
				}
			}
		}
		//if the current letter is not the last letter and the current letter is 'L'...
		if (i < userWord.length() - 1 && userWord[i] == 'L')
		{
			//checks all letters after the current one...
			for (int j = i + 1; j < userWord.length(); j++)
			{
				if (userWord[j] == 'L')
				{
					std::cout << "You have more than one 'L' in your code! Fix yourself! \n";
					return;
				}
			}
		}
		//if the current letter is not the last letter and the current letter is 'D'...
		if (i < userWord.length() - 1 && userWord[i] == 'D')
		{
			//checks all letters after the current one...
			for (int j = i + 1; j < userWord.length(); j++)
			{
				if (userWord[j] == 'D')
				{
					std::cout << "You have more than one 'D' in your code! Fix yourself! \n";
					return;
				}
			}
		}
	}

	//stores how many times a letter appears consecutively
	int charCounter = 0;
	char checker = userWord[0];

	for (int i = 0; i < userWord.length(); i++)
	{
		if (checker == userWord[i])
		{
			charCounter++;
		}
		else
		{
			checker = userWord[i];
			charCounter = 0;
		}
	}
	if (charCounter > 3)
	{
		std::cout << "You have a number repeating more than 3 times, that's invalid! \n";
		return;
	}
	else
	{
		std::cout << "Passed checkRepeats \n";
		largerAfters(userWord);
		return;
	}
}

//function that makes sure no invalid larger numbers come after smaller numbers
void largerAfters(std::string const userWord)
{

	for (int i = 0; i < userWord.length(); i++)
	{
		//if the current letter is 'I', and 'I' is not the last letter...
		if (i < userWord.length() - 1 && userWord[i] == 'I')
			//checks every letter after current letter
			for (int j = i + 1; j < userWord.length(); j++)
			{
				//if 'L', 'C', 'D', or 'M' appear after 'I' this is an invalid input
				if (userWord[j] == 'L' || userWord[j] == 'C' || userWord[j] == 'D' || userWord[j] == 'M')
				{
					std::cout << "You have invalid characters appearing after your 'I'! \n";
					return;
				}
			}

		//if the current letter is 'V', AND 'V' is not the last letter AND the letter after the current letter IS NOT 'I'...
		if (i < userWord.length() - 1 && userWord[i] == 'V' && userWord[i + 1] != 'I')
			//if any character other than 'I' appears after 'V', this is an invalid input
		{
			std::cout << "Only the letter 'I' may follow 'V'! \n";
			return;
		}

		//if the current letter is 'X', and 'X' is not the last letter...
		if (i < userWord.length() - 1 && userWord[i] == 'X')
			//checks every letter after current letter
			for (int j = i + 1; j < userWord.length(); j++)
			{
				//if 'D' or 'M' appear after 'X' this is an invalid input
				if (userWord[j] == 'D' || userWord[j] == 'M')
				{
					std::cout << "You have invalid characters appearing after your 'X'! \n";
					return;
				}
			}

		//if the current letter is 'L', and 'L' is not the last letter...
		if (i < userWord.length() - 1 && userWord[i] == 'L')
			//checks every letter after current letter
			for (int j = i + 1; j < userWord.length(); j++)
			{
				//if 'C', 'D', or 'M' appear after 'L' this is an invalid input, however 'L' is accounted for in the checkRepeats function
				if (userWord[j] == 'C' || userWord[j] == 'D' || userWord[j] == 'M')
				{
					std::cout << "You have invalid characters appearing after your 'L'! \n";
					return;
				}
			}

		//if the current letter is 'D', and 'D' is not the last letter...
		if (i < userWord.length() - 1 && userWord[i] == 'D')
			//checks every letter after current letter
			for (int j = i + 1; j < userWord.length(); j++)
			{
				//if 'D' or 'M' appear after 'D' this is an invalid input, however 'D' is accounted for in the checkRepeats function
				if (userWord[j] == 'D' || userWord[j] == 'M')
				{
					std::cout << "You have invalid characters appearing after your 'D'! \n";
					return;
				}
			}
	}
	subFormat(userWord);
	return;
}

//function that handles the formatting of subtractive Roman Numerals such as IV, XC, etc...
void subFormat(std::string const userWord)
{
	//if an 'I', 'X', or 'C' appears as a subtractive numeral, make sure no that no other 'I' and 'C' appear again while 'X' only appears as part of 'IX'
	for (int i = 0; i < userWord.length(); i++)
	{
		//THIS BLOCK IS FOR SUBTRACTING 'I'
		//if the current letter isn't the laster letter, if the current letter is 'I', and the letter after is 'V' or 'X'
		if (i < userWord.length() - 1 && userWord[i] == 'I' && (userWord[i+1] == 'V' || userWord[i+1] == 'X'))
		{
			//if the minuend is not the last number, this is an invalid number (no more letters come after IV or IX)
			{
				if ((i + 1) != (userWord.length() - 1))
				{
					std::cout << "ERROR: invalid inputs after IV OR IX! \n";
					return;
				}
			}
			//if the current letter is not the first letter...
			if (i != 0)
			//makes sure no other 'I's appear before the subtrahend 'I'
			{
				for (int j = 0; j < i; j++)
				{
					if (userWord[j] == 'I')
					{
						std::cout << "ERROR: can't have any additional I's before the subtrahend 'I'! \n";
						return;
					}
				}
			}
		}
		//THIS BLOCK IS FOR SUBTRACTING 'X'
		//if the current letter is not the last letter and the current letter is 'X'...
		if (i < userWord.length() - 1 && userWord[i] == 'X')
		{
			if (userWord[i + 1] != 'X') //this line of code is designed to prevent numbers such as 'XLX' while still allowing 'XXXIX' by checking the sequence of letters that appear after the first break in sequence of 'X'
			{
				//checks to see if any other instances of 'X' appear after the minuend 'X'
				for (int j = i + 1; j < userWord.length(); j++)
				{
					//if another X is discovered, it needs to have an 'I' in front of it ie. 'XXXIX' 'XLIX' 'CCXIX'
					if (userWord[j] == 'X' && userWord[j - 1] != 'I')
					{
						std::cout << "format invalid, you need a subtracting 'I' before that last 'X'!! \n";
						return;
					}
				}
			}
		}
		//THIS BLOCK IS FOR SUBTRACTING 'C'
		//if the current letter is not the last letter and the current letter is 'C'...
		if (i < userWord.length() - 1 && userWord[i] == 'C')
		{
			if (userWord[i + 1] != 'C') //if 'C' is a minuend in the number, no other C can appear after it; 
			{
				for (int j = i + 1; j < userWord.length(); j++)
				{
					//no C's can appear after a subtrahend 'C' except for in front of an 'X' - 'CXC'
					if (userWord[j] == 'C')
					{
						if (userWord[j - 1] != 'X')
						{
							std::cout << "Additional 'C's can't appear if you're using C as a subtrahend! \n";
							return;
						}
					}
				}
				//if the current letter is not the first letter...
				if (i != 0)
					//makes sure no other 'I's appear before the subtrahend 'I'
				{
					for (int j = 0; j < i; j++)
					{
						if (userWord[j] == 'I')
						{
							std::cout << "ERROR: can't have any additional I's before the subtrahend 'I'! \n";
							return;
						}
					}
				}

			}
		}
	}
	std::cout << "passed subFormat! \n";
	returnValue(userWord);
	return;
}

//function that gives user the decimal value of the Roman Numerals
void returnValue(std::string const userWord)
{
	//parse will stores the values of Roman Numerals and make them easier to add together in a loop
	int parse[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int value = 0;
	//loop that assigns decimal values to Roman Numerals and stores them in array 'parse[16]'
	for (int i = 0; i < userWord.length(); i++)
	{
		if (userWord[i] == 'I')
		{
			parse[i] = 1;
		}
		if (userWord[i] == 'V')
		{
			parse[i] = 5;
		}
		if (userWord[i] == 'X')
		{
			parse[i] = 10;
		}
		if (userWord[i] == 'L')
		{
			parse[i] = 50;
		}
		if (userWord[i] == 'C')
		{
			parse[i] = 100;
		}
		if (userWord[i] == 'D')
		{
			parse[i] = 500;
		}
		if (userWord[i] == 'M')
		{
			parse[i] = 1000;
		}
		//std::cout << parse[i] << '\n';
	}
	for (int i = 0; i < userWord.length(); i++)
	{
		//if the current letter is not the last letter and the same value or greater than the one after it then add the values
		if (i < userWord.length() - 1 && parse[i] >= parse[i + 1])
		{
			value += parse[i];
		}
		//if the current letter is not the last letter and less than the one after it then subtract the values
		if (i < userWord.length() - 1 && parse[i] <  parse[i + 1])
		{
			value -= parse[i];
		}
	}
	//the last value is unaccounted for in the previous loop for simplicity sake, so this add the final value at the end
	value += parse[userWord.length() - 1];
	std::cout << "The value of your Roman Numeral is: " << value << " \n";
	return;
}

int main()
{
	//variable that user-inputted word gets stored in to
	std::string userWord = "";
	std::cin >> userWord;
	//makes sure that the 'userWord' is not longer than 15 as no Roman Numerals are longer than 15 letters
	if (userWord.length() < 16)
	{
		checkValidChar(userWord);
	}
	else
	{
		std::cout << "Too many letters! \n";
	}


}