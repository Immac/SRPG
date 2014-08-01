#ifndef JOB_H
#define JOB_H
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <vector>

typedef std::pair<std::string,std::string> stringPair;
typedef std::pair<std::string,float> stringFloatPair;

class Job
{

public:
    Job() = default;
    Job(std::string name);
    virtual ~Job();
    std::string getName() const;
    void setName(const std::string &value);    
    std::string getAbbreviation() const;
    void setAbbreviation(const std::string &value);
    void addStatistic(std::string const &name, std::string const &abbreviation, float base = 10.0f, float growth = 1.0f);
    std::vector<std::string> getActionAbilities() const;
    std::vector<std::string> getReactionAbilities() const;
    std::vector<std::string> getSupportAbilities() const;
    std::vector<std::string> getPassiveAbilities() const;

public: /*Private*/
    std::unordered_map<std::string,float> growthRate;
    std::unordered_map<std::string,std::string> nameAbbreviation;
    std::unordered_map<std::string,float> baseStats;

    std::vector<std::string> actionAbilities;
    std::vector<std::string> reactionAbilities;
    std::vector<std::string> supportAbilities;
    std::vector<std::string> passiveAbilities;

private:
    std::string name;
    std::string abbreviation;

};

#endif // JOB_H
