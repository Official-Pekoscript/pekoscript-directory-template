#include "mysql.h"

int64_t mysql_object_size() {
    return sizeof(MYSQL);
}

int64_t mysql_bind_object_size() {
    return sizeof(MYSQL_BIND);
}

int64_t mysql_rpl_object_size() {
    return sizeof(MYSQL_BIND);
}

int64_t glue_mysql_affected_rows(void* mysql) {
    return mysql_affected_rows((MYSQL*)mysql);
}

bool glue_mysql_autocommit(void* mysql, bool mode) {
    return mysql_autocommit((MYSQL*)mysql, mode);
}

// bool glue_mysql_bind_param(void *mysql, unsigned n_params, void *bind, const char **name) {
//     return mysql_bind_param((MYSQL*)mysql, n_params, (MYSQL_BIND*)bind, name);
// }

// void glue_mysql_binlog_close(void *mysql, void *rpl) {
//     mysql_binlog_close((MYSQL*)mysql, (MYSQL_RPL*)rpl);
// }

// int glue_mysql_binlog_fetch(void *mysql, void *rpl) {
//     return mysql_binlog_fetch((MYSQL*)mysql, (MYSQL_RPL*)rpl);
// }

// int glue_mysql_binlog_open(void *mysql, void *rpl) {
//     return mysql_binlog_open((MYSQL*)mysql, (MYSQL_RPL*)rpl);
// }

bool glue_mysql_change_user(void *mysql, const char *user, const char *password, const char *db) {
    return mysql_change_user((MYSQL*)mysql, user, password, db);
}

char* glue_mysql_character_set_name(void *mysql) {
    return (char*)mysql_character_set_name((MYSQL*)mysql);
}

// void* glue_mysql_client_find_plugin(void *mysql, const char *name, int type) {
//     return mysql_client_find_plugin((MYSQL*)mysql, name, type);
// }

// void* glue_mysql_client_register_plugin(void *mysql, void *plugin) {
//     return mysql_client_register_plugin((MYSQL*)mysql, (struct st_mysql_client_plugin *)plugin);
// }

void glue_mysql_close(void *mysql) {
    mysql_close((MYSQL*)mysql);
}

bool glue_mysql_commit(void *mysql) {
    return mysql_commit((MYSQL*)mysql);
}

void glue_mysql_data_seek(void *result, int64_t offset) {
    mysql_data_seek((MYSQL_RES*)result, offset);
}

void glue_mysql_debug(char *debug) {
    mysql_debug(debug);
}

int glue_mysql_dump_debug_info(void *mysql) {
    return mysql_dump_debug_info((MYSQL*)mysql);
}

bool glue_mysql_eof(MYSQL_RES *result) {
    return mysql_eof((MYSQL_RES*)result);
}

int glue_mysql_errno(void *mysql) {
    return mysql_errno((MYSQL*)mysql);
}

char *glue_mysql_error(void *mysql) {
    return (char*)mysql_error((MYSQL *)mysql);
}

void* glue_mysql_fetch_field(void *result) {
    return (void*)mysql_fetch_field((MYSQL_RES*)result);
}

void *glue_mysql_fetch_field_direct(void *result, int fieldnr) {
    return (void*)mysql_fetch_field_direct((MYSQL_RES *)result, fieldnr);
}

void *glue_mysql_fetch_fields(void *result) {
    return (void*)mysql_fetch_fields((MYSQL_RES*)result);
}

int64_t *glue_mysql_fetch_lengths(void *result) {
    return (int64_t *)mysql_fetch_lengths((MYSQL_RES*)result);
}

char** glue_mysql_fetch_row(void *result) {
    return mysql_fetch_row((MYSQL_RES*)result);
}

// int glue_mysql_fetch_row_nonblocking(void *result, char ***row) {
//     return mysql_fetch_row_nonblocking((MYSQL_RES *)result, row);
// }

int glue_mysql_field_count(void *mysql) {
    return mysql_field_count((MYSQL*)mysql);
}

