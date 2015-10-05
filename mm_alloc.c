/*
 * mm_alloc.c
 *
 * Stub implementations of the mm_* routines. Remove this comment and provide
 * a summary of your allocator's design here.
 */

#include "mm_alloc.h"

#include <stdlib.h>

/* Your final implementation should comment out this macro. */
#define MM_USE_STUBS

void* mm_malloc(size_t size)
{
  t_block b,last;
  size_t s;
  s = align4(size);

  if (base){
    last = base;
    b = find_block(&last,s);
    if ((b -> size -s) >= (BLOCK_SIZE +4))
      split_block(b,s);
    b -> free = 0;
  }else{
    b = extend_heap(last,s);
    if (!b)
      return (NULL);
  }
}else{
  b = extend_heap(NULL);
  base = b;
 }
return(b-> data);
}

void* mm_realloc(void* ptr, size_t size)
{
  size_t s;
  t_block b,new;

  void *newptr;

  if (!ptr)
    return (malloc(size));
  if(valid_addr(ptr)){
    s = allign4(size);
    b = get_block(ptr);

    if (b->size >= s){
      if _b->size -s >= (BLOCK_SIZE + 4))
      split_block(b,s);
  }else{
    if (b->next && b->next->free && b->size + BLOCK_SIZE + b->next->size){
      fusion(b);
      if (b->size -s >= (BLOCK_SIZE +4))
	split_block(b,s);

    }else{
      newptr = malloc(s);
      if (!newptr)
	return (NULL);
      new = get_block(newptr);
      copy_block(b,newptr);
      free(ptr);
      return (newptr);
    }
  }
  return (ptr);
}
return (NULL);
  
}

void mm_free(void* ptr)
{
#ifdef MM_USE_STUBS
    free(ptr);
#else
#error Not implemented.
#endif
}
