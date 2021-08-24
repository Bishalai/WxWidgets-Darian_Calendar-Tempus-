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

		"Don't judge each day by the harvest you reap but by the seeds that you plant.\n -Robert Louis Stevenson",

		"The future belongs to those who believe in the beauty of their dreams. \n-Eleanor Roosevelt",

		"The best and most beautiful things in the world cannot be seen or even touched — they must be felt with the heart. \n-Helen Keller",

		"Many of life's failures are people who did not realize how close they were to success when they gave up. \n-Thomas A. Edison",

		"Keep smiling, because life is a beautiful thing and there's so much to smile about. \n-Marilyn Monroe",

		"Life is a long lesson in humility. \n-James M. Barrie",

		"In three words I can sum up everything I've learned about life: it goes on. \n-Robert Frost",

		"Love the life you live. Live the life you love. \n-Bob Marley",

		"Life is either a daring adventure or nothing at all. \n-Helen Keller",

		"You have brains in your head. You have feet in your shoes. You can steer yourself any direction you choose. \n-Dr. Seuss",

		"Life is made of ever so many partings welded together. \n-Charles Dickens",

		"Your time is limited, so don't waste it living someone else's life. Don't be trapped by dogma — which is living with the results of other people's thinking. \n-Steve Jobs",

		"Life is trying things to see if they work. \n-Ray Bradbury",

		"You miss 100% of the shots you don't take. \n-Wayne Gretzky",

		"Whether you think you can or you think you can't, you're right. \n-Henry Ford",

		"I alone cannot change the world, but I can cast a stone across the water to create many ripples. \n-Mother Teresa",

		"Nothing is impossible, the word itself says, ‘I'm possible!' \n-Audrey Hepburn",

		//37 for greg year
		"The question isn't who is going to let me; it's who is going to stop me. \n-Ayn Rand",

		//38 for darian year
		"The only person you are destined to become is the person you decide to be. \n-Ralph Waldo Emerson"

	}
		;

	int index;

public:

	quotes();

	string get_quote(int n);

	~quotes();

};

//Tempus