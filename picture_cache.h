#ifndef __PICTURE_CACHE_H
#define __PICTURE_CACHE_H

cairo_surface_t * cache_get(const char * path);

void cache_put(const char * path, cairo_surface_t * picture);

void cache_init();
#endif /*__PICTURE_CACHE_H*/