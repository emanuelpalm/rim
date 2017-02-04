#!/usr/bin/env bash

# Script for generating file.
TARGET=git.gen

command -v git >/dev/null 2>&1 || {
    echo >&2 "GIT not available in PATH.";
    exit 1;
}

GIT_TAG=$(git describe --first-parent 2> /dev/null)
REVISION_HASH=$(git rev-parse --short HEAD 2> /dev/null)
REVISION_UNIXTIME=$(git show --quiet --format=%ct 2> /dev/null)
VERSION=$(expr "$GIT_TAG" : 'v\([0-9]\+.[0-9]\+.[0-9]\+\)')
VERSION_MAJOR=$(expr "$GIT_TAG" : 'v\([0-9]\+\)')
VERSION_MINOR=$(expr "$GIT_TAG" : 'v[0-9]\+.\([0-9]\+\)')
VERSION_PATCH=$(expr "$GIT_TAG" : 'v[0-9]\+.[0-9]\+.\([0-9]\+\)')

echo -n "\
#ifndef LIBRARY_META_GIT_GEN
#define LIBRARY_META_GIT_GEN

/**
 * GIT meta data.
 *
 * @file
 */

/// Project revision hash C string.
#define META_REVISION_HASH \"$REVISION_HASH\"

/// Project revision creation time, as UNIX timestamp.
#define META_REVISION_UNIXTIME $REVISION_UNIXTIME

/// Project version identifier C string, on the form \`MAJOR.MINOR.PATCH\`.
#define META_VERSION \"$VERSION\"

/// Project major version identifier integer.
#define META_VERSION_MAJOR $VERSION_MAJOR

/// Project minor version identifier integer.
#define META_VERSION_MINOR $VERSION_MINOR

/// Project patch version identifier integer.
#define META_VERSION_PATCH $VERSION_PATCH

#endif" > $TARGET
