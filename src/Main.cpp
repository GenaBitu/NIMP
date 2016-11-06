#include "include/Main.hpp"

int main(int argc, char** argv)
{
    QSurfaceFormat format;
    format.setVersion(2, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    new QApplication{argc, argv};

    Registry::getRegistry()->extrinsic->window = new QMainWindow{};
    Registry::getRegistry()->extrinsic->splitter = new BlendSplitter{};

    Registry::getRegistry()->extrinsic->window->setCentralWidget(Registry::getRegistry()->extrinsic->splitter);
    Registry::getRegistry()->extrinsic->window->resize(860, 640);
    Registry::getRegistry()->extrinsic->window->setWindowTitle("NIMP");
    Registry::getRegistry()->extrinsic->window->setWindowIcon(QIcon(":/icons/app_icon"));

    CanvasNode* canvas{new CanvasNode{500, 100}};
    BMPinput* input{new BMPinput{"tex2D.bmp", 10, 300}};
    new BMPinput{"tex2D2.bmp", 10, 100};
    Node::connect(input, 0, canvas, 0);

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
    WidgetRegistry::getRegistry()->addItem("Node Editor", []()->QWidget*{return new NodeEditor{};}, &NodeEditor::populateBar);
    WidgetRegistry::getRegistry()->setDefault(4);

    Registry::getRegistry()->extrinsic->splitter->addWidget();

    Registry::getRegistry()->extrinsic->window->show();

    return qApp->exec();
}
