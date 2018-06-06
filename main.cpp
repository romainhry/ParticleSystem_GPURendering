#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "mainwindow.h"
#endif

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QSurfaceFormat format;

    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("Particle System");
    app.setApplicationVersion("1.0");
#ifndef QT_NO_OPENGL
    MainWindow w;
    w.show();
#else
    QLabel note("OpenGL Support required");
    note.show();
#endif
    return app.exec();
}
