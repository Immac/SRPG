#include "job.h"


std::string Job::getName() const
{
    return name;
}

void Job::setName(const std::string &value)
{
    name = value;
}

void Job::addStatistic(const std::string &name, const std::string &abbreviation, float base, float growth)
{
    nameAbbreviation.insert(stringPair { name, abbreviation} );
    growthRate.insert(stringFloatPair { name, growth} );
    baseStats.insert(stringFloatPair { name, base} );
}
std::vector<std::string> Job::getActionAbilities() const
{
    return actionAbilities;
}
std::vector<std::string> Job::getPassiveAbilities() const
{
    return passiveAbilities;
}
std::vector<std::string> Job::getSupportAbilities() const
{
    return supportAbilities;
}
std::vector<std::string> Job::getReactionAbilities() const
{
    return reactionAbilities;
}


std::string Job::getAbbreviation() const
{
    return abbreviation;
}

void Job::setAbbreviation(const std::string &value)
{
    abbreviation = value;
}




Job::Job(std::string name)
{
    this->name = name;
}

Job::~Job()
{

}
