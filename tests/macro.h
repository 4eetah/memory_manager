#pragma once

#ifdef UNITTEST
#define ASSIST_UNIT_TEST(clazz_) friend class clazz_;
#else
#define ASSIST_UNIT_TEST(clazz_)
#endif
