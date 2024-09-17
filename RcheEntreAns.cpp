/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheEntreAns.cpp
    But du programme: Définition de la classe RcheEntreAns 
*/

#include <string.h> 
#include <iostream> 
#include <wx/wx.h>
#include "AirePtgApp.h"
#include "RcheEntreAns.h"

//Dialog pour recherche entre années
RcheDlgEntreAns::RcheDlgEntreAns(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    //vertical sizer
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    ans1 = new wxTextCtrl(this, -1);
    ans2 = new wxTextCtrl(this, -1);  
    // grid sizer avec 2 lignes et 2 colonnes
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(2, 2, 30, 60);
    
    // contrôle de texte
    textSizer->Add(new wxStaticText(this, -1, "Année de début "),1, wxEXPAND| wxALL, 10);
    
    textSizer->Add(ans1, 1, wxEXPAND| wxALL, 10);
    textSizer->Add(new wxStaticText(this, -1, "Annee de fin "), 1, wxEXPAND| wxALL, 10);
    textSizer->Add(ans2, 1, wxEXPAND| wxALL, 10);
    // Adding button control
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Rechercher");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,0, wxALIGN_CENTER | wxALL, 10); 
    
    SetSizer(dialogSizer);
    dialogSizer->Fit(this); 
}

RcheDlgEntreAns::~RcheDlgEntreAns() {}

BEGIN_EVENT_TABLE(RcheDlgEntreAns, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, RcheDlgEntreAns::OnButtonClick)
END_EVENT_TABLE()
void RcheDlgEntreAns::OnButtonClick(wxCommandEvent &event) {
    event.Skip();
}
//Retourner le résultat de la recherche. Appelée dans TexteFrame::OnRcheEntreAns
wxString RcheDlgEntreAns::GetTexte(){
    string an1 = ans1->GetValue().ToStdString();
    string an2 = ans2->GetValue().ToStdString();
    string temp="" ;
    return AirePtgApp::rechercheEntreAns(an1,an2,temp);
}