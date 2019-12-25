<!-- Author (Created): Roger "Equah" Hürzeler -->
<!-- Author (Modified): Roger "Equah" Hürzeler -->
<!-- Date (Created): 12019.12.24 HE -->
<!-- Date (Modified): 12019.12.25 HE -->
<!-- License: apache-2.0 -->

**Historia [C]**
================================================================================

[Historia](https://github.com/TheEquah/Historia/) C library implementation.

--------------------------------------------------------------------------------

# Architecture

Overview of the Historia architecture.

## Log message

The log message object (`equah_historia__Log`) represents a log message. It contains the time, level, location, message and data of the message to output.

### Time

When creating a log message, Historia uses the `gettimeofday(struct timeval *tv, struct timezone *tz)` function from `sys/time.h` and parses the given time into a string.

### Location

The location string defines where the log message was composed. The formatting is done with `file.c > void function(int example) > n`.

### Message

The message contains human readable information of the log message.

## Log Level

The log level defines the context of the message. The defined contexts are:

| Sortcut | Name        | Historia variable             | Description            |
| :------ | :---------- | :---------------------------- | :--------------------- |
| I       | Information | `equah_historia__lvl_info`    | General information.   |
| W       | Warning     | `equah_historia__lvl_warning` | General warning.       |
| E       | Error       | `equah_historia__lvl_error`   | Critical error.        |
| N       | Notice      | `equah_historia__lvl_note`    | Important information. |

## Log Data

Log messages can contain additional data related to the message. Log data contains the name, type, prefered format and value.

### Name

The log data name is printed to identify the attached value.

### Type

The log data type defines how the value will be printed. Historia defines the following data types:

| C type   | Historia variable        | Description                |
| :------- | :----------------------- | :------------------------- |
| `int`    | `equah_historia__dt_int` | Default integer data type. |
| `char *` | `equah_historia__dt_str` | String data type.          |
| `char[]` | `equah_historia__dt_str` | String data type.          |

### Format

The format option is optional, since the data type defines a default formatting method. But if the value should be printed in a specific way, a format option can be defined.


--------------------------------------------------------------------------------

# Compile

To compile a C file using Historia, use the `#include "equah/historia.h"` at the beginning of the file.

The file can then be compiled by adding the `-I ./<path_to_src> -x c ./<path_to_src>/equah/historia.c` to the `gcc` command where `<path_to_src>` is the path to the (`/src/`)[] directory.

It will probably look something like `gcc -I ./Historia-c/src -x c ./Historia-c/src/equah/historia.c -x c ./main.c -o main.o`.

--------------------------------------------------------------------------------

# Examples

This repository provides the following example uses for Historia.

## Counter

A simple counter example script.

Directory: [`/example/counter`](https://github.com/TheEquah/Historia-c/tree/master/example/counter/)

--------------------------------------------------------------------------------
