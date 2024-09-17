/* 
    Auteur: Ting-Wei Chuang 20125388
    Fichier: RcheEntreAns.h
    But du programme: Déclaration de la classe RcheEntreAns 
*/
#ifndef RCHEENTREANS_H
#define RCHEENTREANS_H
class RcheDlgEntreAns : public wxDialog {
public:
    // --- Constructor. Creates a new Dialog
    RcheDlgEntreAns(wxWindow* parent, const wxString& title);
    // --- Destructor
    ~RcheDlgEntreAns();
    // --- Processes Click Button
    void OnButtonClick(wxCommandEvent &event);
    wxString GetTexte();
protected:
    DECLARE_EVENT_TABLE()
private:
    wxTextCtrl *ans1;
    wxTextCtrl *ans2;
    enum {
        ID_BUTTON_CLICK = wxID_OK
    };
};

#endif