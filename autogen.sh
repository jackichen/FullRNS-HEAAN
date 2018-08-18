#!/bin/sh

echo
echo ... Full RNS HEAAN autogen ...
echo

## Check all dependencies are present
MISSING=""

# Check for aclocal
env aclocal --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  ACLOCAL=aclocal
else
  MISSING="$MISSING aclocal"
fi

# Check for autoconf
env autoconf --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOCONF=autoconf
else
  MISSING="$MISSING autoconf"
fi

# Check for autoheader
env autoheader --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOHEADER=autoheader
else
  MISSING="$MISSING autoheader"
fi

# Check for automake
env automake --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOMAKE=automake
else
  MISSING="$MISSING automake"
fi

# Check for libtoolize or glibtoolize
env libtoolize --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  # libtoolize was found, so use it
  TOOL=libtoolize
else
  # libtoolize wasn't found, so check for glibtoolize
  env glibtoolize --version > /dev/null 2>&1
  if [ $? -eq 0 ]; then
    TOOL=glibtoolize
  else
    MISSING="$MISSING libtoolize/glibtoolize"
  fi
fi

## Do the autogeneration
echo Running ${ACLOCAL}...
$ACLOCAL -I ./contrib/aclocal
echo Running ${AUTOHEADER}...
$AUTOHEADER
echo Running ${TOOL}...
$TOOL --automake --copy --force
echo Running ${AUTOCONF}...
$AUTOCONF
echo Running ${AUTOMAKE}...
$AUTOMAKE --add-missing --force-missing --copy --foreign

# Instruct user on next steps
echo
echo "Please proceed with configuring, compiling, and installing."
