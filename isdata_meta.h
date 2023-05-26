#ifndef __PEEKFS_META_HEADERS_H__
#define __PEEKFS_META_HEADERS_H__

#ifndef __KERNEL__
    #include <stdint.h>
#else
    #include <linux/types.h>
#endif

#define DEFINE_ISDATA_MAGIC_BYTES(name) const uint8_t name[] = {'_', 'I', 'S', 'D', 'A', 'T', 'A', '_', 'M', 'O', 'D', '_', 'H', 'D', 'R', '_'}
#define ISDATA_MAGIC_BYTES_LEN (16)

#define ISDATA_VERSION (2)

#define ISDATA_EFLAG_PTR (1 << 0)
#define ISDATA_EFLAG_STRUCT (1 << 1)

#define ISDATA_SFFLAG_STRUCT (1 << 0)

#define ISDATA_SDFLAG_PACKED (1 << 0)

struct isdata_structfield {
    uint8_t flags;
    uint16_t name_len;
    char* name;
    uint64_t offset_in_bits;
    uint64_t size_or_def;
    uint64_t num_elems;
};

struct isdata_structdef {
    uint8_t flags;
    uint64_t size;
    uint64_t num_fields;
    struct isdata_structfield* fields;
};

struct isdata_entry {
    uint16_t name_len;
    uint32_t flags;
    char* name;
    void* addr;
    uint64_t size_or_def;
    uint64_t num_elems;
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
