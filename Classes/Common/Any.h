/******************************************************************************
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  Author:Zheng Fasheng
 *
 *  Email:zheng_fasheng@outlook.com
 *
 *  Date:2016/9/4 20:55
 *
 *  Summary:Declares any class Derived from the boost library
 *  
 ******************************************************************************/
#pragma once
#include <exception>
#include <typeinfo>
#include <algorithm>
#include <string>
namespace boost{
#define BOOST_NOEXCEPT 

	template <class Derived, class TypeInfo>
	class type_index_facade {
	private:
		/// @cond
		const Derived & derived() const BOOST_NOEXCEPT {
			return *static_cast<Derived const*>(this);
	}
		/// @endcond
	public:
		typedef TypeInfo                                type_info_t;

		/// \b Override: This function \b may be redefined in Derived class. Overrides \b must not throw.
		/// \return Name of a type. By default returns Derived::raw_name().
		inline const char* name() const BOOST_NOEXCEPT{
			return derived().raw_name();
		}

			/// \b Override: This function \b may be redefined in Derived class. Overrides may throw.
			/// \return Human readable type name. By default returns Derived::name().
			inline std::string pretty_name() const {
			return derived().name();
		}

		/// \b Override: This function \b may be redefined in Derived class. Overrides \b must not throw.
		/// \return True if two types are equal. By default compares types by raw_name().
		inline bool equal(const Derived& rhs) const BOOST_NOEXCEPT{
			const char* const left = derived().raw_name();
			const char* const right = rhs.raw_name();
			return left == right || !std::strcmp(left, right);
		}

			/// \b Override: This function \b may be redefined in Derived class. Overrides \b must not throw.
			/// \return True if rhs is greater than this. By default compares types by raw_name().
			inline bool before(const Derived& rhs) const BOOST_NOEXCEPT{
			const char* const left = derived().raw_name();
			const char* const right = rhs.raw_name();
			return left != right && std::strcmp(left, right) < 0;
		}

			/// \b Override: This function \b may be redefined in Derived class. Overrides \b must not throw.
			/// \return Hash code of a type. By default hashes types by raw_name().
			/// \note <boost/functional/hash.hpp> has to be included if this function is used.
			inline std::size_t hash_code() const BOOST_NOEXCEPT{
			const char* const name_raw = derived().raw_name();
			return boost::hash_range(name_raw, name_raw + std::strlen(name_raw));
		}
	};

	class stl_type_index
		: public type_index_facade<
		stl_type_index,
		std::type_info>
	{
	public:
		typedef std::type_info type_info_t;

	private:
		const type_info_t* data_;

	public:
		inline stl_type_index() BOOST_NOEXCEPT
			: data_(&typeid(void))
		{}

		inline stl_type_index(const type_info_t& data) BOOST_NOEXCEPT
			: data_(&data)
		{}

		inline const type_info_t&  type_info() const BOOST_NOEXCEPT;

		inline const char*  raw_name() const BOOST_NOEXCEPT;
		inline const char*  name() const BOOST_NOEXCEPT;
		inline std::string  pretty_name() const;

		inline std::size_t  hash_code() const BOOST_NOEXCEPT;
		inline bool         equal(const stl_type_index& rhs) const BOOST_NOEXCEPT;
		inline bool         before(const stl_type_index& rhs) const BOOST_NOEXCEPT;

		template <class T>
		inline static stl_type_index type_id() BOOST_NOEXCEPT;

		template <class T>
		inline static stl_type_index type_id_with_cvr() BOOST_NOEXCEPT;

		template <class T>
		inline static stl_type_index type_id_runtime(const T& value) BOOST_NOEXCEPT;
	};

	inline const stl_type_index::type_info_t& stl_type_index::type_info() const BOOST_NOEXCEPT{
		return *data_;
	}

	class Any
	{

	public:

		Any() BOOST_NOEXCEPT
			: content(0)
		{
		}

		template <class T> struct remove_cv{ typedef T type; };
		template <class T> struct remove_cv<T const>{ typedef T type; };
		template <class T> struct remove_cv<T volatile>{ typedef T type; };
		template <class T> struct remove_cv<T const volatile>{ typedef T type; };

