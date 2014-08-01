#include "Readers/classreaderxml.h"
#include "printer.h"
namespace
{
    std::string kWarrior = "Warrior";
    std::string kMage = "Mage";
    std::string kHealer = "Healer";
}

int main()
{
    ClassReaderXML classReader;
    Printer jobPrinter;
    auto job1 = classReader.getJob(kWarrior);
    auto job2 = classReader.getJob(kMage);
    auto job3 = classReader.getJob(kHealer);
    jobPrinter.printJob(job1);
    jobPrinter.printJob(job2);
    jobPrinter.printJob(job3);
    return 0;
}

