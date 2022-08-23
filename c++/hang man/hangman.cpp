/*
Zander wooldridge
csc 160-section
04/11/2021
summary: reads words from a fiule and then takes the last one in the file to be the word and the user has to guess the letters
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "randword.h"

int letterFill(char guess, string secretword, string& guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

int main() 
{
	int i = 0;
	std::string letters;
	std::string guessedWord;
	std::string fileWord;
	std::string board;
	std::string gl;
	char guessedLetter;
	bool win = false;
	int faledGueses = 0;
	bool letterFound = false;
	bool foundAlready = false;
	bool letterNotFound = false;
	bool stillplaying = true;
	std::string playerAns;

	//uses the "getwords" function from the randword.cpp file to extract the words from the .dat fiule
	getWords("hangman.dat");

	std::cout <<  "------------- HANGMAN GAME -------------" << std::endl;
	
	// the while loop is there if the player still wants to play
	while (stillplaying == true) {
		//promts the user iif they want to play the game
		std::cout << "Do you want to play hangman? (y or n): ";
		std::cin >> playerAns;
		//sets the random word to the file word varable
		fileWord = getNextWord();
		//if the user declines to play the game it will sya goodbye and exit the game
		if (playerAns == "NO" || playerAns == "no" || playerAns == "No" || playerAns == "QUIT" || playerAns == "quit" || playerAns == "Quit" || playerAns == "STOP" || playerAns == "stop" || playerAns == "TERMINATE" || playerAns == "terminate" || playerAns == "Terminate" || playerAns == "N" || playerAns == "n" || playerAns == "Q" || playerAns == "q")
		{
			std::cout << "Goodbye" << std::endl;
			return 1;
		}
		//when the user wants to play the game the rest of the code will exicute
		else if (playerAns == "YES" || playerAns == "yes" || playerAns == "Yes" || playerAns == "SURE" || playerAns == "sure" || playerAns == "Sure" || playerAns == "OK" || playerAns == "ok" || playerAns == "Ok" || playerAns == "Y" || playerAns == "y")
		{
			string unknown(fileWord.length(), '-');
			std::cout << "Let's PLAY" << std::endl;
			std::cout << unknown << std::endl;
			win = false;

			//resets the failed gusses to zero so if the player has played one game and is starting the next one it will be reset
			faledGueses = 0;
			


			//created a blank bord
			std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "         |" << std::endl << "         |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
			// Initialize the secret word with the * character.

			std::cout << "<<<<<<<<<<<<< MAKE A GUESS >>>>>>>>>>>>>" << std::endl;
			
			//while the user has not failed 6 time the loop will continue
			while (faledGueses < 6)
			{
				//promts the user for the letter
				std::cout << unknown << std::endl;
				std:cout << "Guessed Letters: " << std::endl;
				std::cout << "Enter letter to guess: ";
				std::cin >> guessedLetter;
				
				
				for (int i = 0; i < fileWord.size(); ++i)
				{
					if (letterFill(guessedLetter, fileWord, unknown) == 0)
					{
					}
					if (fileWord.at(i) == guessedLetter) {
						letterFound = true;
						//break;
					}
					else
					{

					}
					if (fileWord == unknown)
					{
						std::cout << fileWord << std::endl;
						std::cout << "Yeah! You got it!" << std::endl;
						win = true;
						break;
					}
				}


				//checks if the letter guessed is in the word that was guesses
				
				
				if (win != true)
				{
					guessedLetter = toupper(guessedLetter);
					std::cout << "You enetered: " << guessedLetter << std::endl;
				}
				//takes wether or not the letter was in the word and prints the corisponding phrase for each posable sitchuation
				if (letterFound == true)
				{
					std::cout << std::endl;
					std::cout << guessedLetter << " is in the word to guess." << std::endl;
					letterFound = false;
				}
				//if the letter is not found in the word the program will give them one failed attempt
				else
				{
					if (foundAlready == true)
					{
					}
					else if (win == false)
					{
						faledGueses = faledGueses + 1;
						std::cout << std::endl;
						std::cout << guessedLetter << " is NOT in the word to guess." << std::endl;
					}
				}
				if (win == true)
				{
					break;
				}
				
				//for each difrent board it cosisponds with how many failled attempts ther are
				if (faledGueses == 0)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "         |" << std::endl << "         |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 1)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << "         |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 2)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << "  |      |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 3)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << " -|      |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 4)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << " -|-     |" << std::endl << "         |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 5)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << " -|-     |" << std::endl << " /       |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				else if (faledGueses == 6)
				{
					std::cout << std::endl << "  -------|" << std::endl << "  |      |" << std::endl << "  O      |" << std::endl << " -|-     |" << std::endl << " / \\     |" << std::endl << "         |" << std::endl << "       -----" << std::endl;
				}
				
			}
			if (win == true)
			{
			}
			else
			{
				std::cout << "Sorry you lose - the word was: " << fileWord << std::endl;
			}
			
		}
		//when the user does not use the right phrases or charcters that i have coded it will print an "error" and then reprompt the user
		else
		{
			std::cout << "Error - please enter (y or n)" << std::endl;
		}

	}
	// end of the program
	return 0;

	
}
