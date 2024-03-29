// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#ifndef PRIVATECTOR_H
#define PRIVATECTOR_H

#include "libsamplemacros.h"

class PrivateCtor
{
public:
    inline static PrivateCtor* instance()
    {
        static PrivateCtor self;
        self.m_instanciations++;
        return &self;
    }

    inline int instanceCalls()
    {
        return m_instanciations;
    }

private:
    int m_instanciations;

    PrivateCtor() : m_instanciations(0) {}
};

#endif
