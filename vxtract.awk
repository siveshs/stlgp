#!/usr/bin/awk -f
/vertex/ { print $2, $3, $4}
/endloop/ {print ""}
