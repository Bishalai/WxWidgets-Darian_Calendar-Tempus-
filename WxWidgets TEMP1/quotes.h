#pragma once
#include<string>

using namespace std;
class quotes
{

private:


	std::string quotations[39] =
	{	"We can do it if we try! \n- Bishal",

		"The clearest way into the Universe is through a forest wilderness. \n- John Muir",

		"And forget not that the earth delights to feel your bare feet and the winds long to play with your hair \n- Khalil Gibran, The Prophet",

		"It is spring again. The earth is like a child that knows poems by heart. \n- Rainer Maria Rilke",

		"Earth's crammed with heaven...But only he who sees, takes off his shoes. \n- Elizabeth Barrett Browning",

		"Time flies like an arrow; fruit flies like a banana. \n- Anthony G.Oettinger",

		"Don’t waste your time in anger, regrets, worries, and grudges. Life is too short to be unhappy. \n- Roy T.Bennett",

		"Don't spend time beating on a wall, hoping to transform it into a door. \n- Coco Chanel",

		"Time is the longest distance between two places. \n- Tennessee Williams",

		"You may delay, but time will not. \n- Benjamin Franklin",

		"Time is a game played beautifully by children. \n- Heraclitus",

		"The future is uncertain but the end is always near. \n- jim morrison",

		"How did it get so late so soon? \n- Dr.Seuss",

		//done for jan to dec now for mars months, help me!!!
	
		"Better three hours too soon than a minute too late. \n- William Shakespeare.",

		"Lost time is never found again. \n- Benjamin Franklin",

		"Time is the most valuable thing a man can spend. \n- Theophrastus.",

		"Time is the wisest counselor of all. \n- Pericles.",

		"Punctuality is the thief of time. \n- Oscar Wilde",

		"Men are from Mars, Women are from Venus. \n- John Gray",

		"Mars is there, waiting to be reached\n- Buzz Aldrin",




	}
		;

	int index;

public:

	quotes();

	string get_quote(int n);

	~quotes();

};