		template <class T, std::size_t N> struct remove_cv<T const[N]>{ typedef T type[N]; };
		template <class T, std::size_t N> struct remove_cv<T const volatile[N]>{ typedef T type[N]; };
		template <class T, std::size_t N> struct remove_cv<T volatile[N]>{ typedef T type[N]; };

		template <class T> struct remove_cv<T const[]>{ typedef T type[]; };
		template <class T> struct remove_cv<T const volatile[]>{ typedef T type[]; };
		template <class T> struct remove_cv<T volatile[]>{ typedef T type[]; };

		template <class T, bool Array, bool Function> struct decay_imp { typedef typename remove_cv<T>::type type; };
		template <class T> struct remove_bounds : public remove_extent<T> {};
		template <class T> struct decay_imp<T, true, false> { typedef typename remove_bounds<T>::type* type; };
		template <class T> struct decay_imp<T, false, true> { typedef T* type; };
		template< class T >
		struct decay
		{
		private:
			typedef typename remove_reference<T>::type Ty;
		public:
			typedef typename decay_imp<Ty, std::is_array<Ty>::value, std::is_function<Ty>::value>::type type;
		};

		template<typename valueType>
		Any(const valueType & value)
			: content(new holder<remove_cv<decay<const valueType>::type>::type>(value))
		{
		}

		Any(const Any & other)
			: content(other.content ? other.content->clone() : 0)
		{
		}

		//c++11
		// Move constructor
		Any(Any&& other) BOOST_NOEXCEPT
			: content(other.content)
		{
			other.content = 0;
		}

		template <bool B, class T = void>
		struct disable_if_c {
			typedef T type;
		};

		template <class T>
		struct disable_if_c<true, T> {};

		template <class Cond, class T = void>
		struct disable_if : public disable_if_c<Cond::value, T> {};

		// Perfect forwarding of ValueType
		template<typename ValueType>
		Any(ValueType&& value
			, typename disable_if<std::is_same<Any&, ValueType> >::type* = 0 // disable if value has type `any&`
			, typename disable_if<std::is_const<ValueType> >::type* = 0) // disable if value has type `const ValueType&&`
			: content(new holder< typename decay<ValueType>::type >(static_cast<ValueType&&>(value)))
		{
		}

		~Any() BOOST_NOEXCEPT
		{
			if (content)
			{
				delete content;
			}
			content = nullptr;
		}

	public:

		Any& swap(Any& rhs) BOOST_NOEXCEPT
		{
			std::swap(content, rhs.content);
			return *this;
		}

			Any& operator=(const Any& rhs)
		{
			Any(rhs).swap(*this);
			return *this;
		}

		//c++11
		//move assignement
		Any& operator=(Any&& rhs) BOOST_NOEXCEPT
		{
			rhs.swap(*this);
			Any().swap(rhs);
			return *this;
		}

		//perfect forwarding of valueType
		template<class valueType>
		Any& operator=(valueType&& rhs)
		{
			Any(static_cast<valueType&&>(rhs)).swap(*this);
			return *this;
		}

	public: // queries

		bool empty() BOOST_NOEXCEPT
		{
			return !content;
		}

			void clear() BOOST_NOEXCEPT
		{
			Any().swap(*this);
		}

	private:

		class placeholder
		{
		public:
			virtual ~placeholder(){}
			//virtual const stl_type_index::type_info_t& type() const = 0;
			virtual placeholder* clone() const = 0;
		};

		template<typename valueType>
		class holder : public placeholder
		{
		public:
			holder(const valueType& value) :held(value){}
			holder(valueType&& value)
				:held(static_cast<valueType&&>(value))
			{

			}
			/*void const stl_type_index::type_info_t& type() override
			{
				return stl_type_index::type_id<vaule_type>().type_info();
			}*/
			virtual placeholder* clone() const
			{
				return new holder(held);
			}

		public:
			valueType held;

		private:
			// intentionally left unimplemented
			holder& operator=(const holder &);
		};

	private: // representation

		template<typename ValueType>
		friend ValueType * any_cast(Any *) BOOST_NOEXCEPT;

		template<typename ValueType>
		friend ValueType * unsafe_any_cast(Any *) BOOST_NOEXCEPT;

	private:

		placeholder* content;
	};

	inline void swap(Any & lhs, Any & rhs) BOOST_NOEXCEPT
	{
		lhs.swap(rhs);
	}

