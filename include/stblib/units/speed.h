namespace stb
{



template<typename _Rep, typename _Period>
struct duration;



}//namespace stb





//specialization of std::common_type for stb::duration
namespace std _GLIBCXX_VISIBILITY(default)
{
//note that std:: qualification is provided even if not needed in order
//to know where types/functions come from


template<typename CT, typename Period1, typename Period2>
struct duration_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type cr;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> r;

public:

  typedef std::__success_type<stb::duration<cr, r>> type;
};

template<typename Period1, typename Period2>
struct duration_common_type_wrapper<std::__failure_type, Period1, Period2>
{
   typedef std::__failure_type type;
};

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
struct common_type<stb::duration<Rep1, Period1>, stb::duration<Rep2, Period2>>
        : public duration_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



} //namespace std







namespace stb
{

// Primary template for duration_cast impl.
template<typename _ToDur, typename _CF, typename _CR,
bool _NumIsOne = false, bool _DenIsOne = false>
struct __duration_cast_impl
{
  template<typename _Rep, typename _Period>
  static constexpr _ToDur
  __cast(const duration<_Rep, _Period>& __d)
  {
    typedef typename _ToDur::rep			__to_rep;
    return _ToDur(static_cast<__to_rep>(static_cast<_CR>(__d.count())
      * static_cast<_CR>(_CF::num) / static_cast<_CR>(_CF::den)));
  }
};


template<typename _ToDur, typename _CF, typename _CR>
struct __duration_cast_impl<_ToDur, _CF, _CR, true, true>
{
  template<typename _Rep, typename _Period>
  static constexpr _ToDur
  __cast(const duration<_Rep, _Period>& __d)
  {
    typedef typename _ToDur::rep			__to_rep;
    return _ToDur(static_cast<__to_rep>(__d.count()));
  }
};


template<typename _ToDur, typename _CF, typename _CR>
struct __duration_cast_impl<_ToDur, _CF, _CR, true, false>
{
  template<typename _Rep, typename _Period>
  static constexpr _ToDur
  __cast(const duration<_Rep, _Period>& __d)
  {
    typedef typename _ToDur::rep			__to_rep;
    return _ToDur(static_cast<__to_rep>(
    static_cast<_CR>(__d.count()) / static_cast<_CR>(_CF::den)));
  }
};


template<typename _ToDur, typename _CF, typename _CR>
struct __duration_cast_impl<_ToDur, _CF, _CR, false, true>
{
  template<typename _Rep, typename _Period>
  static constexpr _ToDur
  __cast(const duration<_Rep, _Period>& __d)
  {
    typedef typename _ToDur::rep			__to_rep;
    return _ToDur(static_cast<__to_rep>(
    static_cast<_CR>(__d.count()) * static_cast<_CR>(_CF::num)));
  }
};


template<typename _Tp>
struct __is_duration : std::false_type
{
};


template<typename _Rep, typename _Period>
struct __is_duration<duration<_Rep, _Period>> : std::true_type
{
};


/// duration_cast
template<typename _ToDur, typename _Rep, typename _Period>
constexpr typename enable_if<__is_duration<_ToDur>::value,
_ToDur>::type
duration_cast(const duration<_Rep, _Period>& __d)
{
  typedef typename _ToDur::period				__to_period;
  typedef typename _ToDur::rep				__to_rep;
  typedef ratio_divide<_Period, __to_period> 		__cf;
  typedef typename common_type<__to_rep, _Rep, intmax_t>::type __cr;
  typedef  __duration_cast_impl<_ToDur, __cf, __cr, __cf::num == 1, __cf::den == 1> __dc;
  return __dc::__cast(__d);
}

/// treat_as_floating_point
template<typename _Rep>
struct treat_as_floating_point : is_floating_point<_Rep>
{
};

/// duration_values
template<typename _Rep>
struct duration_values
{
  static constexpr _Rep zero()
  {
    return _Rep(0);
  }

  static constexpr _Rep max()
  {
    return numeric_limits<_Rep>::max();
  }

  static constexpr _Rep min()
  {
    return numeric_limits<_Rep>::lowest();
  }
};


template<typename _Tp>
struct __is_ratio : std::false_type
{
};


template<intmax_t _Num, intmax_t _Den>
struct __is_ratio<ratio<_Num, _Den>> : std::true_type
{
};


/// duration
template<typename _Rep, typename _Period>
struct duration
{
  typedef _Rep			rep;
  typedef _Period 	period;


  static_assert(!__is_duration<_Rep>::value, "rep cannot be a duration");
  static_assert(__is_ratio<_Period>::value,
  "period must be a specialization of ratio");
  static_assert(_Period::num > 0, "period must be positive");


  constexpr duration() = default;
  duration(const duration&) = default;


  template<typename _Rep2, typename = typename
  enable_if<is_convertible<_Rep2, rep>::value
  && (treat_as_floating_point<rep>::value
  || !treat_as_floating_point<_Rep2>::value)>::type>
  constexpr explicit duration(const _Rep2& _countep):
  _count(static_cast<rep>(_countep))
  {
  }


  template<typename _Rep2, typename _Period2, typename = typename
  enable_if<treat_as_floating_point<rep>::value
  || (ratio_divide<_Period2, period>::den == 1
  && !treat_as_floating_point<_Rep2>::value)>::type>
  constexpr duration(const duration<_Rep2, _Period2>& __d):
  _count(duration_cast<duration>(__d).count())
  {
  }


