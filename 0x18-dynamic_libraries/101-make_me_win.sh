#!/bin/bash

# Full path to the gm program
GM_PROGRAM_PATH="/full/path/to/gm"

# Full path to the shared library
LIBFAKEGM_PATH="/full/path/to/libfakegm.so"

# Set the LD_PRELOAD environment variable to load the shared library
export LD_PRELOAD="$LIBFAKEGM_PATH"

# Run the gm program with your chosen numbers
"$GM_PROGRAM_PATH" 9 8 10 24 75 9