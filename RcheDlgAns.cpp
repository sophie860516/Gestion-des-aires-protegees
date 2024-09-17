/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheDlgAns.cpp
    But du programme: Définition de la classe RcheDlgAns 
*/
#include <string> 
#include <iostream> 
#include <wx/wx.h>
#include "AirePtgApp.h"
#include "RcheDlgAns.h"
using namespace std;
//Dialog pour recherche par année
RcheDlgAns::RcheDlgAns(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    // vertical sizer
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    ans = new wxTextCtrl(this, -1);
        
    // grid sizer avec 1 ligne et 2 colonnes 
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(1, 2, 30, 30);
    
    // contrôle de texte
    textSizer->Add(new wxStaticText(this, -1, "Ans "),
        1, wxEXPAND| wxALL, 10); 
    
    textSizer->Add(ans, 1, wxEXPAND| wxALL, 10);

    // bouton
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Rechercher");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,0, wxALIGN_CENTER | wxALL, 10); 
    
    SetSizer(dialogSizer); 
    dialogSizer->Fit(this); 
}

RcheDlgAns::~RcheDlgAns() {}

BEGIN_EVENT_TABLE(RcheDlgAns, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, RcheDlgAns::OnButtonClick)
END_EVENT_TABLE()
void RcheDlgAns::OnButtonClick(wxCommandEvent &event) {
    event.Skip();
}
//Retourner le résultat de la recherche. Appelée dans TexteFrame::OnRcheAns
wxString RcheDlgAns::GetTexte(){
    string annee = ans->GetValue().ToStdString();
    string temp;
    return AirePtgApp::rechercheAns(annee,temp );
}