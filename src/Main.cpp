#include "include/Main.hpp"

QMainWindow* WINDOW{};
BlendSplitter* SPLITTER{};

int main(int argc, char** argv)
{
    new QApplication{argc, argv};
    WINDOW = new QMainWindow{};
    SPLITTER = new BlendSplitter{};

    WINDOW->setCentralWidget(SPLITTER);

    WINDOW->resize(860, 640);
    WINDOW->setWindowTitle("NIMP");
    WINDOW->setWindowIcon(QIcon(":/icons/app_icon"));

    /*WidgetRegistry::getRegistry()->addItem();
    WidgetRegistry::getRegistry()->addItem("Type1", []()->QWidget* {return new QLabel{"Type 1 Label"};}, [](SwitchingBar* bar, QWidget*)->void {
        QMenu* menu{new QMenu{"Moje první menu"}};
        bar->addMenu(menu);
        QMenu* menu2{new QMenu{"Moje druhé menu"}};
        menu2->addAction(new QAction{"Nw", 0});
        menu2->addAction(new QAction{"Close", 0});
        bar->addMenu(menu2);
        QLabel* lab{new QLabel{"Moje třetí ne-menu"}};
        bar->addWidget(lab);
    });
    WidgetRegistry::getRegistry()->addItem(new RegistryItem{"Type2", []()->QWidget* {return new QLabel{"Type 2 Label"};}});*/

    /*SPLITTER->addWidget(new QLabel{"NIMP2aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"});
    SPLITTER->addWidget(new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"});*/
    SPLITTER->addWidget();

    WINDOW->show();

    return qApp->exec();
}
