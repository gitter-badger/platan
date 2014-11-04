// This file is part of Platan.
// Copyright (C) 2014 Gábor Angyal
//
// Platan is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Platan is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Platan.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>

#include <csvreader.h>

namespace Ui {
class MainWindow;
}

class SubstituteTableModel;
class Ereaser;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    void showCsvConfig();
    void showWelcomeScreen();
protected:
    void keyPressEvent(QKeyEvent* event);

private slots:
    void on_stepButton_clicked();

    void on_sbLines_editingFinished();

    void on_sbLines_valueChanged(int arg1);

    void on_btDelete_clicked();

    void on_btnLoadFile_clicked();

    void on_btBack_clicked();

private:
    void applyEreasers();
    void showAnonymizedTable();
    void printHeaders(QTextStream &out);
    void printData(QTextStream &out);
    bool saveOutput();
    bool checkColumn(int c, Ereaser* ereaser);
    bool ereaseColumn(int c, Ereaser* ereaser);
    bool tryToMatchColumn(int c, QVector<std::shared_ptr<Ereaser>> ereasers);

    bool openFile();

    Ui::MainWindow *ui;
    SubstituteTableModel *model;
    int step;
    std::shared_ptr<CSVReader> reader;
    QString fileName;
};

#endif // MAINWINDOW_H