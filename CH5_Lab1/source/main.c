#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);
int unuse[53] = { 0 };

int main(void)
{
	const char *suit[4] = { "Hearts", "Diamond", "Clubs", "Spades" };

	const char *face[13] = { "Ace", "Deuce", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	int deck[4][13] = { 0 };
	srand(time(0));
	shuffle(deck);
	deal(deck, face, suit);

	system("pause");
	return 0;
}
void shuffle(int wDeck[][13]){
	int row;
	int column;
	int card;
	int rndnum;
	int counter = 52;

	for (int a = 1; a <= 52; a++) {
		unuse[a] = a;
	}

	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 13; b++) {
			if (counter != 0){ rndnum = rand() % counter + 1; }
			else wDeck[a][b] = unuse[0];

			wDeck[a][b] = unuse[rndnum];
			unuse[rndnum] = unuse[counter]; //Á×§K­«½Æ
			counter--;
		}
	}
}
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int card;
	int row;
	int column;

	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++){
			for (column = 0; column <= 12; column++){
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-2s %c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					goto exit;
				}
			}

		}
		exit:;
	}
}

