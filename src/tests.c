#include "TFKS.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    char *word = "asbjdaviesbepatrwillnataskraspoozaddbolt";
    char *temp_word = word;

    for (int i = 0; i < 39; i += 4) {
        uint8_t hash = xor_hash(temp_word + i, 4);
        printf("%d\n", hash);
    }
    return 0;
}
