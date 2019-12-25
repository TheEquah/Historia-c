// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.24 HE
// Date (Modified): 12019.12.25 HE
// License: apache-2.0

#include "equah/historia.h"

// [i] Define default log levels.
const equah_historia__LogLevel equah_historia__lvl_info_ = {'I', "Information"};
const equah_historia__LogLevel *equah_historia__lvl_info = &equah_historia__lvl_info_;
const equah_historia__LogLevel equah_historia__lvl_warning_ = {'W', "Warning"};
const equah_historia__LogLevel *equah_historia__lvl_warning = &equah_historia__lvl_warning_;
const equah_historia__LogLevel equah_historia__lvl_error_ = {'E', "Error"};
const equah_historia__LogLevel *equah_historia__lvl_error = &equah_historia__lvl_error_;
const equah_historia__LogLevel equah_historia__lvl_note_ = {'N', "Notice"};
const equah_historia__LogLevel *equah_historia__lvl_note = &equah_historia__lvl_note_;

// [i] Define default data types.
const equah_historia__LogDataType equah_historia__dt_int_ = {&equah_historia__dtp_int};
const equah_historia__LogDataType *equah_historia__dt_int = &equah_historia__dt_int_;
const equah_historia__LogDataType equah_historia__dt_str_ = {&equah_historia__dtp_str};
const equah_historia__LogDataType *equah_historia__dt_str = &equah_historia__dt_str_;

// [i] Message buffers.
equah_historia__Log log_buffer;
char output_buffer[equah_historia__OUTPUT_BUFF_SIZE];

// [>] Log
// [i] Write log message.
// [P] {const equah_historia__LogLevel *} lvl => Pointer to log message level.
// [P] {const char *} loc => Location where this log message originates from.
// [P] {const char *} msg => Human readable information of log message.
// [P] {const equah_historia__LogData *} => Pointer to array of log message data.
// [P] {size_t} data_len => Amount of log message data entries.
void equah_historia__log(const equah_historia__LogLevel *lvl, const char *loc, const char *msg, const equah_historia__LogData *data, size_t data_len) {
  
  // [i] Get current time.
  static char time_str[20];
  equah_historia__time(time_str);
  
  // [i] Build message in buffer.
  log_buffer.time = time_str;
  log_buffer.level = lvl;
  log_buffer.location = loc;
  log_buffer.message = msg;
  log_buffer.data = data;
  log_buffer.data_len = data_len;
  
  // [i] Call configured output method.
  equah_historia__OUTPUT_FUNCTION(&log_buffer);
  
}

// [>] Log - Compose
// [i] Converts given log message to  string.
// [P] {equah_historia__Log *} log_msg => Pointer to log message to compose.
// [P] {char *} buff => Buffer to store composed log message.
// [R] {size_t} => Count of written char to buffer.
size_t equah_historia__Log__compose(const equah_historia__Log *log_msg, char *buff) {
  
  size_t buff_pos = 0;
  
  // [i] Compose message header.
  buff_pos += sprintf(buff, "\n[%c] %s | %s | %s\n",
    log_msg->level->id,
    log_msg->time,
    log_msg->location,
    log_msg->message
  );
  
  // [i] Compose message data.
  size_t data_pos = 0;
  while (log_msg->data_len > data_pos) {
    char data_val_buff[100];
    buff_pos += sprintf(buff + buff_pos, "\t %s: ", log_msg->data[data_pos].name);
    buff_pos += log_msg->data[data_pos].type->to_str_fn(&log_msg->data[data_pos], buff + buff_pos);
    buff_pos += sprintf(buff + buff_pos, ";\n");
    data_pos++;
  }
  
  buff_pos += sprintf(buff + buff_pos, "\n");
  
  return buff_pos;
}

// [>] Time
// [i] Generates string containing current time.
// [P] {char *} buff => Buffer where time will be written.
// [R] {size_t} => Amount of bytes written to buffer.
size_t equah_historia__time(char *buff) {
  
  static struct timeval log_time;
  gettimeofday(&log_time, NULL);
  size_t size = sprintf(buff, "%li.%li", log_time.tv_sec, log_time.tv_usec);
  
  return size;
}

// [>] Output Printf
// [i] Outputs the log message with the printf method.
// [P] {const equah_historia__Log *} log_msg => Log message to print.
// [R] {size_t} => Amount of written bytes.
size_t equah_historia__output_printf(const equah_historia__Log *log_msg) {
  
  // [i] Compose message.
  equah_historia__Log__compose(log_msg, output_buffer);
  
  // [i] Print composed message.
  size_t size = printf(output_buffer);
  
  return size;
}

// [>] Data Type Print Integer
// [i] Writes data type integer.
// [P] {const equah_historia__LogData *} data => Data to write.
// [P] {char *} buff => Buffer to write data.
// [R] {size_t} => Amount of written bytes.
size_t equah_historia__dtp_int(const equah_historia__LogData *data, char *buff) {
  
  size_t size = 0;
  
  // [i] Define formatting.
  const char *format = "%i";
  if (data->format != NULL) {
    format = data->format;
  }
  
  size += sprintf(buff, format, (int) *((int *) data->value));
  
  return size;
}

// [>] Data Type Print String
// [P] {const equah_historia__LogData *} data => Data to write.
// [P] {char *} buff => Buffer to write data.
// [R] {size_t} => Amount of written bytes.
size_t equah_historia__dtp_str(const equah_historia__LogData *data, char *buff) {
  
  size_t size = 0;
  
  // [i] Define formatting.
  const char *format = "%s";
  if (data->format != NULL) {
    format = data->format;
  }
  
  size += sprintf(buff, format, data->value);
  
  return size;
}
