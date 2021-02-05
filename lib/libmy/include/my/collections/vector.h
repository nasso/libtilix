/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** A continuous growable array type
*/

#ifndef LIBMY_COLLECTIONS_VECTOR_H
#define LIBMY_COLLECTIONS_VECTOR_H

#include <stddef.h>

#define VECTOR_GET_AS(T, V, I) ((T) vector_get(V, I))
#define VECTOR_POP_AS(T, V) ((T) vector_pop(V))

typedef int (vector_for_each_fn_t)(void *user_data, void *element);

typedef struct {
    void *data;
    size_t capacity;
    size_t len;
    size_t stride;
} vector_t;

/**
* \fn vector_t *vector_new(size_t stride);
* \brief Creates a new, empty vector, with an arbitrary initial capacity.
* No assumptions should be made on the initial capacity of the newly created
* \c vector_t.
* \param stride The size, in bytes, of a single element.
* \return A pointer to a new \c vector_t.
* \see vector_from
* \see vector_with_capacity
*/
vector_t *vector_new(size_t);

/**
* \fn vector_t *vector_from(size_t stride, size_t count, const void* data);
* \brief Creates a new vector with the given intial data.
* The vector data is filled with pointers to every element of the array.
* \param stride The size, in bytes, of a single element.
* \param count How many elements there is in the given buffer.
* \param data The data buffer.
* \return A pointer to a new \c vector_t.
* \see vector_new
* \see vector_with_capacity
*/
vector_t *vector_from(size_t, size_t, const void*);

/**
* \fn vector_t *vector_with_capacity(size_t capacity);
* \brief Creates a new, empty vector, with the given initial capacity.
* \param capacity The initial capacity of the new vector.
* \return A pointer to a new \c vector_t.
* \see vector_new
* \see vector_from
*/
vector_t *vector_with_capacity(size_t, size_t);

/**
* \fn void vector_destroy(vector_t *self);
* \brief Frees the vector and the data buffer.
* If any additional freeing operation is required, consider using
* \c vector_destroy_with.
* \param self The \c vector_t to destroy.
* \see vector_destroy_with
*/
void vector_destroy(vector_t*);

/**
* Frees all resources allocated by the vector using a function to free
* individual elements. Equivalent to a call to \c vector_for_each followed by a
* call to \c vector_destroy. The behavior is undefined if a call to the given
* function returns a non-zero value at any point in the array.
* \param self The \c vector_t to destroy.
* \param cb The callback used to free elements.
* \see vector_destroy
*/
void vector_destroy_with(vector_t*, vector_for_each_fn_t*, void*);

/**
* Reserves capacity for at least \p additional elements. The implementation
* might actually reserve more than the requested amount to avoid making too
* many re-allocations. Does nothing if \c capacity is already sufficient.
* \param self
* \param additional The amount of additional elements.
* \return Zero on success, or a non-zero value if an error occured.
*/
int vector_reserve(vector_t*, size_t);

/**
* Calls the given function for every element of the \c vector_t. Starts from
* the first element (index=0) and stops as soon as the given function returns
* a non-zero value or when the end of the array has been reached, whichever
* comes first.
* \param self
* \param cb The function to be called back on every element.
* \param user_data An arbitrary pointer that will be passed to the function.
*/
void vector_for_each(vector_t*, vector_for_each_fn_t*, void*);

void *vector_get(const vector_t*, size_t);
void vector_set(vector_t*, size_t, const void*);
void vector_remove(vector_t*, size_t, void*);
void vector_swap_remove(vector_t*, size_t, void*);
int vector_insert(vector_t*, size_t, const void*);
int vector_push(vector_t*, const void*);
void *vector_pop(vector_t*);

#endif /* LIBMY_COLLECTIONS_VECTOR_H */