int glue_mysql_field_seek(void *result, int offset) {
    return mysql_field_seek((MYSQL_RES*)result, offset);
}

int glue_mysql_field_tell(void *result) {
    return mysql_field_tell((MYSQL_RES*)result);
}

void glue_mysql_free_result(void *result) {
    mysql_free_result((MYSQL_RES*)result);
}

// int glue_mysql_free_result_nonblocking(void *result) {
//     return mysql_free_result_nonblocking((MYSQL_RES*)result);
// }

// bool glue_mysql_free_ssl_session_data(void *mysql, void *data) {
//     return mysql_free_ssl_session_data((MYSQL*)mysql, data);
// }

void glue_mysql_get_character_set_info(void *mysql, void *cs) {
    mysql_get_character_set_info((MYSQL *)mysql, (MY_CHARSET_INFO *)cs);
}

char *glue_mysql_get_client_info(void) {
    return (char*)mysql_get_client_info();
}

int64_t glue_mysql_get_client_version(void) {
    return mysql_get_client_version();
}

char *glue_mysql_get_host_info(void *mysql) {
    return (char*)mysql_get_host_info((MYSQL*)mysql);
}

// int glue_mysql_get_option(void *mysql, int option, void *arg) {
//     return mysql_get_option((MYSQL*)mysql, (enum mysql_option)option, arg);
// }

int glue_mysql_get_proto_info(void *mysql) {
    return mysql_get_proto_info((MYSQL*)mysql);
}

char *glue_mysql_get_server_info(void *mysql) {
    return (char*)mysql_get_server_info((MYSQL*)mysql);
}

int64_t glue_mysql_get_server_version(void *mysql) {
    return mysql_get_server_version((MYSQL*)mysql);
}

char *glue_mysql_get_ssl_cipher(void *mysql) {
    return (char*)mysql_get_ssl_cipher((MYSQL*)mysql);
}

// void *glue_mysql_get_ssl_session_data(void *mysql, int n_ticket, int *out_len) {
//     return mysql_get_ssl_session_data((MYSQL *)mysql, n_ticket, (unsigned int*)out_len);
// }

// bool glue_mysql_get_ssl_session_reused(void *mysql) {
//     return mysql_get_ssl_session_reused((MYSQL*)mysql);
// }

int64_t glue_mysql_hex_string(char *to, char *from, int64_t length) {
    return mysql_hex_string(to, from, length);
}

char *glue_mysql_info(void *mysql) {
    return (char*)mysql_info((MYSQL*)mysql);
}

void *glue_mysql_init(void *mysql) {
    return mysql_init((MYSQL*)mysql);
}

uint64_t glue_mysql_insert_id(void *mysql) {
    return mysql_insert_id((MYSQL*)mysql);
}

int glue_mysql_kill(void *mysql, int64_t pid) {
    return mysql_kill((MYSQL*)mysql, pid);
}

void glue_mysql_library_end(void) {
    mysql_library_end();
}

int glue_mysql_library_init(int argc, char **argv, char **groups) {
    return mysql_library_init(argc, argv, groups);
}

void *glue_mysql_list_dbs(void *mysql, char *wild) {
    return (void*)mysql_list_dbs((MYSQL*)mysql, wild);
}

void *glue_mysql_list_fields(void *mysql, char *table, char *wild) {
    return (void*)mysql_list_fields((MYSQL*)mysql, table, wild);
}

void *glue_mysql_list_processes(void *mysql) {
    return (void*)mysql_list_processes((MYSQL*)mysql);
}

void *glue_mysql_list_tables(void *mysql, char *wild) {
    return (void*)mysql_list_tables((MYSQL*)mysql, wild);
}

// void *glue_mysql_load_plugin(void *mysql, char *name, int type, int argc) {
//     return (void*)mysql_load_plugin((MYSQL*)mysql, name, type, argc);
// }

// void *glue_mysql_load_plugin_v(void *mysql, char *name, int type, int argc, va_list args) {
//     return mysql_load_plugin_v((MYSQL*)mysql, name, type, argc, args);
// }

