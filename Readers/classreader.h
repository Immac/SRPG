#ifndef CLASSREADER_H
#define CLASSREADER_H
#include "job.h"

class ClassReader
{
public:
    ClassReader() = default;
    virtual Job getJob(const std::string &jobName) = 0;
protected:
    ~ClassReader(){}
};

#endif // CLASSREADER_H
