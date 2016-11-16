#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

namespace Ui {
class MainWindow;
}

class MainWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void initializeGL();
    void paintGL();

private:
    Ui::MainWindow *ui;
    QOpenGLShaderProgram *m_shader;

    GLuint mVertexArrayId;
    GLuint mVertexArrayColorId;

    GLuint attributePosition;
    GLuint attributeColor;
    GLuint attributeAlpha;

    GLuint mVertexBuffer;
    GLuint mColorBuffer;

    GLint uniformColor;
};

#endif // MAINWINDOW_H
