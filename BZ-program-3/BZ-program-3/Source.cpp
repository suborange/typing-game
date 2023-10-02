/*
Text editor game. Give a sentence, maybe from list in text file, and linked lists to type text and compare it to the given sentence or paragraph? 
Adds points or something for fun game// typing game. So typing correctly forst try more points, using backspace is small deduction, etc. 
[prog 3 -typing game- linked lists,  dynamic memory, try and exceptions; typing game. from text file, display random words, and 
you gotta follow and type. each sentence is a new dynamic memory, and then deleted after use. has a score. try for playing the game again, or
bad characters? ] write out step by step for this

from a text file of words, it creates random string of sentances to type. each word is inserted into a linked list. have a array or vector of linked lists consisting of words? 
the user or player has to follow along and type the exact words. each character is compared, right char = +3, wrong =-4, backspace =-2?
no symbols, use a try and except to catch the symbols, or other stuff. only lowercase letters? or is shift different than ctrl?
so display a sentace, gotta type it, it is scored. then asks to play again. 

NOTE: maybe instead of vector of linked list, do linked list of vector. the vector holds the words. 

BRAINSTORM:
( maybe add arrow key penalty?)
hard mode with ctrl + backspace? etc? like other "time savers" (part 2)?

maybe when hitting space, it enters the word, so if it is wrong it is wrong word. minus big points. 
OR hitting space does nothing if it is not the last character(pointer == null)


should it follow the word, or the word displays seperatly



STEP BY STEP:
tells the user the rules to the game.
prompts the user to start playiyng the game.
clears the screen an starts to play.
play: grabs 1-8 words randomly from the file-> displays the full sentance on screen-> prompts user to start typing.
then user types, one char at  time is compared, and then the score is determined. correct char = +3, wrong char = -4, backspace =-2


[STEP]
// [cS.0] MAIN FUNCTION - START HERE
// [cS.1] DISPLAY BASIC GAME RULES - OUTPUT TEXT
// [cS.2] SETUP GAME - PRESS ENTER TO CLEAR SCREEN AND CONTINUE TO PLAY
// [cS.3] NEED FILE, CREATE OPEN A FILE FUNCTION
// [cS.4] NEED FILE, CREATE CLOSE THE FILE FUNCTION
// [cS.5] SETUP FILE - OPEN THE FILE, AND READ THE CONTENTS INTO VECTOR AND LINKED LIST
// [cS.6] PLAY GAME - START THE GAME, CREATE VECTOR,  CREATE FSTREAM, CHECK FILE AND CALL OpenFile(), THEN CALL SetupFile(), CALL CloseFile(), CALL Play(), THEN FINALLY CALL Display()
// [cS.7] PLAY - LOOP THROUGH THE VECOTR OF STARTING CHARS, THEN AFTER STARTING CHAR, LOOP AND POINT TO THE NEXT CHAR IN THE WORD. 
DISPLAYS THE FULL WORD, THEN THE USER INPUTS, AND THEN FOR EACH CHAR CALL CompareChar() AND CalculateChar() and then disply what was input
// [cS.7.5] - REFACTORED CODE 
// [cS.8] COMPARE - COPMARE INPUT CHAR TO ALL CASES
// [cS.9] CALCULATE - CALCULATE THE SCORE BASED OF IF COMPARISON CASES
// [cS.10] DISPLAY - 
// [cS.0.5] GOTOXY - TO MOVE THE CURSOR TO THE RIGHT PLACE ON THE CONSOLE. 


TODO:
how to handle the space. like does user enter space? how to go from word to word? maybe when space is entere it goes to next word in vector list?(this needsd to count for how many letters were typed, unless space make whols word wrong at -10 or omethin?
keeping track of the length of the word. so knows when to move to next word
fix the scoreboard - seems good enough atm
should it display two words at a time rather than one?
figure out if i want the sccore to be colored when added or subtracted, or another certain color? - rn its colored red/green

space kinda works, i think i really need to redo the logic includinng the char counts
*/


// Includes
#include"node.h" // should i do this?
#include"Resources.h" // my header
#include<iostream> // for inpute output for console
#include<conio.h> // for _getch() for getting one char, and _putch() for displaying one char
#include <string>
#include<random>
#include<ctime>

using std::default_random_engine;
using std::uniform_int_distribution;

