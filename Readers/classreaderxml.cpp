#include "classreaderxml.h"


ClassReaderXML::ClassReaderXML()
{
}

Job ClassReaderXML::getJob(const std::string& jobName)
{
    tinyxml2::XMLDocument jobDocument;
    auto filepath = kJobLocation + jobName + kJobExtension;
    auto error = jobDocument.LoadFile(filepath.c_str());
    try
    {
        if(error != tinyxml2::XML_NO_ERROR)
            throw error;
    }
    catch(tinyxml2::XMLError e)
    {
        switch (e) {
        case tinyxml2::XML_ERROR_FILE_NOT_FOUND:
            std::cout << "File not Found " << filepath << "\n";
            break;
        default:
            std::cout << "Error number: " << e;
            break;
        }
        return *new Job(kUndefined);
    }
    return createJob(jobDocument);
}

Job ClassReaderXML::createJob(tinyxml2::XMLDocument &jobDocument)
{
    std::shared_ptr<Job> jobToReturn(new Job);
    auto jobXElement = jobDocument.FirstChildElement()->FirstChildElement(kClass.c_str());
    auto attribute = jobXElement->FirstAttribute();

    while(jobXElement)
    {
        attribute = jobXElement->FirstAttribute();
        std::string elementName(jobXElement->Name());

        if(elementName == kClass)
        {
            while(attribute)
            {
                std::string attributeName( attribute->Name() );
                if(attributeName == kName) jobToReturn->setName(std::string(attribute->Value()));
                if(attributeName == kAbbr) jobToReturn->setAbbreviation(std::string(attribute->Value()) );
                attribute = attribute->Next();
            }
        }
        else if (elementName == kStat)
        {
            Statistic stat;
            while(attribute)
            {
                std::string attributeName( attribute->Name() );
                if(attributeName == kName) stat.name = std::string( attribute->Value() );
                if(attributeName == kAbbr) stat.abbreviation = std::string ( attribute->Value() );
                if(attributeName == kBase) stat.base = attribute->FloatValue();
                if(attributeName == kGrowth) stat.growth = attribute->FloatValue();

                attribute = attribute->Next();
            }
            jobToReturn->addStatistic(stat.name,stat.abbreviation,stat.base,stat.growth);
        }

        jobXElement = jobXElement->NextSiblingElement();
    }
    return *jobToReturn;
}
