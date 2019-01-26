#!/usr/bin/env sh
CLEAN=false

for i in "$@"
do
case $i in
    clean)
    CLEAN=true
    shift
    ;;
    *)
    ;;
esac
done

echo "Building..."

if $CLEAN; then
    mingw32-make clean
else
    mingw32-make
fi
