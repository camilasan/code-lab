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

    glDeleteVertexArrays(1, &mVertexArrayMaskId);
    glDeleteBuffers(1, &mMaskBuffer);

    glDeleteVertexArrays(1, &mVertexArrayQuadId);
    glDeleteBuffers(1, &mQuadBuffer);

    glDeleteVertexArrays(1, &mVertexArrayId);
    glDeleteBuffers(1, &mVertexBuffer1);
    glDeleteBuffers(1, &mVertexBuffer2);
    glDeleteBuffers(1, &mVertexBuffer3);

    glDeleteVertexArrays(1, &mVertexArrayColorId);
    glDeleteBuffers(1, &mColorBuffer);
    delete ui;
}

void MainWindow::initializeGL(){

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    glGenVertexArrays(1, &mVertexArrayMaskId);
    glBindVertexArray(mVertexArrayMaskId);

    glGenVertexArrays(1, &mVertexArrayQuadId);
    glBindVertexArray(mVertexArrayQuadId);

    glGenVertexArrays(1, &mVertexArrayId);
    glBindVertexArray(mVertexArrayId);

    glGenVertexArrays(1, &mVertexArrayColorId);
    glBindVertexArray(mVertexArrayColorId);

    m_shader = new QOpenGLShaderProgram(this);
    m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/mask_fp.glsl");
    m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/mask_vp.glsl");

    if(m_shader->link()) qDebug() << "Shader linked.";

    static const GLfloat gVertexBufferMaskData[] =
    {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,

        1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
    };

    static const GLfloat gVertexBufferQuadData[] =
    {
        -0.70f, -0.50f, 0.0f,
        0.70f, -0.50f, 0.0f,
        -0.70f,  0.50f, 0.0f,

        0.70f, 0.50f, 0.0f,
        -0.70f, 0.50f, 0.0f,
        0.70f,  -0.50f, 0.0f,
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

    glGenBuffers(1, &mMaskBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mMaskBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferMaskData), gVertexBufferMaskData, GL_STATIC_DRAW);

    glGenBuffers(1, &mQuadBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mQuadBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferQuadData), gVertexBufferQuadData, GL_STATIC_DRAW);

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

    // Clear the colorbuffer
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Bind our shader
    m_shader->bind();

    // Set colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    //Set Background triangles - Mask

    glStencilMask(0x00);

        // Area where we want things to show up
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mQuadBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 3);


    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilMask(0xFF);

        // Mask
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mMaskBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 3);

    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);

        // Triangles
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

    glStencilMask(0xFF);
    glEnable(GL_DEPTH_TEST);


    m_shader->release();
}
