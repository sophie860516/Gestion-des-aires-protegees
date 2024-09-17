/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheDlgNom.cpp
    But du programme: Définition de la classe RcheDlgNom 
*/

#include <string.h> 
#include <iostream> 
#include <wx/wx.h>
#include "AirePtgApp.h"
#include "RcheDlgNom.h"

//Dialog pour recherche par nom
RcheDlgNom::RcheDlgNom(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    // vertical sizer
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    nom = new wxTextCtrl(this, -1);
        
    //grid sizer avec une ligne et 2 colonnes
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(1, 2, 30, 30);
    
    // contrôle de texte
    textSizer->Add(new wxStaticText(this, -1, "Nom "),1, wxEXPAND| wxALL, 10); 
    
    textSizer->Add(nom, 1, wxEXPAND| wxALL, 10);
    // bouton
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Rechercher");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,0, wxALIGN_CENTER | wxALL, 10); 
    
    SetSizer(dialogSizer); 
    dialogSizer->Fit(this); 
}

RcheDlgNom::~RcheDlgNom() {}

BEGIN_EVENT_TABLE(RcheDlgNom, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, RcheDlgNom::OnButtonClick)
END_EVENT_TABLE()

//Afficher le résultat de la recherche dans un message dialogue
void RcheDlgNom::OnButtonClick(wxCommandEvent &event) {
    
    string n = nom->GetValue().ToStdString();
    wxString text= AirePtgApp::rechercheNom(n);//Appel de la fontions rechercheNom
       
    wxMessageDialog *dlg = new wxMessageDialog(this, text.c_str(),
        "Message", wxOK | wxCENTRE | wxICON_INFORMATION, wxDefaultPosition);
    dlg->ShowModal();
    dlg->Destroy();
}