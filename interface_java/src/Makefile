##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP Java/Swing - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme (doit correspondre au fichier qui contient main())
#

PROG = MainFrame

#
# Fichiers sources .java
#
SOURCES = Client.java  CommandAction.java TextArea.java Printer.java MainFrame.java

#
# Compilateur Java
#
JC = javac

#
# Dossier de compilation
#
BIN = ../bin

#
# Packages
#
PACKAGES = .:interfaces
vpath %.java $(PACKAGES::= )

#
# Options du compilateur Java
#

JFLAGS = -g -d $(BIN) -cp $(PACKAGES)


##########################################
#
# Regles de construction/destruction des .class et de l'executable
#

all: classes

run: all
	java $(BIN)/${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) -r $(BIN)/* 1>/dev/null 2>&1

tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

#.java.class:
#	$(JC) $(JFLAGS) $*.java

%.class: %.java
	$(JC) $(JFLAGS) $<
