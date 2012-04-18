/* * This file is part of meego-im-framework *
 *
 * Copyright (C) 2012 Mattia Barbon <mattia@develer.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#ifndef MALIIT_PLUGINSETTINGS_H
#define MALIIT_PLUGINSETTINGS_H

#include <QScopedPointer>
#include <QSharedPointer>
#include <QVariant>

class MImPluginSettingsInfo;

namespace Maliit {

class PluginSettingsPrivate;
class SettingsEntry;
class AttributeExtension;


class PluginSettings : public QObject
{
    Q_OBJECT

public:
    virtual ~PluginSettings();

    QString descriptionLanguage() const;
    QString pluginName() const;
    QString pluginDescription() const;
    QList<QSharedPointer<SettingsEntry> > configurationEntries() const;

private:
    PluginSettings(const MImPluginSettingsInfo &info, const QSharedPointer<AttributeExtension> &extension);

    QScopedPointer<PluginSettingsPrivate> d_ptr;

    Q_DISABLE_COPY(PluginSettings)
    Q_DECLARE_PRIVATE(PluginSettings)

    friend class SettingsManager;
};

}

#endif // MALIIT_PLUGINSETTINGS_H