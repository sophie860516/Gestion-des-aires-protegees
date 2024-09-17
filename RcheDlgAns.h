/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheDlgAns.h
    But du programme: Déclaration de la classe RcheDlgAns 
*/
#ifndef RCHEANS_H
#define RCHEANS_H
//recherche selon année
class RcheDlgAns : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    RcheDlgAns(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~RcheDlgAns();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);
    wxString GetTexte();
protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *ans;
    enum {
        ID_BUTTON_CLICK = wxID_OK
    };
};
#endif