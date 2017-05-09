#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(50,50,800,600);
    setFixedSize(800,600);
    txt = new QTextEdit;
    txt->setFont(QFont("Times", 14, QFont::AnyStyle));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_triggered()
{
    txt->clear();
    setCentralWidget(txt);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Text Files (*.txt)"));

        if (fileName != "") {
            QFile file(fileName);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream in(&file);
            txt->setText(in.readAll());
            setCentralWidget(txt);
            file.close();
        }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

        if (fileName != "") {
            QFile file(fileName);
            file.open(QIODevice::WriteOnly | QIODevice::Text);
                QTextStream stream(&file);
                stream << txt->toPlainText();
                stream.flush();
                file.close();
        }
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QWidget * form = new QWidget();
    form->setFixedSize(300,310);
    form->setWindowTitle("Blood & Concrete");
    QLabel * lbl = new QLabel(form);
    lbl->setPixmap(QPixmap(":/pic.jpg"));
    lbl->setAlignment(Qt::AlignTop);
    QLabel * lbltext = new QLabel(form);
    lbltext->setGeometry(1,165,300,150);
    lbltext->QLabel::setWordWrap(true);
    lbltext->setFont(QFont("Times", 10, QFont::AnyStyle));
    lbltext->setText("You motherfucker, come on you little ass… "
                     "fuck with me, eh? You fucking little asshole, "
                     "dickhead cocksucker…You fuckin' come on, come "
                     "fuck with me! I'll get your ass, you jerk! Oh, "
                     "you fuckhead motherfucker! Fuck all you and your "
                     "family! Come on, you cocksucker, slime bucket, "
                     "shitface turdball! Come on, you scum sucker, "
                     "you fucking with me? Come on, you asshole!!!");

    form->show();

}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont fontStyle = QFontDialog::getFont(&ok, QFont("Times", 18), this, "Choose font");

    if(ok){
            QTextCharFormat format;
            format.setFont(fontStyle);
            QTextCursor txtCursor(txt->textCursor());
            txtCursor.setCharFormat(format);
            txtCursor.clearSelection();
            txt->setTextCursor(txtCursor);
    }
    else
    {
            return;
    }
}

void MainWindow::on_actionDate_and_Time_triggered()
{
    QDateTime dt = QDateTime::currentDateTime();
    txt->insertPlainText(dt.toString());
}

void MainWindow::on_actionSelect_all_triggered()
{
    txt->selectAll();
    flag = false;
}

void MainWindow::on_actionDelete_triggered()
{
    txt->cut();
    flag = true;
}

void MainWindow::on_actionCopy_triggered()
{
    txt->copy();
    flag = false;
}

void MainWindow::on_actionBack_triggered()
{
    txt->undo();
    flag = false;
}

void MainWindow::on_actionCut_2_triggered()
{
    txt->cut();
    flag = false;
}

void MainWindow::on_actionPaste_triggered()
{
    if (flag == false) {txt->paste();}
    else return;
}

void MainWindow::on_actionRedo_triggered()
{
    txt->redo();
    flag = false;
}
