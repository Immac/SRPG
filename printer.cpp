#include "printer.h"


Printer::Printer()
{
}

void Printer::printJob(Job job)
{
    std::cout << "\nJob Name: " << job.getName() << " : " << job.getAbbreviation() << "\n";
    for(stringPair stat: job.nameAbbreviation)
    {
        std::cout << "Stat: " << stat.first << ":\t" << stat.second;
        std::cout << " >> Base: " << job.baseStats.at(stat.first) << " Growth: " << job.growthRate.at(stat.first) << "\n";
    }
}