	class bad_any_cast :
		public std::bad_cast
	{
	public:
		virtual const char * what() const BOOST_NOEXCEPT
		{
			return "boost::bad_any_cast: "
			"failed conversion using boost::any_cast";
		}
	};

	template<typename ValueType>
	ValueType * any_cast(Any * operand) BOOST_NOEXCEPT
	{
		return operand
		? &static_cast<Any::holder<Any::remove_cv<ValueType>::type> *>(operand->content)->held
		: 0;
	}

	template<typename ValueType>
	inline const ValueType * any_cast(const Any * operand) BOOST_NOEXCEPT
	{
		return any_cast<ValueType>(const_cast<Any *>(operand));
	}

	struct na
	{
		typedef na type;
		enum { value = 0 };
	};

	template<
		bool C
		, typename T1
		, typename T2
	>
	struct if_c
	{
		typedef T1 type;
	};

	template<
		typename T1
		, typename T2
	>
	struct if_c<false, T1, T2>
	{
		typedef T2 type;
	};
#   define BOOST_MPL_AUX_VALUE_WKND(C) C
#   define BOOST_MPL_AUX_STATIC_CAST(T, expr) static_cast<T>(expr)
#   define BOOST_MPL_AUX_LAMBDA_SUPPORT(i,name,params) /**/
	// agurt, 05/sep/04: nondescriptive parameter names for the sake of DigitalMars
	// (and possibly MWCW < 8.0); see http://article.gmane.org/gmane.comp.lib.boost.devel/108959
	template<
		typename T1 = na
		, typename T2 = na
		, typename T3 = na
	>
	struct if_
	{
	private:
		// agurt, 02/jan/03: two-step 'type' definition for the sake of aCC 
		typedef if_c<
			BOOST_MPL_AUX_STATIC_CAST(bool, BOOST_MPL_AUX_VALUE_WKND(T1)::value)
			, T2
			, T3
		> almost_type_;

	public:
		typedef typename almost_type_::type type;

		BOOST_MPL_AUX_LAMBDA_SUPPORT(3, if_, (T1, T2, T3))
	};

	template<typename ValueType>
	ValueType any_cast(Any & operand)
	{
		typedef std::remove_reference<ValueType>::type nonref;


		nonref * result = any_cast<nonref>(&operand);
		if (!result)
			return nullptr;

		// Attempt to avoid construction of a temporary object in cases when 
		// `ValueType` is not a reference. Example:
		// `static_cast<std::string>(*result);` 
		// which is equal to `std::string(*result);`
		/*if_<
			std::is_reference<ValueType>,
			ValueType,
			std::add_reference<ValueType>::type
		>::type ref_type;*/

		return static_cast<ValueType>(*any_cast<ValueType>(&operand));
	}

	template<typename ValueType>
	inline ValueType any_cast(const Any & operand)
	{
		typedef std::remove_reference<ValueType>::type nonref;
		return any_cast<const nonref &>(const_cast<Any &>(operand));
	}

#     define BOOST_STATIC_ASSERT_MSG( ... ) static_assert(__VA_ARGS__)

	template<typename ValueType>
	inline ValueType any_cast(Any&& operand)
	{
		BOOST_STATIC_ASSERT_MSG(
			boost::is_rvalue_reference<ValueType&&>::value /*true if ValueType is rvalue or just a value*/
			|| boost::is_const< typename boost::remove_reference<ValueType>::type >::value,
			"boost::any_cast shall not be used for getting nonconst references to temporary objects"
			);
		return any_cast<ValueType>(operand);
	}

	// Note: The "unsafe" versions of any_cast are not part of the
	// public interface and may be removed at any time. They are
	// required where we know what type is stored in the any and can't
	// use typeid() comparison, e.g., when our types may travel across
	// different shared libraries.
	template<typename ValueType>
	inline ValueType * unsafe_any_cast(Any * operand) BOOST_NOEXCEPT
	{
		return &static_cast<Any::holder<ValueType> *>(operand->content)->held;
	}

		template<typename ValueType>
	inline const ValueType * unsafe_any_cast(const Any * operand) BOOST_NOEXCEPT
	{
		return unsafe_any_cast<ValueType>(const_cast<Any *>(operand));
	}
}