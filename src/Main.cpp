#include "include/Main.hpp"

QMainWindow* WINDOW{};
BlendSplitter* SPLITTER{};
Canvas* CANVAS{}; // DEBUG

int main(int argc, char** argv)
{
    QSurfaceFormat format;
    format.setVersion(3, 0);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    new QApplication{argc, argv};
    WINDOW = new QMainWindow{};
    SPLITTER = new BlendSplitter{};
    CANVAS = new Canvas{}; // DEBUG

    WINDOW->setCentralWidget(SPLITTER);
    WINDOW->resize(860, 640);
    WINDOW->setWindowTitle("NIMP");
    WINDOW->setWindowIcon(QIcon(":/icons/app_icon"));

    WidgetRegistry::getRegistry()->addItem();
    WidgetRegistry::getRegistry()->addItem("Type1", []()->QWidget* {return new QLabel{"Type 1 Label"};}, [](SwitchingBar* bar, QWidget*)->void {
        QMenu* menu{new QMenu{"My first menu"}};
        bar->addMenu(menu);
        QMenu* menu2{new QMenu{"My second menu"}};
        menu2->addAction(new QAction{"New", 0});
        menu2->addAction(new QAction{"Close", 0});
        bar->addMenu(menu2);
        QLabel* lab{new QLabel{"My third not-so-menu"}};
        bar->addWidget(lab);
    });
    WidgetRegistry::getRegistry()->addItem(new RegistryItem{"Type2", []()->QWidget* {return new QLabel{"Type 2 Label"};}});
    WidgetRegistry::getRegistry()->addItem("Canvas", []()->QWidget*{return CANVAS;});
    WidgetRegistry::getRegistry()->setDefault(3);

    /*SPLITTER->addWidget(new QLabel{"NIMP2aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"});
    SPLITTER->addWidget(new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"});*/
    SPLITTER->addWidget();

    WINDOW->show();

    return qApp->exec();
}
