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

    GLuint mVertexArrayMaskId;
    GLuint mVertexArrayId;
    GLuint mVertexArrayColorId;
    GLuint mVertexArrayGreyColorId;
    GLuint mVertexArrayAlphaId;

    GLuint mVertexArrayQuadId;
    GLuint mQuadBuffer;

    GLuint mVertexArrayQuadId2;
    GLuint mQuadBuffer2;

    GLuint mMaskBuffer;

    GLuint mVertexBuffer1;
    GLuint mVertexBuffer2;
    GLuint mVertexBuffer3;

    GLuint mColorBuffer;
    GLuint mAlphaBuffer;
    GLint uniformColor;

    GLuint mGreyColorBuffer;
};

#endif // MAINWINDOW_H
