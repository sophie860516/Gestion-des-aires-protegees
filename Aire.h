/*

fichier: Aire.h
*/
#include <iostream> // entr�e-sortie standard
#include <iomanip>  // formatage (pr�sentation)
#include <string>   // cha�ne de caract�res 
#include <fstream>


#ifndef AIRE_H
#define AIRE_H

using namespace std;

class Aire{
	private:
		string nom;
		string pays;
		string longtitude;
		string latitude;
		string surface;
		string année;
	public:
		//constructeur quans tous les champs de membre sont fournis
		Aire(string nom, string pays, string longtitude,string latitude, string surface, string année);	
		//constructeur pour seulement nom et année
		Aire(string nom, string année);
		//constructeur pour recherche par nom
		Aire(string nom);
		//méthodes get
		string getNom()const;
		string getPays()const;
		string getAns()const;
        //méthode set
        void setAns(string);
		//Pour afficher une aire
        string afficheWx()const;

		//surcharger l'opérateur <<
		friend ostream& operator<<(ostream&, const Aire&);
		//surcharger l'opérateur ==
		bool operator == (const Aire& a2);

};
#endif