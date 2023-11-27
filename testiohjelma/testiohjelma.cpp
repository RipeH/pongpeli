#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eSuun {
	STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };	//nimet‰‰n koordinaatit mit‰ k‰ytet‰‰n

class cPallo	//Luodaan palloluokka
{
private:
	int x, y;
	int origX, origY;
	eSuun suunta;


public:
	cPallo(int posX, int posY)		//annetaan palloluokalle sijainti ja aloituspiste
	{
		origX = posX;
		origY = posY;
		x = posX; y = posY;
		suunta = STOP;
	}

	void Reset()		//Alotetaan peli alusta
	{
		x = origX; y = origY;
		suunta = STOP;
	}
	void suunnanmuutos(eSuun d)		//Luodaan suunnanmuutoksille omat funktiot
	{
		suunta = d;
	}
	void randomsuunta()
	{
		suunta = (eSuun)((rand() % 6) + 1);
	}
	inline int haeX() { return x; }
	inline int haeY() { return y; }
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
		o << "Pallo [" << c.x << "," << c.y << "][" << c.suunta << "]";
		return o;
	}
 };

 class cMaila
 {
 private:
	 int x, y;
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
	 inline int haeX() { return x; }
	 inline int haeY() { return y; }
	 inline void liikuYlos() { y--; }
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
	 cPallo* pallo;
	 cMaila* pelaaja1;
	 cMaila* pelaaja2;
 
 public:
	 cPelimoottori(int l, int k)
	 {
		 srand(time(NULL));			//Annetaan mailoille ohjausnapit, sek‰ kent‰n leveys ja pallon sijainti
		 quit = false;
		 ylos1 = 'w'; ylos2 = 'i';
		 alas1 = 's'; alas2 = 'k';
		 pisteet1 = pisteet2 = 0;
		 leveys = l; korkeus = k;
		 pallo = new cPallo(l / 2, k / 2);
		 pelaaja1 = new cMaila(1, k / 2 - 3);
		 pelaaja2 = new cMaila(l - 2, k / 2 - 3);
	 }
	 ~cPelimoottori()
	 {
		 delete pallo, pelaaja1, pelaaja2;			//Poistetaan vanhat tiedot aina uuteen peliin
	 }
	 void pisteLisays(cMaila* pelaaja)
	 {
		 if (pelaaja == pelaaja1)
			 pisteet1++;
		 else if (pelaaja == pelaaja2)
			 pisteet2++;

		 pallo->Reset();

		 pelaaja1->Reset();
		 pelaaja2->Reset();
	 }
	 void piirto()
	 {
		 system("cls");									//Annetaan koko pelikent‰n tiedot mink‰kokoinen yms.
		 for (int i = 0; i < leveys + 2; i++)
			 cout << "\xB2";
		 cout << endl;


		 for (int i = 0; i < korkeus; i++)			
		 
		 {
			 for (int j = 0; j < leveys; j++)
			 {
				 int pallox = pallo->haeX();
				 int palloy = pallo->haeY();
				 int pelaaja1x = pelaaja1->haeX();
				 int pelaaja2x = pelaaja2->haeX();
				 int pelaaja1y = pelaaja1->haeY();
				 int pelaaja2y = pelaaja2->haeY();

				 if (j == 0)
					 cout << "\xB2";

				 if (pallox == j && palloy == i)
					 cout << "0"; //pallo on t‰ss‰
				 else if (pelaaja1x == j && pelaaja1y == i)
					 cout << "\xDB"; //pelaaja 1 t‰ss‰
				 else if (pelaaja2x == j && pelaaja2y == i)
					 cout << "\xDB"; //pelaaja 2 t‰ss‰
				
				 
				 else if (pelaaja1x == j && pelaaja1y + 1 == i)
					 cout << "\xDB"; //pelaaja 1
				 else if (pelaaja1x == j && pelaaja1y + 2 == i)
					 cout << "\xDB";
				 else if (pelaaja1x == j && pelaaja1y + 3 == i)
					 cout << "\xDB";

				 else if (pelaaja2x == j && pelaaja2y + 1 == i)
					 cout << "\xDB"; //pelaaja 2
				 else if (pelaaja2x == j && pelaaja2y + 2 == i)
					 cout << "\xDB";
				 else if (pelaaja2x == j && pelaaja2y + 3 == i)
					 cout << "\xDB";
				 else			//T‰m‰ kohta t‰ss‰, hakkasin p‰‰t‰ sein‰‰n kauan mutta piti vain lis‰t‰ v‰lilyˆnti niin korjaantu sein‰t.
					 cout << " ";


				 if (j == leveys - 1)
					 cout << "\xB2";
			}
			 cout << endl;
		 }
		 for (int i = 0; i < leveys + 2; i++)
			 cout << "\xB2";
		 cout << endl;

		 cout << "Pelaaja 1 pisteet: " << pisteet1 << endl << "Pelaaja 2 pisteet: " << pisteet2 << endl;
	 }	 
	 void input()			//Luodaan ohjauskomennot mailoille
	 {
		 pallo->liiku();

		 int pallox = pallo->haeX();
		 int palloy = pallo->haeY();
		 int pelaaja1x = pelaaja1->haeX();
		 int pelaaja2x = pelaaja2->haeX();
		 int pelaaja1y = pelaaja1->haeY();
		 int pelaaja2y = pelaaja2->haeY();

		 if (_kbhit())				//N‰pp‰imistˆn klikkauksesta ylˆs, alas yms.
		 {
			 char current = _getch();
			 if (current == ylos1)
				 if (pelaaja1y > 0)
					 pelaaja1->liikuYlos();
			 
			 if (current == ylos2)
				 if (pelaaja2y > 0)
					 pelaaja2->liikuYlos();
			 
			 if (current == alas1)
				 if (pelaaja1y + 4 < korkeus)
					 pelaaja1->liikuAlas();

			 if (current == alas2)
				 if (pelaaja2y + 4 < korkeus)
					 pelaaja2->liikuAlas();

			 if (pallo->haesuunta() == STOP)
				 pallo->randomsuunta();

			 if (current == 'q')
				 quit = true;

		 }
	 }
	 void logiikka()
	 {
		 int pallox = pallo->haeX();
		 int palloy = pallo->haeY();
		 int pelaaja1x = pelaaja1->haeX();
		 int pelaaja2x = pelaaja2->haeX();
		 int pelaaja1y = pelaaja1->haeY();
		 int pelaaja2y = pelaaja2->haeY();
		
		 
		 //vasen maila
		 for (int i = 0; i < 4; i++)
			 if (pallox == pelaaja1x + 1)
				 if (palloy == pelaaja1y + i)
					 pallo->suunnanmuutos((eSuun)((rand() % 3) + 4));
		 //oikea maila
		 for (int i = 0; i < 4; i++)
			 if (pallox == pelaaja2x - 1)
				 if (palloy == pelaaja2y + i)
					 pallo->suunnanmuutos((eSuun)((rand() % 3) + 1));
		
		 //alasein‰
		 if (palloy == korkeus - 1)
			 pallo->suunnanmuutos(pallo->haesuunta() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		 //yl‰sein‰
		 if (palloy == 0)
			 pallo->suunnanmuutos(pallo->haesuunta() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		 //oikeanpuoleinen sein‰
		 if (pallox == leveys - 1)
			 pisteLisays(pelaaja1);
		 //vasemmanpuoleinen sein‰
		 if (pallox == 0)
			 pisteLisays(pelaaja2);

	 }
	 void run()
		 {
			 while (!quit)
			 {
				 piirto();
				 input();
				 logiikka();


			 }
		 }
	 

 };
int main()
{
	cPelimoottori c(40, 20);
	c.piirto();
	c.run();
	return 0;
}

