#include "image.h"
#include "command_line/commandcommandlinefunctions.h"
#include "../program/globals.h"
#include "../ui/mygraphicsscene.h"

int bandageImage(QApplication * a, QStringList arguments)
{
    if (arguments.size() == 0)
    {
        printImageUsage();
        return 1;
    }

    QString filename = arguments.at(0);
    arguments.pop_front();

    QStringList invalidOptions;
    arguments.removeDuplicates();
    for (int i = 0; i < arguments.size(); ++i)
    {
//        if (arguments.at(i) == "-d")
//            drawGraph = true;
//        else
//            invalidOptions.push_back(arguments.at(i));
    }

    if (invalidOptions.size() > 0)
    {
        voidPrintInvalidImageOptions(invalidOptions);
        return 1;
    }

    bool loadSuccess = loadAssemblyGraph(filename);
    if (!loadSuccess)
        return 1;

    MyGraphicsScene scene;





    return 0;
}


void printImageUsage()
{
    QTextStream(stdout) << "" << endl;
    QTextStream(stdout) << "Usage:   Bandage image <graph>" << endl << endl;
    QTextStream(stdout) << "Options: " << endl << endl;
}


void voidPrintInvalidImageOptions(QStringList invalidOptions)
{
    QString invalidOptionText = "Invalid option";
    if (invalidOptions.size() > 1)
        invalidOptionText += "s";
    invalidOptionText += ": ";
    for (int i = 0; i < invalidOptions.size(); ++i)
    {
        invalidOptionText += invalidOptions.at(i);
        if (i < invalidOptions.size() - 1)
            invalidOptionText += ", ";
    }

    QTextStream(stdout) << "" << endl;
    QTextStream(stdout) << invalidOptionText << endl;
    printImageUsage();
    QTextStream(stdout) << "" << endl;
}

