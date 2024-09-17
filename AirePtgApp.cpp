/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: AirePtgApp.cpp
    But du programme: Création du cadre pour l'application, incluant l'ajout dans la 
                      base de données, la sauvagarde du fichier, la sauvgarde de base 
                      de données et les fontions de recherche. 
*/
#include <wx/wx.h>//pour créer un cadre 
#include <vector>//vecteur pour la base de données
#include <string>
#include <iostream> //entrée sortie
#include <fstream> //lecture et écriture de fichier
#include "Aire.h" //fichier d'en-tête pour la classe Aire
#include "AirePtgApp.h"//fichier d'en-tête pour la classe AirePtgApp
#include "RcheDlgPays.h"//fichier d'en-tête pour la classe RcheDlgPays
#include "RcheDlgAns.h"//fichier d'en-tête pour la classe RcheDlgAns
#include "RcheDlgNom.h"//fichier d'en-tête pour la classe RcheDlgNom
#include "RcheEntreAns.h"//fichier d'en-tête pour la classe RcheEntreAns

using namespace std;


IMPLEMENT_APP(AirePtgApp)

//créer un vector global en guise de base de données
vector<Aire> VAire;

//lire un fichier et remplir le vecteur
void  lireRemplir(string nomFichier, vector<Aire> & VAire)
{
	ifstream  aLire; // localiser et ouvrir pour la lecture
	string ligne, nom, pays, longtitude, latitude, surface, année;
	
	aLire.open(nomFichier, ios::in);
	if(!aLire.is_open()){
		cout<<"erreur "<<endl;
		exit(1);
	}
	while (aLire>>quoted(nom)>>quoted(pays)>>quoted(longtitude)>>quoted(latitude)>>quoted(surface)>>quoted(année))
	{
		VAire.push_back(Aire(nom, pays, longtitude, latitude, surface,année));
    }
	aLire.clear();  //nettoyer toutes les exceptions levées
	aLire.close();  // fermer le fichier à lire
}
//enregistrer le contenu du vecteur dans un fichier
void lireVecteur(vector<Aire> &VAire,string fnom){
	string filename = fnom;
	fstream inout;
	// Si le fichier existe deja, son contenu est efface.
	inout.open(filename, ios::trunc| ios::in | ios::out);
    
	if (!inout.is_open()) {
		cerr << "erreur a l'ouverture du fichier!\n";
		exit(1);
	}
	// ecriture du texte dans le fichier choisi

	for (vector<Aire>::iterator il = VAire.begin(); il!=VAire.end(); ++il){
		inout << il->afficheWx() << endl;
    }
	inout.clear(); //nettoyer toutes les exceptions levées
	inout.close(); // fermer le fichier à remplir
}

//chercher par le nom
string AirePtgApp::rechercheNom(Aire aChercher){
	vector<Aire> :: iterator cestlui = find(VAire.begin(), VAire.end(), aChercher);
	if(cestlui!=VAire.end()){
		return cestlui->afficheWx();
	}else{
        string Na = "Non trouvé";
		return Na;
	}
}

//chercher par l'année
string AirePtgApp::rechercheAns(string an,string temp){
	//utiliser for_each
	auto AireParAn = [an, &temp](Aire &A){ 
		if(A.getAns() == an){
            
            temp += A.afficheWx() + "\n";
        }
	};
	for_each(VAire.begin(), VAire.end(),AireParAn);
    return temp;
}
//cherche par pays
string AirePtgApp::recherchePays(string pays,string temp){
	auto AireParPays = [pays, &temp](Aire& A){ 
		if(A.getPays() == pays )
		temp  += A.afficheWx() + "\n";
	};
	for_each(VAire.begin(), VAire.end(), AireParPays);
    return temp;
}

