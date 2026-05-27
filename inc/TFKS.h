#include <stdbool.h>
#include <stdint.h>

typedef enum {
    STANDARD,
    RAM_ONLY,
    RAM_LIMITED,
} TFKS_Type_t;

typedef struct {
    uint32_t filename_len;
    uint32_t hash_itterations;
    uint32_t hash_size;
    int32_t token_len;
    TFKS_Type_t StorageType;
    char *filename;
} TFKS_config_t;
typedef struct {
    TFKS_config_t config;
    uint32_t users;
    bool active;
    char *database;
} TFKS_instance_t;

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

// The internal database structure, the first 32 bytes, are char value, a,b,c,d,e,f,g, for comparison,
// The next 128 bytes, are lookup positions for the first user with that element,,  So compare char, lookup matching index, jump to
// positions. Each element is structure,  uint16(size of total user), uint16_t(size of user name), char array of length, (uint16_t
// hash_len), char array of the hash. (uint16_t), token_length, (uint8_t) token count, array of char for token.
uint8_t xor_hash(const char *buffer, const uint8_t length);

typedef enum {
    empty,
    used,
    unique,
} entry_state_t;

typedef struct {
    entry_state_t state;
    char *location;
} db_entry_t

    static int
    db_del_user();
static int db_get_user();
static int db_add_user();
static int db_get_element_position();
