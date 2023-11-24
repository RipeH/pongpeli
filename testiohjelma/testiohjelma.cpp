#include <iostream>
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
	 
	apuri ostream& operator<<(ostream& o, cPallo c)
	{
		o << "Pallo [" << c.x << "," << c.y << "]" << c.suunta << "]" << endl;
		return o;
	}
 };


int main()
{
	cPallo c(0, 0);			//Luodaan objekti cPallo
	cout << c << endl;
	c.randomsuunta();
	cout << c << endl;
	c.liiku();
	cout << c << endl;
	c.randomsuunta();
	c.liiku();
	cout << c << endl;
	c.randomsuunta();
		c.liiku();
	cout << c << endl;


	return 0;
}