// using
using std::cout;
using std::endl;

// this needs windows header file to work. 
// [S.0.5] GOTOXY - TO MOVE THE CURSOR TO THE RIGHT PLACE ON THE CONSOLE. 
void gotoxy(short int x, short int y) //Functon for moving the cursor 
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

// [S.0] code
int main() // do i dare try something with system arguments? an actual executable?
{
	

	// display game rules to the user, explaining the game
	DisplayGameRules(); // definition line 101
	SetupGame(); // definition line 124
	return PlayGame();

}

// [S.1]
void DisplayGameRules()
{

	// first check if the handle fails or not, if it fail, it should fail before
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //HANDLE for console colors
	
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	// explain what the game is
	cout << "Welcome to the game! This is a fun typing game where you have to type accurately and will be scored." << endl;
	cout << "Here are a couple rules: " << endl;

	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Rule 1: Entering the correct character awards +1 points."<<endl;
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Rule 2: Entering a wrong character awards -4 point. "<<endl;
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Rule 3: Entering a backspace awards -2 points"<<endl;
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Have fun playing!" << endl<<endl;	

}

// [S.2]
void SetupGame() 
{


	// first check if the handle fails or not, if it fail, it should fail before
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //HANDLE for console colors

	cout << "Press enter to start playing the game...";
	std::cin.ignore(ALL, NEW_LINE); // allows the player to type a key to move foward and play the game. 
	SetConsoleTextAttribute(hStdout, FOREGROUND_WHITE);

	system("CLS"); // clear the screen, preapre to play the game

}


// [S.6] PLAY GAME - START THE GAME, CREATE VECTOR,  CREATE FSTREAM, CHECK FILE AND CALL OpenFile(), THEN CALL SetupFile(), CALL CloseFile(), CALL Play(), THEN FINALLY CALL Display()
// || [S.5]
int PlayGame() 
{
	// create my node here to hold the stored vector of linked lists?

	// first check if the handle fails or not, if it fail, it should fail before
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //HANDLE for console colors
	if (hStdout == INVALID_HANDLE_VALUE)
	{
		cout << "ERROR while getting input handle" << endl;
		return EXIT_FAILURE;
	}

	std::vector<Node*> stored_words; // DO I REALLY NEED TWO VECTORS, OR CANI JUST USE ONE
	// fixed to one vector 
	std::fstream word_file;
	

	if (OpenFile(word_file))
	{
		// stored_words = SetupFile(word_file); // using two vectors
		SetupFile(word_file, stored_words); // now just using one vector
	}
	else {
		return EXIT_FAILURE;
	}
	// once done with the file
	CloseFile(word_file); // definition line


	int score = 0;
	ShowScore(score);
	//play
	 Play(stored_words,score, hStdout);

	 // now loop through all to delete the memory to handle it safely and correctly. 
	 // delete stored_words[];
	
	// display the stats? // display the score? maybe score inside with one of the loops?
	
	 return EXIT_SUCCESS;
}

// [S.5]  SETUP FILE - OPEN THE FILE, AND READ THE CONTENTS INTO VECTOR AND LINKED LIST
// || [S.6]
void SetupFile(std::fstream& word_file, std::vector<Node*>& list_word) 
//TODO 
// maybe add a space to the end of the character? then with linked list when the space input == space, then it measn go to next word? use a flag? or keep with pointer condition?
{
		// now start reading from the file 
		// maybe here make the array or vector, and asign it to the start for each word
		// std::vector<Node*> list_word;
		string word; 
		// pointers for linked lists 
		Node* start = nullptr;
		Node* curr = nullptr;


		//loop can start here.
		// start to file, the first word. now loop through each of the file words, this should go till end of file.
		while (word_file >> word)
		{
			

			// start the vector with starting pointer.
			//list_word.push_back(start);

			// need to rethink all this logic here. this is just for getting from the file. i know the string size, etc. so a closed loop
			for (unsigned int ind = ZERO; ind<word.size(); ind++)
			{
				// create node and initialize
				Node* letter = new Node(word[ind]); // initiale with the first character
				// letter in memory seems to turn up as last address
				// DO I NEED TO MAKE FIRST LETTER, PREV->NULLPTR ?????

				if (ind == ZERO) // first character, start of the word
				{
					// now make nodes nd insert each letter into a node. another function 
					// letter->character = word[ind]; // set first letter, to the first character
					start = letter;	
					start->prev = nullptr;
					list_word.push_back(start);
					// list_word.push_back(start); // set the starting word, to point to first node, first letter of first word
					curr = letter; // set current position to this start				
				}
				else // other than first character, linking the list
				{
					curr->next = letter; // point previous curr, to current letter node
					letter->prev = curr; // now point current, to previous letter node
					curr = letter; //update curr to actual current node
				}
				// delete letter; // is this right?

			}
			// refactor this shit
			// add a space to the end of the word to handle the space easiest.? i think
			Node* space_node = new Node(SPACE);
			curr->next = space_node;
			space_node->prev = curr;
			curr = space_node;
			
		}
		

		
	// then with the file create a linked list to insert characters, and words. maybe use an arrayor vector to add words, of linked lists?
	// if not make it rapid fire, one word at a time


		// soo all the pointers here will stay in memory, how should i be handleing this? i should delete them at some point right? 
		//maybe  i can use vector at some point to delete, go backwords?

		// delete curr;
		// delete start;
		// return list_word;
}

