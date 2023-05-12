#ifndef __PEEKFS_META_HEADERS_H__
#define __PEEKFS_META_HEADERS_H__

#ifndef __KERNEL__
    #include <stdint.h>
#else
    #include <linux/types.h>
#endif

#define DEFINE_ISDATA_MAGIC_BYTES(name) static const uint8_t name[] = {'_', 'I', 'S', 'D', 'A', 'T', 'A', '_', 'M', 'O', 'D', '_', 'H', 'D', 'R', '_'}
#define ISDATA_MAGIC_BYTES_LEN (16)

#define ISDATA_VERSION (1)

#define ISDATA_EFLAG_PTR (1 << 0)

struct isdata_entry {
    uint16_t name_len;
    char* name;
    uint32_t flags;
    uint64_t size;
    uint64_t num_elems;
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
