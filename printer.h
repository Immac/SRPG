#ifndef PRINTER_H
#define PRINTER_H
#include "job.h"
#include <iostream>

class Printer
{
public:
    Printer();
    void printJob(Job job);
};

#endif // PRINTER_H
