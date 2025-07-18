#
# Makefile for the Fast Light Tool Kit (FLTK) documentation.
#
# Copyright 1998-2024 by Bill Spitzak and others.
#
# This library is free software. Distribution and use rights are outlined in
# the file "COPYING" which should have been included with this file.  If this
# file is missing or damaged, see the license at:
#
#     https://www.fltk.org/COPYING.php
#
# Please see the following page on how to report bugs and issues:
#
#      https://www.fltk.org/bugs.php
#

# Get configuration stuff...
include ../makeinclude

# make sure that all docs are (re-)created independent of missing deps
.PHONY: pdf html refman.pdf

SRC_DOCDIR      = 	./src

# These are the HTML "source" files...
HTMLFILES	= 	 \
			 $(SRC_DOCDIR)/index.dox \
                         $(SRC_DOCDIR)/preface.dox \
                         $(SRC_DOCDIR)/intro.dox \
                         $(SRC_DOCDIR)/basics.dox \
                         $(SRC_DOCDIR)/common.dox \
                         $(SRC_DOCDIR)/coordinates.dox \
                         $(SRC_DOCDIR)/resize.dox \
                         $(SRC_DOCDIR)/editor.dox \
                         $(SRC_DOCDIR)/drawing.dox \
                         $(SRC_DOCDIR)/events.dox \
                         $(SRC_DOCDIR)/subclassing.dox \
                         $(SRC_DOCDIR)/opengl.dox \
                         $(SRC_DOCDIR)/fltk-options.dox \
                         $(SRC_DOCDIR)/advanced.dox \
                         $(SRC_DOCDIR)/unicode.dox \
                         $(SRC_DOCDIR)/enumerations.dox \
                         $(SRC_DOCDIR)/glut.dox \
                         $(SRC_DOCDIR)/forms.dox \
                         $(SRC_DOCDIR)/osissues.dox \
                         $(SRC_DOCDIR)/migration_1_4.dox \
                         $(SRC_DOCDIR)/development.dox \
                         $(SRC_DOCDIR)/license.dox \
                         $(SRC_DOCDIR)/examples.dox \
                         $(SRC_DOCDIR)/faq.dox \
                         $(SRC_DOCDIR)/Fl_Terminal.dox

MANPAGES =	$(SRC_DOCDIR)/fltk.$(CAT3EXT) $(SRC_DOCDIR)/fltk-config.$(CAT1EXT) \
		$(SRC_DOCDIR)/fluid.$(CAT1EXT) $(SRC_DOCDIR)/blocks.$(CAT6EXT) \
		$(SRC_DOCDIR)/checkers.$(CAT6EXT) $(SRC_DOCDIR)/sudoku.$(CAT6EXT) \
		$(SRC_DOCDIR)/fltk-options.$(CAT1EXT)

# Get FLTK's Git Revision either from Git /or/ from fltk_git_rev.dat (Issue #499)
#
# Note: this may fail (return "unknown") if the sources were downloaded
# from GitHub as a "release" (zip) archive. This is not supported.

# Test/debug only: should be commented out unless used (see: debug_git_rev)
# GIT_REV_FROM_GIT  := "$$(git rev-parse HEAD 2>/dev/null)"
# GIT_REV_FROM_FILE := "$$(cat ../fltk_git_rev.dat 2>/dev/null)"

FLTK_GIT_REVISION := "`( (git rev-parse HEAD || cat ../fltk_git_rev.dat;) || echo 'unknown'; ) 2>/dev/null`"

all:	$(MANPAGES)

# Use `make docs' to create all docs for distribution files.
# You need installed versions of Doxygen and LaTeX for this.

docs:	all html pdf

# Synonyms for docs:

alldocs: docs
dist:	docs

debug_git_rev:
	# echo "GIT_REV_FROM_GIT  = $(GIT_REV_FROM_GIT)"
	# echo "GIT_REV_FROM_FILE = $(GIT_REV_FROM_FILE)"
	echo "FLTK_GIT_REVISION = $(FLTK_GIT_REVISION)"

