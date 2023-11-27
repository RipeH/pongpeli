#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
	enum eSuun {
	STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, UPRIGHT = 5, DOWNRIGHT = 6	//nimet‰‰n koordinaatit mit‰ k‰ytet‰‰n
};
	class cPallo		//Luodaan palloluokka
{
private:
	int x, y;
	int origX, origY;
	eSuun suunta;


	public
		cPallo(int posX, int posY)		//annetaan palloluokalle sijainti ja aloituspiste
	{
		origX = posX;
		origY = posY;
		x = posX; y = posY;
		suunta = STOP;
	}

	{
		void Reset()		//Alotetaan peli alusta
	}

	x = origX; y = origY;
	direction = STOP;

}	
	void suunnanmuutos(eSuun d)		//Luodaan suunnanmuutoksille omat funktiot
	{
		direction = d;
	}
	void randomsuunta()
	{
		direction = (eSuun)((rand() % 6) + 1);
	}
		inline int getX() { return x; }
		inline int getY() { return y; }
		inline eSuun haesuunta() { return suunta; }
		

		void liiku()	
		{						//Luodaan suunnanvaihtojen funktiot
			switch (suunta)
			{
			case STOP:
				break;
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++;
				break;
			case UPLEFT:
				x--; y--;
				break;
			case DOWNLEFT:
				x--; y--;
				break;
			case UPRIGHT:
				x++; y--;
				break;
			case DOWNRIGHT:
				x++; y++;
				break;
			default:
				break;
			}
		}
	 
	friend ostream & operator<<(ostream& o, cPallo c)
	{
		o << "Pallo [" << c.x << "," << c.y << "]" << c.suunta << "]";
		return o;
	}
 };

 class cMaila
 {
 private:
	 int x, y :
		 int origX, origY;
 public:
	 cMaila()
	 {
		 x = y = 0;

	 }

	 cMaila(int posX, int posY) : cMaila()
	 {
		 origX = posX;
		 origY = posY;
		 x = posX;
		 y = posY;
	 }
	 inline void Reset() { x = origX; y = origY; }		//mailan liikesuunnat
	 inline int getX() { return x; }
	 inline int getY) { return y; }
	 inline void liikuYlos() { y - ; }
	 inline void liikuAlas() { y++; }

	 friend ostream & operator<<(ostream & o, cMaila c) //Luodaan maila
	 {
		 o << "Maila [" << c.x << "," << c.y << "]";
		 return o;
	 }
 };
 class cPelimoottori			//Luodaan pelimoottori jossa on kaikki objektit mit‰ tarvitaa
 {
 private:
	 int leveys, korkeus;
	 int pisteet1, pisteet2;
	 char ylos1, alas1, ylos2, alas2;
	 bool quit;
	 cPallo* ball;
	 cMaila* pelaaja1;
	 cMaila* pelaaja2;
 public:
	 cPelimoottori (int l, int k)
	 {srand()
 };
int main()
{


	return 0;
}

