#ifndef CLASSREADERXML_H
#define CLASSREADERXML_H
#include "TinyXml/tinyxml2.h"
#include "classreader.h"
#include <memory>
#include <iostream>
namespace
{
    const std::string kJobLocation = "Jobs/";
    const std::string kJobExtension = ".xjob";
    const std::string kName = "name";
    const std::string kClass = "class";
    const std::string kStat = "stat";
    const std::string kAbbr = "abbreviation";
    const std::string kBase = "base";
    const std::string kGrowth = "growth";
    const std::string kUndefined = "Undefined";
}
struct Statistic
{
    std::string name;
    std::string abbreviation;
    float base;
    float growth;
};
class ClassReaderXML: public ClassReader
{
public:
    ClassReaderXML();
    Job getJob(const std::string &jobName);
private:
    Job createJob(tinyxml2::XMLDocument &jobDocument);

};

#endif // CLASSREADERXML_H
