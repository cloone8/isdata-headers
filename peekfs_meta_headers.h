#ifndef __PEEKFS_META_HEADERS_H__
#define __PEEKFS_META_HEADERS_H__

#include <stdint.h>

#define DEFINE_ISDATA_MAGIC_BYTES(name) static const uint8_t name[] = {'_', 'I', 'S', 'D', 'A', 'T', 'A', '_', 'M', 'O', 'D', '_', 'H', 'D', 'R', '_'}
#define ISDATA_MAGIC_BYTES_LEN (sizeof(isdata_magic_bytes))

#define ISDATA_VERSION (0)

#define ISDATA_EFLAG_ARRAY (1 << 0)
#define ISDATA_EFLAG_PTR (1 << 1)

struct isdata_entry {
    uint16_t name_len;
    char* name;
    uint64_t size;
    uint32_t flags;
    void* addr;
};

struct isdata_module {
    uint8_t magic[16];
    uint16_t version;
    uint16_t name_len;
    char* name;
    uint64_t num_entries;
    struct isdata_entry* entries;
};

#endif
