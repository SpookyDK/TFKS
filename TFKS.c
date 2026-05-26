#include "TFKS.h"

int TFKS_Init(const TFKS_config_t config_struct, TFKS_instance_t *instance);

int TFKS_add_user(const TFKS_instance_t instance, const char *userID, const uint32_t userID_len, const char *passWD,
                  const uint32_t passWD_len);
int TFKS_del_user(const TFKS_instance_t instance, const char *userID, const uint32_t userID_len);
int TFKS_auth_user(const TFKS_instance_t instance, const char *userID, const uint32_t userID_len, const char *passWD,
                   const uint32_t passWD_len);
int TFKS_generate_token(const TFKS_instance_t instance, const int32_t timelimit);
int TFKS_auth_token(const TFKS_instance_t instance, const char *userID, const uint32_t userID_len, const char *token,
                    const uint32_t token_len);
int TFKS_auth_user_r_token(const TFKS_instance_t, const char *userID, const uint32_t userID_len, const char *passWD,
                           const uint32_t passWD_len, char *token, uint32_t *token_len);
int TFKS_print_info(const TFKS_instance_t instance, const bool print_names, const bool print_passwd, const bool print_tokens);

static int hash_function(const TFKS_instance_t instance, const char *passWD, const uint32_t passWD_len, char *hash, uint32_t *hash_len);
static int lookup_user(const TFKS_instance_t instance, const char *userID, const uint32_t userID_len, char *hash, uint32_t *hash_len,
                       char *tokens, uint32_t *tokens_len, uint32_t *token_count);

static int db_del_user();
static int db_get_user();
static int db_add_user();
static int db_get_element_position();
