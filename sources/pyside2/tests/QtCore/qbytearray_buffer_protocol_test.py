#!/usr/bin/python
# -*- coding: utf-8 -*-

#############################################################################
##
## Copyright (C) 2016 The Qt Company Ltd.
## Contact: https://www.qt.io/licensing/
##
## This file is part of the test suite of Qt for Python.
##
## $QT_BEGIN_LICENSE:GPL-EXCEPT$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see https://www.qt.io/terms-conditions. For further
## information use the contact form at https://www.qt.io/contact-us.
##
## GNU General Public License Usage
## Alternatively, this file may be used under the terms of the GNU
## General Public License version 3 as published by the Free Software
## Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
## included in the packaging of this file. Please review the following
## information to ensure the GNU General Public License requirements will
## be met: https://www.gnu.org/licenses/gpl-3.0.html.
##
## $QT_END_LICENSE$
##
#############################################################################

'''Tests QByteArray implementation of Python buffer protocol'''

import os
from os.path import isdir
import sys
import unittest

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from init_paths import init_test_paths
init_test_paths(False)

import py3kcompat as py3k

from PySide2.QtCore import QByteArray


class QByteArrayBufferProtocolTest(unittest.TestCase):
    '''Tests QByteArray implementation of Python buffer protocol'''

    def testQByteArrayBufferProtocol(self):
        if py3k.IS_PY3K:
            return
        #Tests QByteArray implementation of Python buffer protocol using the os.path.isdir
        #function which an unicode object or other object implementing the Python buffer protocol
        isdir(QByteArray('/tmp'))

if __name__ == '__main__':
    unittest.main()