//Rechercher les aires répertoriées entre l’année A (début) et l’année B (fin inclusivement).
string AirePtgApp::rechercheEntreAns(string an1, string an2,string temp){
	auto AireEntreAns = [an1, an2, &temp](Aire& A){
		if (A.getAns()>=an1 && A.getAns()<=an2){
            temp += A.afficheWx() + "\n";
		}
	};
	for_each(VAire.begin(), VAire.end(), AireEntreAns);
    return temp;
}
bool AirePtgApp::OnInit() {

 
    const wxString Titre("Base de données des aires protégés");
    
    TexteFrame *frame = new TexteFrame(Titre,100, 100, 700, 500);

  
    frame->Show(TRUE);
    
    SetTopWindow(frame);
    
    return true;

}
//Constructeur de TexteFrame
TexteFrame::TexteFrame
                (const wxString titre,
                    int xpos, int ypos,
                    int width, int height)
                : wxFrame
                    ( (wxFrame *) NULL,
                    -1,
                    titre,
                    wxPoint(xpos, ypos),
                    wxSize(width, height)
                ){

 
    // Initialisation du pointeur à la valeur "NULL castée"
    leTexte = (wxTextCtrl *) NULL;
    menuBar = (wxMenuBar *) NULL;
    fichierMenu = (wxMenu *) NULL; 
    infoMenu =  (wxMenu *) NULL;
    
    leTexte = new wxTextCtrl
                ( this,
                    -1,
                    wxString::FromUTF8("Le contenu de la base de donn"+wxString::FromUTF8("\xc3\xa9")+
                    "et les r"+wxString::FromUTF8("\xc3\xa9")+"sultat des recherches s'afficheront ici\n"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_MULTILINE|wxTE_RICH2
                    );
                    
    //créer une instance de wxMenu pour " Fichier "
    fichierMenu = new wxMenu;
    fichierMenu->Append(ID_OUVRIR,  "&Ouvrir fichier\tCTRL-O");
    fichierMenu->Append(ID_SAUVEGARDER_SOUS, "&Sauvegarder sous\tCTRL-S");
    fichierMenu->Append(ID_ENREGISTRER_SOUS, "&Enregistrer sous\tF11");
    fichierMenu->AppendSeparator();
    fichierMenu->Append(ID_QUITTER,  "&Quitter\tCTRL-Q");
    
    // Place à la création du menu " Apropos "
    infoMenu = new wxMenu();
    infoMenu->Append(ID_AIDE, "&Aide\tF1");
    infoMenu->Append(ID_APROPOS, "&Apropos\tF2");
     
    //Place à la création du menu " Ajout "
    ajoutMenu = new wxMenu();
    ajoutMenu->Append(ID_AJOUTFICHIER, "&Ajout Fichier\tF3");
    ajoutMenu ->Append(ID_AJOUTINFOAIRE, "&Ajout Info Aire\tF4");
    ajoutMenu ->Append(ID_AJOUTANSAIRE, "&Ajout Ans Aire\tF5");
    //Place à la création du menu " Recherche "
    rechercheMenu = new wxMenu();
    rechercheMenu->Append(ID_RECHERCHENOM, "&Recherche Par Nom\tF6");
    rechercheMenu->Append(ID_RECHERCHEANS, "&Recherche Par Ans\tF7");
    rechercheMenu->Append(ID_RECHERCHEENTREANS, "&Recherche Entre 2 ann"+wxString::FromUTF8("\xc3\xa9")+"es\tF8");
    rechercheMenu->Append(ID_RECHERCHEPAYS, "&Recherche Par Pays\tF9");
    
    //Ce bloc consiste à créer le menu bar
    menuBar = new wxMenuBar;
    menuBar->Append(fichierMenu, "&Fichier");
    menuBar->Append(infoMenu, "&Info");
    menuBar->Append(ajoutMenu, "&Ajout");
    menuBar->Append(rechercheMenu, "&Recherche");     
    
    //ajouter la barre de menus à notre cadre
    SetMenuBar(menuBar);
}

//destructeur
TexteFrame::~TexteFrame(){}

//Event table pour quand on clique sur le bouton sur le menubar
BEGIN_EVENT_TABLE(TexteFrame, wxFrame)
    EVT_MENU(ID_OUVRIR, TexteFrame::OnFichierOuvrir)
    EVT_MENU(ID_SAUVEGARDER_SOUS, TexteFrame::OnFichierSauvegarderSous)
    EVT_MENU(ID_ENREGISTRER_SOUS, TexteFrame::OnEnregistrerSous)
    EVT_MENU(ID_QUITTER, TexteFrame::OnFichierQuitter)
    EVT_MENU(ID_APROPOS, TexteFrame::OnInfoApropos)
    EVT_MENU(ID_AIDE, TexteFrame::OnAide)
    EVT_MENU(ID_AJOUTFICHIER, TexteFrame::OnAjoutFichier)
    EVT_MENU(ID_AJOUTINFOAIRE, TexteFrame::OnAjoutInfoAire)
    EVT_MENU(ID_AJOUTANSAIRE, TexteFrame::OnAjoutAnsAire)
    EVT_MENU(ID_RECHERCHENOM, TexteFrame::OnRcheNom)
    EVT_MENU(ID_RECHERCHEANS, TexteFrame::OnRcheAns)
    EVT_MENU(ID_RECHERCHEPAYS, TexteFrame::OnRchePays)
    EVT_MENU(ID_RECHERCHEENTREANS, TexteFrame::OnRcheEntreAns)
END_EVENT_TABLE()

//Ouvrir un fichier dialog. Écrire le contenu du fichier choisi dans le textframe et remplir le vecteur 
void TexteFrame::OnFichierOuvrir(wxCommandEvent &event){
    wxFileDialog *dlg = new wxFileDialog(this, "Ouvrir un fichier texte", "", "",
        "Tous les fichiers(*.*)|*.*|Fichiers textes(*.txt)|*.txt", wxFD_OPEN, wxDefaultPosition);
    
    if ( dlg->ShowModal() == wxID_OK ){
        wxString fileName = dlg->GetPath();
        leTexte->LoadFile(fileName);
        lireRemplir(fileName.ToStdString(),VAire);//remplir le vecteur
        wxLogMessage("Ajout r"+wxString::FromUTF8("\xc3\xa9")+"ussi!");
    } 
    dlg->Destroy();
}
//Sauvgarder le contenu dans le textframe si il y a des changements
void TexteFrame::OnFichierSauvegarderSous(wxCommandEvent &event){
    wxFileDialog *dlg = new wxFileDialog(this, "Sauvegarder sous", "", "",
        "Tous les fichiers(*.*)|*.*|Fichiers textes(*.txt)|*.txt", wxFD_SAVE, wxDefaultPosition);
    
    if ( dlg->ShowModal() == wxID_OK ){
        wxString fileName = dlg->GetPath();
        leTexte->SaveFile(fileName);
    }
    dlg->Destroy();
}
//Sauvgarder la base de données (le vecteur)
void TexteFrame::OnEnregistrerSous(wxCommandEvent &event){
    wxFileDialog *dlg = new wxFileDialog(this, "Enregistrer sous", "", "",
        "Tous les fichiers(*.*)|*.*|Fichiers textes(*.txt)|*.txt", wxFD_SAVE, wxDefaultPosition);
    if ( dlg->ShowModal() == wxID_OK ){
        wxString fileName = dlg->GetFilename();
        lireVecteur(VAire, fileName.ToStdString());
    }
    dlg->Destroy();
}
//Quitter le programme
void TexteFrame::OnFichierQuitter(wxCommandEvent &event){
    Close(FALSE);
}
//Ouvrir l'aide en ligne 
void TexteFrame::OnAide(wxCommandEvent &event){
/*
    wxFileDialog *dlg = new wxFileDialog(this, "Aide en ligne", "", "aide.txt",
        "Tous les fichiers(*.*)|*.*|Fichiers textes(*.txt)|*.txt", wxFD_OPEN, wxDefaultPosition);
    if ( dlg->ShowModal() == wxID_OK ){
        wxString fileName = dlg->GetPath();
        leTexte->AppendText("Aide en ligne ");
        leTexte->LoadFile(fileName);    
        //wxTextFile tfile(fileName);
        //tfile.Open();
    }
    dlg->Destroy();
*/
    wxString text = 
    "Aide en ligne pour le logiciel AirePtgApp (Aire Protégée App):\nIl s'agit d'une base de données permettant le stockage et la recherche des aires protégées.\nle stockage est possible à partir d'un fichier ou en utilisant le bouton Ajout\n la recherche est effectuée selon le nom, l'année, le pays ou l'intervalle.";


    wxMessageDialog *dlg = new wxMessageDialog(this, text.c_str(),
        "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
        dlg->ShowModal();
        dlg->Destroy();
}
//Afficher le apropos du programme
void TexteFrame::OnInfoApropos(wxCommandEvent &event){
    wxString MonInfo = "À propos d'AirePtgApp\nVersion 1.0\nConcepteur: Ting-Wei Chuang\nTous droits réserv"+wxString::FromUTF8("\xc3\xa9")+"s";
    wxMessageDialog *dlg = new wxMessageDialog(this, MonInfo,
    "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
    dlg->ShowModal();
    dlg->Destroy();
}
//Ajouter une instance d'Aire dans le vecteur en ouvrant un nouveau fichier 
void TexteFrame::OnAjoutFichier(wxCommandEvent &event){
       wxFileDialog *dlg = new wxFileDialog(this, "Ouvrir un fichier texte", "", "",
        "Tous les fichiers(*.*)|*.*|Fichiers textes(*.txt)|*.txt", wxFD_OPEN, wxDefaultPosition);
    
    if ( dlg->ShowModal() == wxID_OK ){
        wxString fileName = dlg->GetPath();
        leTexte->LoadFile(fileName);
        lireRemplir(fileName.ToStdString(),VAire);//remplir le vecteur
        wxLogMessage("Ajout r"+wxString::FromUTF8("\xc3\xa9")+"ussi!");
    }
    dlg->Destroy();
}

//Ajouter une aire dans le vecteur en fournissant ses infos 
void TexteFrame::OnAjoutInfoAire(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez les infos pour ajouter une aire");
    AireDialog *AireDlg = new AireDialog(NULL,montexte);
    AireDlg ->ShowModal();
    AireDlg->Destroy();
    
}
//Ajouter une aire en fournissant son nom et l'année 
void TexteFrame::OnAjoutAnsAire(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez le nom et l'ans pour ajouter une aire");
    AireDialogAns *AireDlgAns = new AireDialogAns(NULL,montexte);
    AireDlgAns ->ShowModal();
    AireDlgAns->Destroy();
}
//Recherche par nom et affiche le résultat sur le textctrl
void TexteFrame::OnRcheNom(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez le nom de l'aire");
    RcheDlgNom * DlgNoms = new RcheDlgNom(NULL,montexte);
    DlgNoms->ShowModal();
    DlgNoms->Destroy();

 }
//Recherche par année et affiche le résultat sur le textctrl
void TexteFrame::OnRcheAns(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez l'ans de l'aire");
    RcheDlgAns * DlgAns = new RcheDlgAns(NULL,montexte);
    wxMessageDialog *dlg = new wxMessageDialog(this, "Recherche termin"+wxString::FromUTF8("\xc3\xa9")+"e",
    "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
    if(DlgAns->ShowModal()==wxID_OK){
        leTexte->AppendText("---------------------------\n");
        leTexte->AppendText("Résultat de la recherche\n");
        if(DlgAns->GetTexte().size() > 0){
            leTexte->AppendText(DlgAns->GetTexte());
        }else{
            leTexte->AppendText("Pas d'aire pour l'ann"+wxString::FromUTF8("\xc3\xa9")+"e"+" recherch"+wxString::FromUTF8("\xc3\xa9"));
        }
        leTexte->AppendText("\nFin de r"+wxString::FromUTF8("\xc3\xa9")+"sultat\n");
        leTexte->AppendText("---------------------------");
    }else{
        leTexte->AppendText("Annuler ");
    }
    dlg->ShowModal();
    dlg->Destroy();
    DlgAns->Destroy();
 }
 //Recherche par pays et affiche le résultat sur le textctrl
 void TexteFrame::OnRchePays(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez le pays de l'aire");
    RcheDlgPays * DlgPays = new RcheDlgPays(NULL,montexte);
    wxMessageDialog *dlg = new wxMessageDialog(this, "Recherche termin"+wxString::FromUTF8("\xc3\xa9")+"e",
    "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
   if(DlgPays->ShowModal()==wxID_OK){
        leTexte->AppendText("---------------------------\n");      
        leTexte->AppendText("R"+wxString::FromUTF8("\xc3\xa9")+"sultat de la recherche\n");
        if(DlgPays->GetTexte().size() > 0){
            leTexte->AppendText(DlgPays->GetTexte());
        }else{
            leTexte->AppendText("Pas d'aire pour le pays recherch"+wxString::FromUTF8("\xc3\xa9"));
        }
        leTexte->AppendText("\nFin de r"+wxString::FromUTF8("\xc3\xa9")+"sultat\n");
        leTexte->AppendText("---------------------------");
    }else{
        leTexte->AppendText("Annuler ");
    }
    dlg->ShowModal();
    dlg->Destroy();
    DlgPays->Destroy();

 }
 //Recherche par l'intervalle d'année et affiche le résultat sur le textctrl
 void TexteFrame::OnRcheEntreAns(wxCommandEvent &event){
    wxString montexte = wxString::FromUTF8("Entrez les ann"+wxString::FromUTF8("\xc3\xa9")+"es");
    RcheDlgEntreAns * DlgEAns = new RcheDlgEntreAns(NULL,montexte);
    wxMessageDialog *dlg = new wxMessageDialog(this, "Recherche termin"+wxString::FromUTF8("\xc3\xa9")+"e",
        "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
   if(DlgEAns->ShowModal()==wxID_OK){
        leTexte->AppendText("---------------------------\n");
        leTexte->AppendText("R"+wxString::FromUTF8("\xc3\xa9")+"sultat de la recherche\n");
        if(DlgEAns->GetTexte().size() > 0){
            leTexte->AppendText(DlgEAns->GetTexte());
        }else{
            leTexte->AppendText("Pas d'aire pour l'intervalle recherch"+wxString::FromUTF8("\xc3\xa9"));
        }
        leTexte->AppendText("\nFin de r"+wxString::FromUTF8("\xc3\xa9")+"sultat\n");
        leTexte->AppendText("---------------------------");
    }else{
        leTexte->AppendText("Annuler ");
    }
    dlg->ShowModal();
    dlg->Destroy();
    DlgEAns->Destroy();
    
 }
 
//AireDialog sera ouvert pour recevoir des informations pour créer une aire

AireDialog::AireDialog(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    // Sizer vertical
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    nom = new wxTextCtrl(this, -1);
    pays = new wxTextCtrl(this, -1);
    longtitude = new wxTextCtrl(this, -1);
    latitude = new wxTextCtrl(this, -1);
    surface = new wxTextCtrl(this, -1);
    an = new wxTextCtrl(this, -1);
    
    // grid sizer avec 2 colonnes et 6 lignes
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(6, 2, 50, 50);
    
    // static text control
    textSizer->Add(new wxStaticText(this, -1, "Nom "),1,wxEXPAND| wxALL, 10);
    textSizer->Add(nom, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Pays "), 1, wxEXPAND| wxALL,10);
    textSizer->Add(pays, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Longtitude "), 1, wxEXPAND| wxALL,10);
    textSizer->Add(longtitude, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Latitude "), 1, wxEXPAND| wxALL,10);
    textSizer->Add(latitude, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Surface "), 1, wxEXPAND| wxALL,10);
    textSizer->Add(surface, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Ann"+wxString::FromUTF8("\xc3\xa9")+"e "), 1, wxEXPAND| wxALL,10);
    textSizer->Add(an, 1, wxEXPAND| wxALL,10);
    // Ajouter button control
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Ajouter");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,
        0, //interdire d'ajuster verticallement
        wxALIGN_CENTER | wxALL, 10); // centré le bouton
    
    SetSizer(dialogSizer); // Utiliser dialog sizer pour la disposition
    dialogSizer->Fit(this); // Fit dialog aux éléments d'AireDialog
}
//Destructeur
AireDialog::~AireDialog() {}

BEGIN_EVENT_TABLE(AireDialog, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, AireDialog::OnButtonClick)
END_EVENT_TABLE()
//Créer une Aire à partir des infos reçus, l'ajouter dans le vecteur après la clique sur le bouton ajouter 
void AireDialog::OnButtonClick(wxCommandEvent &event) {
    string n = nom->GetValue().ToStdString();
    string p = pays->GetValue().ToStdString();
    string lo = longtitude->GetValue().ToStdString();
    string la = latitude->GetValue().ToStdString();
    string surf = surface->GetValue().ToStdString();
    string annee = an->GetValue().ToStdString();
    VAire.push_back(Aire(n,p,lo,la,surf,annee));

    wxString text = n + " est ajout"+ wxString::FromUTF8("\xc3\xa9")+ " dans la base de donn"+ wxString::FromUTF8("\xc3\xa9") +"e";
    wxMessageDialog *dlg = new wxMessageDialog(this, text.c_str(),
        "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
    dlg->ShowModal();
    dlg->Destroy();
}

//Dialog pour ajouter par nom et annee initialisation
AireDialogAns::AireDialogAns(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    // Créer un vertical sizer
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    nom = new wxTextCtrl(this, -1);
    an = new wxTextCtrl(this, -1);
    
    // Créer un grid sizer de 2 colonnes et 2 lignes 
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(2, 2, 50, 50);
    
    // Ajouter contrôle de texte
    textSizer->Add(new wxStaticText(this, -1, "Nom"),1,wxEXPAND| wxALL,10); 
    
    textSizer->Add(nom, 1, wxEXPAND| wxALL,10);
    textSizer->Add(new wxStaticText(this, -1, "Ann"+wxString::FromUTF8("\xc3\xa9")+"e"), 1, wxEXPAND| wxALL,10);
    textSizer->Add(an, 1, wxEXPAND| wxALL,10);
    // Ajouter le bouton 
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Ajouter");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,0, wxALIGN_CENTER | wxALL, 10); 
    
    SetSizer(dialogSizer); 

    dialogSizer->Fit(this); 
}

AireDialogAns::~AireDialogAns() {}
BEGIN_EVENT_TABLE(AireDialogAns, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, AireDialogAns::OnButtonClick)
END_EVENT_TABLE()

void AireDialogAns::OnButtonClick(wxCommandEvent &event) {
    wxMessageDialog *dlg = new wxMessageDialog(this, "l'ann"+wxString::FromUTF8("\xc3\xa9")+"e est ajout"+wxString::FromUTF8("\xc3\xa9")+
    "e pour l'aire recherch"+wxString::FromUTF8("\xc3\xa9"),
    "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);    
    wxMessageDialog *dlg1 = new wxMessageDialog(this, "le nom de l'aire n'est pas trouv"+wxString::FromUTF8("\xc3\xa9"),
    "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
    
    vector<Aire> :: iterator cestlui = find(VAire.begin(), VAire.end(), Aire(nom->GetValue().ToStdString()));
	if(cestlui!=VAire.end()){
		cestlui->setAns(an->GetValue().ToStdString());
        dlg->ShowModal();
	}else{
        dlg1->ShowModal();
    }
    dlg->Destroy();
    dlg1->Destroy();
}