clean:
	$(RM) Doxyfile Doxybook
	$(RM) copyright.dox generated.dox make_pdf
	$(RM) fltk.pdf refman.pdf src/fltk-title.tex src/fltk-book.tex.in src/fltk-book.tex
	$(RMDIR) html latex
	$(RM) *~ *.bck *.bak *.log
	$(RM) $(MANPAGES) $(SRC_DOCDIR)/*.0

depend:

install: $(MANPAGES)
	echo "Installing documentation files in $(DESTDIR)$(docdir) ..."
	-$(INSTALL_DIR) "$(DESTDIR)$(docdir)"
	if test -f html/index.html ; then \
	  for file in html/* ; do \
		$(INSTALL_DATA) $$file "$(DESTDIR)$(docdir)"; \
	  done \
	fi
	if test -f fltk.pdf ; then \
	  echo "Installing fltk.pdf in $(DESTDIR)$(docdir) ..."; \
	  $(INSTALL_DATA) fltk.pdf "$(DESTDIR)$(docdir)"; \
	fi
	echo "Installing man pages in $(DESTDIR)$(mandir) ..."
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/cat1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fluid.$(CAT1EXT) "$(DESTDIR)$(mandir)/cat1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk-config.$(CAT1EXT) "$(DESTDIR)$(mandir)/cat1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk-options.$(CAT1EXT) "$(DESTDIR)$(mandir)/cat1"
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/cat3"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk.$(CAT3EXT) "$(DESTDIR)$(mandir)/cat3"
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/man1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fluid.man "$(DESTDIR)$(mandir)/man1/fluid.1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk-config.man "$(DESTDIR)$(mandir)/man1/fltk-config.1"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk-options.man "$(DESTDIR)$(mandir)/man1/fltk-options.1"
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/man3"
	$(INSTALL_MAN) $(SRC_DOCDIR)/fltk.man "$(DESTDIR)$(mandir)/man3/fltk.3"

install-linux install-osx:
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/cat6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/blocks.$(CAT6EXT) "$(DESTDIR)$(mandir)/cat6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/checkers.$(CAT6EXT) "$(DESTDIR)$(mandir)/cat6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/sudoku.$(CAT6EXT) "$(DESTDIR)$(mandir)/cat6"
	-$(INSTALL_DIR) "$(DESTDIR)$(mandir)/man6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/blocks.man "$(DESTDIR)$(mandir)/man6/blocks.6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/checkers.man "$(DESTDIR)$(mandir)/man6/checkers.6"
	$(INSTALL_MAN) $(SRC_DOCDIR)/sudoku.man "$(DESTDIR)$(mandir)/man6/sudoku.6"


uninstall:
	$(RMDIR) "$(DESTDIR)$(docdir)"
	$(RM) "$(DESTDIR)$(mandir)/cat1/fluid.$(CAT1EXT)"
	$(RM) "$(DESTDIR)$(mandir)/man1/fluid.1"
	$(RM) "$(DESTDIR)$(mandir)/cat1/fltk-config.$(CAT1EXT)"
	$(RM) "$(DESTDIR)$(mandir)/man1/fltk-config.1"
	$(RM) "$(DESTDIR)$(mandir)/cat1/fltk-options.$(CAT1EXT)"
	$(RM) "$(DESTDIR)$(mandir)/man1/fltk-options.1"
	$(RM) "$(DESTDIR)$(mandir)/cat3/fltk.$(CAT3EXT)"
	$(RM) "$(DESTDIR)$(mandir)/man3/fltk.3"

uninstall-linux uninstall-osx:
	$(RM) "$(DESTDIR)$(mandir)/cat6/blocks.$(CAT6EXT)"
	$(RM) "$(DESTDIR)$(mandir)/cat6/checkers.$(CAT6EXT)"
	$(RM) "$(DESTDIR)$(mandir)/cat6/sudoku.$(CAT6EXT)"
	$(RM) "$(DESTDIR)$(mandir)/man6/blocks.6"
	$(RM) "$(DESTDIR)$(mandir)/man6/checkers.6"
	$(RM) "$(DESTDIR)$(mandir)/man6/sudoku.6"

# The documentation is generated using doxygen. There are two control files
# for doxygen: Doxyfile for html documentation and Doxybook for pdf docs.
# Both files are generated from the common source file Doxyfile.in.
# Note that Doxyfile.in is shared with CMake to configure these files.

# Note: There's no way to enable the "Driver Documentation" via configure+make,
#       please use CMake 'FLTK_INCLUDE_DRIVER_DOCS' instead.
#       Alternatively (if you really need it) edit this Makefile and
#       replace the two lines below containing "@DRIVER_DOCS@" to read:
#	    -e's, @DRIVER_DOCS@, DriverDev,' \
#       (w/o leading '#') to enable the "Driver Documentation" section.
#       Please take care of copying tabs and spaces literally.
# Note: There's no intention to enable this via configure option (use CMake).

Doxyfile: Doxyfile.in generated.dox copyright.dox
	echo "Generating Doxyfile ..."
	./convert_doxyfile "$(DOXYDOC)" $< $@ Doxyfile_error.log
	sed -e's,@FLTK_VERSION@,$(FLTK_VERSION),' \
	    -e's,@GENERATE_HTML@,YES,' \
	    -e's,@GENERATE_LATEX@,NO,' \
	    -e's, @LATEX_HEADER@,,' \
	    -e's, @DRIVER_DOCS@,,' \
	    -e's,@CMAKE_CURRENT_SOURCE_DIR@,.,' \
	    -e's,@CMAKE_CURRENT_BINARY_DIR@,,' \
	    -e's,@FLTK_SOURCE_DIR@,..,' \
	    -i $@

Doxybook: Doxyfile.in generated.dox copyright.dox
	echo "Generating Doxybook ..."
	./convert_doxyfile "$(DOXYDOC)" $< $@ Doxybook_error.log
	sed -e's,@FLTK_VERSION@,$(FLTK_VERSION),' \
	    -e's,@GENERATE_HTML@,NO,' \
	    -e's,@GENERATE_LATEX@,YES,' \
	    -e's,@LATEX_HEADER@,src/fltk-book.tex,' \
	    -e's, @DRIVER_DOCS@,,' \
	    -e's,@CMAKE_CURRENT_SOURCE_DIR@,.,' \
	    -e's,@CMAKE_CURRENT_BINARY_DIR@,,' \
	    -e's,@FLTK_SOURCE_DIR@,..,' \
	    -i $@

# The HTML files are generated using doxygen, and this needs
# an installed doxygen version and may take some time, so this target
# is not made by default.
# Use `make html' or `make docs' to create the html docs.

html:	$(HTMLFILES) Doxyfile
	echo "Generating HTML documentation..."
	-$(RMDIR) html
	-$(INSTALL_DIR) html
	-"$(DOXYDOC)"
	if test "x$(DOXYDOC)" = "x" ; then \
	  echo "Sorry - doxygen not found. Please install doxygen and run configure."; \
	fi

# The PDF documentation (fltk.pdf) is generated using doxygen and LaTeX, and
# this needs installed Doxygen and LaTeX programs and may take some time, so
# this target is not made by default.
# Use `make pdf' or `make docs' to create the PDF docs.

pdf:	refman.pdf
	cp -f latex/refman.pdf fltk.pdf

refman.pdf: $(HTMLFILES) Doxybook src/fltk-book.tex make_pdf
	-$(RMDIR) latex
	echo "Generating PDF documentation ..."
	"$(DOXYDOC)" Doxybook
	./make_pdf

make_pdf: make_pdf.in
	echo "Generating $@ ..."
	PDF_DATE=`date +D:%Y%m%d%H%M%S`; \
	sed -e"s/@PDF_DATE@/$$PDF_DATE/g" \
	    < $< > $@
	chmod +x $@

src/fltk-title.tex: src/fltk-title.tex.in
	echo "Generating $@ ..."
	TODAY=`LC_ALL=C date '+%B %e, %Y'`; \
	sed -e"s/@FLTK_GIT_REVISION@/$(FLTK_GIT_REVISION)/g" \
	    -e"s/@TODAY@/$$TODAY/g" \
	    < $< > $@

src/fltk-book.tex.in: src/fltk-title.tex
	echo "Generating $@ ..."
	./make_header "$(DOXYDOC)" $< $@

src/fltk-book.tex: src/fltk-book.tex.in
	echo "Generating $@ ..."
	DOXY_VERSION=`"$(DOXYDOC)" --version|cut -f1 -d' '`; \
	YEAR=`date +%Y`; \
	sed -e"s/@YEAR@/$$YEAR/g" \
	    -e"s/@FLTK_VERSION@/$(FLTK_VERSION)/g" \
	    -e"s/@DOXY_VERSION@/$$DOXY_VERSION/g" \
	    < $< > $@

generated.dox: generated.dox.in
	echo "Generating $@ ..."
	CURRENT_DATE=`LC_ALL=C date "+%b %d, %Y"`; \
	DOXYGEN_VERSION_SHORT=`"$(DOXYDOC)" --version|cut -f1 -d' '`; \
	sed -e"s/@CURRENT_DATE@/$$CURRENT_DATE/g" \
	    -e"s/@FLTK_GIT_REVISION@/$(FLTK_GIT_REVISION)/g" \
	    -e"s/@DOXYGEN_VERSION_SHORT@/$$DOXYGEN_VERSION_SHORT/g" \
	    < $< > $@

copyright.dox: copyright.dox.in
	echo "Generating $@ ..."
	YEAR=`date +%Y`; \
	sed -e"s/@YEAR@/$$YEAR/g" \
	    < $< > $@