// [S.7]PLAY - LOOP THROUGH THE VECOTR OF STARTING CHARS, THEN AFTER STARTING CHAR, LOOP AND POINT TO THE NEXT CHAR IN THE WORD. 
// DISPLAYS THE FULL WORD, THEN THE USER INPUTS, AND THEN FOR EACH CHAR CALL CompareChar() AND CalculateChar() and then disply what was input
void Play(std::vector<Node*>& key_words, int& score_, HANDLE& hStdout_)
{
	
	//MAYBE NEED MOER FUNCTIONS HERE 
	// setup vars 
	short int x=5, y=6; // for the character coordinates. for gotoxy()
	// soft reset the coordinates to display the words, 
	// For random number generations
	static short int move_y = 6;

	
	
	
	short int index = 0, reset_count=0;
	// this will play, so get user char, compare the car, keep track of score, then redisplay to show score(green/red)
	// first make loop
	//for (short int i = 0; i<key_words.size(); i++) // this loop is for every word, every first linked list?
	while (1) // do i need an end condition?
	{
		default_random_engine randomEngine{ static_cast<unsigned int> (time(0)) };
		uniform_int_distribution<unsigned int> randomInt{ 0,108 };
		index = randomInt(randomEngine);
		
		reset_count++; // one word, one count
		y = move_y; //reset to top of the console
		gotoxy(x,y); // reset the cursor position, after dispalying the score elsewhere. 
		SetConsoleTextAttribute(hStdout_, FOREGROUND_WHITE);
		DisplayKeyWords(key_words, index);
		
		SetupUserInput(key_words, index, score_, x, y, move_y, hStdout_);
		// every 8 words or so, the count should clear the screen, somehow redisplay the score.
		if (reset_count % 8 == 0)
		{
			// system("CLS");
			x = 5;
			move_y++;
			move_y++;
			move_y++;
			ShowScore(score_); // does this redisplay the score correctly?

		}

		
		/*x=1;
		gotoxy(x, y);
		_putch(SPACE);*/

		// should be out of loop for word, so then handle pre for next word here? (like the space) how to handle characters typed outside of the "word"
		// if the word is right or wrong, thhink about coloring the key display, and then clearing this line, to start the next word on the same line.?
		// OR just leave it all on one line to see the history of what was typed. 
	}


}
// [S.7.5] - seperate/refacctored into new function
void DisplayKeyWords(std::vector<Node*> key_words_, short int i_)
{
	
	// SEPERATE INTO FUNCTION. NO RETURNS SO EZ. 234-251
	Node* temp_letter;// create temp node for displaying. doesnt change any data so can just display then delete.
	
					  // need to compare for each word, so compare to a space? new word? break;?
					  // get the list for each word. 

	temp_letter = key_words_[i_];	// get the first word from the vector strcuture for DISPLAY

								// got the first word, so can then get the first char of linked list, and then can displlay, then loop through all letters.
								// DISPLAYING ONLY
	while (temp_letter != nullptr) // while the temp is not null, there IS some character from text file to display (key_words)
	{
		
		_putch(temp_letter->character); // display the characater of this letter sequence. 
		
		temp_letter = temp_letter->next; // loop through all letters in the word, NOT null.
	}

	

} 

