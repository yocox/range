#ifndef YOCO_CPPGM_GENERIC_RANGE_ITERATOR_RANGE_HH
#define YOCO_CPPGM_GENERIC_RANGE_ITERATOR_RANGE_HH

#include <vector>
#include "range_traits.hh"

namespace range {

template <typename IterType>
class iterator_range;

namespace internal {

template <typename IterType>
struct range_traits<iterator_range<IterType>>
{
    static constexpr bool bounded = true;
};

} // namespace internal

template <typename IterType>
class iterator_range {
  public:
    using iterator = IterType;
    using const_iterator = IterType;
    using size_type = long int;

    // ctor
    template <typename T>
    iterator_range(std::vector<T>& v) : begin_(v.begin()), end_(v.end()) {}
    iterator_range(IterType b, IterType e) : begin_(b), end_(e) {}

    // query
    bool empty() const { return begin_ == end_; }

    // get iter
    iterator& begin() { return begin_; }
    iterator& end() { return end_; }
    const iterator& begin() const { return begin_; }
    const iterator& end() const { return end_; }
    size_type size() const { return std::distance(begin_, end_); }

    // operating iter
    void advance_begin() { ++begin_; }
    void advance_end() { ++end_; }
    void set_begin(iterator i) { begin_ = i; }
    void set_end(iterator i) { end_ = i; }

    iterator_range& operator++(   ) { ++begin_; return *this; }
    iterator_range& operator--(   ) { --begin_; return *this; }
    iterator_range& operator++(int) { end_++  ; return *this; }
    iterator_range& operator--(int) { end_--  ; return *this; }

  private:
    iterator begin_;
    iterator end_;
} ;

template <typename T>
auto make_range(T& c) -> iterator_range<typename T::iterator>
{
    return iterator_range<typename T::iterator>(c);
}

} // namespace range

#endif // YOCO_CPPGM_GENERIC_RANGE_ITERATOR_RANGE_HH

