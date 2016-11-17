#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Sloth");
}

MainWindow::~MainWindow()
{
    // Cleanup VBO

    glDeleteVertexArrays(1, &mVertexArrayBackgroundId);
    glDeleteBuffers(1, &mBackgroundBuffer);

    glDeleteVertexArrays(1, &mVertexArrayId);
    glDeleteBuffers(1, &mVertexBuffer1);
    glDeleteBuffers(1, &mVertexBuffer2);
    glDeleteBuffers(1, &mVertexBuffer3);

    glDeleteVertexArrays(1, &mVertexArrayColorId);
    glDeleteBuffers(1, &mColorBuffer);
    delete ui;
}

void MainWindow::initializeGL(){

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    glGenVertexArrays(1, &mVertexArrayBackgroundId);
    glBindVertexArray(mVertexArrayBackgroundId);

    glGenVertexArrays(1, &mVertexArrayId);
    glBindVertexArray(mVertexArrayId);

    glGenVertexArrays(1, &mVertexArrayColorId);
    glBindVertexArray(mVertexArrayColorId);

    m_shader = new QOpenGLShaderProgram(this);
    m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/line_fp.glsl");
    m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/line_vp.glsl");

    if(m_shader->link()) qDebug() << "Shader linked.";

    static const GLfloat gVertexBufferBkgData[] =
    {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,

        1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
    };

    static const GLfloat gVertexBufferData1[] =
    {
        -0.85f, -0.25f, 0.0f, //lower left
        -0.60f, -0.25f, 0.0f, //lower right
        -0.72f, 0.25f, 0.0f, //top
    };

    static const GLfloat gVertexBufferData2[] =
    {
        0.50f, -0.50f, 0.0f, //lower left
        1.0f, -0.50f, 0.0f, //lower right
        0.75f, 0.0f, 0.0f, //top
    };

    static const GLfloat gVertexBufferData3[] =
    {
        -0.25f, -0.75f, 0.0f, //lower left
        0.25f, -0.75f, 0.0f, //lower right
        0.0f, 0.50f, 0.0f, //top
    };


    static const GLfloat g_color_buffer_data[] = {
        1.0f,  0.500f,  0.200f,
        0.200f, 0.800f,  0.500f,
        0.500f,  0.200f,  0.800f
    };

    glGenBuffers(1, &mBackgroundBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mBackgroundBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferBkgData), gVertexBufferBkgData, GL_STATIC_DRAW);

    glGenBuffers(1, &mVertexBuffer1);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData1), gVertexBufferData1, GL_STATIC_DRAW);

    glGenBuffers(1, &mVertexBuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData2), gVertexBufferData2, GL_STATIC_DRAW);

    glGenBuffers(1, &mVertexBuffer3);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData3), gVertexBufferData3, GL_STATIC_DRAW);

    glGenBuffers(1, &mColorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

void MainWindow::paintGL(){
    // Bind our shader
    m_shader->bind();

    // Set colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_FALSE);
    glStencilFunc(GL_NEVER, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_KEEP, GL_KEEP);  // draw 1s on test fail (always)

    // draw stencil pattern
    glStencilMask(0xFF);
    glClear(GL_STENCIL_BUFFER_BIT);  // needs mask=0xFF

    //Set Background triangles - Mask
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mBackgroundBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 1, 3);

    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);
    glStencilMask(0x00);

    // draw only where stencil's value is 1
    glStencilFunc(GL_EQUAL, 1, 0xFF);

    // Set triangles - this would be the plots
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer3);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisable(GL_STENCIL_TEST);



    m_shader->release();
}