bool glue_mysql_more_results(void *mysql) {
    return mysql_more_results((MYSQL*)mysql);
}

int glue_mysql_next_result(void *mysql) {
    return mysql_next_result((MYSQL*)mysql);
}

// int glue_mysql_next_result_nonblocking(void *mysql) {
//     return mysql_next_result_nonblocking((MYSQL*)mysql);
// }

int glue_mysql_num_fields(void *result) {
    return mysql_num_fields((MYSQL_RES*)result);
}

uint64_t glue_mysql_num_rows(void *result) {
    return mysql_num_rows((MYSQL_RES*)result);
}

int glue_mysql_options(void *mysql, int option, void *arg) {
    return mysql_options((MYSQL*)mysql, (enum mysql_option)option, arg);
}

// int glue_mysql_options4(void *mysql, int option, void *arg1, void *arg2) {
//     return mysql_options4((MYSQL*)mysql, (enum mysql_option)option, arg1, arg2);
// }

int glue_mysql_ping(void *mysql) {
    return mysql_ping((MYSQL*)mysql);
}

// int glue_mysql_plugin_get_option(void *plugin, char *option, void *value) {
//     return mysql_plugin_get_option((struct st_mysql_client_plugin*)plugin, option, value);
// }

// int glue_mysql_plugin_options(void *plugin, char *option, void *value) {
//     return mysql_plugin_options((struct st_mysql_client_plugin*)plugin, option, value);
// }

int glue_mysql_query(MYSQL *mysql, char *stmt_str) {
    return mysql_query((MYSQL*)mysql, stmt_str);
}

void *glue_mysql_real_connect(void *mysql, char *host, char *user, char *passwd, char *db, int port, char *unix_socket, int64_t client_flag) {
    return (void*)mysql_real_connect((MYSQL*)mysql, host, user, passwd, db, port, unix_socket, client_flag);
}

// void *glue_mysql_real_connect_dns_srv(void *mysql, char *dns_srv_name, char *user, char *passwd, char *db, int64_t client_flag) {
//     return (void*)mysql_real_connect_dns_srv((MYSQL*)mysql, dns_srv_name, user, passwd, db, client_flag);
// }

// int glue_mysql_real_connect_nonblocking(void *mysql, char *host, char *user, char *passwd, char *db, int port, char *unix_socket, int64_t client_flag) {
//     return (int)mysql_real_connect_nonblocking((MYSQL*)mysql, host, user, passwd, db, port, unix_socket, client_flag);
// }

int64_t glue_mysql_real_escape_string(void *mysql, char *to, char *from, int64_t length) {
    return mysql_real_escape_string((MYSQL*)mysql, to, from, length);
}

// int64_t glue_mysql_real_escape_string_quote(void *mysql, char *to, const char *from, unsigned long length, char quote) {
//     return mysql_real_escape_string_quote((MYSQL*)mysql, to, from, length, quote);
// }

int glue_mysql_real_query(void *mysql, char *stmt_str, int64_t length) {
    return mysql_real_query((MYSQL*)mysql, stmt_str, length);
}

// int glue_mysql_real_query_nonblocking(void *mysql, char *stmt_str, int64_t length) {
//     return (int)mysql_real_query_nonblocking((MYSQL*)mysql, stmt_str, length);
// }

int glue_mysql_refresh(MYSQL *mysql, unsigned int options) {
    return mysql_refresh((MYSQL*)mysql, options);
}

// int glue_mysql_reset_connection(void *mysql) {
//     return mysql_reset_connection((MYSQL*)mysql);
// }

// void glue_mysql_reset_server_public_key(void) {
//     mysql_reset_server_public_key();
// }

// int glue_mysql_result_metadata(void *result) {
//     return mysql_result_metadata((MYSQL_RES*)result);
// }

bool glue_mysql_rollback(void *mysql) {
    return mysql_rollback((MYSQL*)mysql);
}

