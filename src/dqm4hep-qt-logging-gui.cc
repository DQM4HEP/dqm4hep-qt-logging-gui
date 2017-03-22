  /// \file dqm4hep-qt-logging-gui.cc
/*
 *
 * dqm4hep-qt-logging-gui.cc source template automatically generated by a class generator
 * Creation date : mer. mars 22 2017
 *
 * This file is part of DQM4HEP libraries.
 *
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */

// -- qt headers
#include <QApplication>
#include <QMetaType>

// -- dqm4hep headers
#include "MainWindow.h"

// -- json headers
#include "json/json.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  size_t maxSize(10000);

  if(argc > 2)
    maxSize = atoi(argv[1]);

  qRegisterMetaType<Json::Value>("Json::Value");

  MainWindow mainWindow;
  mainWindow.setMaxSize(maxSize);
  mainWindow.show();

  return app.exec();
}
