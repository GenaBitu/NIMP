#include "include/Main.hpp"

QMainWindow* WINDOW{};
Splitter* SPLITTER{};

int main(int argc, char** argv)
{
    new QApplication{argc, argv};
    WINDOW = new QMainWindow{};
    SPLITTER = new Splitter{};

    WINDOW->setCentralWidget(SPLITTER);

    WINDOW->resize(860, 640);
    WINDOW->setWindowTitle("NIMP");
    WINDOW->setWindowIcon(QIcon(":/icons/app_icon"));

    SPLITTER->addWidget(new QLabel{"NIMP2aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"});
    SPLITTER->addWidget(new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"});

    WINDOW->show();

    return qApp->exec();
}
