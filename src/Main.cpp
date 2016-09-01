#include "include/Main.hpp"

CanvasNode* CNVS;

int main(int argc, char** argv)
{
    QSurfaceFormat format;
    format.setVersion(3, 0);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    new QApplication{argc, argv};
    CNVS = new CanvasNode{};
    BMPinput* input{new BMPinput{}};
    Node::connect(input, 0, CNVS, 0);
    Registry::getRegistry()->extrinsic->window = new QMainWindow{};
    Registry::getRegistry()->extrinsic->splitter = new BlendSplitter{};

    Registry::getRegistry()->extrinsic->window->setCentralWidget(Registry::getRegistry()->extrinsic->splitter);
    Registry::getRegistry()->extrinsic->window->resize(860, 640);
    Registry::getRegistry()->extrinsic->window->setWindowTitle("NIMP");
    Registry::getRegistry()->extrinsic->window->setWindowIcon(QIcon(":/icons/app_icon"));

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
    WidgetRegistry::getRegistry()->addItem("Canvas", []()->QWidget*{return new Canvas{};});
    WidgetRegistry::getRegistry()->addItem("Node Editor", []()->QWidget*{return new NodeEditor{};});
    WidgetRegistry::getRegistry()->setDefault(4);

    Registry::getRegistry()->extrinsic->splitter->addWidget();

    Registry::getRegistry()->extrinsic->window->show();

    return qApp->exec();
}
