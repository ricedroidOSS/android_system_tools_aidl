/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <android/aidl/tests/ITestService.h>
#include <binder/IServiceManager.h>
#include <gtest/gtest.h>
#include <utils/String16.h>

using android::sp;
using android::aidl::tests::ITestService;

class AidlTest : public testing::Test {
 public:
  void SetUp() override {
    using android::getService;
    using android::OK;
    using android::String16;

    static const char kServiceName[] = "android.aidl.tests.ITestService";
    ASSERT_EQ(OK, getService(String16(kServiceName), &service));
    ASSERT_NE(nullptr, service);
  }

  sp<ITestService> service;
};