  ~duration() = default;
  duration& operator=(const duration&) = default;


  constexpr rep count() const
  {
    return _count;
  }


  constexpr duration operator+() const
  {
    return *this;
  }


  constexpr duration operator-() const
  {
    return duration(-_count);
  }


  duration& operator++()
  {
    ++_count;
    return *this;
  }

  duration operator++(int)
  {
    return duration(_count++);
  }


  duration& operator--()
  {
    --_count;
    return *this;
  }

  duration operator--(int)
  {
    return duration(_count--);
  }


  duration& operator+=(const duration& __d)
  {
    _count += __d.count();
    return *this;
  }


  duration& operator-=(const duration& __d)
  {
    _count -= __d.count();
    return *this;
  }

  duration& operator*=(const rep& Obj2)
  {
    _count *= Obj2;
    return *this;
  }

  duration& operator/=(const rep& Obj2)
  {
    _count /= Obj2;
    return *this;
  }


  template<typename _Rep2 = rep>
  typename enable_if<!treat_as_floating_point<_Rep2>::value, duration&>::type
  operator%=(const rep& Obj2)
  {
    _count %= Obj2;
    return *this;
  }

  template<typename _Rep2 = rep>
  typename enable_if<!treat_as_floating_point<_Rep2>::value, duration&>::type
  operator%=(const duration& __d)
  {
    _count %= __d.count();
    return *this;
  }


  static constexpr duration zero()
  {
    return duration(duration_values<rep>::zero());
  }

  static constexpr duration min()
  {
    return duration(duration_values<rep>::min());
  }

  static constexpr duration max()
  {
    return duration(duration_values<rep>::max());
  }

private:

  rep _count;
};


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr typename common_type<duration<_Rep1, _Period1>, duration<_Rep2, _Period2>>::type
operator+(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__cd;
  return __cd(__cd(Obj1).count() + __cd(Obj2).count());
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr typename common_type<duration<_Rep1, _Period1>, duration<_Rep2, _Period2>>::type
operator-(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__cd;
  return __cd(__cd(Obj1).count() - __cd(Obj2).count());
}


template<typename _Rep1, typename _Rep2, bool = is_convertible<_Rep2,
typename common_type<_Rep1, _Rep2>::type>::value>
struct __common_rep_type
{
};


template<typename _Rep1, typename _Rep2>
struct __common_rep_type<_Rep1, _Rep2, true>
{
  typedef typename common_type<_Rep1, _Rep2>::type type;
};


template<typename _Rep1, typename _Period, typename _Rep2>
constexpr duration<typename __common_rep_type<_Rep1, _Rep2>::type, _Period>
operator*(const duration<_Rep1, _Period>& __d, const _Rep2& __s)
{
  typedef duration<typename common_type<_Rep1, _Rep2>::type, _Period>
  __cd;
  return __cd(__cd(__d).count() * __s);
}


template<typename _Rep1, typename _Rep2, typename _Period>
constexpr duration<typename __common_rep_type<_Rep2, _Rep1>::type, _Period>
operator*(const _Rep1& __s, const duration<_Rep2, _Period>& __d)
{
  return __d * __s;
}


template<typename _Rep1, typename _Period, typename _Rep2>
constexpr duration<typename __common_rep_type<_Rep1, typename
enable_if<!__is_duration<_Rep2>::value, _Rep2>::type>::type, _Period>
operator/(const duration<_Rep1, _Period>& __d, const _Rep2& __s)
{
  typedef duration<typename common_type<_Rep1, _Rep2>::type, _Period>
  __cd;
  return __cd(__cd(__d).count() / __s);
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr typename common_type<_Rep1, _Rep2>::type
operator/(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__cd;
  return __cd(Obj1).count() / __cd(Obj2).count();
}


template<typename _Rep1, typename _Period, typename _Rep2>
constexpr duration<typename __common_rep_type<_Rep1, typename
enable_if<!__is_duration<_Rep2>::value, _Rep2>::type>::type, _Period>
operator%(const duration<_Rep1, _Period>& __d, const _Rep2& __s)
{
  typedef duration<typename common_type<_Rep1, _Rep2>::type, _Period>
  __cd;
  return __cd(__cd(__d).count() % __s);
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr typename common_type<duration<_Rep1, _Period1>, duration<_Rep2, _Period2>>::type
operator%(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__cd;
  return __cd(__cd(Obj1).count() % __cd(Obj2).count());
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator==(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__ct;
  return __ct(Obj1).count() == __ct(Obj2).count();
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator<(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  typedef duration<_Rep1, _Period1>			__dur1;
  typedef duration<_Rep2, _Period2>			__dur2;
  typedef typename common_type<__dur1,__dur2>::type	__ct;
  return __ct(Obj1).count() < __ct(Obj2).count();
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator!=(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  return !(Obj1 == Obj2);
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator<=(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  return !(Obj2 < Obj1);
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator>(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  return Obj2 < Obj1;
}


template<typename _Rep1, typename _Period1, typename _Rep2, typename _Period2>
constexpr bool
operator>=(const duration<_Rep1, _Period1>& Obj1, const duration<_Rep2, _Period2>& Obj2)
{
  return !(Obj1 < Obj2);
}




}//namespace stb
