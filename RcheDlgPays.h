/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheDlgPays.h
    But du programme: Déclaration de la classe RcheDlgPays 
*/
#ifndef RCHEPAYS_H
#define RCHEPAYS_H

class RcheDlgPays : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    RcheDlgPays(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~RcheDlgPays();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);
    wxString GetTexte();
protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *pays;
    enum {
        ID_BUTTON_CLICK = wxID_OK
    };
};
#endif