void* glue_mysql_row_seek(void *result, void *offset) {
    return (void*)mysql_row_seek((MYSQL_RES*)result, (MYSQL_ROW_OFFSET)offset);
}

void* glue_mysql_row_tell(void *result) {
    return mysql_row_tell((MYSQL_RES*)result);
}

int glue_mysql_select_db(void *mysql, char *db) {
    return mysql_select_db((MYSQL*)mysql, db);
}

void glue_mysql_server_end(void) {
    mysql_server_end();
}

int glue_mysql_server_init(int argc, char **argv, char **groups) {
    return mysql_server_init(argc, argv, groups);
}

// int glue_mysql_session_track_get_first(void *mysql, int type, char **data, int64_t *length) {
//     return mysql_session_track_get_first((MYSQL*)mysql, (enum enum_session_state_type)type, (const char**)data, (size_t*)length);
// }

// int glue_mysql_session_track_get_next(void *mysql, int type, char **data, int64_t *length) {
//     return mysql_session_track_get_next((MYSQL*)mysql, (enum enum_session_state_type)type, (const char**)data, (size_t*)length);
// }

int glue_mysql_set_character_set(void *mysql, char *csname) {
    return mysql_set_character_set((MYSQL*)mysql, csname);
}

void glue_mysql_set_local_infile_default(void *mysql) {
    mysql_set_local_infile_default((MYSQL*)mysql);
}

void glue_mysql_set_local_infile_handler(void *mysql, int (*local_infile_init)(void**, char*, void*), int (*local_infile_read)(void*, char*, int), void (*local_infile_end)(void*), int (*local_infile_error)(void*, char*, int), void *userdata) {
    mysql_set_local_infile_handler((MYSQL*)mysql, (int(*)(void**, const char*, void*))local_infile_init, (int(*)(void*, char*, unsigned int))local_infile_read, local_infile_end, (int(*)(void*, char*, unsigned int))local_infile_error, userdata);
}

int glue_mysql_set_server_option(void *mysql, int option) {
    return mysql_set_server_option((MYSQL*)mysql, (enum enum_mysql_set_option)option);
}

int glue_mysql_shutdown(void *mysql, int shutdown_level) {
    return mysql_shutdown((MYSQL*)mysql, (enum mysql_enum_shutdown_level)shutdown_level);
}

char *glue_mysql_sqlstate(void *mysql) {
    return (char*)mysql_sqlstate((MYSQL*)mysql);
}

bool glue_mysql_ssl_set(void *mysql, char *key, char *cert, char *ca, char *capath, char *cipher) {
    return mysql_ssl_set((MYSQL*)mysql, key, cert, ca, capath, cipher);
}

char *glue_mysql_stat(void *mysql) {
    return (char*)mysql_stat((MYSQL*)mysql);
}

int64_t glue_mysql_stmt_affected_rows(void *stmt) {
    return mysql_stmt_affected_rows((MYSQL_STMT*)stmt);
}

bool glue_mysql_stmt_attr_get(void *stmt, int option, void *arg) {
    return mysql_stmt_attr_get((MYSQL_STMT*)stmt, (enum enum_stmt_attr_type)option, arg);
}

bool glue_mysql_stmt_attr_set(void *stmt, int option, void *arg) {
    return mysql_stmt_attr_set((MYSQL_STMT*)stmt, (enum enum_stmt_attr_type)option, arg);
}

bool glue_mysql_stmt_bind_param(void *stmt, void *bind) {
    return mysql_stmt_bind_param((MYSQL_STMT*)stmt, (MYSQL_BIND*)bind);
}

bool glue_mysql_stmt_bind_result(void *stmt, void *bind) {
    return mysql_stmt_bind_result((MYSQL_STMT*)stmt, (MYSQL_BIND*)bind);
}

bool glue_mysql_stmt_close(void *stmt) {
    return mysql_stmt_close((MYSQL_STMT*)stmt);
}

void glue_mysql_stmt_data_seek(void *stmt, int64_t offset) {
    mysql_stmt_data_seek((MYSQL_STMT*)stmt, offset);
}