// [S.7.5] - seperate/refacctored into new function
void SetupUserInput(std::vector<Node*> key_words_, short int i_, int& score__, short int& x_, short int& y_, short int move_y_,HANDLE& hStdout__)
{

	character_typed which_letter;
	bool next_word;
	next_word= false; // reset to false after start to a word. 
	Node* compare_char = key_words_[i_]; // new pointer for comparing user input to the key words from the text file. FOR COMPARING INPUT
	// does this help with memory leak? what really would here prevent or go wrong here ??
	// make prev null? this should be the first letter right? so prev == nullptr
	// compare_char->prev = nullptr;
	// TODO something herre doesnt work with the score
	

	/*gotoxy(xdisplay,ydisplay);

	if (score__ < 0) cout << "0";
	else cout << score__; */// if it changes digits, 2->1, 3->2 it will display wrong. need to fix this. maybe display some spaces first?


	// GOTOXY()
	// y relates to vertical, ,so go to next line? or skip a line go 2 lines.
	// this is for the first line of input.
	
	y_ = move_y_ +2; // go to line 2 or 3 for displaying user input



	while (compare_char !=nullptr) // || next_word != true) // no it should check nullptr, because its a linked list(address or pointer), then add space ?
									// while we are not a space? should be a word at a time, to loop through the linked list
		// check until the next word is activated,
	{
		

		// y relates to vertical, ,so go to next line? or skip a line go 2 lines.
		// need to get to right coordinates for user input. this is after displaying the words.
		gotoxy(x_, y_); 

		// what should be in here? this is going through every character for one word
		//then get user input for one char - static??
		static char user_input; // should it static? should it be here in this scope?

		//get ch for user input for different line
		user_input = _getch(); // i put count here at first, but again needsd to be later because the backspace should decrease this
		
		
		// maybe check here before hand for cases. can remove later case checks
		// so if bs handle that, if space handle that.. (maybe no space till compare_char is null???)

		char compare_letter;
		// conditional to set this char
		if (compare_char->character == SPACE || compare_char->character == NULL) // works for the last char, but clean it up
		{
			
			if (user_input == SPACE) // need to add something here that can checkm if the whole word is correct, otherwise the word is wrong. minus 25 points
			{

				_putch(user_input);
				x_++; // CursorToNextChar()
				//compare_char = nullptr; // end the word now, move to next word
				gotoxy(x_,y_);
			//	__debugbreak();
				break;
				// ADD something for a wrong word?

			}
			else if (user_input == BACKSPACE || user_input == CON_DELETE) // if a character is deleted, well then delete it, cuz oop
			{
				//__debugbreak();

				which_letter = BACKSPACE_CHAR;
				SetConsoleTextAttribute(hStdout__, FOREGROUND_RED | FOREGROUND_INTENSITY);
				

				DisplayUserCharInput(which_letter, user_input, compare_char, x_, y_, next_word, hStdout__);
				CalculateScore(which_letter, score__);
				// should i do this? pass the argument all the way down? is too many times exponentially bad? or fine for memory?

				ShowScore(score__);
				// not a space character in the word, so it should be fine to go normally
			}

			
		}
		else if (compare_char->prev == nullptr && user_input == BACKSPACE)// first char for backspace
		{
			// do nothing
		}
		else
		{
			compare_letter = compare_char->character;
			// first i instantly went to next, but this should happen later, not here
			// then compare the char

			which_letter = CompareChar(compare_letter, user_input, hStdout__); // should i pass which_letter instead later, or nest the funktion(); ?
			// do nothing when its the first character and its a backspace, delete, or no arrow keys. ( maybe add arrow key penalty?) 
					
			

			DisplayUserCharInput(which_letter, user_input, compare_char, x_, y_, next_word, hStdout__);

			CalculateScore(which_letter, score__);
			// should i do this? pass the argument all the way down? is too many times exponentially bad? or fine for memory?
			ShowScore(score__);
			// not a space character in the word, so it should be fine to go normally
		}
		

		/*

		// before redisplaying user, need to gotoxy, and then after need to go to xy again?(unless all key words are displayed first)
		// redisplay text based on correctness or not, green = correct, red = wrong
		// need to account for backspace key, use the flag to determine backspace case. gotoxy for both backspace or input
		if (which_letter == CORRECT_CHAR) // no, check for majority case first, catch them here. // check for unique case first? or non unique case first?
		{
		// NOT unique, continue displaying user input here.
		// gotoxy();

		SetConsoleTextAttribute(hStdout_, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		_putch(user_input); // display the character the user typed
		x++;
		SetConsoleTextAttribute(hStdout_, 15);

		}
		else if (which_letter == BACKSPACE)
		{
		// backspace - take care of this
		// _putch(user_input); // display the character the user typed
		x--; x--; // ? go back one? or got back two?
		_putch(' ');
		//if (compare_char != nullptr)
		//{
		//	compare_char = compare_char->prev->prev;
		//	delete compare_char->next;

		//	while (compare_char != nullptr)
		//	{
		//		compare_char = compare_char->next;
		//	}
		//}
		}
		else if (which_letter == SPACE) // take care of space stuff
		{
		// do nothing?
		// OR make sure its the last
		// OR make it enter the word, so whatever is typed ends, correct or wrong, calculates score, then moves on to the next word. ( maybe shows the displayed word in red so like u missed it )
		// also if the word is correct it redisplays green, showing that word is correct.
		}
		else  // else should be for more unique cases? yes, make first case for majority.
		{
		// wrong char pressed. still display, but displahy red. score is calculated already
		// now handle backspacec correctly after this.
		SetConsoleTextAttribute(hStdout_, FOREGROUND_RED | FOREGROUND_INTENSITY);
		_putch(user_input);
		x++;
		SetConsoleTextAttribute(hStdout_, 15);
		}


		*/
	}
	// this fucks shit up. 
	
	//delete compare_char; // delete the memeory alocated. 
	
	//_putch(' '); // to move to the next word, because we should be done. may need a flag here or figure out the space key
	//x_++;

}

