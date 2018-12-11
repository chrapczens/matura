#include <iostream>
#include <fstream>
#include <math.h>

#define L 1095

using namespace std;

int konwersja_dec(string kod, unsigned short podstawa)
{
	if (kod.length() == 0)
	{
		return 0;
	}

	int s = 0;
	int i = 0;
	int l = kod.length() - 1;

	while(i <= l)
	{
		s += pow(podstawa, l - i) * (kod[i] - '0');

		++i;
	}

	return s;
}

string konwersja_bin(int k)
{
	string bin = "";
	int absk = abs(k);

	while(absk > 0)
	{
		if (absk % 2 == 0)
		{
			bin = "0" + bin;
		}
		else
		{
			bin = "1" + bin;
		}

		absk = absk / 2;
	}

	if (k < 0)
	{
		bin = "-" + bin;
	}

	return bin;
}

void czytanie(int s[L][2], string sciezka, unsigned short podstawa)
{
	fstream plik;

	plik.open(sciezka, ios::in);

	if (plik.good())
	{
		int g;
		int t;

		string linia;
		string godzina;
		string temp;

		int i = 0;
		while(!plik.eof())
		{
			plik >> godzina;
			plik >> temp;

			g = konwersja_dec(godzina, podstawa);

			if (temp.length() > 0 && temp[0] == '-')
			{
				t = konwersja_dec(temp.substr(1), podstawa);
				t = -1*t;
			}
			else
			{
				t = konwersja_dec(temp, podstawa);
			}

			s[i][0] = g;
			s[i][1] = t;

			++i;
		}
	}
	plik.close();
}

int szukanie_min(int s[L][2])
{
	int min = 100;

	for(int i = 0; i < L; ++i)
	{
		if (s[i][1] < min)
		{
			min = s[i][1];
		}
	}

	return min;
}

int main()
{
	int s1[L][2];
	int s2[L][2];
	int s3[L][2];

	czytanie(s1, "./../data/58/dane_systemy1.txt", 2);
	czytanie(s2, "./../data/58/dane_systemy2.txt", 4);
	czytanie(s3, "./../data/58/dane_systemy3.txt", 8);

	unsigned wskazanie = 0;
	unsigned licznik = 0;

	for(int i = 0; i < L; ++i)
	{
		wskazanie = 12 + 24*i;

		if (s1[i][0] != wskazanie && s2[i][0] != wskazanie && s3[i][0] != wskazanie)
		{
			++licznik;
		}
	}
	cout << "Liczba pomiarow z niepoprawnym stanem zegara " << licznik << endl;

	system("pause");

	return 0;
}