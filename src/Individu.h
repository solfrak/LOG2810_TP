#include <string>
#include <vector>
class Individu
{
private:
    bool isInfected_;
    std::string name_;
public:
    Individu(std::string, bool);
    std::string getName(){
        return name_;
    }
    bool getIsInfected(){
        return isInfected_;
    }
};