// [S.7.5] SHOW SCORE - REFACTORED INTO FUNCTION
void ShowScore(int score___)
{
	ScoreSetup();
	// display the score - refactor to function
	gotoxy(SCORE_X, SCORE_Y);
	cout << SPACE << SPACE << SPACE << SPACE << SPACE << SPACE; // display spaces to "clear" the score area
	gotoxy(SCORE_X, SCORE_Y); // now display over the spaces.
	if (score___ < 0) { score___ = 0; cout << score___; }
	else cout << score___; // if it changes digits, 2->1, 3->2 it will display wrong. need to fix this. maybe display some spaces first?



}
// [S.7.5] SCORE SETUP - DISPLAY SCORE BOX
void ScoreSetup()
{

	gotoxy(SCORE_X - 2,SCORE_Y);
cout << '|';
gotoxy(SCORE_X - 2, SCORE_Y - 1);
cout << '|';
gotoxy(SCORE_X - 2, SCORE_Y + 1);
cout << '|';
gotoxy(SCORE_X + 8, SCORE_Y - 1);
cout << '|';
gotoxy(SCORE_X + 8, SCORE_Y + 1);
cout << '|';
gotoxy(SCORE_X + 8, SCORE_Y);
cout << '|';
gotoxy(SCORE_X, SCORE_Y - 2);
cout << "_______";
gotoxy(SCORE_X, SCORE_Y + 1);
cout << "_______";
}
	

