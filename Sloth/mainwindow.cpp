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
    glDeleteVertexArrays(2, &mVertexArrayId);
    glDeleteBuffers(1, &mVertexBuffer);

    glDeleteVertexArrays(2, &mVertexArrayColorId);
    glDeleteBuffers(1, &mColorBuffer);
    delete ui;
}

void MainWindow::initializeGL(){

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glGenVertexArrays(1, &mVertexArrayId);
    glBindVertexArray(mVertexArrayId);

    m_shader = new QOpenGLShaderProgram(this);
    m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/line_fp.glsl");
    m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/line_vp.glsl");

    if(m_shader->link()) qDebug() << "Shader linked.";

    m_shader->setUniformValue("u_color", QVector3D(1.0,0.0,0.0));

    attributePosition   = m_shader->attributeLocation ("position");
    attributeColor      = m_shader->attributeLocation ("color");
    attributeAlpha      = m_shader->attributeLocation ("alpha");

    uniformColor = m_shader->uniformLocation("u_color");

    static const GLfloat gVertexBufferData[] =
    {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
        -21.0f, -21.0f, 20.0f,
         21.0f, -21.0f, 20.0f,
         20.0f,  21.0f, 20.0f,
    };

    static const GLfloat g_color_buffer_data[] = {
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f
    };


    glGenBuffers(1, &mVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData), gVertexBufferData, GL_STATIC_DRAW);    

    glGenBuffers(1, &mColorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

void MainWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind our shader
    m_shader->bind();

    // Set colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer);
    glVertexAttribPointer(
       1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    // Set triangles
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    // First Triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // Second Triangle
    glDrawArrays(GL_TRIANGLES, 1, 3);

    m_shader->release();
}