int glue_mysql_stmt_errno(void *stmt) {
    return mysql_stmt_errno((MYSQL_STMT*)stmt);
}

char* glue_mysql_stmt_error(void *stmt) {
    return (char*)mysql_stmt_error((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_execute(void *stmt) {
    return mysql_stmt_execute((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_fetch(void *stmt) {
    return mysql_stmt_fetch((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_fetch_column(void *stmt, void *bind, int column, int64_t offset) {
    return mysql_stmt_fetch_column((MYSQL_STMT*)stmt, (MYSQL_BIND*)bind, column, offset);
}

int glue_mysql_stmt_field_count(void *stmt) {
    return mysql_stmt_field_count((MYSQL_STMT*)stmt);
}

bool glue_mysql_stmt_free_result(void *stmt) {
    return mysql_stmt_free_result((MYSQL_STMT*)stmt);
}

void *glue_mysql_stmt_init(void *mysql) {
    return (void*)mysql_stmt_init((MYSQL*)mysql);
}

int64_t glue_mysql_stmt_insert_id(void *stmt) {
    return mysql_stmt_insert_id((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_next_result(void *mysql) {
    return mysql_stmt_next_result((MYSQL_STMT*)mysql);
}

int64_t glue_mysql_stmt_num_rows(void *stmt) {
    return mysql_stmt_num_rows((MYSQL_STMT*)stmt);
}

int64_t glue_mysql_stmt_param_count(void *stmt) {
    return mysql_stmt_param_count((MYSQL_STMT*)stmt);
}

void *glue_mysql_stmt_param_metadata(void *stmt) {
    return (void*)mysql_stmt_param_metadata((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_prepare(void *stmt, char *stmt_str, int64_t length) {
    return mysql_stmt_prepare((MYSQL_STMT*)stmt, stmt_str, length);
}

bool glue_mysql_stmt_reset(void *stmt) {
    return mysql_stmt_reset((MYSQL_STMT*)stmt);
}

void *glue_mysql_stmt_result_metadata(void *stmt) {
    return mysql_stmt_result_metadata((MYSQL_STMT*)stmt);
}

void* glue_mysql_stmt_row_seek(void *stmt, void *offset) {
    return (void*)mysql_stmt_row_seek((MYSQL_STMT*)stmt, (MYSQL_ROW_OFFSET)offset);
}

void* glue_mysql_stmt_row_tell(void *stmt) {
    return (void*)mysql_stmt_row_tell((MYSQL_STMT*)stmt);
}

bool glue_mysql_stmt_send_long_data(void *stmt, int parameter_number, char *data, int64_t length) {
    return mysql_stmt_send_long_data((MYSQL_STMT*)stmt, parameter_number, data, length);
}

char *glue_mysql_stmt_sqlstate(void *stmt) {
    return (char*)mysql_stmt_sqlstate((MYSQL_STMT*)stmt);
}

int glue_mysql_stmt_store_result(void *stmt) {
    return mysql_stmt_store_result((MYSQL_STMT*)stmt);
}

void *glue_mysql_store_result(void *mysql) {
    return mysql_store_result((MYSQL*)mysql);
}

// int glue_mysql_store_result_nonblocking(void *mysql, void *result) {
//     return (int)mysql_store_result_nonblocking((MYSQL*)mysql, (MYSQL_RES**)result);
// }

void glue_mysql_thread_end(void) {
    mysql_thread_end();
}

int64_t glue_mysql_thread_id(void *mysql) {
    return mysql_thread_id((MYSQL*)mysql);
}

bool glue_mysql_thread_init(void) {
    return mysql_thread_init();
}

int glue_mysql_thread_safe(void) {
    return mysql_thread_safe();
}

void *glue_mysql_use_result(void *mysql) {
    return (void*)mysql_use_result((MYSQL*)mysql);
}

int glue_mysql_warning_count(void *mysql) {
    return mysql_warning_count((MYSQL*)mysql);
}