#define MAIN
//#include "includes.h"

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStyle>
#include <QStyleFactory>
#include <QStyleOption>
#include <stdio.h>

QTranslator MyTranslator, QtTranslator;
QString theme;
int loadlanguage()
{
    QString datei = "settings.txt", mylanguage, text, junk;
    QFile f(datei);
    QTextStream in(&f);
    if(f.open(QIODevice::ReadOnly))
    {
        text = in.readAll();
        char* dataf = new char[text.length() + 1];
        char outs[2] = ";";
        strcpy(dataf, text.toLatin1().data());

        junk = strtok(dataf, outs);
        mylanguage = strtok(NULL, outs);
        junk = strtok(NULL, outs);
        junk = strtok(NULL, outs);
        theme = strtok(NULL, outs);
    }
#ifdef WIN32
    if(mylanguage == "Systemsprache")
    {MyTranslator.load("qt_de.qm" , "translations\\");} //isn't finish
    else if(mylanguage == "Deutsch")
        {MyTranslator.load("tr_de.qm", "translations\\"); QtTranslator.load("qt_de.qm", "translations\\");}
    else if(mylanguage == "English")
        {MyTranslator.load("tr_en.qm", "translations\\"); QtTranslator.load("qt_en.qm", "translations\\");}
    else if(mylanguage == "Francais")
        {MyTranslator.load("tr_fr.qm", "translations\\"); QtTranslator.load("qt_fr.qm", "translations\\");}
    else if(mylanguage == "")
        {MyTranslator.load("tr_de.qm", "translations\\"); QtTranslator.load("qt_de.qm", "translations\\");}
    else
        return 1;
#endif
#ifndef WIN32
    if(mylanguage == "Systemsprache")
        MyTranslator.load("qt_de.qm" , "./translations/"); //isn't finish
    else if(mylanguage == "Deutsch")
        MyTranslator.load("qt_de.qm", "./translations/");
    else if(mylanguage == "English")
        MyTranslator.load("qt_en.qm", "./translations/");
    else if(mylanguage == "Francais")
        MyTranslator.load("qt_fr.qm", "./translations/");
    else if(mylanguage == "")
        MyTranslator.load("qt_de.qm", "./translations/");
    else
        return 1;
#endif
    return 0;
}

QPalette loadpalette()
{
    QPalette palette;
    if(theme == "Dark")
    {
        palette = QPalette(QColor(60,60,60));
        palette.setColor(QPalette::Base, QColor(120,120,120));
        palette.setColor(QPalette::Text, Qt::black);
    }
    else if(theme == "Dark Fusion")
    {
        palette.setColor(QPalette::Window, QColor(53,53,53));
        palette.setColor(QPalette::WindowText, Qt::white);
        palette.setColor(QPalette::Base, QColor(25,25,25));
        palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        palette.setColor(QPalette::ToolTipBase, Qt::white);
        palette.setColor(QPalette::ToolTipText, Qt::white);
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::Button, QColor(53,53,53));
        palette.setColor(QPalette::ButtonText, Qt::white);
        palette.setColor(QPalette::BrightText, Qt::red);
        palette.setColor(QPalette::Link, QColor(42, 130, 218));
        palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        palette.setColor(QPalette::HighlightedText, Qt::black);
    }
    else if(theme == "Cusis")
    {
        palette.setColor( QPalette::WindowText, QColor( 240, 240, 240 ) );
        palette.setColor( QPalette::Base, QColor( 128, 128, 128 ) );
        palette.setColor( QPalette::Base, QColor( 0, 0, 0 ) );
        palette.setColor( QPalette::Shadow, QColor( 0, 0, 0 ) );
        palette.setColor( QPalette::ButtonText, QColor( 255, 255, 255 ) );
        palette.setColor( QPalette::BrightText, QColor( 0, 255, 0 ) );
        palette.setColor( QPalette::Highlight, QColor( 224, 224, 224 ) );
        palette.setColor( QPalette::HighlightedText, QColor( 0, 0, 0 ) );
        palette.setColor( QPalette::Background, QColor( 21, 21, 21 ) );
        palette.setColor( QPalette::Text, QColor( 255, 255, 255 ) );
        palette.setColor( QPalette::Button, QColor( 66, 66, 66 ) );
    }
    return palette;
}

int main(int argc, char *argv[])
{
    int languagesucces = loadlanguage();
    QApplication a(argc, argv);
    a.installTranslator(&MyTranslator);
    a.installTranslator(&QtTranslator);
    if(theme == "Dark Fusion")
    {
        a.setStyle(QStyleFactory::create("Fusion"));
        a.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    }
    a.setPalette(loadpalette());
    MainWindow w;
    w.show();
    bool succsess = a.exec();
    return (succsess+(languagesucces*2));
}

#undef MAIN
