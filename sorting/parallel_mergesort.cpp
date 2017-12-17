/*
 * =====================================================================================
 *
 *       Filename:  parallel_mergesort.cpp
 *
 *    Description:  Parallel merge sort
 *
 *        Version:  1.0
 *        Created:  12/16/2017 20:56:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DENDI SUHUBDY (2017) 
 *   Organization:  
 *
 * =====================================================================================
 */

template< class _Type >
inline void parallel_merge_sort_simplest_r( _Type* src, int l, int r, _Type* dst, bool srcToDst = true )    // srcToDst specifies direction for this level of recursion
{
    if ( r == l ) {    // termination/base case of sorting a single element
        if ( srcToDst )  dst[ l ] = src[ l ];    // copy the single element from src to dst
        return;
    }
    int m = ( r + l ) / 2;
    //tbb::parallel_invoke(             // Intel's     Threading Building Blocks (TBB)
    Concurrency::parallel_invoke(       // Microsoft's Parallel Pattern Library  (PPL)
        [&] { parallel_merge_sort_simplest_r( src, l,     m, dst, !srcToDst ); },       // reverse direction of srcToDst for the next level of recursion
        [&] { parallel_merge_sort_simplest_r( src, m + 1, r, dst, !srcToDst ); }        // reverse direction of srcToDst for the next level of recursion
    );
    if ( srcToDst ) merge_parallel_L5( src, l, m, m + 1, r, dst, l );
    else            merge_parallel_L5( dst, l, m, m + 1, r, src, l );
}
template< class _Type >
inline void parallel_merge_sort_simplest( _Type* src, int l, int r, _Type* dst, bool srcToDst = true )  // srcToDst specifies direction for this level of recursion
{
    if ( r < l ) return;
    parallel_merge_sort_simplest_r( src, l, r, dst, srcToDst );
