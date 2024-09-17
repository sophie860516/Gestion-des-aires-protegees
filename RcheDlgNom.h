/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheDlgNom.h
    But du programme: Déclaration de la classe RcheDlgNom 
*/
#ifndef RCHENOM_H
#define RCHENOM_H
class RcheDlgNom : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    RcheDlgNom(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~RcheDlgNom();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);
protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *nom;
    enum {
        ID_BUTTON_CLICK = wxID_HIGHEST+1
    };
};

#endif