﻿/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt for Python.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ENUMVALUETYPEENTRY_H
#define ENUMVALUETYPEENTRY_H

#include "typesystem.h"

class EnumTypeEntry;
class EnumValueTypeEntryPrivate;

// EnumValueTypeEntry is used for resolving integer type templates
// like array<EnumValue>. Note: Dummy entries for integer values will
// be created for non-type template parameters, where m_enclosingEnum==nullptr.
class EnumValueTypeEntry : public TypeEntry
{
public:
    explicit EnumValueTypeEntry(const QString& name, const QString& value,
                                const EnumTypeEntry* enclosingEnum,
                                bool isScopedEnum, const QVersionNumber &vr);

    QString value() const;
    const EnumTypeEntry* enclosingEnum() const;

    TypeEntry *clone() const override;

protected:
    explicit EnumValueTypeEntry(EnumValueTypeEntryPrivate *d);
};

#endif // ENUMVALUETYPEENTRY_H