// [S.8] COMPARE - COPMARE INPUT CHAR TO ALL CASES
character_typed CompareChar(char key_letter,char user_letter, HANDLE& hStdout___)
{
	// think about enumerator 
	
	// maybye think about adding a ullptr check here? what would that help with?

	//if (user_letter == SPACE) // what to do when space is hit. do nothing when its not the end? only allow space for the new word?
	//{
	//	SetConsoleTextAttribute(hStdout___, FOREGROUND_RED | FOREGROUND_INTENSITY);
	//	// if it is the last char
	//	// if it is a blank space, do nothing
	//	//__debugbreak();
	//	return SPACE_CHAR;
	//}
	////MAYBE CHANGE THESE CASES, MAY NEED TO CHECK FOR BACKSPACE, RATHER THAN NOT BACKSPACE
	//// should i have the least compared, most unique be else? 
	//else 
	if (user_letter == BACKSPACE || user_letter == CON_DELETE)
	{
		SetConsoleTextAttribute(hStdout___, FOREGROUND_RED | FOREGROUND_INTENSITY);
		return BACKSPACE_CHAR; // make flag here of a backspace stroke? (this alreaddy is a flag)
	}
	// majority run, so make it the first comparison || fixed this to deal with space, is now 3rd check
	else if (key_letter == user_letter)
	{
		SetConsoleTextAttribute(hStdout___, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		// then this is goood, add a point
		// return true for good point? return false for bad point?
		return CORRECT_CHAR; // if the key word is a space, handle with space
	}	
	// add another else if for special characters, and then deal with the special characters(basically do nothing)
	// is the charater within the bounds of ascii characters? 
	// if it is not correct, not backspace, not space, then it must be some other character that is WRONG, so wrong here
	else // if (user_letter >= CON_LOWERBOUND_LIMIT && user_letter <= CON_UPPERBOUND_LIMIT)
	{
		SetConsoleTextAttribute(hStdout___, FOREGROUND_RED | FOREGROUND_INTENSITY);
		return WRONG_CHAR;
	}
	// if its not correct, backspace, or space, then i tmust be wrong, last case scenario. (or switch this ti space? )
	//else 
	//{
	//	// do nothing when its NOT correct, NOT backspace, NOT space, NOT wrong. 
	//	return 
	//}		
	// add some secret keys, or some default backup for weird keys?

	
}

// [S.9] CALCULATE - CALCULATE THE SCORE BASED OF IF COMPARISON CASES
// takes the return argument from CompareChar - 0, 1,2, ( so far )
void CalculateScore(character_typed calculate_letter_, int& score__)
{
	// swith case?

	// then calcualte or keep score?
	// figure out the else case, should it be correct case? 
	if (calculate_letter_ == CORRECT_CHAR) // correct char = 1 ;; add 3 points
	{
		score__ += 1;
	}
	else if (calculate_letter_ == WRONG_CHAR || calculate_letter_ == SPACE_CHAR) // wrong char = 0 ;; sub 4 points
	{
		(score__-4) <0 ? score__= 0 : score__ -= 4;
	}
	else if (calculate_letter_ == BACKSPACE_CHAR) // backcspace was entered, recalcualte. ;; sub 2 points
	{
		(score__ -3) <0 ? score__= 0 : score__ -= 2;
	}
	else // should i do something here fr space key?
	{

	}
}



// [S.10] DISPLAY INPUT - DISPLAYS THE CHARACTERS TYPED BY THE USER, GREEN == CORRECT, RED == WRONG, HANDLES BACKSPACE, NEED TO HANDLE SPACE
void DisplayUserCharInput(character_typed which_letter, char user_input, Node*& redisplayKeyChar,  short int& x__, short int& y__, bool& par_next_word, HANDLE& hStdout___)
{
	//MAYBE add a display function here to handle displaying user input, and to clean up?
	// DisplayUserInput()

	// AFTER CHANGING TO ENUM TYPE, FIX CASSES TO SWITCH CASE WITH ENUMS & ADD FUNCTION FOR THIS LOGIC
	// ALSO ADD EACH LOGIC INTO OWN FUNCTIONS AS WELL.
	// VIDEO NOTE - refactor this switch, make a function for each case. for video sake I keep it all here. 

	switch (which_letter)
	{
	case CORRECT_CHAR:

		// NOT unique, continue displaying user input here. 
		// gotoxy();

	
			_putch(user_input); // display the character the user typed
			x__++; // CursorToNextChar()
			//SetConsoleTextAttribute(hStdout___, FOREGROUND_WHITE);
			// par_is_last_char++; // keep count of the chars, for knowing when the word is done? maybe compre this to the length of the displayed word above?
			redisplayKeyChar = redisplayKeyChar->next; // we know a letter was entered, so go to the next letter now.
			break;
		
		
		

	case WRONG_CHAR:
		// wrong char pressed. still display, but display red. score is calculated already 
		// now handle backspacec correctly after this. 
		
			_putch(user_input);
			x__++; // CursorToNextChar()
			//SetConsoleTextAttribute(hStdout___, FOREGROUND_WHITE);
			 // par_is_last_char++; // keep count of the chars, for knowing when the word is done? maybe compre this to the length of the displayed word above?
			redisplayKeyChar = redisplayKeyChar->next; // we know a letter was entered, so go to the next letter now.
			
		
		break;

	case BACKSPACE_CHAR: // possible advantage of dta struct of pointers, know where every start is, when -> prev is null
		//BUGS - backspace to ffirst character doesnt work
		// caps is wrong, should caps count or not?
		// 
		if (redisplayKeyChar->prev != nullptr)
		{

			// backspace - take care of this
			x__--; // CursorToPrevChar()
			// ? go back one? or got back two? || just go back one, but then need to point back two because i point forward one after. see below
			gotoxy(x__, y__);
			_putch(' '); // i want to display space, for user to type again

			// par_is_last_char--; // keep count of the chars, for knowing when the word is done? maybe compre this to the length of the displayed word above?
			redisplayKeyChar = redisplayKeyChar->prev; // we know a backspace was entered so no go back one.

		}
		//SetConsoleTextAttribute(hStdout___, FOREGROUND_RED | FOREGROUND_INTENSITY);
	
		//x__++;
		
		//if (compare_char != nullptr)
		//{
		//	compare_char = compare_char->prev->prev;
		//	delete compare_char->next;

		//	while (compare_char != nullptr)
		//	{
		//		compare_char = compare_char->next;
		//	}
		//}

		break;
		// dont need the space anymore here, unless i figure out how i could use the same flow, rather than the extra logic above. 
	case SPACE_CHAR:

		// do nothing?
		// OR make sure its the last 
		// OR make it enter the word, so whatever is typed ends, correct or wrong, calculates score, then moves on to the next word. ( maybe shows the displayed word in red so like u missed it )
		// also if the word is correct it redisplays green, showing that word is correct. 
		//if (user_input == SPACE) // if something, if the user entered a space, then do it.  but this means the user entered a space?
		//{
		//	// after user entered space, to movev on to the next word
		//	_putch(user_input); // display the space for the next word
		//	x__++; // move correctly for space
		//	redisplayKeyChar = nullptr; // now set it to nul, to terminate the loop for this word. word is DONEZO
		//	//__debugbreak();
		//}
		//else
		//{
			// just do space as normally, there will be special case noe for the last char
			_putch(user_input);
			x__++;
			// par_is_last_char++; // keep count of the chars, for knowing when the word is done? maybe compre this to the length of the displayed word above?
			redisplayKeyChar = redisplayKeyChar->next; // we know a letter was entered, so go to the next letter now.
		//}
			
		break;
	//case NEXT_WORD_CHAR: // for special case of when space = last char, and waiting for suer to enter a space to continue on.

	//	if (user_input == SPACE) // when they entered a space , now it is time to move on to the next word.
	//	{
	//		_putch(user_input);
	//		x__++;
	//		redisplayKeyChar = nullptr; // now that its last char, wait and skip everythingt thats not a space.

	//	}
	//	else if (user_input == BACKSPACE)
	//	{
	//		if (redisplayKeyChar->prev != nullptr)
	//		{

	//			// backspace - take care of this
	//			x__--; // ? go back one? or got back two? || just go back one, but then need to point back two because i point forward one after. see below
	//			gotoxy(x__, y__);
	//			_putch(' '); // i want to display space, for user to type again

	//			par_is_last_char--; // keep count of the chars, for knowing when the word is done? maybe compre this to the length of the displayed word above?
	//			redisplayKeyChar = redisplayKeyChar->prev; // we know a backspace was entered so no go back one.

	//		}
	//	}
	//	break;


		// add some secret keys? 
	default:
		//cout << "NOTHING IS HERE" << endl;
		break;
	}

}


//// probably wont work, need to pass the fstream object itself to do this. so figure that out!

// [S.3] NEED FILE, CREATE OPEN A FILE FUNCTION
bool OpenFile(std::fstream& file)
{
	file.open(FILE_PATH);
	
	if (file.is_open())
	{
		return true;
	}
	else
	{
		gotoxy(0,0);
		cout << "UH OH, ERROR OPENING FILE... NOW EXITING...";
		return false;
	}
}

//// [S.4] NEED FILE, CREATE CLOSE THE FILE FUNCTION
void CloseFile(std::fstream& file) 
{
		
	if (file.is_open())
	{
		file.close();
	}

}