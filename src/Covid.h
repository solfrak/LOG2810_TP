#include "individue.h"
#include "Contact.h"
#include <vector>
#include <memory>
class Covid
{
private:
public:
    void loadDoc();
    std::vector<std::unique_ptr<individue>> individus;
    std::vector<std::unique_ptr<Contact>> contacts;
    individue* getIndividus(int index);
    Contact* getContact(int index);
    void creerGrapheExposition();
    void afficherGrapheExposition();
    // void IdentifierExposition();
    // void NotifierExposition();
};
