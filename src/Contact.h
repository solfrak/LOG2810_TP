#include <string>
class Contact
{
private:
public:
    Contact(std::string, std::string, float);
    void print();
    std::string name1_, name2_;
    float distance_;
};

