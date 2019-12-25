# Author (Created): Roger "Equah" Hürzeler
# Date (Created): 12019.12.25 HE
# License: apache-2.0

echo "=== COMPILE ==="
SRC_DIR="`dirname $0`/../../src"
MAIN_DIR="`dirname $0`"
gcc -I $SRC_DIR -x c $SRC_DIR/equah/historia.c -x c $MAIN_DIR/counter.c -o $MAIN_DIR/counter.o

echo "=== EXECUTE ==="
$MAIN_DIR/counter.o

echo "=== END ==="
