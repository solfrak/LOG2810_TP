#include <string>
class Contact
{
private:
    std::string name1_, name2_;
    float distance_;
public:
    Contact(std::string, std::string, float);
    std::string print();
};

