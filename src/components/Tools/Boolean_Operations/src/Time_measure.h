#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H

#ifdef _MSC_VER

#include <windows.h>

class Time_measure
{
private:
	__int64 freq, t0; //la frequence de l'horloge et le temps initial

public:
	Time_measure() //Le constructeur qui va r�cup�rer la fr�quence de l'horloge
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		//On passe en param�tre � QueryPerformanceFrequency une structure LARGE_INTEGER qui est compos�e d'un __int64
		//Cette structure(i�i freq) va contenir la frequence de l'horloge
	}

	void Start()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&t0);
		//On fait pareil qu'au dessus mais cette fois t0 va contenir le temps au debut du chronometrage
	}

	double GetDiff()
	{
		__int64 t1; //le temps au moment de l'execution de la fonction
		QueryPerformanceCounter((LARGE_INTEGER*)&t1); //On assigne � t1 le temp au moment de l'execution de la fonction
		return (double)(t1 - t0) / freq; //La forumle qui permet de calculer le temps �coul�
		//Pour avoir le temps �coul�, on retranche le temps au moment de la fonction du temps au debut du chrono,
		//Puis on le multiplie par la pr�cision (1000000000) et on le divise par la frequence.
	}
};
#else

#include <ctime>

class Time_measure
{
private:
	double t0;

public:
	Time_measure() {}

	void Start() {t0 = clock();}

	double GetDiff()
	{
		return (double)((clock()-t0)/CLOCKS_PER_SEC);
	}
};

#endif // _MSC_VER

#endif // TIME_MEASURE_H
