TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += app

SUBDIRS += lib
app.depends = lib

#SUBDIRS += tests
#tests.depends = lib
