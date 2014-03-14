#ifndef YOCO_GENERIC_RANGE_IOTA_RANGE_HH
#define YOCO_GENERIC_RANGE_IOTA_RANGE_HH

#include <vector>
#include "range_traits.hh"

namespace range {

template <typename IterType>
class iota_range;

namespace internal {

template <typename IterType>
struct range_traits<iota_range<IterType>>
{
    static constexpr bool bounded = true;
};

} // namespace internal

template <typename T>
class iota_iterator {
  public:
    iota_iterator(T init) : v_(init) { } ;
    iota_iterator operator++(   ) { ++v_; return *this; }
    iota_iterator operator--(   ) { --v_; return *this; }
    iota_iterator operator++(int) { v_++; return *this; }
    iota_iterator operator--(int) { v_--; return *this; }
    T operator*() const { return v_; }
    bool operator==(const iota_iterator<T>& rhs) { return v_ == rhs.v_; }
    bool operator!=(const iota_iterator<T>& rhs) { return v_ != rhs.v_; }
  private:
    T v_;
} ;

template <typename T>
class iota_iterator_with_strid {
  public:
    iota_iterator_with_strid(T init, T strid) : v_(init), strid_(strid) { } ;
    iota_iterator_with_strid operator++(   ) { v_ += strid_; return *this; }
    iota_iterator_with_strid operator--(   ) { v_ += strid_; return *this; }
    iota_iterator_with_strid operator++(int) { v_ += strid_; return *this; }
    iota_iterator_with_strid operator--(int) { v_ += strid_; return *this; }
    T operator*() const { return v_; }
    bool operator==(const iota_iterator_with_strid<T>& rhs) { return v_ >= rhs.v_; }
    bool operator!=(const iota_iterator_with_strid<T>& rhs) { return !(*this == rhs); }
  private:
    T v_;
    T strid_;
} ;

template <typename T = int>
class iota_range {
  public:
    using iterator = iota_iterator<T>;
    using const_iterator = iota_iterator<T>;
    using size_type = long int;

    // ctor
    iota_range(T end) : begin_(0), end_(end) {}
    iota_range(T begin, T end) : begin_(begin), end_(end) {}

    // query
    bool empty() const { return begin_ == end_; }

    // get iter
    iterator begin() { return iota_iterator<T>(begin_); }
    iterator end() { return iota_iterator<T>(end_); }
    const iterator begin() const { return iota_iterator<T>(begin_); }
    const iterator end() const { return iota_iterator<T>(end_); }
    size_type size() const { return end_ - begin_; }

    // operating iter
    void advance_begin() { ++begin_; }
    void advance_end() { ++end_; }
    void set_begin(iterator i) { begin_ = i; }
    void set_end(iterator i) { end_ = i; }

    iota_range& operator++(   ) { ++begin_; return *this; }
    iota_range& operator--(   ) { --begin_; return *this; }
    iota_range& operator++(int) { ++end_  ; return *this; }
    iota_range& operator--(int) { --end_  ; return *this; }

  private:
    T begin_;
    T end_;
} ;

template <typename T = int>
class iota_range_with_strid {
  public:
    using iterator = iota_iterator_with_strid<T>;
    using const_iterator = iota_iterator_with_strid<T>;
    using size_type = long int;

    // ctor
    iota_range_with_strid(T begin, T end, T strid) : begin_(begin), end_(end), strid_(strid) {}

    // query
    bool empty() const { return begin_ == end_; }

    // get iter
    iterator begin() { return iota_iterator_with_strid<T>(begin_, strid_); }
    iterator end() { return iota_iterator_with_strid<T>(end_, strid_); }
    const iterator begin() const { return iota_iterator_with_strid<T>(begin_, strid_); }
    const iterator end() const { return iota_iterator_with_strid<T>(end_, strid_); }
    size_type size() const { return end_ - begin_; }

    // operating iter
    void advance_begin() { ++begin_; }
    void advance_end() { ++end_; }
    void set_begin(iterator i) { begin_ = i; }
    void set_end(iterator i) { end_ = i; }

    iota_range_with_strid& operator++(   ) { ++begin_; return *this; }
    iota_range_with_strid& operator--(   ) { --begin_; return *this; }
    iota_range_with_strid& operator++(int) { ++end_  ; return *this; }
    iota_range_with_strid& operator--(int) { --end_  ; return *this; }

  private:
    T begin_;
    T end_;
    T strid_;
} ;

template <typename T> iota_range<T> xrange(T e) { return iota_range<T>(0, e); }
template <typename T> iota_range<T> xrange(T b, T e) { return iota_range<T>(b, e); }
template <typename T> iota_range_with_strid<T> xrange(T b, T e, T s) { return iota_range_with_strid<T>(b, e, s); }

} // namespace range

#endif // YOCO_GENERIC_RANGE_IOTA_RANGE_HH


