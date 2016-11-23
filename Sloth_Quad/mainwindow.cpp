#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MU_PREC 1E-10 // treshhold prectision

MainWindow::MainWindow(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Sloth");
}

MainWindow::~MainWindow()
{
    // Cleanup VBO
    glDeleteVertexArrays(1, &maskID);
    glDeleteBuffers(1, &maskBuffer);

    glDeleteVertexArrays(1, &stencil1ID);
    glDeleteBuffers(1, &stencil1Buffer);

    glDeleteVertexArrays(1, &stencil2ID);
    glDeleteBuffers(1, &stencil2Buffer);

    glDeleteVertexArrays(1, &triangle1ID);
    glDeleteBuffers(1, &triangle1Buffer);

    glDeleteVertexArrays(1, &triangle2ID);
    glDeleteBuffers(1, &triangle2Buffer);

    glDeleteVertexArrays(1, &triangle3ID);
    glDeleteBuffers(1, &triangle3Buffer);

    glDeleteVertexArrays(1, &colorID);
    glDeleteBuffers(1, &colorBuffer);

    glDeleteVertexArrays(1, &greyColorID);
    glDeleteBuffers(1, &greyColorBuffer);

    delete ui;
}

void MainWindow::initializeGL(){

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    glGenVertexArrays(1, &maskID);
    glBindVertexArray(maskID);

    glGenVertexArrays(1, &stencil1ID);
    glBindVertexArray(stencil1ID);

    glGenVertexArrays(1, &stencil2ID);
    glBindVertexArray(stencil2ID);

    glGenVertexArrays(1, &triangle1ID);
    glBindVertexArray(triangle1ID);

    glGenVertexArrays(1, &triangle2ID);
    glBindVertexArray(triangle2ID);

    glGenVertexArrays(1, &triangle3ID);
    glBindVertexArray(triangle3ID);

    glGenVertexArrays(1, &colorID);
    glBindVertexArray(colorID);

    glGenVertexArrays(1, &greyColorID);
    glBindVertexArray(greyColorID);

    m_shader = new QOpenGLShaderProgram(this);
    m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/mask_fp.glsl");
    m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/mask_vp.glsl");

    if(m_shader->link()) qDebug() << "Shader linked.";

    static const GLfloat maskVertices[] =
    {
        -1.0f, -1.0f, 0.0f, //left bottom
        1.0f, -1.0f, 0.0f, //right bottom
        -1.0f,  1.0f, 0.0f, //top

        1.0f, 1.0f, 0.0f, //top
        -1.0f, 1.0f, 0.0f, //top first triangle
        1.0f,  -1.0f, 0.0f,//right bottom first triangle
    };

    static const GLfloat stencil1Vertices[] =
    {
        -0.75f, 0.25f, 0.0f, //left bottom
        0.75f, 0.25f, 0.0f, //right bottom
        -0.75f,  0.50f, 0.0f, //top

        0.75f,  0.50f, 0.0f, //top
        -0.75f,  0.50f, 0.0f, //top first triangle
        0.75f, 0.25f, 0.0f,//right bottom first triangle
    };

    static const GLfloat stencil2Vertices[] =
    {
        -0.75f, -0.50f, 0.0f, //left bottom
        0.75f, -0.50f, 0.0f, //right bottom
        -0.75f,  0.0f, 0.0f, //top

        0.75f,   0.0f, 0.0f, //top
        -0.75f,  0.0f, 0.0f, //top first triangle
        0.75f, 0.50f, 0.0f,//right bottom first triangle
    };


    static const GLfloat triangle1Vertices[] =
    {
        -0.85f, -0.25f, 0.0f, //lower left
        -0.60f, -0.25f, 0.0f, //lower right
        -0.72f, 0.25f, 0.0f, //top
    };

    static const GLfloat triangle2Vertices[] =
    {
        0.50f, -0.50f, 0.0f, //lower left
        1.0f, -0.50f, 0.0f, //lower right
        0.75f, 0.0f, 0.0f, //top
    };

    static const GLfloat triangle3Vertices[] =
    {
        -0.40f, -0.5f, 0.0f, //lower left
        0.0f, -0.5f, 0.0f, //lower right
        -0.20f, 1.0f, 0.0f, //top
    };

    static const GLfloat color[] = {
        0.12f,  0.12f,  1.0f,
        0.35f,  0.35f,  1.0f,
        0.75f,  0.45f,  1.0f,
    };

    static const GLfloat greyColor[] = {
        1.0f,  1.0f,  1.0f
    };


    glGenBuffers(1, &maskBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, maskBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(maskVertices), maskVertices, GL_STATIC_DRAW);

    glGenBuffers(1, &stencil1Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, stencil1Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(stencil1Vertices), stencil1Vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &stencil2Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, stencil2Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(stencil2Vertices), stencil2Vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &triangle1Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangle1Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1Vertices), triangle1Vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &triangle2Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangle2Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2Vertices), triangle2Vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &triangle3Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangle3Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle3Vertices), triangle3Vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

    glGenBuffers(1, &greyColorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, greyColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(greyColor), greyColor, GL_STATIC_DRAW);
}

void MainWindow::paintGL(){

    // Clear the colorbuffer
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Bind our shader
    m_shader->bind();

    // Set colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


    // Top Stencil area
    glStencilMask(0x00);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, stencil1Buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 3);
    glStencilFunc(GL_ALWAYS , 1, 0xFF);

    // Top Stencil area content
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);

        // Set colors
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, greyColorBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle3Buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    glStencilMask(0xFF);
    glEnable(GL_DEPTH_TEST);

    // Bottom Stencil area
    glStencilMask(0x00);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, stencil2Buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 3);
    glStencilFunc(GL_ALWAYS , 1, 0xFF);

    // Bottom Stencil area content
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);
        // Set colors
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, greyColorBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Triangles
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle1Buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle2Buffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    glStencilMask(0xFF);
    glEnable(GL_DEPTH_TEST);

    // Mask
    glStencilMask(0xFF);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, maskBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 1, 3);

    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);

    m_shader->release();
}
