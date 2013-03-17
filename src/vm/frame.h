#ifndef VM_FRAME_H
#define VM_FRAME_H
#include <hash.h>
#include "vm/page.h"
#include "threads/palloc.h"

struct hash frame_table;

struct frame {
	struct hash_elem hash_elem;		/* Used to store the frame in the frame table. */
	int32_t frame_addr;				/* The address of the frame in memory. */
	struct page *page;				/* Stores the page mapped into this frame */
};

void frame_table_init(void);

void *frame_allocator_get_user_page(void *user_vaddr, enum palloc_flags flags, bool writable);
void *frame_allocator_get_user_page_multiple(void *user_vaddr,
											 unsigned int num_frames,
											 enum palloc_flags flags,
											 bool writable);
void frame_allocator_free_user_page(void *kernel_vaddr);

#endif /* vm/frame.h */