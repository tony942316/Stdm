module;

#include <set>

export module Stdm.Containers.Set;

// Opeartors
export using std::operator==;
export using std::operator<=>;

export namespace stdm
{
    // Classes
    using std::set;
    using std::multiset;

    // Functions
    using std::swap;
    using std::erase_if;

    // Range Access
    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;
}
