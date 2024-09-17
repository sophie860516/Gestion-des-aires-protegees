#include <string.h> 
#include <iostream> 
#include <wx/wx.h>
#include "RcheDlgPays.h"
#include "AirePtgApp.h"
using namespace std;
//Dialog pour recherche par pays
RcheDlgPays::RcheDlgPays(wxWindow* parent, const wxString& title)
    : wxDialog(parent, -1, title, wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER){

    // vertical sizer
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    
    pays = new wxTextCtrl(this, -1);
        
    // grid size avec une ligne et 2 colonnes
    wxFlexGridSizer *textSizer = new wxFlexGridSizer(1, 2, 30, 30);
    
    // contrôle de texte
    textSizer->Add(new wxStaticText(this, -1, "Pays "),1, wxEXPAND| wxALL, 10); 
    
    textSizer->Add(pays, 1, wxEXPAND| wxALL, 10);

    // bouton
    wxButton *button = new wxButton(this, ID_BUTTON_CLICK, "Rechercher");
    dialogSizer->Add(textSizer, 0, wxALIGN_CENTER);
    dialogSizer->Add(button,0, wxALIGN_CENTER | wxALL, 10); 
    
    SetSizer(dialogSizer); 
    dialogSizer->Fit(this); 
}

RcheDlgPays::~RcheDlgPays() {}

BEGIN_EVENT_TABLE(RcheDlgPays, wxDialog)
    EVT_BUTTON(ID_BUTTON_CLICK, RcheDlgPays::OnButtonClick)
END_EVENT_TABLE()
void RcheDlgPays::OnButtonClick(wxCommandEvent &event) {
    event.Skip();
}
//Retourner le résultat de la recherche. Appelée dans TexteFrame::OnRchePays
wxString RcheDlgPays::GetTexte(){
    string cible = pays->GetValue().ToStdString();
    string temp="" ;
    return AirePtgApp::recherchePays(cible,temp);
}