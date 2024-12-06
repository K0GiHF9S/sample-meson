#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Return;

template <typename T>
class GMockHelper
{
public:
    GMockHelper()
    {
        instance = static_cast<T *>(this);
    }

    ~GMockHelper()
    {
        instance = nullptr;
    }

    static T *GetInstance() { return instance; }

private:
    static T *instance;
};

template <typename T>
T *GMockHelper<T>::instance = nullptr;

#define MOCK_FUNCTION_IMPL(_ClassName, _FunctionName, _N, _Signature)                                                 \
    typename ::testing::internal::Function<GMOCK_PP_REMOVE_PARENS(_Signature)>::Result                                \
    _FunctionName(GMOCK_PP_REPEAT(GMOCK_INTERNAL_PARAMETER, _Signature, _N))                                          \
    {                                                                                                                 \
        return _ClassName::GetInstance()->_FunctionName(GMOCK_PP_REPEAT(GMOCK_INTERNAL_FORWARD_ARG, _Signature, _N)); \
    }

#define MOCK_FUNCTION(_ClassName, _Ret, _FunctionName, _Args) \
    GMOCK_INTERNAL_ASSERT_PARENTHESIS(_Args);                 \
    MOCK_FUNCTION_IMPL(_ClassName, _FunctionName, GMOCK_PP_NARG0 _Args, (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))
