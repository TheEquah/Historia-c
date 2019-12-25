// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.24 HE
// Date (Modified): 12019.12.25 HE
// License: apache-2.0

#ifndef equah_historia__HEADER
#define equah_historia__HEADER

#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>

// [>] Output Buffer Size
// [i] Amount of bytes used to compose message for output buffer.
#define equah_historia__OUTPUT_BUFF_SIZE 1000

// [>] Output Function
// [i] Function to be executed to output log message.
#define equah_historia__OUTPUT_FUNCTION equah_historia__output_printf

// [i] Type definitions.
typedef struct equah_historia__Log_ equah_historia__Log;
typedef struct equah_historia__LogLevel_ equah_historia__LogLevel;
typedef struct equah_historia__LogData_ equah_historia__LogData;
typedef struct equah_historia__LogDataType_ equah_historia__LogDataType;

// [>] Log
// [i] Stores data for a log message.
struct equah_historia__Log_ {
  
  // [>] Time
  // [i] Stores time of this log message.
  const char *time;
  
  // [>] Level
  // [i] Represents the level of this log message.
  const equah_historia__LogLevel *level;
  
  // [>] Location
  // [i] String representing the location of this log message.
  const char *location;
  
  // [>] Message
  // [i] Human readable message of this log message.
  const char *message;
  
  // [>] Data
  // [i] Log message data.
  const equah_historia__LogData *data;
  
  // [i] Data Length
  // [i] Amount of log data entries.
  size_t data_len;
  
};

// [>] Log Level
// [i] Represents the context of a log message.
struct equah_historia__LogLevel_ {
  
  // [>] Identity
  // [i] Single character identifier.
  char id;
  
  // [>] Name
  // [i] Fully written name of this level.
  const char *name;
  
};

// [>] Log Data
// [i] Represents data stored in a log message.
struct equah_historia__LogData_ {
  
  // [>] Name
  // [i] Name to identify this data.
  const char *name;
  
  // [>] Type
  // [i] A Log Data Type of the value.
  const equah_historia__LogDataType *type;
  
  // [>] Format
  // [i] If supported, a prefered format type.
  const char *format;
  
  // [>] Value
  // [i] Pointer to value.
  const void *value;
  
};

// [>] Log Data Type
// [i] Represents a type of log data.
struct equah_historia__LogDataType_ {
  
  // [>] To String Function
  // [i] Function to parse this datatype into a string.
  size_t (*to_str_fn)(const equah_historia__LogData *, char *);
  
};

// [i] Function declarations.
void equah_historia__log(const equah_historia__LogLevel *, const char *, const char *, const equah_historia__LogData *, size_t);
size_t equah_historia__Log__compose(const equah_historia__Log *, char *);
size_t equah_historia__time(char *);
size_t equah_historia__output_printf(const equah_historia__Log *);
size_t equah_historia__dtp_int(const equah_historia__LogData *, char *);
size_t equah_historia__dtp_str(const equah_historia__LogData *, char *);

// [i] Declare default log levels.
extern const equah_historia__LogLevel *equah_historia__lvl_info;
extern const equah_historia__LogLevel *equah_historia__lvl_warning;
extern const equah_historia__LogLevel *equah_historia__lvl_error;
extern const equah_historia__LogLevel *equah_historia__lvl_note;

// [i] Define default datat ypes.
extern const equah_historia__LogDataType *equah_historia__dt_int;
extern const equah_historia__LogDataType *equah_historia__dt_str;

#endif
