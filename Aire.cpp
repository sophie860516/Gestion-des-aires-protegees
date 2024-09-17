#include <iostream> // entr�e-sortie standard
#include <iomanip>  // formatage (pr�sentation)
#include <string>   // cha�ne de caract�res 
#include <fstream>
#include "Aire.h"

using namespace std;

Aire::Aire(string nom, string pays, string longtitude, string latitude, string surface, string année){
	this->nom = nom;
	this->pays = pays;
	this->longtitude = longtitude;
	this->latitude = latitude;
	this->surface = surface;
	this->année = année;
}
Aire::Aire(string nom, string année){
	this->nom = nom;
	pays = "";
	longtitude = "";
	latitude = "";
	surface = "";
	this->année = année;
}
Aire::Aire(string nom){
	this->nom = nom;
	pays = "";
	longtitude = "";
	latitude = "";
	surface = "";
	année = "";
}
string Aire::getNom()const{
	return nom;
}
string Aire::getPays()const{
	return pays;
}
string Aire::getAns()const{
	return année;
}
void Aire::setAns(string ans2){
    année = ans2;
}

ostream& operator<<(ostream& out, const Aire& unAire){
	out<< "Noms: "<<unAire.getNom() << " Pays: "<< unAire.getPays() << " Année: "<<unAire.getAns();
	return out;
}

bool Aire::operator == (const Aire& a2){
	return nom == a2.getNom();
}

string Aire::afficheWx() const{
    return "\"" + nom + "\"" + " \""+ pays +"\""+" \""+longtitude+ "\""+"\""+latitude +"\""
	+"\""+surface+"\""+ "\""+année+"\"";
}

