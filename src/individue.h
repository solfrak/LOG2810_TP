#include <string>
#include <vector>
class individue
{
private:
    bool isInfected_;
    std::string name_;
public:
    individue(std::string, bool);
    std::string getName(){
        return name_;
    }
    bool getIsInfected(){
        return isInfected_;
    }
};

