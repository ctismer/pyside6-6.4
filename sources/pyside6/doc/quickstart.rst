.. _quick-start:

Quick start
===========

New to Qt? Check also the :ref:`faq-section` section at the end of this page.

Requirements
------------

Before you can install |project|, first you must install the following software:

 * Python 3.7+,
 * We recommend using a virtual environment, such as
   `venv <https://docs.python.org/3/library/venv.html>`_ or
   `virtualenv <https://virtualenv.pypa.io/en/latest>`_

Installation
------------

* **Creating and activating an environment**
  You can do this by running the following on a terminal:

  * Create environment (Your Python executable might be called ``python3``)::

        python -m venv env

  * Activate the environment (Linux and macOS)::

        source env/bin/activate

  * Activate the environment (Windows)::

        env\Scripts\activate.bat

  Check this animation on how to do it:

  .. image:: https://qt-wiki-uploads.s3.amazonaws.com/images/8/8a/Pyside6_install.gif
     :alt: Installation gif

* **Installing PySide6**

  Now you are ready to install the |project| packages using ``pip``.
  From the terminal, run the following command:

  * For the latest version::

        pip install pyside6

  * For a specific version, like 6.4.1::

        pip install pyside6==6.4.1

  * It is also possible to install a specific snapshot from our servers.
    To do so, you can use the following command::

      pip install --index-url=https://download.qt.io/snapshots/ci/pyside/6.0.0/latest pyside6 --trusted-host download.qt.io

* **Test your installation**

  Now that you have |project| installed, test your setup by running the following Python
  constructs to print version information::

    import PySide6.QtCore

    # Prints PySide6 version
    print(PySide6.__version__)

    # Prints the Qt version used to compile PySide6
    print(PySide6.QtCore.__version__)

.. note:: For more information about what's included in the ``pyside6``
   package, check :ref:`package_details`.

Create a Simple Application
---------------------------

Your |project| setup is ready. You can explore it further by developing a simple application
that prints "Hello World" in several languages. The following instructions will
guide you through the development process:

* **Imports**

  Create a new file named :code:`hello_world.py`, and add the following imports to it.::

    import sys
    import random
    from PySide6 import QtCore, QtWidgets, QtGui

  The |pymodname| Python module provides access to the Qt APIs as its submodule.
  In this case, you are importing the :code:`QtCore`, :code:`QtWidgets`, and :code:`QtGui` submodules.

* **Main Class**

  Define a class named :code:`MyWidget`, which extends QWidget and includes a QPushButton and
  QLabel.::

    class MyWidget(QtWidgets.QWidget):
        def __init__(self):
            super().__init__()

            self.hello = ["Hallo Welt", "Hei maailma", "Hola Mundo", "Привет мир"]

            self.button = QtWidgets.QPushButton("Click me!")
            self.text = QtWidgets.QLabel("Hello World",
                                         alignment=QtCore.Qt.AlignCenter)

            self.layout = QtWidgets.QVBoxLayout(self)
            self.layout.addWidget(self.text)
            self.layout.addWidget(self.button)

            self.button.clicked.connect(self.magic)

        @QtCore.Slot()
        def magic(self):
            self.text.setText(random.choice(self.hello))

  The MyWidget class has the :code:`magic` member function that randomly chooses an item from the
  :code:`hello` list. When you click the button, the :code:`magic` function is called.

* **Application execution**

  Now, add a main function where you instantiate :code:`MyWidget` and :code:`show` it.::

    if __name__ == "__main__":
        app = QtWidgets.QApplication([])

        widget = MyWidget()
        widget.resize(800, 600)
        widget.show()

        sys.exit(app.exec())

  Run your example by writing the following command: :command:`python hello_world.py`.

  Try clicking the button at the bottom to see which greeting you get.

  .. image:: images/screenshot_hello.png
     :alt: Hello World application

.. _faq-section:

Frequently Asked Questions
--------------------------

Here you can find a couple of common questions and situations that will
clarify questions before you start programming.

.. panels::
    :container: container-lg pb-1
    :column: col-lg-4 col-md-4 col-sm-6 col-xs-12 p-2

    .. link-button:: faq/whatisqt
        :type: ref
        :text: Qt, QML, Widgets... What is the difference?
        :classes: btn-link btn-block stretched-link
    ---

    .. link-button:: faq/whichide
        :type: ref
        :text: Which IDEs are compatible with PySide?
        :classes: btn-link btn-block stretched-link
    ---

    .. link-button:: faq/whatisshiboken
        :type: ref
        :text: Binding Generation: What is Shiboken?
        :classes: btn-link btn-block stretched-link
    ---

    .. link-button:: faq/typesoffiles
        :type: ref
        :text: File Types in PySide
        :classes: btn-link btn-block stretched-link
    ---

    .. link-button:: faq/distribution
        :type: ref
        :text: Distributing your application to other systems and platforms
        :classes: btn-link btn-block stretched-link

    ---

    .. link-button:: faq/whyqtforpython
        :type: ref
        :text: As a Qt/C++ developer, why should I consider Qt for Python?
        :classes: btn-link btn-block stretched-link

.. toctree::
    :hidden:

    faq/whatisqt.rst
    faq/whichide.rst
    faq/whatisshiboken.rst
    faq/typesoffiles.rst
    faq/distribution.rst
    faq/whyqtforpython.rst


