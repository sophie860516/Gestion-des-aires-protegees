/*
    Auteur: Ting-Wei Chuang 20125388
    Fichier: AirePtgApp.h
    But du programme: fichier d'en-tête pour AirePtgApp.cpp
*/
#include <string.h>
#include "Aire.h"
#ifndef AIREPTGAPP_H
#define AIREPTGAPP_H

using namespace std;
class AirePtgApp : public wxApp {
public:
    virtual bool OnInit();
    static string recherchePays(string, string);
    static string rechercheAns(string,string);
    static string rechercheNom(Aire);
    static string rechercheEntreAns(string,string,string);
};

class TexteFrame : public wxFrame {
public:
       // constructeur
    TexteFrame( const wxString titre, int xpos, int ypos, 
               int width, int height);

    // destructeur
    ~TexteFrame();
    
    // Menu Fichier | Ouvrir
    void OnFichierOuvrir(wxCommandEvent &event);
    // Menu Fichier | Sauvegarder
    void OnFichierSauvegarderSous(wxCommandEvent &event);
    // Menu Fichier | Quitter
    void OnFichierQuitter(wxCommandEvent &event);
    // Menu Info | Apropos
    void OnAide(wxCommandEvent &event);
    void OnInfoApropos(wxCommandEvent &event);
    void OnAjoutFichier(wxCommandEvent &event);
    void OnAjoutInfoAire(wxCommandEvent &event);
    void OnAjoutAnsAire(wxCommandEvent &event);
    void OnRcheNom(wxCommandEvent &event);
    void OnRcheAns(wxCommandEvent &event);
    void OnEnregistrerSous(wxCommandEvent &event);
    void OnRchePays(wxCommandEvent &event);
    void OnRcheEntreAns(wxCommandEvent &event);
protected:
    DECLARE_EVENT_TABLE();
private:
    wxTextCtrl *leTexte;
    wxMenuBar *menuBar;
    wxMenu *fichierMenu; 
    wxMenu *infoMenu;
    wxMenu *ajoutMenu;
    wxMenu *rechercheMenu;
        
    enum {
        ID_QUITTER = 100,
        ID_OUVRIR,
        ID_SAUVEGARDER_SOUS,
        ID_AIDE,
        ID_APROPOS,
        ID_AJOUTFICHIER,
        ID_AJOUTINFOAIRE,
        ID_AJOUTANSAIRE,
        ID_RECHERCHENOM,
        ID_RECHERCHEANS,
        ID_ENREGISTRER_SOUS,
        ID_RECHERCHEPAYS,
        ID_RECHERCHEENTREANS
    }; 

};

class AireDialog : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    AireDialog(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~AireDialog();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);
protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *nom;
    wxTextCtrl *pays;
    wxTextCtrl *longtitude;
    wxTextCtrl *latitude;
    wxTextCtrl *surface;
    wxTextCtrl *an;
    enum {
        ID_BUTTON_CLICK = wxID_HIGHEST+1
    };
};

class AireDialogAns : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    AireDialogAns(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~AireDialogAns();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);

protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *nom;
    wxTextCtrl *an;
    enum {
        ID_BUTTON_CLICK = wxID_HIGHEST+1
    };
};
#endif
