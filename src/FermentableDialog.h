/*
 * FermentableDialog.h is part of Brewtarget, and is Copyright the following
 * authors 2009-2023
 * - Jeff Bailey <skydvr38@verizon.net>
 * - Matt Young <mfsy@yahoo.com>
 * - Philip Greggory Lee <rocketman768@gmail.com>
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FERMENTABLEDIALOG_H
#define FERMENTABLEDIALOG_H
#pragma once

#include <QDialog>
#include <QEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>

// Forward declarations.
class MainWindow;
class FermentableEditor;
class FermentableTableModel;
class FermentableSortFilterProxyModel;

/*!
 * \class FermentableDialog
 *
 * \brief View/controller class that shows the list of fermentables in the database.
 */
class FermentableDialog : public QDialog {
   Q_OBJECT

public:
   FermentableDialog(MainWindow* parent);
   virtual ~FermentableDialog() {}

   //! \name Public UI Variables
   //! @{
   QVBoxLayout *verticalLayout;
   QTableView *tableWidget;
   QHBoxLayout *horizontalLayout;
   QLineEdit *qLineEdit_searchBox;
   QSpacerItem *horizontalSpacer;
   QPushButton *pushButton_addToRecipe;
   QPushButton *pushButton_new;
   QPushButton *pushButton_edit;
   QPushButton *pushButton_remove;
   //! @}

public slots:
   /*! If \b index is the default, will add the selected fermentable to list.
    *  Otherwise, will add the fermentable at the specified index.
    */
   void addFermentable(const QModelIndex& index = QModelIndex());
   void removeFermentable();
   void editSelected();

   void filterFermentables(QString searchExpression);
   //void changed(QMetaProperty,QVariant);
   void newFermentable(QString folder = "");

protected:

   virtual void changeEvent(QEvent* event)
   {
      if(event->type() == QEvent::LanguageChange)
         retranslateUi();
      QDialog::changeEvent(event);
   }

private:
   MainWindow* mainWindow;
   FermentableTableModel* fermTableModel;
   FermentableSortFilterProxyModel* fermTableProxy;
   FermentableEditor* fermEdit;
   int numFerms;

   void doLayout();
   void retranslateUi();
};

#endif
