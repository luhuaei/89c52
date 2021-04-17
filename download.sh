#!/bin/sh
set -e

module="$1"

if ["$module" == ""]; then
    echo "Please input the module name"
    exit 0
fi

pushd $module
sdcc "$module".c
packihx "$module".ihx > "$module".hex
popd

sudo -E ./stcgal/stcgal.py -a -D -P stc89a "$module/$module".hex
