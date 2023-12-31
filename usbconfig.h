/****************************************************************************
**
** Copyright (C) 2008 Ben Klopfenstein <benklop@gmail.com>
**
** This file is part of QtEmu.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU Library General Public License
** along with this library; see the file COPYING.LIB.  If not, write to
** the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA 02110-1301, USA.
**
****************************************************************************/

#ifndef USBCONFIG_H
#define USBCONFIG_H

#include <QObject>

class MachineConfigObject;
class MachineProcess;

#if QT_VERSION >= 0x060000
typedef QList<QString> QStringList;
#else
#include <QStringList>
#endif

class UsbConfig : public QObject
{
    Q_OBJECT

public:
    UsbConfig(MachineProcess * parent, MachineConfigObject * config);

    QStringList getOptionString();

private:
    MachineConfigObject * config;
    MachineProcess * parent;

public slots:
    void vmAddDevice(QString id);
    void vmRemoveDevice(QString id);

};

#endif // USBCONFIG_H
